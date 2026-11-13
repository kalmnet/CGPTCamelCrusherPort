#import <Cocoa/Cocoa.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AudioUnit/AUCocoaUIView.h>
#include <AudioUnitSDK/AUMIDIEffectBase.h>
#include "Dsp.h"
#include "State.h"
#include "EditorModel.h"
#include <dlfcn.h>
#include <atomic>
#include <memory>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <random>
namespace {
NSBundle* ownBundle(){Dl_info info{};if(!dladdr(reinterpret_cast<void*>(&ownBundle),&info)||!info.dli_fname)return nil;NSString* executable=[NSString stringWithUTF8String:info.dli_fname];NSString* path=[[[executable stringByDeletingLastPathComponent]stringByDeletingLastPathComponent]stringByDeletingLastPathComponent];return [NSBundle bundleWithPath:path];}
const void* retainPreset(CFAllocatorRef,const void* value){auto* p=new AUPreset(*static_cast<const AUPreset*>(value));if(p->presetName)CFRetain(p->presetName);return p;}
void releasePreset(CFAllocatorRef,const void* value){auto* p=static_cast<const AUPreset*>(value);if(p->presetName)CFRelease(p->presetName);delete p;}
CFStringRef describePreset(const void* value){auto* p=static_cast<const AUPreset*>(value);return p->presetName?CFStringCreateCopy(nullptr,p->presetName):CFStringCreateCopy(nullptr,CFSTR(""));}
Boolean equalPreset(const void* a,const void* b){auto* x=static_cast<const AUPreset*>(a);auto* y=static_cast<const AUPreset*>(b);return x->presetNumber==y->presetNumber;}
const CFArrayCallBacks presetCallbacks{0,retainPreset,releasePreset,describePreset,equalPreset};
constexpr OSType fourcc(char a,char b,char c,char d){return (UInt32(a)<<24)|(UInt32(b)<<16)|(UInt32(c)<<8)|UInt32(d);}
#ifdef CAMEL_AU_LEGACY_ID
constexpr OSType auSubtype=fourcc('C','a','C','r'),auMaker=fourcc('C','a','m','A');
#else
constexpr OSType auSubtype=fourcc('C','r','P','1'),auMaker=fourcc('P','r','s','v');
#endif
}
class CamelCrusherAU final:public ausdk::AUMIDIEffectBase {
 camel::Dsp dsp;camel::Bank bank=camel::factoryBank();std::atomic<bool> reset{true};
 void storeCurrent(){for(UInt32 i=0;i<camel::parameterCount;++i)bank.programs[bank.current].values[i]=AUEffectBase::GetParameter(i);}
 void currentName(){CFStringRef name=CFStringCreateWithCString(nullptr,bank.programs[bank.current].name.c_str(),kCFStringEncodingUTF8);AUPreset p{SInt32(bank.current),name};SetAFactoryPresetAsCurrent(p);CFRelease(name);}

 void restoreName(NSDictionary* state){NSString* name=state[@"name"];if(![name isKindOfClass:NSString.class]){currentName();return;}NSNumber* number=state[@"preservationPresetNumber"];bool factory=[number isKindOfClass:NSNumber.class]&&number.intValue>=0;AUPreset preset{factory?SInt32(bank.current):-1,(__bridge CFStringRef)name};if(factory)SetAFactoryPresetAsCurrent(preset);else AUMIDIEffectBase::NewCustomPresetSet(preset);}
public:
 explicit CamelCrusherAU(AudioComponentInstance ci):AUMIDIEffectBase(ci,true){CreateElements();for(UInt32 i=0;i<camel::parameterCount;++i)AUEffectBase::SetParameter(i,bank.programs[0].values[i]);currentName();}
 bool CanScheduleParameters()const noexcept override{return false;}
 UInt32 SupportedNumChannels(const AUChannelInfo** info)override{static const AUChannelInfo channels{2,2};if(info)*info=&channels;return 1;}
 OSStatus Initialize()override{auto e=AUMIDIEffectBase::Initialize();if(e!=noErr)return e;dsp.prepare(float(GetSampleRate()));reset.store(true);return noErr;}
 OSStatus Reset(AudioUnitScope,AudioUnitElement)override{reset.store(true);return noErr;}
 OSStatus GetParameterInfo(AudioUnitScope scope,AudioUnitParameterID id,AudioUnitParameterInfo& info)override{if(scope!=kAudioUnitScope_Global||id>=camel::parameterCount)return kAudioUnitErr_InvalidParameter;std::memset(&info,0,sizeof info);std::strncpy(info.name,camel::parameterNames[id],sizeof info.name-1);info.unit=kAudioUnitParameterUnit_Generic;info.minValue=0;info.maxValue=1;info.defaultValue=camel::factoryBank().programs[0].values[id];info.flags=kAudioUnitParameterFlag_IsReadable|kAudioUnitParameterFlag_IsWritable;FillInParameterName(info,CFStringCreateWithCString(nullptr,camel::parameterNames[id],kCFStringEncodingUTF8),true);return noErr;}
 OSStatus ProcessBufferLists(AudioUnitRenderActionFlags& flags,const AudioBufferList& input,AudioBufferList& output,UInt32 n)override{
  if(n==0)return noErr;
  if(input.mNumberBuffers!=2||output.mNumberBuffers!=2||input.mBuffers[0].mNumberChannels!=1||input.mBuffers[1].mNumberChannels!=1)return kAudioUnitErr_FormatNotSupported;
  camel::Parameters p;for(UInt32 i=0;i<camel::parameterCount;++i)p[i]=AUEffectBase::GetParameter(i);if(reset.exchange(false))dsp.restore(p);else for(UInt32 i=0;i<camel::parameterCount;++i)dsp.setParameter(i,p[i]);
  if(!input.mBuffers[0].mData||!input.mBuffers[1].mData||!output.mBuffers[0].mData||!output.mBuffers[1].mData)return kAudioUnitErr_InvalidPropertyValue;
  dsp.process(static_cast<const float*>(input.mBuffers[0].mData),static_cast<const float*>(input.mBuffers[1].mData),static_cast<float*>(output.mBuffers[0].mData),static_cast<float*>(output.mBuffers[1].mData),int(n));flags&=~kAudioUnitRenderAction_OutputIsSilence;return noErr;
 }
 bool SupportsTail()override{return true;}Float64 GetTailTime()override{return 30.;}
 OSStatus GetPresets(CFArrayRef* output)const override{
  if(!output)return noErr;
  CFMutableArrayRef result=CFArrayCreateMutable(nullptr,20,&presetCallbacks);if(!result)return memFullErr;
  const auto factory=camel::factoryBank();
  for(int i=0;i<20;++i){CFStringRef name=CFStringCreateWithCString(nullptr,factory.programs[i].name.c_str(),kCFStringEncodingUTF8);AUPreset preset{i,name};CFArrayAppendValue(result,&preset);CFRelease(name);}*output=result;return noErr;
 }
 OSStatus NewFactoryPresetSet(const AUPreset& preset)override{if(preset.presetNumber<0||preset.presetNumber>=20)return kAudioUnitErr_InvalidPropertyValue;storeCurrent();bank.current=UInt32(preset.presetNumber);for(UInt32 i=0;i<camel::parameterCount;++i)AUEffectBase::SetParameter(i,bank.programs[bank.current].values[i]);currentName();reset.store(true);return noErr;}
 OSStatus SaveState(CFPropertyListRef* output)override{if(!output)return paramErr;for(UInt32 i=0;i<camel::parameterCount;++i)bank.programs[bank.current].values[i]=AUEffectBase::GetParameter(i);auto bytes=camel::encodeLegacy({bank.programs[bank.current]});auto bankBytes=camel::encodeState(bank);NSData* data=[NSData dataWithBytes:bytes.data() length:bytes.size()];AUPreset present{-1,nullptr};AUMIDIEffectBase::GetProperty(kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&present);NSString* presetName=CFBridgingRelease(present.presetName);if(!presetName)presetName=[NSString stringWithUTF8String:bank.programs[bank.current].name.c_str()];NSDictionary* state=@{@"version":@0,@"type":@(fourcc('a','u','m','f')),@"subtype":@(auSubtype),@"manufacturer":@(auMaker),@"name":presetName,@"preservationPresetNumber":@(present.presetNumber),@"data":data,@"preservationProgram":@(bank.current),@"preservationBank":[NSData dataWithBytes:bankBytes.data() length:bankBytes.size()]};*output=CFBridgingRetain(state);return noErr;}
 OSStatus RestoreState(CFPropertyListRef plist)override{if(!plist||CFGetTypeID(plist)!=CFDictionaryGetTypeID())return kAudioUnitErr_InvalidPropertyValue;NSDictionary* dict=(__bridge NSDictionary*)plist;NSData* savedBank=dict[@"preservationBank"];if(savedBank){if(![savedBank isKindOfClass:NSData.class]||savedBank.length>1048576)return kAudioUnitErr_InvalidPropertyValue;camel::Bank decoded=camel::factoryBank();if(!camel::decodeState(static_cast<const std::uint8_t*>(savedBank.bytes),savedBank.length,decoded))return kAudioUnitErr_InvalidPropertyValue;bank=decoded;for(UInt32 i=0;i<camel::parameterCount;++i)AUEffectBase::SetParameter(i,bank.programs[bank.current].values[i]);restoreName(dict);reset.store(true);return noErr;}
  NSData* data=dict[@"data"];if(![data isKindOfClass:NSData.class]||data.length>1048576)return kAudioUnitErr_InvalidPropertyValue;
  std::vector<camel::Program> p;auto* bytes=static_cast<const std::uint8_t*>(data.bytes);
  if(!camel::decodeLegacy(bytes,data.length,p)){
   if(data.length!=camel::parameterCount*4)return kAudioUnitErr_InvalidPropertyValue;camel::Program program;for(UInt32 i=0;i<camel::parameterCount;++i){UInt32 bits=(UInt32(bytes[4*i])<<24)|(UInt32(bytes[4*i+1])<<16)|(UInt32(bytes[4*i+2])<<8)|bytes[4*i+3];std::memcpy(&program.values[i],&bits,4);if(!std::isfinite(program.values[i])||program.values[i]<0||program.values[i]>1)return kAudioUnitErr_InvalidPropertyValue;}p={program};
  }
  if(p.size()!=1)return kAudioUnitErr_InvalidPropertyValue;NSNumber* index=dict[@"preservationProgram"];if([index isKindOfClass:NSNumber.class]&&index.intValue>=0&&index.intValue<20)bank.current=UInt32(index.intValue);bank.programs[bank.current]=p[0];for(UInt32 i=0;i<camel::parameterCount;++i)AUEffectBase::SetParameter(i,p[0].values[i]);restoreName(dict);reset.store(true);return noErr;
 }
 OSStatus GetPropertyInfo(AudioUnitPropertyID id,AudioUnitScope scope,AudioUnitElement elem,UInt32& size,bool& writable)override{if(id==kAudioUnitProperty_CocoaUI&&scope==kAudioUnitScope_Global&&elem==0){size=sizeof(AudioUnitCocoaViewInfo);writable=false;return noErr;}return AUMIDIEffectBase::GetPropertyInfo(id,scope,elem,size,writable);}
 OSStatus GetProperty(AudioUnitPropertyID id,AudioUnitScope scope,AudioUnitElement elem,void* output)override{if(id==kAudioUnitProperty_CocoaUI){auto* info=static_cast<AudioUnitCocoaViewInfo*>(output);info->mCocoaAUViewBundleLocation=(CFURLRef)CFBridgingRetain(ownBundle().bundleURL);info->mCocoaAUViewClass[0]=CFStringCreateCopy(nullptr,CFSTR("CCPAUCocoaView"));return noErr;}return AUMIDIEffectBase::GetProperty(id,scope,elem,output);}
};
AUSDK_COMPONENT_ENTRY(ausdk::AUMIDIEffectFactory,CamelCrusherAU)
namespace {
class AUModel:public camel::EditorModel {
 AudioUnit unit;camel::Bank bank=camel::factoryBank();
 void event(AudioUnitEventType type,int id){AudioUnitEvent e{};e.mEventType=type;e.mArgument.mParameter={unit,AudioUnitParameterID(id),kAudioUnitScope_Global,0};AUEventListenerNotify(nullptr,nullptr,&e);}
public:
 explicit AUModel(AudioUnit u):unit(u){}
 float value(int id)const override{float v=0;AudioUnitGetParameter(unit,AudioUnitParameterID(id),kAudioUnitScope_Global,0,&v);return v;}
 void begin(int id)override{event(kAudioUnitEvent_BeginParameterChangeGesture,id);}void change(int id,float v)override{AudioUnitSetParameter(unit,AudioUnitParameterID(id),kAudioUnitScope_Global,0,v,0);event(kAudioUnitEvent_ParameterValueChange,id);}void end(int id)override{event(kAudioUnitEvent_EndParameterChangeGesture,id);}
 int program()const override{AUPreset p{};UInt32 size=sizeof p;if(AudioUnitGetProperty(unit,kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&p,&size)==noErr){int n=p.presetNumber;if(p.presetName)CFRelease(p.presetName);if(n>=0&&n<20)return n;}CFPropertyListRef state=nullptr;UInt32 bytes=sizeof state;if(AudioUnitGetProperty(unit,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&state,&bytes)==noErr&&state){NSDictionary* dict=(__bridge NSDictionary*)state;NSNumber* index=dict[@"preservationProgram"];int i=[index isKindOfClass:NSNumber.class]?index.intValue:-1;CFRelease(state);if(i>=0&&i<20)return i;}return int(bank.current);}
 std::string programName(int i)const override{
  if(i<0||i>=20)return "";AUPreset preset{};UInt32 size=sizeof preset;
  if(AudioUnitGetProperty(unit,kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&preset,&size)==noErr){char name[256]{};bool matches=(preset.presetNumber==i||(preset.presetNumber<0&&i==program()))&&preset.presetName&&CFStringGetCString(preset.presetName,name,sizeof name,kCFStringEncodingUTF8);if(preset.presetName)CFRelease(preset.presetName);if(matches)return name;}return bank.programs[i].name;
 }
 void selectProgram(int i)override{if(i<0||i>=20)return;AUPreset p{i,CFStringCreateWithCString(nullptr,bank.programs[i].name.c_str(),kCFStringEncodingUTF8)};AudioUnitSetProperty(unit,kAudioUnitProperty_PresentPreset,kAudioUnitScope_Global,0,&p,sizeof p);CFRelease(p.presetName);bank.current=UInt32(i);}
 bool loadPreset(const std::uint8_t* data,std::size_t size,std::string& error)override{std::vector<camel::Program> p;if(!camel::importFile(data,size,p,&error)||p.size()!=1)return false;bank.current=UInt32(program());auto raw=camel::encodeLegacy(p);NSDictionary* state=@{@"data":[NSData dataWithBytes:raw.data() length:raw.size()],@"preservationProgram":@(bank.current)};CFPropertyListRef plist=(__bridge CFPropertyListRef)state;
 if(AudioUnitSetProperty(unit,kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0,&plist,sizeof plist)!=noErr){error="Audio Unit rejected preset";return false;}
 for(int i=0;i<17;++i){begin(i);change(i,p[0].values[i]);end(i);}bank.programs[bank.current]=p[0];return true;}
 std::string readout(int id)const override{return camel::displayValue(id,value(id));}
 void randomize()override{std::mt19937 rng(std::random_device{}());std::uniform_real_distribution<float> u(0,1);std::normal_distribution<float> mech(0,.6f),tube(0,1);auto update=[&](int i,float v){begin(i);change(i,std::clamp(v,0.f,1.f));end(i);};if(value(0)>.5f){update(1,mech(rng));update(2,tube(rng));}if(value(3)>.5f){update(4,u(rng));update(5,u(rng));}if(value(6)>.5f){update(7,u(rng));update(8,u(rng)<.5f?0:1);}}
};
}
@interface CCPAUContainer:NSView { @public std::unique_ptr<AUModel> model;void* native; }
@end
@implementation CCPAUContainer
- (void)dealloc {camel::destroyNativeEditor(native);native=nullptr;}
@end
@interface CCPAUCocoaView:NSObject<AUCocoaUIBase>
@end
@implementation CCPAUCocoaView
- (unsigned)interfaceVersion{return 0;}
- (NSString*)description{return @"CamelCrusher Preservation";}
- (NSView*)uiViewForAudioUnit:(AudioUnit)unit withSize:(NSSize)size{CCPAUContainer* view=[[CCPAUContainer alloc]initWithFrame:NSMakeRect(0,0,345,373)];view->model=std::make_unique<AUModel>(unit);view->native=camel::createNativeEditor((__bridge void*)view,view->model.get(),ownBundle().resourcePath.UTF8String);return view;}
@end
