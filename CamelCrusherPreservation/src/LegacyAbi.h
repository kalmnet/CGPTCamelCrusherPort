#pragma once
#include <cstdint>
#include <cstddef>
// Independent ABI declaration. No VST2 SDK headers or source are included.
namespace camel::legacy {
struct Effect;
using Dispatch=std::intptr_t(*)(Effect*,std::int32_t,std::int32_t,std::intptr_t,void*,float);
using Audio=void(*)(Effect*,float**,float**,std::int32_t);
using Set=void(*)(Effect*,std::int32_t,float);using Get=float(*)(Effect*,std::int32_t);
struct Effect {
 std::int32_t magic;Dispatch dispatcher;Audio process;Set setParameter;Get getParameter;
 std::int32_t numPrograms,numParams,numInputs,numOutputs,flags;
 void* reserved1;void* reserved2;std::int32_t initialDelay,realQualities,offQualities;float ioRatio;
 void* object;void* user;std::int32_t uniqueId,version;Audio processReplacing;
 void(*processDoubleReplacing)(Effect*,double**,double**,std::int32_t);char future[56];
};
static_assert(sizeof(void*)!=8||offsetof(Effect,processReplacing)==120,"64-bit legacy ABI alignment");
static_assert(sizeof(void*)!=8||sizeof(Effect)==192,"64-bit legacy ABI size");
struct Rect {std::int16_t top,left,bottom,right;};
}
