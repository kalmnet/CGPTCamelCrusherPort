#include "Dsp.h"
extern "C" {
void* camel_create(){return new camel::Dsp;}
void camel_destroy(void* p){delete static_cast<camel::Dsp*>(p);}
void camel_prepare(void* p,float rate){static_cast<camel::Dsp*>(p)->prepare(rate);}
void camel_restore(void* p,const float* v){camel::Parameters a;for(int i=0;i<17;++i)a[i]=v[i];static_cast<camel::Dsp*>(p)->restore(a);}
void camel_set(void* p,int id,float v){static_cast<camel::Dsp*>(p)->setParameter(id,v);}
void camel_process(void* p,const float* l,const float* r,float* ol,float* or_,int n){static_cast<camel::Dsp*>(p)->process(l,r,ol,or_,n);}
float camel_mech(float x,float a){return camel::mechSample(x,a);}
float camel_tube(float x,float a){return camel::tubeSample(x,a);}
}
extern "C" {
void* camel_compressor_create(float rate){auto* p=new camel::Compressor;p->prepare(rate);return p;}
void camel_compressor_process(void* p,float* l,float* r,int n,float dest){static_cast<camel::Compressor*>(p)->process(l,r,n,dest);}
}
