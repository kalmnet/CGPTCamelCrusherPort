#import <Cocoa/Cocoa.h>
#import <AudioUnit/AUCocoaUIView.h>
#include <AudioToolbox/AudioToolbox.h>
#include "Dsp.h"
#include "State.h"
#include <array>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>

static void require(bool b,const char* text){if(!b)throw std::runtime_error(text);}
static void check(OSStatus e,const char* text){if(e)throw std::runtime_error(std::string(text)+" OSStatus="+std::to_string(e));}
struct Unit {
 AudioUnit u=nullptr;
 explicit Unit(AudioComponent c){check(AudioComponentInstanceNew(c,&u),"Instantiate");}
 ~Unit(){if(u){AudioUnitUninitialize(u);AudioComponentInstanceDispose(u);}}
};
struct Source {const float* l=nullptr;const float* r=nullptr;UInt32 count=0;};
static OSStatus input(void* ref,AudioUnitRenderActionFlags*,const AudioTimeStamp*,UInt32,UInt32 n,AudioBufferList* b){
 auto* s=static_cast<Source*>(ref);if(n>s->count||b->mNumberBuffers!=2)return kAudioUnitErr_FormatNotSupported;
 for(int ch=0;ch<2;++ch){const float* p=ch?s->r:s->l;if(b->mBuffers[ch].mData)std::memcpy(b->mBuffers[ch].mData,p,n*4);else b->mBuffers[ch].mData=const_cast<float*>(p);b->mBuffers[ch].mDataByteSize=n*4;b->mBuffers[ch].mNumberChannels=1;}return noErr;
}
static void setup(AudioUnit u,double rate,UInt32 block,Source* source){
 AudioStreamBasicDescription f{};f.mSampleRate=rate;f.mFormatID=kAudioFormatLinearPCM;f.mFormatFlags=kAudioFormatFlagsNativeFloatPacked|kAudioFormatFlagIsNonInterleaved;f.mBytesPerPacket=f.mBytesPerFrame=4;f.mFramesPerPacket=1;f.mChannelsPerFrame=2;f.mBitsPerChannel=32;
 check(AudioUnitSetProperty(u,kAudioUnitProperty_StreamFormat,kAudioUnitScope_Input,0,&f,sizeof f),"Input format");
 check(AudioUnitSetProperty(u,kAudioUnitProperty_StreamFormat,kAudioUnitScope_Output,0,&f,sizeof f),"Output format");
 check(AudioUnitSetProperty(u,kAudioUnitProperty_MaximumFramesPerSlice,kAudioUnitScope_Global,0,&block,sizeof block),"Max frames");
 AURenderCallbackStruct cb{input,source};check(AudioUnitSetProperty(u,kAudioUnitProperty_SetRenderCallback,kAudioUnitScope_Input,0,&cb,sizeof cb),"Callback");
}
static void params(AudioUnit u,const camel::Parameters& p){for(UInt32 i=0;i<17;++i)check(AudioUnitSetParameter(u,i,kAudioUnitScope_Global,0,p[i],0),"Set parameter");}
static void verify(AudioUnit u,const camel::Parameters& p){for(UInt32 i=0;i<17;++i){float v=0;check(AudioUnitGetParameter(u,i,kAudioUnitScope_Global,0,&v),"Get parameter");require(v==p[i],"Exact parameter recall");}}
static void select(AudioUnit u,int i){AUPreset p{i,CFSTR("test")};check(AudioUnitSetProperty(u,kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&p,sizeof p),"Select preset");}
static int selected(AudioUnit u){AUPreset p{};UInt32 n=sizeof p;check(AudioUnitGetProperty(u,kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&p,&n),"Current preset");if(p.presetName)CFRelease(p.presetName);return p.presetNumber;}
int main(int argc,char** argv){@autoreleasepool{
 if(argc!=2)return 2;
 try {
  [NSApplication sharedApplication];
  NSURL* url=[NSURL fileURLWithPath:[NSString stringWithUTF8String:argv[1]] isDirectory:YES];
  CFBundleRef bundle=CFBundleCreate(nullptr,(__bridge CFURLRef)url);require(bundle&&CFBundleLoadExecutable(bundle),"Load AU bundle");
  auto factory=reinterpret_cast<AudioComponentFactoryFunction>(CFBundleGetFunctionPointerForName(bundle,CFSTR("CamelCrusherAUFactory")));require(factory,"AU factory exported");
  AudioComponentDescription desc{'aumf','CrP1','Prsv',0,0};
  auto component=AudioComponentRegister(&desc,CFSTR("Preservation test AU"),0x200,factory);require(component,"Register runtime AU");
  auto bank=camel::factoryBank();
  {
   Unit u(component);UInt32 bytes=0;Boolean writable=false;check(AudioUnitGetPropertyInfo(u.u,kAudioUnitProperty_ParameterList,kAudioUnitScope_Global,0,&bytes,&writable),"Parameter list");require(bytes==17*sizeof(AudioUnitParameterID),"17 legacy parameter IDs");
   CFArrayRef presets=nullptr;bytes=sizeof presets;check(AudioUnitGetProperty(u.u,kAudioUnitProperty_FactoryPresets,kAudioUnitScope_Global,0,&presets,&bytes),"Factory presets");require(presets&&CFArrayGetCount(presets)==20,"20 factory presets");CFRelease(presets);
   select(u.u,13);auto values=bank.programs[13].values;values[1]=.125f;values[12]=.375f;params(u.u,values);
   select(u.u,4);auto other=bank.programs[4].values;other[11]=.55f;params(u.u,other);select(u.u,13);verify(u.u,values);
   CFPropertyListRef state=nullptr;bytes=sizeof state;check(AudioUnitGetProperty(u.u,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&state,&bytes),"Save state");
   Unit restored(component);check(AudioUnitSetProperty(restored.u,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&state,sizeof state),"Restore state");require(selected(restored.u)==13,"Current program recall");verify(restored.u,values);
   select(restored.u,4);verify(restored.u,other);select(restored.u,13);verify(restored.u,values);CFRelease(state);
   AUPreset custom{-1,CFSTR("User saved name")};check(AudioUnitSetProperty(u.u,kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&custom,sizeof custom),"Custom preset name");
   CFPropertyListRef customState=nullptr;bytes=sizeof customState;check(AudioUnitGetProperty(u.u,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&customState,&bytes),"Save custom name");Unit named(component);check(AudioUnitSetProperty(named.u,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&customState,sizeof customState),"Restore custom name");verify(named.u,values);
   AUPreset namedPreset{};bytes=sizeof namedPreset;check(AudioUnitGetProperty(named.u,kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&namedPreset,&bytes),"Read custom name");require(namedPreset.presetNumber==-1&&namedPreset.presetName&&CFEqual(namedPreset.presetName,CFSTR("User saved name")),"User preset name retained");CFRelease(namedPreset.presetName);CFRelease(customState);
   // Original-style raw single-program state, retaining unused slots.
   auto program=bank.programs[7];program.values[16]=.625f;auto raw=camel::encodeLegacy({program});NSData* data=[NSData dataWithBytes:raw.data() length:raw.size()];
   NSDictionary* legacy=@{@"data":data};CFPropertyListRef plist=(__bridge CFPropertyListRef)legacy;
   check(AudioUnitSetProperty(restored.u,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&plist,sizeof plist),"Legacy AU raw chunk");verify(restored.u,program.values);
   NSMutableData* big=[NSMutableData dataWithLength:68];auto* out=static_cast<unsigned char*>(big.mutableBytes);
   for(int i=0;i<17;++i){UInt32 bits;std::memcpy(&bits,&values[i],4);out[4*i]=bits>>24;out[4*i+1]=bits>>16;out[4*i+2]=bits>>8;out[4*i+3]=bits;}
   legacy=@{@"data":big};plist=(__bridge CFPropertyListRef)legacy;check(AudioUnitSetProperty(restored.u,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&plist,sizeof plist),"Legacy big endian floats");verify(restored.u,values);
   NSDictionary* bad=@{@"data":[NSData dataWithBytes:"bad" length:3]};plist=(__bridge CFPropertyListRef)bad;require(AudioUnitSetProperty(restored.u,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&plist,sizeof plist)!=noErr,"Reject malformed state");verify(restored.u,values);
   // Discover the public Cocoa factory and open its actual editor.
   AudioUnitCocoaViewInfo info{};bytes=sizeof info;check(AudioUnitGetProperty(u.u,kAudioUnitProperty_CocoaUI,kAudioUnitScope_Global,0,&info,&bytes),"Cocoa UI metadata");
   @autoreleasepool {
    NSBundle* ui=[NSBundle bundleWithURL:(__bridge NSURL*)info.mCocoaAUViewBundleLocation];[ui load];Class cls=NSClassFromString((__bridge NSString*)info.mCocoaAUViewClass[0]);require(cls!=Nil,"Cocoa factory class");
    id<AUCocoaUIBase> maker=[[cls alloc]init];NSView* view=[maker uiViewForAudioUnit:u.u withSize:NSMakeSize(345,373)];require(view&&view.subviews.count==1,"AU editor attached");
    id images=[view.subviews[0] valueForKey:@"images"];require([images count]==8,"Eight original GUI images loaded");require(view.frame.size.width==345&&view.frame.size.height==373,"Original GUI size");
   }
   CFRelease(info.mCocoaAUViewBundleLocation);CFRelease(info.mCocoaAUViewClass[0]);
  }
  int cases=0;std::uint64_t samples=0;double worst=0;
  for(double rate:{44100.,48000.,96000.})for(UInt32 block:{31u,64u,257u,512u})for(int preset=0;preset<20;++preset){
   Unit u(component);Source source;setup(u.u,rate,block,&source);auto values=bank.programs[preset].values;params(u.u,values);check(AudioUnitInitialize(u.u),"Initialize");camel::Dsp dsp;dsp.prepare(float(rate));dsp.restore(values);
   std::vector<float> l(block),r(block),ol(block),orr(block),rl(block),rr(block);
   struct List{UInt32 count;AudioBuffer b[2];} list{2,{{1,block*4,ol.data()},{1,block*4,orr.data()}}};
   for(int pass=0;pass<8;++pass){
    if(pass==4){values[1]=.73f;values[4]=.37f;values[7]=.61f;values[8]=1-values[8];params(u.u,values);for(int i=0;i<17;++i)dsp.setParameter(i,values[i]);}
    for(UInt32 i=0;i<block;++i){l[i]=float(std::sin((pass*block+i)*.071)*1.2);r[i]=float(std::cos((pass*block+i)*.113)*.8);}
    source={l.data(),r.data(),block};list.b[0]={1,block*4,ol.data()};list.b[1]={1,block*4,orr.data()};AudioTimeStamp time{};time.mSampleTime=pass*block;time.mFlags=kAudioTimeStampSampleTimeValid;AudioUnitRenderActionFlags flags=0;
    check(AudioUnitRender(u.u,&flags,&time,0,block,reinterpret_cast<AudioBufferList*>(&list)),"Render");dsp.process(l.data(),r.data(),rl.data(),rr.data(),int(block));
    samples+=block*2;for(UInt32 i=0;i<block;++i){require(std::isfinite(ol[i])&&std::isfinite(orr[i]),"Finite AU output");worst=std::max(worst,double(std::fabs(ol[i]-rl[i])));worst=std::max(worst,double(std::fabs(orr[i]-rr[i])));}
   }++cases;
  }
  require(worst==0,"AU render equals recovered core");
  std::cout<<"AU render cases="<<cases<<" channel_samples="<<samples<<" max_absolute_error="<<worst<<"; parameter, bank, legacy state, preset and Cocoa editor tests passed\n";
  // Registered component retains executable factory: keep the bundle loaded until process exit.
  CFRelease(bundle);return 0;
 }catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
}}
