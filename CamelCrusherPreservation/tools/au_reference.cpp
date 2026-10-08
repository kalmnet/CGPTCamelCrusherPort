#include <AudioToolbox/AudioToolbox.h>
#include <CoreFoundation/CoreFoundation.h>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
struct Input {std::vector<float> left,right;std::size_t offset=0;};
static OSStatus inputCallback(void* ref,AudioUnitRenderActionFlags*,const AudioTimeStamp*,UInt32,UInt32 frames,AudioBufferList* data){auto* in=static_cast<Input*>(ref);if(data->mNumberBuffers!=2||in->offset+frames>in->left.size())return kAudioUnitErr_TooManyFramesToProcess;for(UInt32 i=0;i<2;++i){auto& source=i?in->right:in->left;auto& b=data->mBuffers[i];if(b.mData)std::memcpy(b.mData,source.data()+in->offset,frames*sizeof(float));else b.mData=source.data()+in->offset;b.mDataByteSize=frames*sizeof(float);b.mNumberChannels=1;}return noErr;}
static void check(OSStatus e,const char* what){if(e!=noErr)throw std::runtime_error(std::string(what)+" OSStatus="+std::to_string(e));}
static OSType four(const char* s){if(std::strlen(s)!=4)throw std::runtime_error("FourCC must be 4 chars");return (UInt32(s[0])<<24)|(UInt32(s[1])<<16)|(UInt32(s[2])<<8)|UInt32(s[3]);}
int main(int argc,char** argv){
 if(argc!=9){std::cerr<<"Usage: au_reference input.f32 output.f32 rate block parameters.f32 type subtype manufacturer\nOriginal: aumf CaCr CamA. New: aumf CrP1 Prsv\n";return 2;}
 AudioUnit unit=nullptr;
 try {
  UInt32 block=UInt32(std::atoi(argv[4]));double rate=std::strtod(argv[3],nullptr);if(block==0||block>65536||rate<=0)throw std::runtime_error("Invalid rate/block");
  AudioComponentDescription desc{four(argv[6]),four(argv[7]),four(argv[8]),0,0};auto component=AudioComponentFindNext(nullptr,&desc);if(!component)throw std::runtime_error("AU not found in this architecture");check(AudioComponentInstanceNew(component,&unit),"Instantiate");
  AudioStreamBasicDescription format{};format.mSampleRate=rate;format.mFormatID=kAudioFormatLinearPCM;format.mFormatFlags=kAudioFormatFlagsNativeFloatPacked|kAudioFormatFlagIsNonInterleaved;format.mBytesPerPacket=format.mBytesPerFrame=4;format.mFramesPerPacket=1;format.mChannelsPerFrame=2;format.mBitsPerChannel=32;
  check(AudioUnitSetProperty(unit,kAudioUnitProperty_StreamFormat,kAudioUnitScope_Input,0,&format,sizeof format),"Input format");check(AudioUnitSetProperty(unit,kAudioUnitProperty_StreamFormat,kAudioUnitScope_Output,0,&format,sizeof format),"Output format");check(AudioUnitSetProperty(unit,kAudioUnitProperty_MaximumFramesPerSlice,kAudioUnitScope_Global,0,&block,sizeof block),"Maximum frames");
  std::ifstream f(argv[1],std::ios::binary|std::ios::ate);if(!f)throw std::runtime_error("Input open failed");auto bytes=f.tellg();if(bytes<0||bytes%8)throw std::runtime_error("Invalid input length");f.seekg(0);std::vector<float> stereo(std::size_t(bytes)/4);f.read(reinterpret_cast<char*>(stereo.data()),bytes);Input input;input.left.resize(stereo.size()/2);input.right.resize(stereo.size()/2);for(std::size_t i=0;i<input.left.size();++i){input.left[i]=stereo[i*2];input.right[i]=stereo[i*2+1];}
  AURenderCallbackStruct callback{inputCallback,&input};check(AudioUnitSetProperty(unit,kAudioUnitProperty_SetRenderCallback,kAudioUnitScope_Input,0,&callback,sizeof callback),"Input callback");
  std::array<float,17> values{};std::ifstream params(argv[5],std::ios::binary);params.read(reinterpret_cast<char*>(values.data()),68);if(params.gcount()!=68)throw std::runtime_error("Expected 17 normalized float32 parameters");
  for(UInt32 i=0;i<17;++i)check(AudioUnitSetParameter(unit,i,kAudioUnitScope_Global,0,values[i],0),"Set parameter");check(AudioUnitInitialize(unit),"Initialize");
  std::array<float,17> readback{};for(UInt32 i=0;i<17;++i){check(AudioUnitGetParameter(unit,i,kAudioUnitScope_Global,0,&readback[i]),"Read parameter");if(std::fabs(readback[i]-values[i])>1e-6f)throw std::runtime_error("Parameter readback differs at index "+std::to_string(i));}
  std::ofstream parameterLog(std::string(argv[2])+".params.f32",std::ios::binary);parameterLog.write(reinterpret_cast<char*>(readback.data()),68);
  std::ofstream out(argv[2],std::ios::binary);std::vector<float> l(block),r(block),interleaved(block*2);
  struct StereoList{UInt32 count;AudioBuffer buffers[2];} list{2,{{1,block*4,l.data()},{1,block*4,r.data()}}};
  for(std::size_t offset=0;offset<input.left.size();offset+=block){UInt32 n=UInt32(std::min<std::size_t>(block,input.left.size()-offset));input.offset=offset;list.buffers[0].mDataByteSize=list.buffers[1].mDataByteSize=n*4;AudioTimeStamp time{};time.mSampleTime=double(offset);time.mFlags=kAudioTimeStampSampleTimeValid;AudioUnitRenderActionFlags flags=0;check(AudioUnitRender(unit,&flags,&time,0,n,reinterpret_cast<AudioBufferList*>(&list)),"Render");for(UInt32 i=0;i<n;++i){interleaved[i*2]=l[i];interleaved[i*2+1]=r[i];}out.write(reinterpret_cast<char*>(interleaved.data()),n*8);}
  if(!out)throw std::runtime_error("Output write failed");AudioUnitUninitialize(unit);AudioComponentInstanceDispose(unit);return 0;
 }catch(const std::exception& e){if(unit)AudioComponentInstanceDispose(unit);std::cerr<<e.what()<<'\n';return 1;}
}
