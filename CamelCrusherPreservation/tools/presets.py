#!/usr/bin/env python3
"""Parse CamelCrusher legacy state and convert it into a VST3 preset, without DSP guesses."""
import argparse,json,math,pathlib,struct,plistlib
PLUGIN_ID=b'CaCr'
PROCESSOR_UID='CC010101F4D14E5589A8C50AE7B68302'
def legacy(data):
 p=0;programs=[]
 while p<len(data):
  start=p
  if len(data)-p<4:raise ValueError('Truncated version')
  version=struct.unpack_from('<f',data,p)[0];p+=4
  if not math.isfinite(version) or version<0:raise ValueError('Invalid version')
  end=data.find(b'\0',p)
  if end<0 or end-p>63:raise ValueError('Invalid name')
  name=data[p:end].decode('latin1');p=end+1
  if len(data)-p<4:raise ValueError('Truncated count')
  count=struct.unpack_from('<I',data,p)[0];p+=4
  if count>17 or len(data)-p<count*4:raise ValueError('Invalid parameters')
  values=list(struct.unpack_from('<'+'f'*count,data,p));p+=count*4
  if not all(math.isfinite(v) and 0<=v<=1 for v in values):raise ValueError('Invalid value')
  values.extend([0.]*(17-count));programs.append(dict(name=name,version=version,parameters=values,chunk_offset=start))
  if len(programs)>20:raise ValueError('Too many programs')
 if not programs:raise ValueError('Empty state')
 return programs
def parse(data):
 if data.startswith(b'<?xml') or data.startswith(b'bplist00'):
  obj=plistlib.loads(data)
  if not isinstance(obj,dict) or not isinstance(obj.get('data'),bytes):raise ValueError('AU preset has no data blob')
  if 'subtype' in obj and obj['subtype'] not in (0x43614372,0x43725031):raise ValueError('Wrong AU subtype')
  payload=obj['data']
  try:return legacy(payload)
  except ValueError:
   if len(payload)!=68:raise
   values=list(struct.unpack('>17f',payload))
   if not all(math.isfinite(v) and 0<=v<=1 for v in values):raise ValueError('Invalid AU parameter array')
   return [dict(name=str(obj.get('name','Imported AU')),version=1.,parameters=values)]
 if data[:4]!=b'CcnK':return legacy(data)
 if len(data)<28:raise ValueError('Truncated FXP/FXB')
 size,magic,version,pid,fxver,count=struct.unpack_from('>I4sI4sII',data,4)
 if pid!=PLUGIN_ID or size not in (len(data)-8,len(data)):raise ValueError('Wrong plugin ID or file size')
 if magic in (b'FBCh',b'FPCh'):
  offset=156 if magic==b'FBCh' else 56
  if len(data)<offset+4:raise ValueError('Truncated chunk header')
  n=struct.unpack_from('>I',data,offset)[0]
  if n!=len(data)-offset-4:raise ValueError('Invalid chunk size')
  programs=legacy(data[offset+4:])
  if len(programs)!=(count if magic==b'FBCh' else 1):raise ValueError('Program count mismatch')
  return programs
 if magic==b'FxCk':
  if count>17 or len(data)!=56+count*4:raise ValueError('Invalid parameter FXP')
  values=list(struct.unpack_from('>'+'f'*count,data,56))
  if not all(math.isfinite(v) and 0<=v<=1 for v in values):raise ValueError('Invalid parameter')
  return [dict(name=data[28:56].split(b'\0')[0].decode('latin1'),version=1.,parameters=values+[0.]*(17-count))]
 raise ValueError('Unsupported FXP/FXB kind')
def encode(programs):
 out=bytearray()
 for p in programs:
  name=p['name'].encode('latin1')
  if len(name)>63 or b'\0' in name:raise ValueError('Invalid program name')
  out+=struct.pack('<f',p['version'])+name+b'\0'+struct.pack('<I17f',17,*p['parameters'])
 return bytes(out)
def vstpreset(programs,index):
 if len(programs)==1:programs=programs*20;index=0
 if len(programs)!=20 or not 0<=index<20:raise ValueError('Need 20 programs and index 0..19')
 state=b'CCP1'+struct.pack('<I',index)+encode(programs)
 offset=48+len(state)
 header=b'VST3'+struct.pack('<I',1)+PROCESSOR_UID.encode('ascii')+struct.pack('<Q',offset)
 return header+state+b'List'+struct.pack('<I',1)+b'Comp'+struct.pack('<QQ',48,len(state))
def main():
 ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('input',type=pathlib.Path);ap.add_argument('--json',type=pathlib.Path);ap.add_argument('--vstpreset',type=pathlib.Path);ap.add_argument('--program',type=int,default=0);ap.add_argument('--raw',type=pathlib.Path);ap.add_argument('--parameters',type=pathlib.Path);ap.add_argument('--aupreset',type=pathlib.Path);args=ap.parse_args()
 try:
  p=parse(args.input.read_bytes())
  if args.json:args.json.write_text(json.dumps(p,indent=2)+'\n')
  if args.vstpreset:args.vstpreset.write_bytes(vstpreset(p,args.program))
  if args.raw:args.raw.write_bytes(encode(p))
  if not 0<=args.program<len(p):raise ValueError('Program index out of range')
  if args.parameters:args.parameters.write_bytes(struct.pack('<17f',*p[args.program]['parameters']))
  if args.aupreset:
   item=p[args.program];obj=dict(version=0,type=0x61756d66,subtype=0x43614372,manufacturer=0x43616d41,name=item['name'],data=encode([item]))
   args.aupreset.write_bytes(plistlib.dumps(obj))
  print(json.dumps({'programs':len(p),'names':[x['name'] for x in p],'selected_program':args.program},indent=2))
 except (OSError,ValueError,struct.error) as e:ap.exit(1,str(e)+'\n')
if __name__=='__main__':main()
