#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
namespace camel {
constexpr std::size_t parameterCount=17, programCount=20;
using Parameters=std::array<float,parameterCount>;
inline constexpr const char* parameterNames[]={"DistOn","DistMech","DistTube","MmFilterOn","MmFilterCutoff","MmFilterRes","CompressOn","CompressAmount","CompressMode","MasterOn","MasterMix","MasterVolume","Unused1","Unused2","Unused3","Unused4","Unused5"};
Parameters defaults();
float cutoffHz(float normalized);
float mechSample(float input,float amount);
float tubeSample(float input,float amount);
struct Ramp {
 float current=0,target=0,start=0; int elapsed=0,length=441;
 void set(float value); float advance(int samples);
 void reset(float value) {current=target=value;start=0;elapsed=0;}
};
struct Envelope {
 float sampleRate=44100,attack=0,release=0,value=0,up=0,down=0;
 void configure(float rate,float a,float r);
 float process(float input);
};
struct Compressor {
 float amount=0,mode=0,release=0,sampleRate=44100,gain=1,step=0;
 Envelope envelope;
 void prepare(float rate); void clear();
 void process(float* left,float* right,int count,float destination);
};
struct Biquad {
 float sampleRate=44100,cutoff=0,resonance=0,destCutoff=0,destResonance=0;
 bool dirty=true; float b0=0,b1=0,b2=0,a1=0,a2=0,y1=0,y2=0,x1=0,x2=0;
 void clear(); void setCutoff(float midiNote); void setResonance(float value);
 void update(); void process(float* data,int count);
};
struct Filter {
 Biquad left,right; Envelope limiterEnvelope;
 float rate=44100,cutoff=-1,resonance=-1,mix=-1,gain=1,step=0,maxNote=0;
 bool initialized=false;
 void prepare(float sampleRate);
 float note(float normalized,bool clampNyquist=false) const;
 void process(float* l,float* r,int count,float newCutoff,float newResonance);
};
class Dsp {
public:
 Dsp(); void prepare(float sampleRate); void resume();
 void setParameter(std::size_t id,float normalized);
 void restore(const Parameters& values);
 Parameters parameters() const {return values;}
 void process(const float* left,const float* right,float* outLeft,float* outRight,int frames);
private:
 Parameters values{}; std::array<Ramp,parameterCount> ramps{};
 Compressor compressor; Filter filter; float rate=44100,masterGain=0,masterMix=0;
};
}
