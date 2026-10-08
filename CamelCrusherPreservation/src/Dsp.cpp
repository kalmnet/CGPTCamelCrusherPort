#include "Dsp.h"
#include <algorithm>
#include <cmath>
#include <cstring>
namespace camel {
Parameters defaults(){Parameters p{};p[4]=0.5f;p[9]=p[10]=p[11]=1;return p;}
float cutoffHz(float p){
 if(p>=1)return 16000;
 if(p<=0)return 80;
 double d=std::log10(double(1.f-p))*-0.25;
 if(d>1.)return 16000;
 if(d<1.0000000116860974e-7)return 80;
 return float(d*15920.+80.);
}
float mechSample(float x,float a){
 float g=a*10.f+1.f; float slope=0.25f/(g-0.75f);x=x*g;
 if(x>0.75f)return (x-0.75f)*slope+0.75f;
 if(x<-.75f)return -((-.75f-x)*slope+.75f);
 return x;
}
float tubeSample(float x,float a){
 float g=a*4.f+1.f;x=x*g;
 if(x>.6000000238418579f){float v=(1.f-(x-.6000000238418579f)/(g-.6000000238418579f))*.7071070075035095f;return (.5f-v*v)*.7999999523162842f+.6000000238418579f;}
 if(x<-.6000000238418579f){float v=(1.f-(-.6000000238418579f-x)/(g-.6000000238418579f))*.7071070075035095f;return -((.5f-v*v)*.7999999523162842f+.6000000238418579f);}
 return x;
}
void Ramp::set(float v){if(v!=target){target=v;elapsed=0;start=current;}}
float Ramp::advance(int n){if(current!=target){elapsed+=n;float f=float(elapsed)/float(length);float inv=1.f-f;if(f>1){f=1;inv=0;}current=inv*start+f*target;}return current;}
void Envelope::configure(float r,float a,float rel){sampleRate=r;attack=a;release=rel;up=a!=0?1.f/(a*r):0;down=rel!=0?1.f/(rel*r):0;value=0;}
float Envelope::process(float x){
 float base=value-down,delta;
 if(x<=base){if(-base<=x)delta=0;else delta=-x-base;}else delta=x-base;
 float increment=up;if(delta<=up)increment=delta;
 value=std::max(0.f,increment+base);return value;
}
void Compressor::prepare(float r){sampleRate=r;envelope.configure(r,.029999999329447746f,.07999999821186066f);}
void Compressor::clear(){gain=1;step=0;envelope.value=0;}
void Compressor::process(float* l,float* r,int n,float destination){
 const float initial=amount,scale=1.f/(1.f-initial),oldRelease=release;
 release=.0002500000118743628f;
 const float kneeSpan=scale-.3100000023841858f;
 for(int i=0;i<n;++i){
  float a=l[i],b=r[i];float peak=std::max(std::fabs(a),std::fabs(b));
  if(mode!=0)peak=envelope.process(peak);else peak=std::fabs(peak);
  a=a*scale;b=b*scale;peak=peak*scale;
  if(peak>.3100000023841858f){float v=(1.f-(peak-.3100000023841858f)/kneeSpan)*.7071070075035095f;
   float next=((.5f-v*v)*1.3799999952316284f+.3100000023841858f)/peak;
   if(next<gain){gain=next;step=(1.f-next)/(oldRelease*sampleRate);}
  }
  if(gain<1.f){a=a*gain;b=b*gain;gain=gain+step;}
  l[i]=a;r[i]=b;amount=amount+(destination-initial)/float(n);
 }
 amount=destination;
}
void Biquad::clear(){cutoff=destCutoff;resonance=destResonance;dirty=true;y1=y2=x1=x2=0;}
void Biquad::setCutoff(float note){destCutoff=std::pow(2.f,(note-69.f)*.0833333358168602f)*440.f;dirty=true;}
void Biquad::setResonance(float v){destResonance=v;dirty=true;}
void Biquad::update(){
 const float q=destResonance*6.f+1.f;
 double omega=(double(destCutoff)/double(sampleRate))*6.283185307179586;
 double sine=std::sin(omega),cosine=std::cos(omega);
 double alpha=sine/(double(q)+double(q));double den=alpha+1.;double num=1.-cosine;
 b0=float(num*.5/den);b1=float(num/den);b2=b0;a1=float(cosine*-2./den);a2=float((1.-alpha)/den);
 auto flush=[](float& v){if(std::fpclassify(v)==FP_SUBNORMAL)v=0;};flush(b0);flush(b1);flush(b2);flush(a1);flush(a2);
 cutoff=destCutoff;resonance=destResonance;dirty=false;
}
void Biquad::process(float* data,int n){
 if(dirty)update();
 for(int i=0;i<n;++i){float x=data[i];float y=((x*b0+b1*x1+b2*x2)-y1*a1)-a2*y2;y2=y1;y1=y;x2=x1;x1=x;data[i]=y;}
 if(std::fpclassify(y1)==FP_SUBNORMAL||y1>1000.f||y1<-1000.f||y2>1000.f||y2<-1000.f)y1=y2=0;
}
void Filter::prepare(float r){rate=r;left.sampleRate=right.sampleRate=r;initialized=false;cutoff=resonance=mix=-1;gain=1;step=0;
 limiterEnvelope.configure(r,.007499999832361937f,.05000000074505806f);
 float v=(12.f/std::log(2.f))*std::log(r*.5f*.0022727272007614374f)+69.f;
 maxNote=v>=0?v-.009999999776482582f:-.009999999776482582f;
}
float Filter::note(float p,bool clamp)const{
 // Preserve the original float Hz -> float log -> float MIDI -> float pow round trip.
 float hz=cutoffHz(p)*.0022727272007614374f;
 float v=(12.f/std::log(2.f))*std::log(hz)+69.f;v=std::max(0.f,v);
 return clamp?std::min(maxNote,v):v;
}
void Filter::process(float* l,float* r,int n,float c,float res){
 float dryL[64],dryR[64];std::memcpy(dryL,l,n*sizeof(float));std::memcpy(dryR,r,n*sizeof(float));
 const float initialMix=mix;
 bool moving=(cutoff!=c)||!initialized;
 if(!initialized){
  left.setCutoff(note(cutoff,true));right.setCutoff(note(cutoff,true));
  left.setResonance(resonance);right.setResonance(resonance);left.clear();right.clear();gain=1;step=0;initialized=true;
 }
 if(resonance!=res){resonance=res;left.setResonance(res);right.setResonance(res);left.setCutoff(note(cutoff));right.setCutoff(note(cutoff));}
 float dc=moving?(c-cutoff)/float(n):0;
 for(int offset=0;offset<n;offset+=16){int size=std::min(16,n-offset);left.process(l+offset,size);right.process(r+offset,size);
  if(moving){cutoff=cutoff+float(size)*dc;left.setCutoff(note(cutoff));right.setCutoff(note(cutoff));}
 }
 cutoff=c;resonance=res;
 for(int i=0;i<n;++i){float peak=std::max(std::fabs(l[i]),std::fabs(r[i]));peak=limiterEnvelope.process(peak);
  if(peak>1){float g=1.f/peak;if(g<gain){gain=g;step=(1.f-g)/(7.5f*rate);}}
  if(gain<1){l[i]=gain*l[i];r[i]=r[i]*gain;gain=gain+step;}
 }
 for(int i=0;i<n;++i){l[i]=(1.f-mix)*dryL[i]+mix*l[i];r[i]=(1.f-mix)*dryR[i]+mix*r[i];mix=(1.f-initialMix)/float(n)+mix;}
 mix=1;
}
Dsp::Dsp(){prepare(44100);restore(defaults());}
void Dsp::prepare(float r){rate=r;for(auto& p:ramps)p.length=std::max(1,int(r*.01f));filter.prepare(r);compressor.prepare(r);}
void Dsp::resume(){for(std::size_t i=0;i<parameterCount;++i)ramps[i].reset(values[i]*(i==7?.9900000095367432f:1.f));compressor.clear();}
void Dsp::setParameter(std::size_t id,float v){if(id>=parameterCount||!std::isfinite(v))return;v=std::clamp(v,0.f,1.f);values[id]=v;ramps[id].set(v*(id==7?.9900000095367432f:1.f));if(id==8)compressor.mode=v<.5f?.009999999776482582f:0;}
void Dsp::restore(const Parameters& p){for(std::size_t i=0;i<parameterCount;++i)setParameter(i,p[i]);resume();}
void Dsp::process(const float* inL,const float* inR,float* outL,float* outR,int frames){
 if(frames<=0)return;
 // MasterOn is checked by the original wrapper, before CamelCrusher::process.
 if(values[9]<.5f){std::memmove(outL,inL,frames*sizeof(float));std::memmove(outR,inR,frames*sizeof(float));return;}
 bool mech=false,tube=false;
 if(ramps[0].advance(frames)>.5f){mech=ramps[1].advance(frames)>0;tube=ramps[2].advance(frames)>0;}
 const bool filtering=ramps[3].advance(frames)>.5f,compressing=ramps[6].advance(frames)>.5f;
 for(int offset=0;offset<frames;offset+=64){int n=std::min(64,frames-offset);float l[64],r[64],dryL[64],dryR[64];
  std::memcpy(dryL,inL+offset,n*sizeof(float));std::memcpy(dryR,inR+offset,n*sizeof(float));std::memcpy(l,dryL,n*sizeof(float));std::memcpy(r,dryR,n*sizeof(float));
  if(mech){float a=ramps[1].advance(n);for(int i=0;i<n;++i){l[i]=mechSample(l[i],a);r[i]=mechSample(r[i],a);}}
  if(filtering){float c=ramps[4].advance(n),res=ramps[5].advance(n);filter.process(l,r,n,c,res);}
  if(tube){float a=ramps[2].advance(n);for(int i=0;i<n;++i){l[i]=tubeSample(l[i],a);r[i]=tubeSample(r[i],a);}}
  if(compressing)compressor.process(l,r,n,std::min(ramps[7].advance(n),.9900000095367432f));
  float mixDest=ramps[10].advance(n),volume=ramps[11].advance(n);float destGain=float(std::pow(double(volume),2.736999988555908));
  float gainStart=masterGain,mixStart=masterMix,inv=1.f/float(n);
  for(int i=0;i<n;++i){float a=(masterMix*l[i]+(1.f-masterMix)*dryL[i])*masterGain;
   float b=(masterMix*r[i]+(1.f-masterMix)*dryR[i])*masterGain;
   masterGain=masterGain+(destGain-gainStart)*inv;masterMix=(mixDest-mixStart)*inv+masterMix;
   outL[offset+i]=std::clamp(a,-.9998999834060669f,.9998999834060669f);outR[offset+i]=std::clamp(b,-.9998999834060669f,.9998999834060669f);
  }
 }
}
}
