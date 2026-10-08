#include "LegacyAbi.h"
#include "Dsp.h"
#include "State.h"
#include "EditorModel.h"
#include <atomic>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <random>
#include <vector>
#if defined(_WIN32)
#define CAMEL_EXPORT extern "C" __declspec(dllexport)
#else
#define CAMEL_EXPORT extern "C" __attribute__((visibility("default")))
#endif
namespace camel {
#if defined(__APPLE__)
std::string legacyResourceDirectory();
#endif
class Legacy:public EditorModel {
public:
 legacy::Effect effect{};legacy::Dispatch host=nullptr;Bank bank=factoryBank();Dsp dsp;
 std::array<std::atomic<float>,parameterCount> controls{};
 std::atomic<int> selected{0};std::atomic<bool> reset{true},bypassed{false};
 std::vector<std::uint8_t> chunk;std::vector<float> scratchLeft=std::vector<float>(16384),scratchRight=std::vector<float>(16384);legacy::Rect rect{0,0,373,345};void* editor=nullptr;bool cocoaView=false;
 explicit Legacy(legacy::Dispatch h):host(h){
  effect.magic=0x56737450;effect.dispatcher=dispatch;effect.process=processAdding;effect.processReplacing=processReplacing;effect.setParameter=set;effect.getParameter=get;
  effect.numPrograms=programCount;effect.numParams=parameterCount;effect.numInputs=effect.numOutputs=2;effect.flags=(1<<4)|(1<<5);
#if defined(__APPLE__)
  effect.flags|=1;
#endif
  effect.object=this;effect.uniqueId=0x43614372;effect.version=101;effect.ioRatio=1;apply(0);
 }
 ~Legacy(){closeEditor();}
 void closeEditor(){
#if defined(__APPLE__)
 destroyNativeEditor(editor);
#endif
 editor=nullptr;}
 void store(){int i=selected.load();for(std::size_t p=0;p<parameterCount;++p)bank.programs[i].values[p]=controls[p].load();}
 void apply(int i){bank.current=std::uint32_t(i);for(std::size_t p=0;p<parameterCount;++p)controls[p].store(bank.programs[i].values[p]);selected.store(i);reset.store(true);}
 float value(int id)const override{return id>=0&&id<int(parameterCount)?controls[id].load():0;}
 void begin(int id)override{if(host)host(&effect,43,id,0,nullptr,0);}
 void change(int id,float v)override{set(&effect,id,v);if(host)host(&effect,0,id,0,nullptr,v);}
 void end(int id)override{if(host)host(&effect,44,id,0,nullptr,0);}
 int program()const override{return selected.load();}
 std::string programName(int i)const override{return i>=0&&i<int(programCount)?bank.programs[i].name:"";}
 void selectProgram(int i)override{if(i<0||i>=int(programCount))return;store();apply(i);if(host)host(&effect,42,0,0,nullptr,0);}
 bool loadPreset(const std::uint8_t* bytes,std::size_t size,std::string& error)override{std::vector<Program> p;if(!importFile(bytes,size,p,&error)||p.size()!=1)return false;bank.programs[selected.load()]=p[0];apply(selected.load());if(host)host(&effect,42,0,0,nullptr,0);return true;}
 std::string readout(int id)const override{return displayValue(id,value(id));}
 void randomize()override{std::mt19937 rng(std::random_device{}());std::uniform_real_distribution<float> u(0,1);std::normal_distribution<float> mech(0,.6f),tube(0,1);auto update=[&](int i,float v){begin(i);change(i,std::clamp(v,0.f,1.f));end(i);};if(value(0)>.5f){update(1,mech(rng));update(2,tube(rng));}if(value(3)>.5f){update(4,u(rng));update(5,u(rng));}if(value(6)>.5f){update(7,u(rng));update(8,u(rng)<.5f?0:1);}}
 static Legacy* self(legacy::Effect* e){return static_cast<Legacy*>(e->object);}
 static void set(legacy::Effect* e,std::int32_t id,float v){if(id>=0&&id<int(parameterCount)&&std::isfinite(v))self(e)->controls[id].store(std::clamp(v,0.f,1.f));}
 static float get(legacy::Effect* e,std::int32_t id){return self(e)->value(id);}
 static void processReplacing(legacy::Effect* e,float** in,float** out,std::int32_t n){auto* p=self(e);if(n<=0||!in||!out||!in[0]||!in[1]||!out[0]||!out[1])return;
  Parameters v;for(std::size_t i=0;i<parameterCount;++i)v[i]=p->controls[i].load();if(p->reset.exchange(false))p->dsp.restore(v);else for(std::size_t i=0;i<parameterCount;++i)p->dsp.setParameter(i,v[i]);
  if(p->bypassed.load()){std::memmove(out[0],in[0],n*sizeof(float));std::memmove(out[1],in[1],n*sizeof(float));return;}
  p->dsp.process(in[0],in[1],out[0],out[1],n);
 }
 static void processAdding(legacy::Effect* e,float** in,float** out,std::int32_t n){auto* p=self(e);if(n<=0||!in||!out||!in[0]||!in[1]||!out[0]||!out[1]||std::size_t(n)>p->scratchLeft.size())return;float* scratch[]={p->scratchLeft.data(),p->scratchRight.data()};processReplacing(e,in,scratch,n);for(int i=0;i<n;++i){out[0][i]+=scratch[0][i];out[1][i]+=scratch[1][i];}}
 static void copy(void* dest,const std::string& s,std::size_t capacity){if(!dest||!capacity)return;std::size_t n=std::min(capacity-1,s.size());std::memcpy(dest,s.data(),n);static_cast<char*>(dest)[n]=0;}
 static std::intptr_t dispatch(legacy::Effect* e,std::int32_t op,std::int32_t index,std::intptr_t value,void* ptr,float opt){auto* p=self(e);
  switch(op){
  case 0:return 1;case 1:delete p;return 1;
  case 2:p->selectProgram(int(value));return 1;case 3:return p->selected.load();
  case 4:if(ptr)p->bank.programs[p->selected.load()].name=std::string(static_cast<const char*>(ptr),strnlen(static_cast<const char*>(ptr),63));return 1;
  case 5:copy(ptr,p->programName(p->selected.load()),24);return 1;
  case 6:copy(ptr,index==4?"Hz":(index==7||index==11?"dB":(index==1||index==2||index==5||index==10?"%":"")),8);return 1;
  case 7:{std::string text=p->readout(index);auto separator=text.rfind(' ');if(separator!=std::string::npos)text.resize(separator);if(index==0||index==3||index==6||index==8||index==9)text=std::to_string(int(p->value(index)));copy(ptr,text,8);return 1;}case 8:copy(ptr,index>=0&&index<int(parameterCount)?parameterNames[index]:"",8);return 1;
  case 10:if(opt>0){p->dsp.prepare(opt);p->reset.store(true);}return 1;case 11:if(value>0&&value<=1048576){p->scratchLeft.resize(std::size_t(value));p->scratchRight.resize(std::size_t(value));}return 1;case 12:if(value)p->reset.store(true);return 1;
  case 13:if(ptr)*static_cast<legacy::Rect**>(ptr)=&p->rect;return 1;
  case 14:
#if defined(__APPLE__)
   if(p->cocoaView&&ptr&&!p->editor){auto path=legacyResourceDirectory();p->editor=createNativeEditor(ptr,p,path.c_str());return p->editor?1:0;}
#endif
   return 0;
  case 15:p->closeEditor();return 1;case 19:return 1;
  case 23:{if(!ptr)return 0;p->store();std::vector<Program> programs;if(index)programs={p->bank.programs[p->selected.load()]};else programs.assign(p->bank.programs.begin(),p->bank.programs.end());p->chunk=encodeLegacy(programs);*static_cast<void**>(ptr)=p->chunk.data();return std::intptr_t(p->chunk.size());}
  case 24:{if(!ptr||value<=0||value>1024*1024)return 0;std::vector<Program> programs;if(!decodeLegacy(static_cast<const std::uint8_t*>(ptr),std::size_t(value),programs))return 0;
   int active=p->selected.load();if(index){if(programs.size()!=1)return 0;p->bank.programs[active]=programs[0];}else{if(programs.size()!=programCount)return 0;std::copy(programs.begin(),programs.end(),p->bank.programs.begin());}p->apply(active);return 1;}
  case 50:if(index==0x436f636b&&value==0x4e535677){p->cocoaView=true;return 1;}return 0;
  case 29:if(index<0||index>=int(programCount))return 0;copy(ptr,p->programName(index),24);return 1;
  case 26:return index>=0&&index<int(parameterCount);case 35:return 1;
  case 44:p->bypassed.store(value!=0);return 1;
  case 45:copy(ptr,"CamelCrusher",32);return 1;case 47:copy(ptr,"Camel Audio",64);return 1;case 48:copy(ptr,"CamelCrusher",64);return 1;case 49:return 101;
  case 51:if(ptr){const char* s=static_cast<const char*>(ptr);if(std::strcmp(s,"hasCockosViewAsConfig")==0){p->cocoaView=true;return 0xbeef;}if(std::strcmp(s,"plugAsChannelInsert")==0||std::strcmp(s,"plugAsSend")==0||std::strcmp(s,"2in2out")==0)return 1;}return 0;
  case 52:return 0;case 58:return 2400;case 71:case 72:return 1;default:return 0;
  }
 }
};
}
CAMEL_EXPORT camel::legacy::Effect* VSTPluginMain(camel::legacy::Dispatch host){if(!host||!host(nullptr,1,0,0,nullptr,0))return nullptr;auto* p=new camel::Legacy(host);return &p->effect;}
#if defined(__APPLE__)
CAMEL_EXPORT camel::legacy::Effect* main_macho(camel::legacy::Dispatch host){return VSTPluginMain(host);}
#endif
