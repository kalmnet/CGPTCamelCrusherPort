#pragma once
#include <cstdint>
#include <string>
namespace camel {
struct EditorModel {
 virtual ~EditorModel()=default;
 virtual float value(int id)const=0;
 virtual void begin(int id)=0;virtual void change(int id,float value)=0;virtual void end(int id)=0;
 virtual int program()const=0;virtual std::string programName(int index)const=0;virtual void selectProgram(int index)=0;
 virtual bool loadPreset(const std::uint8_t* data,std::size_t size,std::string& error)=0;
 virtual std::string readout(int id)const=0;
 virtual void randomize()=0;
};
void* createNativeEditor(void* parent,EditorModel* model,const char* resourceDirectory);
void destroyNativeEditor(void* editor);
}
