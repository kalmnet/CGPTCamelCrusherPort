#include "Vst3.h"
#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "pluginterfaces/vst/ivstplugview.h"
#include "pluginterfaces/vst/ivstmessage.h"
#include "public.sdk/source/main/pluginfactory.h"
#include "base/source/fstring.h"
#include "pluginterfaces/base/ustring.h"
#include <algorithm>
#include <cstring>
#include <random>
namespace camel {
using namespace Steinberg;using namespace Steinberg::Vst;
namespace {
bool readStream(IBStream* stream,std::vector<std::uint8_t>& bytes){if(!stream)return false;bytes.clear();std::uint8_t buffer[4096];for(;;){int32 count=0;stream->read(buffer,sizeof buffer,&count);if(count<0||count>4096)return false;if(count==0)break;if(bytes.size()+count>1024*1024)return false;bytes.insert(bytes.end(),buffer,buffer+count);}return !bytes.empty();}
bool writeStream(IBStream* stream,const std::vector<std::uint8_t>& bytes){if(!stream)return false;int32 count=0;return stream->write(const_cast<std::uint8_t*>(bytes.data()),int32(bytes.size()),&count)==kResultOk&&count==int32(bytes.size());}
void text16(const std::string& s,TChar* dest){UString(dest,128).fromAscii(s.c_str());}
}
Processor::Processor(){setControllerClass(controllerUid);dsp.restore(bank.programs[0].values);}
tresult PLUGIN_API Processor::initialize(FUnknown* context){auto r=AudioEffect::initialize(context);if(r!=kResultOk)return r;addAudioInput(STR16("Stereo In"),SpeakerArr::kStereo);addAudioOutput(STR16("Stereo Out"),SpeakerArr::kStereo);return kResultOk;}
tresult PLUGIN_API Processor::setupProcessing(ProcessSetup& setup){auto r=AudioEffect::setupProcessing(setup);if(r!=kResultOk)return r;dsp.prepare(float(setup.sampleRate));return kResultOk;}
tresult PLUGIN_API Processor::setActive(TBool active){if(active)dsp.resume();return AudioEffect::setActive(active);}
tresult PLUGIN_API Processor::setBusArrangements(SpeakerArrangement* in,int32 ni,SpeakerArrangement* out,int32 no){if(ni!=1||no!=1||!in||!out||in[0]!=SpeakerArr::kStereo||out[0]!=SpeakerArr::kStereo)return kResultFalse;return AudioEffect::setBusArrangements(in,ni,out,no);}
tresult PLUGIN_API Processor::canProcessSampleSize(int32 n){return n==kSample32?kResultTrue:kResultFalse;}
tresult PLUGIN_API Processor::process(ProcessData& data){
 // Legacy parameter updates occur at host-block granularity. Collapse each queue to its last point.
 if(data.inputParameterChanges){int32 count=data.inputParameterChanges->getParameterCount();
  for(int32 i=0;i<count;++i){auto* q=data.inputParameterChanges->getParameterData(i);if(!q)continue;int32 points=q->getPointCount(),offset=0;ParamValue v=0;if(points<=0||q->getPoint(points-1,offset,v)!=kResultOk)continue;
   auto id=q->getParameterId();if(id==programId){auto index=std::uint32_t(std::clamp(v,0.,1.)*19.+.5);bank.current=index;dsp.restore(bank.programs[index].values);}
   else if(id<parameterCount){dsp.setParameter(id,float(v));bank.programs[bank.current].values[id]=float(std::clamp(v,0.,1.));}
  }
 }
 if(data.numSamples==0)return kResultOk;
 if(data.symbolicSampleSize!=kSample32||data.numInputs!=1||data.numOutputs!=1||data.inputs[0].numChannels!=2||data.outputs[0].numChannels!=2)return kResultFalse;
 auto** in=data.inputs[0].channelBuffers32;auto** out=data.outputs[0].channelBuffers32;if(!in||!out||!in[0]||!in[1]||!out[0]||!out[1])return kInvalidArgument;
 dsp.process(in[0],in[1],out[0],out[1],data.numSamples);data.outputs[0].silenceFlags=0;return kResultOk;
}
tresult PLUGIN_API Processor::notify(IMessage* message){if(message&&message->getMessageID()&&std::strcmp(message->getMessageID(),"LegacyProgramName")==0){int64 index=0;const void* bytes=nullptr;uint32 size=0;auto* a=message->getAttributes();if(a&&a->getInt("index",index)==kResultOk&&index>=0&&index<20&&a->getBinary("name",bytes,size)==kResultOk&&bytes&&size<=63){bank.programs[std::size_t(index)].name.assign(static_cast<const char*>(bytes),size);return kResultOk;}return kInvalidArgument;}return AudioEffect::notify(message);}
tresult PLUGIN_API Processor::getState(IBStream* state){return writeStream(state,encodeState(bank))?kResultOk:kResultFalse;}
tresult PLUGIN_API Processor::setState(IBStream* state){std::vector<std::uint8_t> bytes;if(!readStream(state,bytes)||!decodeState(bytes.data(),bytes.size(),bank))return kResultFalse;dsp.restore(bank.programs[bank.current].values);return kResultOk;}
tresult PLUGIN_API Controller::initialize(FUnknown* context){auto r=EditController::initialize(context);if(r!=kResultOk)return r;
 for(std::size_t i=0;i<parameterCount;++i){String128 title{};text16(parameterNames[i],title);int32 steps=(i==0||i==3||i==6||i==8||i==9||i>=12)?1:0;parameters.addParameter(title,nullptr,steps,bank.programs[0].values[i],i<12?ParameterInfo::kCanAutomate:(ParameterInfo::kCanAutomate|ParameterInfo::kIsHidden),int32(i));}
 parameters.addParameter(STR16("Legacy Program"),nullptr,19,0,ParameterInfo::kCanAutomate|ParameterInfo::kIsProgramChange,programId);return kResultOk;}
void Controller::updateParameters(){for(std::size_t i=0;i<parameterCount;++i)EditController::setParamNormalized(ParamID(i),bank.programs[bank.current].values[i]);EditController::setParamNormalized(programId,double(bank.current)/19.);}
tresult PLUGIN_API Controller::setComponentState(IBStream* state){std::vector<std::uint8_t> bytes;if(!readStream(state,bytes)||!decodeState(bytes.data(),bytes.size(),bank))return kResultFalse;updateParameters();return kResultOk;}
tresult PLUGIN_API Controller::setParamNormalized(ParamID id,ParamValue v){if(id==programId){bank.current=std::uint32_t(std::clamp(v,0.,1.)*19.+.5);updateParameters();}else if(id<parameterCount)bank.programs[bank.current].values[id]=float(std::clamp(v,0.,1.));return EditController::setParamNormalized(id,v);}
tresult PLUGIN_API Controller::getParamStringByValue(ParamID id,ParamValue v,String128 out){if(id==programId){text16(programName(int(std::clamp(v,0.,1.)*19.+.5)),out);return kResultOk;}if(id>=parameterCount)return kResultFalse;text16(displayValue(id,float(v)),out);return kResultOk;}
float Controller::value(int id)const{return id>=0&&id<int(parameterCount)?bank.programs[bank.current].values[std::size_t(id)]:0;}
void Controller::begin(int id){beginEdit(ParamID(id));}void Controller::change(int id,float v){setParamNormalized(ParamID(id),v);performEdit(ParamID(id),v);}void Controller::end(int id){endEdit(ParamID(id));}
std::string Controller::programName(int i)const{return i>=0&&i<int(programCount)?bank.programs[std::size_t(i)].name:"";}
void Controller::selectProgram(int i){if(i<0||i>=int(programCount))return;beginEdit(programId);setParamNormalized(programId,double(i)/19.);performEdit(programId,double(i)/19.);endEdit(programId);}
bool Controller::loadPreset(const std::uint8_t* data,std::size_t size,std::string& error){std::vector<Program> p;if(!importFile(data,size,p,&error))return false;
 if(p.size()!=1){error="Use the command-line converter and a VST3 preset to import a complete bank.";return false;}
 bank.programs[bank.current]=p[0];
 if(auto* message=allocateMessage()){message->setMessageID("LegacyProgramName");message->getAttributes()->setInt("index",bank.current);message->getAttributes()->setBinary("name",p[0].name.data(),uint32(p[0].name.size()));sendMessage(message);message->release();}
 for(int i=0;i<int(parameterCount);++i){begin(i);change(i,p[0].values[i]);end(i);}return true;
}
void Controller::randomize(){std::mt19937 rng(std::random_device{}());std::uniform_real_distribution<float> uniform(0,1);std::normal_distribution<float> mech(0,.6f),tube(0,1);
 auto set=[&](int id,float v){begin(id);change(id,std::clamp(v,0.f,1.f));end(id);};
 // GUI convenience approximation; original random Gaussian generator remains separately documented.
 if(value(0)>.5f){set(1,mech(rng));set(2,tube(rng));}if(value(3)>.5f){set(4,uniform(rng));set(5,uniform(rng));}if(value(6)>.5f){set(7,uniform(rng));set(8,uniform(rng)<.5f?0.f:1.f);}
}
#if !defined(__APPLE__)
IPlugView* PLUGIN_API Controller::createView(FIDString){return nullptr;}
#endif
}
using namespace Steinberg;using namespace Steinberg::Vst;
BEGIN_FACTORY_DEF("Preservation Research",""," ")
 DEF_CLASS2(INLINE_UID_FROM_FUID(camel::processorUid),PClassInfo::kManyInstances,kVstAudioEffectClass,"CamelCrusher Preservation",Vst::kDistributable,"Fx|Distortion","0.1.0",kVstVersionString,camel::Processor::create)
 DEF_CLASS2(INLINE_UID_FROM_FUID(camel::controllerUid),PClassInfo::kManyInstances,kVstComponentControllerClass,"CamelCrusher Preservation Controller",0,"","0.1.0",kVstVersionString,camel::Controller::create)
END_FACTORY
