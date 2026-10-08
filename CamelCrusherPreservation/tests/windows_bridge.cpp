#include "Dsp.h"
#include <cstdint>
// Linux x86-64 research bridge to selected Microsoft-x64-ABI routines.
#define MSABI __attribute__((ms_abi))
extern "C" {
void windows_distortion(void* f,void* obj,float* l,float* r,int n,float p){reinterpret_cast<void(MSABI*)(void*,float*,float*,int,float)>(f)(obj,l,r,n,p);}
void windows_construct(void* f,void* obj){reinterpret_cast<void(MSABI*)(void*)>(f)(obj);}
void windows_rate(void* f,void* obj,float p){reinterpret_cast<void(MSABI*)(void*,float)>(f)(obj,p);}
void windows_compress(void* f,void* obj,float* l,float* r,int n,float p){reinterpret_cast<void(MSABI*)(void*,float*,float*,int,float,float)>(f)(obj,l,r,n,p,.00025f);}
float windows_read_float(void* f,void* obj){return reinterpret_cast<float(MSABI*)(void*)>(f)(obj);}
void windows_write_float(void* f,void* obj,float p){reinterpret_cast<void(MSABI*)(void*,float)>(f)(obj,p);}
std::uint32_t windows_read_word(void* f,void* obj){return reinterpret_cast<std::uint32_t(MSABI*)(void*)>(f)(obj);}
void windows_write_word(void* f,void* obj,std::uint32_t p){reinterpret_cast<void(MSABI*)(void*,std::uint32_t)>(f)(obj,p);}
float port_mech(float x,float p){return camel::mechSample(x,p);}float port_tube(float x,float p){return camel::tubeSample(x,p);}
void* port_compressor(float rate,int follower){auto* p=new camel::Compressor;p->prepare(rate);p->clear();p->mode=follower?.01f:0;return p;}
void port_compress(void* p,float* l,float* r,int n,float v){static_cast<camel::Compressor*>(p)->process(l,r,n,v);}
void port_destroy(void* p){delete static_cast<camel::Compressor*>(p);}
}
