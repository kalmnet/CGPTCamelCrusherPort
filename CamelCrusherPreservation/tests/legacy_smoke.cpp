#include "LegacyAbi.h"
#include "State.h"
#include "Dsp.h"
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <cmath>
#if defined(_WIN32)
#include <windows.h>
#else
#include <dlfcn.h>
#endif
using camel::legacy::Effect;
static std::intptr_t host(Effect*,std::int32_t op,std::int32_t,std::intptr_t,void*,float){return op==1?2400:0;}
static void require(bool v,const char* text){if(!v)throw std::runtime_error(text);}
int main(int argc,char** argv){if(argc!=2)return 2;try{
#if defined(_WIN32)
 auto handle=LoadLibraryA(argv[1]);auto entry=reinterpret_cast<Effect*(*)(camel::legacy::Dispatch)>(GetProcAddress(handle,"VSTPluginMain"));
#else
 auto handle=dlopen(argv[1],RTLD_NOW);require(handle!=nullptr,"Load module");auto entry=reinterpret_cast<Effect*(*)(camel::legacy::Dispatch)>(dlsym(handle,"VSTPluginMain"));
#endif
 require(entry!=nullptr,"Entry point");auto* e=entry(host);require(e&&e->uniqueId==0x43614372&&e->numParams==17&&e->numPrograms==20,"Original identity and dimensions");
 auto d=[&](int op,int index=0,std::intptr_t value=0,void* ptr=nullptr,float opt=0){return e->dispatcher(e,op,index,value,ptr,opt);};d(0);d(10,0,0,nullptr,48000);d(11,0,257);d(2,0,13);
 auto bank=camel::factoryBank();bank.programs[13].values[12]=.375f;auto raw=camel::encodeLegacy({bank.programs[13]});require(d(24,1,raw.size(),raw.data())==1,"Load single legacy chunk into selected program");require(d(3)==13&&e->getParameter(e,12)==.375f,"Recall selected program and unused slot");void* saved=nullptr;auto n=d(23,1,0,&saved);require(n==std::intptr_t(raw.size())&&std::memcmp(saved,raw.data(),raw.size())==0,"Legacy saved chunk byte identical");
 char name[24]{};require(d(29,13,0,name)&&std::string(name)=="Dream","Indexed program name");require(d(35)==1,"Effect category");
 d(12,0,1);std::vector<float> l(257),r(257),ol(257),or_(257),refL(257),refR(257);for(int i=0;i<257;++i){l[i]=float(std::sin(i*.05)*.6);r[i]=float(std::cos(i*.07)*.4);}float* in[]={l.data(),r.data()};float* out[]={ol.data(),or_.data()};e->processReplacing(e,in,out,257);camel::Dsp dsp;dsp.prepare(48000);dsp.restore(bank.programs[13].values);dsp.process(l.data(),r.data(),refL.data(),refR.data(),257);require(ol==refL&&or_==refR,"Legacy wrapper render matches core");
 d(44,0,1);e->processReplacing(e,in,out,257);require(ol==l&&or_==r,"Host bypass");d(1);
#if defined(_WIN32)
 FreeLibrary(handle);
#else
 dlclose(handle);
#endif
 std::cout<<"Legacy identity, parameter recall, chunk round trip and render checks passed\n";return 0;
 }catch(const std::exception& ex){std::cerr<<ex.what()<<'\n';return 1;}}
