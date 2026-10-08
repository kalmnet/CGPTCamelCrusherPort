#import <Cocoa/Cocoa.h>
#include "Vst3.h"
#include "public.sdk/source/common/pluginview.h"
#include "pluginterfaces/vst/ivstplugview.h"
#include <cstring>
extern void* moduleHandle;
namespace camel {
class MacView:public Steinberg::CPluginView {
 Controller* controller;void* native=nullptr;
public:
 explicit MacView(Controller* c):controller(c){controller->addRef();rect={0,0,345,373};}
 ~MacView()override{removed();controller->release();}
 Steinberg::tresult PLUGIN_API isPlatformTypeSupported(Steinberg::FIDString type)override{return type&&std::strcmp(type,Steinberg::kPlatformTypeNSView)==0?Steinberg::kResultTrue:Steinberg::kResultFalse;}
 Steinberg::tresult PLUGIN_API attached(void* parent,Steinberg::FIDString type)override{if(isPlatformTypeSupported(type)!=Steinberg::kResultTrue||!parent||native)return Steinberg::kResultFalse;
  CFURLRef resourceURL=moduleHandle?CFBundleCopyResourcesDirectoryURL(static_cast<CFBundleRef>(moduleHandle)):nullptr;
  NSURL* url=CFBridgingRelease(resourceURL);NSString* path=url.path;
  if(!path)return Steinberg::kResultFalse;native=createNativeEditor(parent,controller,path.UTF8String);if(!native)return Steinberg::kResultFalse;systemWindow=parent;return Steinberg::kResultOk;
 }
 Steinberg::tresult PLUGIN_API removed()override{destroyNativeEditor(native);native=nullptr;systemWindow=nullptr;return Steinberg::kResultOk;}
 Steinberg::tresult PLUGIN_API checkSizeConstraint(Steinberg::ViewRect* r)override{if(!r)return Steinberg::kInvalidArgument;r->right=r->left+345;r->bottom=r->top+373;return Steinberg::kResultTrue;}
};
Steinberg::IPlugView* PLUGIN_API Controller::createView(Steinberg::FIDString name){return name&&std::strcmp(name,Steinberg::Vst::ViewType::kEditor)==0?new MacView(this):nullptr;}
}
