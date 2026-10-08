#include "Dsp.h"
#include "State.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
// Float32 little-endian stereo, interleaved. Block size is part of the reference experiment.
int main(int argc,char** argv){if(argc!=7){std::cerr<<"Usage: camel_render input.f32 output.f32 rate block state-file program-index\n";return 2;}
 float rate=std::strtof(argv[3],nullptr);int block=std::atoi(argv[4]),index=std::atoi(argv[6]);if(rate<=0||block<1||block>1048576||index<0||index>=20)return 2;
 std::ifstream stateFile(argv[5],std::ios::binary);std::vector<std::uint8_t> state((std::istreambuf_iterator<char>(stateFile)),{});camel::Bank bank=camel::factoryBank();bank.current=std::uint32_t(index);std::string error;if(!camel::decodeState(state.data(),state.size(),bank,&error)){std::cerr<<error<<'\n';return 1;}
 camel::Dsp dsp;dsp.prepare(rate);dsp.restore(bank.programs[bank.current].values);std::ifstream input(argv[1],std::ios::binary);std::ofstream output(argv[2],std::ios::binary);if(!input||!output)return 1;
 std::vector<float> interleaved(std::size_t(block)*2),l(block),r(block),ol(block),or_(block);
 while(input){input.read(reinterpret_cast<char*>(interleaved.data()),std::streamsize(block)*8);auto bytes=input.gcount();if(bytes%8){std::cerr<<"Incomplete stereo float frame\n";return 1;}int n=int(bytes/8);if(!n)break;for(int i=0;i<n;++i){l[i]=interleaved[i*2];r[i]=interleaved[i*2+1];}dsp.process(l.data(),r.data(),ol.data(),or_.data(),n);for(int i=0;i<n;++i){interleaved[i*2]=ol[i];interleaved[i*2+1]=or_[i];}output.write(reinterpret_cast<const char*>(interleaved.data()),std::streamsize(n)*8);}
 return output?0:1;
}
