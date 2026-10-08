import sys,ctypes as C,struct,numpy as np
from binary_oracle import MachO
m=None;lib=None;fp=C.POINTER(C.c_float)
class Original:
 def __init__(self,rate,params):
  self.obj=C.create_string_buffer(0x4628);self.base=C.addressof(self.obj);self.ps=[C.create_string_buffer(0x22d8) for _ in range(17)];self.ptrs=(C.c_void_p*17)(*[C.addressof(p) for p in self.ps]);self.l=(C.c_float*64)();self.r=(C.c_float*64)()
  self.pack('Q',8,C.addressof(self.ptrs));self.pack('i',0x10,17);self.pack('i',0x14,17)
  self.pack('Q',0x4608,C.addressof(self.l));self.pack('Q',0x4610,C.addressof(self.r))
  self.pack('f',0x2a90,rate);self.pack('f',0x1c2c,120)
  comp=m.fn('__ZN12CACompressorC1Ev',None,[C.c_void_p]);comp(self.base+0x45d8)
  m.fn('__ZN12CACompressor13setSampleRateEf',None,[C.c_void_p,C.c_float])(self.base+0x45d8,rate)
  m.fn('__ZN12CACompressor5clearEv',None,[C.c_void_p])(self.base+0x45d8)
  fb=self.base+0x30b8
  ctor=m.fn('__ZN14CAFilterBiquadC1Ev',None,[C.c_void_p])
  ctor(fb+0x18);ctor(fb+0x70)
  for pos in [0x10b8,0x10d0]:m.fn('__ZN16EnvelopeFollowerC1Ev',None,[C.c_void_p])(fb+pos)
  C.c_float.from_address(fb+0x10bc).value=.0075;C.c_float.from_address(fb+0x10c0).value=.05
  m.fn('__ZN8MMFilter5resetEf',None,[C.c_void_p,C.c_float])(fb,rate)
  self.proc=m.fn('__ZN12CamelCrusher7processEPfS0_S0_S0_ib',None,[C.c_void_p,fp,fp,fp,fp,C.c_int,C.c_bool])
  self.setf=m.fn('__ZN6PParam8setParamEf',None,[C.c_void_p,C.c_float])
  for i,(p,v) in enumerate(zip(self.ps,params)):
   addr=C.addressof(p);C.c_byte.from_address(addr).value=[0,1,1,0,6,1,0,7,0,0,1,8,0,0,0,0,0][i];C.c_float.from_address(addr+0x19c).value=.99 if i==7 else 1;C.c_int.from_address(addr+0x1b8).value=int(np.float32(rate)*np.float32(.01))
   self.set(i,v); m.fn('__ZN6PParam13resetToStoredEv',None,[C.c_void_p])(addr)
 def pack(self,fmt,off,value):struct.pack_into('<'+fmt,self.obj,off,value)
 def set(self,i,v):
  self.setf(C.addressof(self.ps[i]),v)
  if i==8:self.pack('f',0x45dc,.01 if v<.5 else 0)
 def process(self,l,r):
  l=np.asarray(l,dtype=np.float32);r=np.asarray(r,dtype=np.float32);ol=np.zeros_like(l);or_=np.zeros_like(r)
  self.proc(self.base,l.ctypes.data_as(fp),r.ctypes.data_as(fp),ol.ctypes.data_as(fp),or_.ctypes.data_as(fp),len(l),True)
  return ol,or_
def configure(binary,bridge):
 global m,lib
 m=MachO(binary);lib=C.CDLL(str(bridge));lib.camel_create.restype=C.c_void_p
 lib.camel_prepare.argtypes=[C.c_void_p,C.c_float];lib.camel_restore.argtypes=[C.c_void_p,fp];lib.camel_set.argtypes=[C.c_void_p,C.c_int,C.c_float];lib.camel_process.argtypes=[C.c_void_p,fp,fp,fp,fp,C.c_int];lib.camel_destroy.argtypes=[C.c_void_p]
class Port:
 def __init__(self,rate,p):self.obj=lib.camel_create();lib.camel_prepare(self.obj,rate);a=(C.c_float*17)(*p);lib.camel_restore(self.obj,a)
 def set(self,i,v):lib.camel_set(self.obj,i,v)
 def process(self,l,r):
  l=np.asarray(l,dtype=np.float32);r=np.asarray(r,dtype=np.float32);ol=np.zeros_like(l);or_=np.zeros_like(r)
  lib.camel_process(self.obj,l.ctypes.data_as(fp),r.ctypes.data_as(fp),ol.ctypes.data_as(fp),or_.ctypes.data_as(fp),len(l));return ol,or_
 def __del__(self):lib.camel_destroy(self.obj)

if __name__=='__main__':
 import argparse,json,pathlib
 ap=argparse.ArgumentParser(description='Differential original Intel DSP vs C++ core; explicit binary execution opt-in')
 ap.add_argument('--binary',type=pathlib.Path,required=True);ap.add_argument('--bridge',type=pathlib.Path,required=True);ap.add_argument('--execute-original',action='store_true');ap.add_argument('--report',type=pathlib.Path);args=ap.parse_args()
 if not args.execute_original:ap.error('The original machine-code DSP will run; pass --execute-original to enable this experiment')
 configure(args.binary,args.bridge.resolve())
 presets=json.loads((pathlib.Path(__file__).resolve().parents[1]/'docs/factory-presets.json').read_text())
 rng=np.random.default_rng(19388);worst=0.;cases=0;samples=0;bad=[];nonfinite=0
 for rate in [22050,44100,48000,88200,96000,192000]:
  for preset in presets:
   a=Original(rate,preset['parameters']);b=Port(rate,preset['parameters'])
   for j,n in enumerate([1,8,16,31,63,64,65,127,128,257,512,1024]*2):
    l=rng.uniform(-1.5,1.5,n).astype('f');r=rng.uniform(-1.5,1.5,n).astype('f')
    if j>11:
     i=[1,2,4,5,7,8,10,11][(j-12)%8];v=float(rng.random());a.set(i,v);b.set(i,v)
    x=a.process(l,r);y=b.process(l,r)
    if not all(np.all(np.isfinite(v)) for v in x+y):nonfinite+=1
    err=max(float(np.max(np.abs(x[0]-y[0]))),float(np.max(np.abs(x[1]-y[1]))));cases+=1;samples+=n*2;worst=max(worst,err)
    if err>1e-5:bad.append(dict(rate=rate,preset=preset['name'],block=j,frames=n,error=err))
 report=dict(binary_kind=m.kind,binary_sha256=m.digest,cases=cases,channel_samples=samples,max_absolute_error=worst,nonfinite_cases=nonfinite,failures=bad,seed=19388,
  limitations=['Selected DSP routines and reconstructed object state; not full plugin hosting','Linux libm imports; not macOS Intel math or ARM64 math','Host MIDI and bypass dispatch are outside this comparison'])
 text=json.dumps(report,indent=2)+'\n'
 if args.report:args.report.write_text(text)
 print(text,end='');sys.exit(1 if bad or nonfinite else 0)
