#import <Cocoa/Cocoa.h>
#include "EditorModel.h"
#include "Dsp.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>
#include <memory>
#ifndef CAMEL_EDITOR_CLASS
#define CAMEL_EDITOR_CLASS CCPGenericEditorView
#endif
#define CCPView CAMEL_EDITOR_CLASS
@interface CCPView:NSView {
@public camel::EditorModel* model;
 NSDictionary<NSString*,NSImage*>* images;
 NSTimer* timer;
 int dragged;CGFloat anchorY;float anchorValue;NSString* status;NSDate* statusUntil;
}
- (id)initWithModel:(camel::EditorModel*)m resources:(NSString*)resources;
- (void)tick:(NSTimer*)sender;
@end
@implementation CCPView
- (id)initWithModel:(camel::EditorModel*)m resources:(NSString*)resources {
 self=[super initWithFrame:NSMakeRect(0,0,345,373)];if(self){model=m;dragged=-1;
  NSMutableDictionary* dict=[NSMutableDictionary dictionary];
  for(NSString* name in @[@"Background",@"Knob",@"OnButton",@"PhatButton",@"SelectorPreset",@"ButtonRandom",@"FontDisplay",@"FontVersion"]){NSImage* im=[[NSImage alloc]initWithContentsOfFile:[resources stringByAppendingPathComponent:[name stringByAppendingString:@".png"]]];if(im)dict[name]=im;}
  images=dict;
 }
 return self;
}
- (void)viewDidMoveToSuperview { [timer invalidate];timer=nil;if(self.superview)timer=[NSTimer scheduledTimerWithTimeInterval:1./30 target:self selector:@selector(tick:) userInfo:nil repeats:YES];}
- (void)dealloc {[timer invalidate];}
- (BOOL)isFlipped{return YES;}
- (BOOL)acceptsFirstResponder{return YES;}
- (void)tick:(NSTimer*)sender{[self setNeedsDisplay:YES];}
- (void)sprite:(NSString*)name frame:(int)frame height:(CGFloat)height rect:(NSRect)rect {
 NSImage* im=images[name];if(!im)return;NSRect source=NSMakeRect(0,im.size.height-(frame+1)*height,im.size.width,height);
 [im drawInRect:rect fromRect:source operation:NSCompositingOperationSourceOver fraction:1 respectFlipped:YES hints:@{NSImageHintInterpolation:@(NSImageInterpolationNone)}];
}
- (void)bitmapText:(NSString*)text at:(NSPoint)point {
 // Widths are recovered from SkinParameters.txt; glyph order is exact.
 static const char* chars="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz%'()*+,-./:?";
 static const int widths[]={6,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,6,6,5,7,7,6,5,6,6,6,5,6,7,7,7,5,5,6,6,6,6,6,4,6,6,3,4,6,3,7,6,6,6,6,4,6,4,6,7,7,7,6,6,7,3,4,4,7,5,3,5,3,5,3,5};
 NSImage* im=images[@"FontDisplay"];
 for(NSUInteger k=0;k<text.length;++k){unichar ch=[text characterAtIndex:k];const char* found=ch<128?strchr(chars,char(ch)):nullptr;
  if(!found){point.x+=4;continue;}int index=int(found-chars),x=0;for(int j=0;j<index;++j)x+=widths[j];int width=widths[index];
  [im drawInRect:NSMakeRect(point.x,point.y,width,12) fromRect:NSMakeRect(x,0,width,12) operation:NSCompositingOperationSourceOver fraction:1 respectFlipped:YES hints:@{NSImageHintInterpolation:@(NSImageInterpolationNone)}];point.x+=width;
 }
}
- (void)drawRect:(NSRect)dirty {
 NSImage* background=images[@"Background"];
 if(background)[background drawInRect:self.bounds fromRect:NSZeroRect operation:NSCompositingOperationSourceOver fraction:1 respectFlipped:YES hints:nil];
 else {[[NSColor darkGrayColor]setFill];NSRectFill(self.bounds);[@"Skin resources missing" drawAtPoint:NSMakePoint(20,20) withAttributes:@{NSForegroundColorAttributeName:NSColor.whiteColor}];}
 const int ids[]={2,1,4,5,7,11,10};const CGFloat xs[]={63,123,222,282,63,222,282};const CGFloat ys[]={214,214,214,214,319,319,319};
 for(int i=0;i<7;++i)[self sprite:@"Knob" frame:int(std::round(std::clamp(model->value(ids[i]),0.f,1.f)*54)) height:48 rect:NSMakeRect(xs[i]-24,ys[i]-24,48,48)];
 const int switches[]={0,3,6,9};const CGFloat sx[]={39,199,39,199};const CGFloat sy[]={175,175,280,280};
 for(int i=0;i<4;++i)[self sprite:@"OnButton" frame:model->value(switches[i])>=.5f?1:0 height:24 rect:NSMakeRect(sx[i]-16,sy[i]-12,32,24)];
 [self sprite:@"PhatButton" frame:model->value(8)>=.5f?1:0 height:20 rect:NSMakeRect(112,309,22,20)];
 [self sprite:@"SelectorPreset" frame:0 height:30 rect:NSMakeRect(23,113,196,30)];
 [self sprite:@"ButtonRandom" frame:0 height:28 rect:NSMakeRect(228.5,113,93,28)];
 NSString* name=[NSString stringWithUTF8String:model->programName(model->program()).c_str()];
 if(statusUntil&&[statusUntil timeIntervalSinceNow]>0)name=status;
 [self bitmapText:name at:NSMakePoint(51,121)];
 [@"v1.01" drawAtPoint:NSMakePoint(202,66) withAttributes:@{NSFontAttributeName:[NSFont systemFontOfSize:9],NSForegroundColorAttributeName:NSColor.whiteColor}];
}
- (void)showValue:(int)id {status=[NSString stringWithUTF8String:model->readout(id).c_str()];statusUntil=[NSDate dateWithTimeIntervalSinceNow:3];}
- (void)mouseDown:(NSEvent*)event {
 NSPoint p=[self convertPoint:event.locationInWindow fromView:nil];
 const int ids[]={2,1,4,5,7,11,10};const CGFloat xs[]={63,123,222,282,63,222,282};const CGFloat ys[]={214,214,214,214,319,319,319};
 for(int i=0;i<7;++i)if(NSPointInRect(p,NSMakeRect(xs[i]-24,ys[i]-24,48,48))){dragged=ids[i];anchorY=p.y;anchorValue=model->value(dragged);model->begin(dragged);[self showValue:dragged];return;}
 const int switches[]={0,3,6,9,8};const CGFloat sx[]={39,199,39,199,123};const CGFloat sy[]={175,175,280,280,319};
 for(int i=0;i<5;++i)if(NSPointInRect(p,NSMakeRect(sx[i]-16,sy[i]-12,32,24))){int id=switches[i];model->begin(id);model->change(id,model->value(id)>=.5f?0:1);model->end(id);[self showValue:id];return;}
 if(NSPointInRect(p,NSMakeRect(228,113,94,28))){model->randomize();return;}
 if(NSPointInRect(p,NSMakeRect(23,113,196,30))){NSMenu* menu=[[NSMenu alloc]initWithTitle:@"Presets"];
  for(int i=0;i<20;++i){NSMenuItem* item=[[NSMenuItem alloc]initWithTitle:[NSString stringWithUTF8String:model->programName(i).c_str()] action:@selector(preset:) keyEquivalent:@""];item.tag=i;item.target=self;item.state=model->program()==i?NSControlStateValueOn:NSControlStateValueOff;[menu addItem:item];}
  [menu addItem:NSMenuItem.separatorItem];NSMenuItem* load=[[NSMenuItem alloc]initWithTitle:@"Import FXP…" action:@selector(load:) keyEquivalent:@""];load.target=self;[menu addItem:load];[menu popUpMenuPositioningItem:nil atLocation:p inView:self];
 }
}
- (void)mouseDragged:(NSEvent*)event {if(dragged<0)return;NSPoint p=[self convertPoint:event.locationInWindow fromView:nil];float scale=(event.modifierFlags&NSEventModifierFlagShift)?1000.f:150.f;model->change(dragged,std::clamp(anchorValue+float(anchorY-p.y)/scale,0.f,1.f));[self showValue:dragged];}
- (void)mouseUp:(NSEvent*)event {if(dragged>=0){model->end(dragged);dragged=-1;}}
- (void)preset:(NSMenuItem*)item {model->selectProgram(int(item.tag));statusUntil=nil;}
- (void)load:(id)sender {
 NSOpenPanel* panel=[NSOpenPanel openPanel];panel.allowedFileTypes=@[@"fxp"];panel.allowsMultipleSelection=NO;
 __weak CCPView* weakSelf=self;
 [panel beginSheetModalForWindow:self.window completionHandler:^(NSModalResponse response){CCPView* view=weakSelf;if(response!=NSModalResponseOK||!view||!view.superview)return;NSData* data=[NSData dataWithContentsOfURL:panel.URL];std::string error;
  if(!data||!view->model->loadPreset(static_cast<const std::uint8_t*>(data.bytes),data.length,error)){NSAlert* alert=[[NSAlert alloc]init];alert.messageText=@"Could not import preset";alert.informativeText=[NSString stringWithUTF8String:error.c_str()];[alert beginSheetModalForWindow:view.window completionHandler:nil];}
 }];
}
@end
namespace camel {
void* createNativeEditor(void* parent,EditorModel* model,const char* path){if(!parent||!model)return nullptr;NSView* host=(__bridge NSView*)parent;CCPView* view=[[CCPView alloc]initWithModel:model resources:[NSString stringWithUTF8String:path]];[host addSubview:view];return (__bridge_retained void*)view;}
void destroyNativeEditor(void* pointer){if(!pointer)return;CCPView* view=(__bridge_transfer CCPView*)pointer;[view->timer invalidate];view->timer=nil;if(view->dragged>=0)view->model->end(view->dragged);[view removeFromSuperview];}
}
