#!/usr/bin/env python3
"""Selected Windows DLL DSP experiment, not a Windows plugin host. Linux x86-64 only."""
import argparse,ctypes as C,hashlib,json,mmap,pathlib,platform,struct
import numpy as np
KNOWN='4406af857e7d80fb8b8aed7aab3714b48af5b49f9e97b686d8ada2b4fb8bccad' # populated from the exact user-supplied DLL hash

def main():
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--binary',type=pathlib.Path,required=True);p.add_argument('--bridge',type=pathlib.Path,required=True);p.add_argument('--execute-original',action='store_true');p.add_argument('--report',type=pathlib.Path);a=p.parse_args()
 if not a.execute_original:p.error('Original selected machine code will run; explicit --execute-original is required')
 if platform.system()!='Linux' or platform.machine()!='x86_64':p.error('Requires Linux x86-64')
 data=a.binary.read_bytes();digest=hashlib.sha256(data).hexdigest()
 if digest!=KNOWN:p.error('Unknown DLL hash')
 pe=struct.unpack_from('<I',data,0x3c)[0];n=struct.unpack_from('<H',data,pe+6)[0];opt=pe+24;size=struct.unpack_from('<I',data,opt+56)[0];sections=opt+struct.unpack_from('<H',data,pe+20)[0]
 mapped=mmap.mmap(-1,size,prot=mmap.PROT_READ|mmap.PROT_WRITE|mmap.PROT_EXEC)
 for i in range(n):
  o=sections+i*40;vs,rva,rs,raw=struct.unpack_from('<IIII',data,o+8);mapped[rva:rva+rs]=data[raw:raw+rs]
 base=C.addressof(C.c_char.from_buffer(mapped));lib=C.CDLL(str(a.bridge.resolve()));fp=C.POINTER(C.c_float);ptr=C.c_void_p
 lib.windows_distortion.argtypes=[ptr,ptr,fp,fp,C.c_int,C.c_float];lib.windows_construct.argtypes=[ptr,ptr];lib.windows_rate.argtypes=[ptr,ptr,C.c_float];lib.windows_compress.argtypes=[ptr,ptr,fp,fp,C.c_int,C.c_float]
 for name in ['port_mech','port_tube']:f=getattr(lib,name);f.argtypes=[C.c_float,C.c_float];f.restype=C.c_float
 lib.port_compressor.argtypes=[C.c_float,C.c_int];lib.port_compressor.restype=ptr;lib.port_compress.argtypes=[ptr,fp,fp,C.c_int,C.c_float];lib.port_destroy.argtypes=[ptr]
 rng=np.random.default_rng(19388);results={}
 lib.windows_read_float.argtypes=[ptr,ptr];lib.windows_read_float.restype=C.c_float;lib.windows_write_float.argtypes=[ptr,ptr,C.c_float];lib.windows_read_word.argtypes=[ptr,ptr];lib.windows_read_word.restype=C.c_uint32;lib.windows_write_word.argtypes=[ptr,ptr,C.c_uint32]
 presets=json.loads((pathlib.Path(__file__).resolve().parents[1]/'docs/factory-presets.json').read_text());words=0
 for preset in presets:
  values=[1.]+preset['parameters'];expected=struct.pack('<18f',*values)+struct.pack('<I',17);buffer=C.create_string_buffer(len(expected));obj=C.create_string_buffer(32);struct.pack_into('<Q',obj,16,C.addressof(buffer));addr=C.addressof(obj)
  for v in values:lib.windows_write_float(base+0xc510,addr,v)
  lib.windows_write_word(base+0xc5e0,addr,17)
  if buffer.raw!=expected:raise AssertionError('Original Windows primitive byte encoding differs')
  struct.pack_into('<i',obj,8,0)
  for v in values:
   if struct.pack('<f',lib.windows_read_float(base+0xc570,addr))!=struct.pack('<f',v):raise AssertionError('Float read mismatch')
  if lib.windows_read_word(base+0xc640,addr)!=17:raise AssertionError('Integer read mismatch')
  words+=len(values)+1
 results['state_primitives']={'factory_programs':20,'words_round_tripped':words,'max_absolute_error':0.,'byte_identical':True}
 for name,rva in [('mech',0x1c680),('tube',0x1c6c0)]:
  worst=0.;samples=0
  for amount in [0.,.01,.1,.25,.5,.75,.99,1.]:
   l=rng.uniform(-2,2,4096).astype('f');r=rng.uniform(-2,2,4096).astype('f');func=getattr(lib,'port_'+name);ref=[np.array([func(float(x),amount) for x in v],dtype='f') for v in [l,r]];obj=C.create_string_buffer(12)
   lib.windows_distortion(base+rva,C.addressof(obj),l.ctypes.data_as(fp),r.ctypes.data_as(fp),len(l),amount);worst=max(worst,float(np.max(np.abs(l-ref[0]))),float(np.max(np.abs(r-ref[1]))));samples+=len(l)*2
  if not all(np.all(np.isfinite(v)) for v in [l,r]+ref):raise AssertionError('Non-finite distortion output')
  results[name]={'channel_samples':samples,'max_absolute_error':worst}
 worst=0.;samples=0;cases=0
 for rate in [22050,44100,48000,88200,96000,192000]:
  for follower in [0,1]:
   obj=C.create_string_buffer(48);addr=C.addressof(obj);lib.windows_construct(base+0x1bdc0,addr);lib.windows_rate(base+0x1be40,addr,rate);lib.windows_construct(base+0x1be50,addr);C.c_float.from_address(addr+4).value=.01 if follower else 0;port=lib.port_compressor(rate,follower)
   for frames in [1,8,16,31,63,64,65,127,128,257,512,1024]*2:
    dest=float(np.float32(rng.random()*.99));l=rng.uniform(-1.5,1.5,frames).astype('f');r=rng.uniform(-1.5,1.5,frames).astype('f');rl=l.copy();rr=r.copy();lib.windows_compress(base+0x1be70,addr,l.ctypes.data_as(fp),r.ctypes.data_as(fp),frames,dest);lib.port_compress(port,rl.ctypes.data_as(fp),rr.ctypes.data_as(fp),frames,dest);worst=max(worst,float(np.max(np.abs(l-rl))),float(np.max(np.abs(r-rr))));samples+=frames*2;cases+=1
    if not all(np.all(np.isfinite(v)) for v in [l,r,rl,rr]):raise AssertionError('Non-finite compressor output')
   lib.port_destroy(port)
 results['compressor']={'cases':cases,'channel_samples':samples,'max_absolute_error':worst}
 report={'dll_sha256':digest,'seed':19388,'routines':results,'limitations':['Selected distortion and compressor routines only','No full DLL load, Windows host, original CRT math, filter, master, or whole-plugin equality test','Object state reconstructed; DLL entry point and GUI never run']};text=json.dumps(report,indent=2)+'\n';print(text,end='')
 if a.report:a.report.write_text(text)
 if any(v['max_absolute_error']!=0 for v in results.values()):raise SystemExit(1)
if __name__=='__main__':main()
