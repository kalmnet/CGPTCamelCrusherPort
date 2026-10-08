#import <Cocoa/Cocoa.h>
#include <dlfcn.h>
#include <string>
namespace camel {
std::string legacyResourceDirectory(){Dl_info info{};if(!dladdr(reinterpret_cast<void*>(&legacyResourceDirectory),&info)||!info.dli_fname)return "";NSString* executable=[NSString stringWithUTF8String:info.dli_fname];NSString* contents=[[executable stringByDeletingLastPathComponent]stringByDeletingLastPathComponent];return [[contents stringByAppendingPathComponent:@"Resources"]UTF8String];}
}
