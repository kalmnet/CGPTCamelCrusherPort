#include "Dsp.h"
#include "State.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
static void require(bool v,const char* message){if(!v)throw std::runtime_error(message);}
int main(){try{
 std::ifstream originalFile(CAMEL_FACTORY_FIXTURE,std::ios::binary);std::vector<std::uint8_t> originalBytes((std::istreambuf_iterator<char>(originalFile)),{});std::vector<camel::Program> originalPrograms;require(camel::importFile(originalBytes.data(),originalBytes.size(),originalPrograms),"Original Camel FXB byteSize quirk");require(originalPrograms.size()==20,"Original 20-program bank");
 auto bank=camel::factoryBank();for(std::size_t i=0;i<20;++i)require(originalPrograms[i].name==bank.programs[i].name&&originalPrograms[i].values==bank.programs[i].values,"Factory bank exact float32 values");require(bank.programs[0].name=="Annihilate","Factory first program");require(bank.programs[19].name=="Turn it to 11","Factory last program");
 bank.current=13;bank.programs[13].values[12]=.37f;
 auto state=camel::encodeState(bank);camel::Bank decoded;
 require(camel::decodeState(state.data(),state.size(),decoded),"State decode");require(decoded.current==13,"Selected program recall");require(decoded.programs[13].values==bank.programs[13].values,"All 17 slots retained");
 auto raw=camel::encodeLegacy({bank.programs[13]});std::vector<camel::Program> legacy;
 require(camel::decodeLegacy(raw.data(),raw.size(),legacy),"Legacy decode");require(camel::encodeLegacy(legacy)==raw,"Legacy byte round trip");
 auto fxp=camel::exportFxp(bank.programs[13]);require(camel::importFile(fxp.data(),fxp.size(),legacy),"FXP import");require(legacy[0].values==bank.programs[13].values,"FXP parameters retained");
 for(std::size_t n=0;n<raw.size();++n){std::vector<camel::Program> out;require(!camel::decodeLegacy(raw.data(),n,out),"Reject truncated chunk");}
 auto bad=raw;bad[bad.size()-4]=0;bad[bad.size()-3]=0;bad[bad.size()-2]=0xc0;bad[bad.size()-1]=0x7f;require(!camel::decodeLegacy(bad.data(),bad.size(),legacy),"Reject NaN state");
 camel::Dsp dsp;auto p=camel::defaults();p[9]=0;dsp.restore(p);float inputL[]={-2,0,.5f,2},inputR[]={2,1,-1,-2},outL[4],outR[4];dsp.process(inputL,inputR,outL,outR,4);require(std::memcmp(inputL,outL,sizeof inputL)==0&&std::memcmp(inputR,outR,sizeof inputR)==0,"Master bypass is bit exact and unclipped");
 require(camel::cutoffHz(0)==80&&camel::cutoffHz(1)==16000,"Cutoff endpoints");require(std::fabs(camel::tubeSample(2,.5f)-.37499961256980896f)<1e-7f,"Tube beyond unity preserves polynomial fold");
 p=bank.programs[0].values;dsp.prepare(48000);dsp.restore(p);std::vector<float> l(50000),r(50000),ol(50000),or_(50000);for(std::size_t i=0;i<l.size();++i){l[i]=float(std::sin(double(i)*.05)*.8);r[i]=float(std::sin(double(i)*.037)*.6);}dsp.process(l.data(),r.data(),ol.data(),or_.data(),int(l.size()));for(float x:ol)require(std::isfinite(x)&&std::fabs(x)<=.9999f,"Finite bounded output");
 std::cout<<"Core state, malformed input, bypass, curve and render checks passed\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
