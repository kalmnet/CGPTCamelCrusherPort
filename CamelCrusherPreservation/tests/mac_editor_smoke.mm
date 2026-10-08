#import <Cocoa/Cocoa.h>
extern "C" void* camel_test_parent_create(){@autoreleasepool{[NSApplication sharedApplication];NSView* parent=[[NSView alloc]initWithFrame:NSMakeRect(0,0,345,373)];return (__bridge_retained void*)parent;}}
extern "C" int camel_test_parent_children(void* p){return int(((__bridge NSView*)p).subviews.count);}
extern "C" int camel_test_editor_images(void* p){NSView* parent=(__bridge NSView*)p;if(parent.subviews.count!=1)return 0;id images=[parent.subviews[0] valueForKey:@"images"];return [images isKindOfClass:NSDictionary.class]?int([images count]):0;}
extern "C" void camel_test_parent_destroy(void* p){NSView* parent=(__bridge_transfer NSView*)p;(void)parent;}
