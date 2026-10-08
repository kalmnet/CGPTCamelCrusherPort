#!/usr/bin/env python3
"""Limited x86-64 Mach-O DSP oracle. Linux x86-64 only; not a general plug-in loader.
Only the exact supplied slice hashes are accepted. No GUI, initializers, installers,
network routines or whole plug-in entry points are called. Math imports use host libm.
"""
import ctypes as C,hashlib,mmap,struct,pathlib,platform
KNOWN={'ef7529f06f4f9ee05d914a4b59a21b63c651dfe362fc80dafa4e73ddab63f557':'vst',
       '834860ca5d4c59576dde1619d4e17050489ade3b0f756827ee4a7c56f3d322b0':'au'}
class MachO:
 def __init__(self,path):
  if platform.system()!='Linux' or platform.machine()!='x86_64':raise RuntimeError('Oracle requires Linux x86-64')
  b=pathlib.Path(path).read_bytes();digest=hashlib.sha256(b).hexdigest()
  if digest not in KNOWN:raise ValueError('Binary hash is not one of the supplied original slices')
  self.kind=KNOWN[digest];self.digest=digest;self.b=b;segs=[];sections=[];symbols=[];off=32
  for _ in range(struct.unpack_from('<I',b,16)[0]):
   cmd,size=struct.unpack_from('<II',b,off)
   if cmd==0x19:
    va,vs,fo,fs=struct.unpack_from('<QQQQ',b,off+24);segs.append((va,vs,fo,fs))
    if b[off+8:off+24].split(b'\0')[0]==b'__DATA':dataStart,dataEnd=va,va+fs
    ns=struct.unpack_from('<I',b,off+64)[0]
    for j in range(ns):
     s=off+72+j*80;name=b[s:s+16].split(b'\0')[0].decode();addr,sz=struct.unpack_from('<QQ',b,s+32);flags,r1,r2=struct.unpack_from('<III',b,s+64);sections.append((name,addr,sz,flags,r1,r2))
   if cmd==2:so,n,st,ss=struct.unpack_from('<IIII',b,off+8)
   if cmd==0xb:indoff,indn=struct.unpack_from('<II',b,off+56)
   off+=size
  self.symbols={}
  for i in range(n):
   ix,ty,se,de,val=struct.unpack_from('<IBBHQ',b,so+16*i);name=b[st+ix:b.find(b'\0',st+ix)].decode('utf8','replace');symbols.append(name);self.symbols[name]=val
  total=max(a+s for a,s,_,_ in segs);self.mem=mmap.mmap(-1,total,prot=mmap.PROT_READ|mmap.PROT_WRITE|mmap.PROT_EXEC);self.base=C.addressof(C.c_char.from_buffer(self.mem))
  for a,vs,fo,fs in segs:self.mem[a:a+fs]=b[fo:fo+fs]
  # Limited relocation for the selected vtables in these two known images only.
  for a in range(dataStart,dataEnd,8):
   v=struct.unpack_from('<Q',self.mem,a)[0]
   if 0x2000<=v<dataEnd:struct.pack_into('<Q',self.mem,a,self.base+v)
  libc=C.CDLL(None);libm=C.CDLL('libm.so.6');self.bound=[]
  allowed={'_memcpy','_pow','_powf','_sin','_cos','_log10','_logf'}
  for name,addr,sz,flags,r1,r2 in sections:
   if flags&255==8:
    for j in range(sz//r2):
     ix=struct.unpack_from('<I',b,indoff+4*(r1+j))[0]
     if ix>=len(symbols) or symbols[ix] not in allowed:continue
     nm=symbols[ix];fn=getattr(libc,nm[1:]) if nm=='_memcpy' else getattr(libm,nm[1:]);stub=addr+j*r2
     if self.mem[stub:stub+2]!=b'\xff\x25':raise ValueError('Unexpected import stub')
     ptr=stub+6+struct.unpack_from('<i',self.mem,stub+2)[0];struct.pack_into('<Q',self.mem,ptr,C.cast(fn,C.c_void_p).value);self.bound.append(nm)
 def fn(self,name,result,args):
  return C.CFUNCTYPE(result,*args)(self.base+self.symbols[name])
