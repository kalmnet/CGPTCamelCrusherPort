#include "State.h"
#include "Presets.generated.h"
#include <cmath>
#include <cstring>
#include <cstdio>
namespace camel {
namespace {
struct Reader {
 const std::uint8_t* data;std::size_t size,pos=0;
 bool u32(std::uint32_t& v,bool big=false){if(size-pos<4)return false;v=0;for(int i=0;i<4;++i)v|=std::uint32_t(data[pos+i])<<(big?(3-i)*8:i*8);pos+=4;return true;}
 bool f32(float& v,bool big=false){std::uint32_t n;if(!u32(n,big))return false;std::memcpy(&v,&n,4);return std::isfinite(v);}
 bool name(std::string& v){v.clear();while(pos<size&&data[pos]!=0){if(v.size()>=63)return false;v+=char(data[pos++]);}if(pos==size)return false;++pos;return true;}
};
void u32(std::vector<std::uint8_t>& out,std::uint32_t v,bool big=false){for(int i=0;i<4;++i)out.push_back(std::uint8_t(v>>(big?(3-i)*8:i*8)));}
void f32(std::vector<std::uint8_t>& out,float v){std::uint32_t n;std::memcpy(&n,&v,4);u32(out,n);}
bool fail(std::string* e,const char* s){if(e)*e=s;return false;}
}
Bank factoryBank(){Bank b;for(std::size_t i=0;i<programCount;++i){b.programs[i].name=factoryNames[i];b.programs[i].values=factoryValues[i];}return b;}
bool decodeLegacy(const std::uint8_t* data,std::size_t size,std::vector<Program>& result,std::string* error){
 if(!data||size==0||size>1024*1024)return fail(error,"Invalid chunk length");
 Reader r{data,size};std::vector<Program> tmp;
 while(r.pos<size){if(tmp.size()>=programCount)return fail(error,"Too many programs");Program p;std::uint32_t count;
  if(!r.f32(p.version)||p.version<0||!r.name(p.name)||!r.u32(count)||count>parameterCount)return fail(error,"Invalid program header");
  // CAProgram::load clears all slots before reading, rather than applying defaults.
  p.values.fill(0);
  for(std::uint32_t i=0;i<count;++i)if(!r.f32(p.values[i])||p.values[i]<0||p.values[i]>1)return fail(error,"Invalid parameter value");
  tmp.push_back(std::move(p));
 }
 if(tmp.empty())return fail(error,"Empty chunk");result=std::move(tmp);return true;
}
std::vector<std::uint8_t> encodeLegacy(const std::vector<Program>& programs){std::vector<std::uint8_t> b;for(const auto& p:programs){f32(b,p.version);b.insert(b.end(),p.name.begin(),p.name.end());b.push_back(0);u32(b,parameterCount);for(float v:p.values)f32(b,v);}return b;}
bool decodeState(const std::uint8_t* data,std::size_t size,Bank& destination,std::string* error){
 if(data&&size>=8&&std::memcmp(data,"CCP1",4)==0){Reader r{data,size,4};std::uint32_t index;if(!r.u32(index)||index>=programCount)return fail(error,"Invalid current program");std::vector<Program> p;
  if(!decodeLegacy(data+8,size-8,p,error)||p.size()!=programCount)return fail(error,"State needs 20 programs");Bank b;for(std::size_t i=0;i<programCount;++i)b.programs[i]=p[i];b.current=index;destination=std::move(b);return true;
 }
 std::vector<Program> p;if(!importFile(data,size,p,error))return false;
 Bank b=destination;
 if(p.size()==1)b.programs[b.current]=p[0];
 else if(p.size()==programCount)for(std::size_t i=0;i<programCount;++i)b.programs[i]=p[i];
 else return fail(error,"Expected one preset or a 20-program bank");destination=std::move(b);return true;
}
std::vector<std::uint8_t> encodeState(const Bank& b){std::vector<std::uint8_t> out{'C','C','P','1'};u32(out,b.current);std::vector<Program> p(b.programs.begin(),b.programs.end());auto chunk=encodeLegacy(p);out.insert(out.end(),chunk.begin(),chunk.end());return out;}
bool importFile(const std::uint8_t* data,std::size_t size,std::vector<Program>& result,std::string* error){
 if(!data||size==0)return fail(error,"Empty file");
 if(size>=4&&std::memcmp(data,"CcnK",4)==0){
  if(size<28)return fail(error,"Truncated FXP/FXB");Reader r{data,size,4};std::uint32_t bytes,magic,ver,id,fxver,n;
  if(!r.u32(bytes,true)||!r.u32(magic,true)||!r.u32(ver,true)||!r.u32(id,true)||!r.u32(fxver,true)||!r.u32(n,true)||id!=0x43614372||(bytes!=size-8&&bytes!=size))return fail(error,"Wrong FXP/FXB size or plugin ID");
  if(magic==0x46424368||magic==0x46504368){std::size_t offset=magic==0x46424368?156:56;if(size<offset+4)return fail(error,"Truncated chunk header");r.pos=offset;std::uint32_t cs;if(!r.u32(cs,true)||cs!=size-r.pos)return fail(error,"Invalid chunk size");
   std::vector<Program> decoded;if(!decodeLegacy(data+r.pos,cs,decoded,error))return false;
   if(magic==0x46424368&&decoded.size()!=n)return fail(error,"Bank count mismatch");
   if(magic==0x46504368&&decoded.size()!=1)return fail(error,"Preset count mismatch");result=std::move(decoded);return true;
  }
  if(magic==0x4678436b){if(size<56||n>parameterCount||size!=56+n*4)return fail(error,"Invalid parameter FXP");Program p;p.values.fill(0);std::size_t len=0;while(len<28&&data[28+len])++len;p.name.assign(reinterpret_cast<const char*>(data+28),len);r.pos=56;
   for(std::uint32_t i=0;i<n;++i)if(!r.f32(p.values[i],true)||p.values[i]<0||p.values[i]>1)return fail(error,"Invalid FXP parameter");result={p};return true;
  }
  return fail(error,"Unsupported FXP/FXB type");
 }
 return decodeLegacy(data,size,result,error);
}
std::vector<std::uint8_t> exportFxp(const Program& p){auto raw=encodeLegacy({p});std::vector<std::uint8_t> out{'C','c','n','K'};u32(out,std::uint32_t(52+raw.size()),true);u32(out,0x46504368,true);u32(out,1,true);u32(out,0x43614372,true);u32(out,1,true);u32(out,parameterCount,true);for(std::size_t i=0;i<28;++i)out.push_back(i<p.name.size()?std::uint8_t(p.name[i]):0);u32(out,std::uint32_t(raw.size()),true);out.insert(out.end(),raw.begin(),raw.end());return out;}
std::string displayValue(std::size_t id,float v){char text[64];switch(id){case 4:std::snprintf(text,sizeof text,"%d Hz",int(cutoffHz(v)));break;case 7:std::snprintf(text,sizeof text,"%.0f dB",-20.*std::log10(double(1.f-v*.99f)));break;case 11:if(v<.0001f)return "-inf dB";std::snprintf(text,sizeof text,"%.0f dB",20.*std::log10(std::pow(double(v),2.736999988555908)));break;case 0:case 3:case 6:case 8:case 9:return v>=.5f?"On":"Off";default:std::snprintf(text,sizeof text,"%d %%",int(v*100.f));}return text;}
}
