#pragma once
#include "Dsp.h"
#include <string>
#include <vector>
namespace camel {
struct Program {float version=1;std::string name="Init";Parameters values=defaults();};
struct Bank {std::array<Program,programCount> programs{};std::uint32_t current=0;};
Bank factoryBank();
// All readers validate completely before mutating the destination.
bool decodeLegacy(const std::uint8_t* data,std::size_t size,std::vector<Program>& result,std::string* error=nullptr);
std::vector<std::uint8_t> encodeLegacy(const std::vector<Program>& programs);
bool decodeState(const std::uint8_t* data,std::size_t size,Bank& destination,std::string* error=nullptr);
std::vector<std::uint8_t> encodeState(const Bank& bank);
bool importFile(const std::uint8_t* data,std::size_t size,std::vector<Program>& result,std::string* error=nullptr);
std::vector<std::uint8_t> exportFxp(const Program& program);
std::string displayValue(std::size_t id,float normalized);
}
