#pragma once
#include "Dsp.h"
#include "State.h"
#include "EditorModel.h"
#include "public.sdk/source/vst/vstaudioeffect.h"
#include "public.sdk/source/vst/vsteditcontroller.h"
namespace camel {
inline const Steinberg::FUID processorUid(0xCC010101,0xF4D14E55,0x89A8C50A,0xE7B68302);
inline const Steinberg::FUID controllerUid(0xCC010102,0xF4D14E55,0x89A8C50A,0xE7B68302);
constexpr Steinberg::Vst::ParamID programId=0x100;
class Processor:public Steinberg::Vst::AudioEffect {
public:
 Processor();static Steinberg::FUnknown* create(void*){return static_cast<Steinberg::Vst::IAudioProcessor*>(new Processor);}
 Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown*)override;
 Steinberg::tresult PLUGIN_API setupProcessing(Steinberg::Vst::ProcessSetup&)override;
 Steinberg::tresult PLUGIN_API setActive(Steinberg::TBool)override;
 Steinberg::tresult PLUGIN_API setBusArrangements(Steinberg::Vst::SpeakerArrangement*,Steinberg::int32,Steinberg::Vst::SpeakerArrangement*,Steinberg::int32)override;
 Steinberg::tresult PLUGIN_API canProcessSampleSize(Steinberg::int32)override;
 Steinberg::tresult PLUGIN_API process(Steinberg::Vst::ProcessData&)override;
 Steinberg::tresult PLUGIN_API getState(Steinberg::IBStream*)override;
 Steinberg::tresult PLUGIN_API setState(Steinberg::IBStream*)override;
 Steinberg::tresult PLUGIN_API notify(Steinberg::Vst::IMessage*)override;
 Steinberg::uint32 PLUGIN_API getTailSamples()override{return Steinberg::Vst::kInfiniteTail;}
private:Dsp dsp;Bank bank=factoryBank();
};
class Controller:public Steinberg::Vst::EditController,public EditorModel {
public:
 static Steinberg::FUnknown* create(void*){return static_cast<Steinberg::Vst::IEditController*>(new Controller);}
 Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown*)override;
 Steinberg::tresult PLUGIN_API setComponentState(Steinberg::IBStream*)override;
 Steinberg::tresult PLUGIN_API setParamNormalized(Steinberg::Vst::ParamID,Steinberg::Vst::ParamValue)override;
 Steinberg::tresult PLUGIN_API getParamStringByValue(Steinberg::Vst::ParamID,Steinberg::Vst::ParamValue,Steinberg::Vst::String128)override;
 Steinberg::IPlugView* PLUGIN_API createView(Steinberg::FIDString)override;
 float value(int id)const override;void begin(int id)override;void change(int id,float v)override;void end(int id)override;
 int program()const override{return int(bank.current);}std::string programName(int i)const override;
 void selectProgram(int i)override;bool loadPreset(const std::uint8_t*,std::size_t,std::string&)override;
 std::string readout(int id)const override{return displayValue(id,value(id));}void randomize()override;
private:Bank bank=factoryBank();void updateParameters();
};
}
