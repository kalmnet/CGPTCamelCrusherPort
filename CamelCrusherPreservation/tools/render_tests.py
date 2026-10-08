#!/usr/bin/env python3
import argparse,pathlib,struct,math,json
# Standard-library fixtures and metrics, independent of Python audio packages.
def fixtures(directory,rate=48000):
 directory.mkdir(parents=True,exist_ok=True);n=rate*2
 signals={
  'silence':lambda i:(0.,0.),
  'impulse':lambda i:(1. if i==0 else 0.,-.5 if i==0 else 0.),
  'sine_997':lambda i:(.5*math.sin(2*math.pi*997*i/rate),.3*math.sin(2*math.pi*1994*i/rate)),
  'sweep':lambda i:(.5*math.sin(2*math.pi*(20*i/rate+19980*(i/rate)**2/4)),)*2,
  'step':lambda i:((.9 if rate//4<=i<rate//2 else 0.),)*2,
  'over_unity':lambda i:(1.5*math.sin(2*math.pi*81*i/rate),-1.5*math.sin(2*math.pi*81*i/rate)),
 }
 for name,fn in signals.items():
  with (directory/(name+'.f32')).open('wb') as f:
   for i in range(n):f.write(struct.pack('<ff',*fn(i)))
 return {'sample_rate':rate,'frames':n,'signals':list(signals)}
def read(path):
 data=path.read_bytes()
 if len(data)%4:raise ValueError('Incomplete float sample')
 return struct.unpack('<'+'f'*(len(data)//4),data)
def compare(a,b):
 x,y=read(a),read(b)
 if len(x)!=len(y):raise ValueError('Length mismatch; compare with matching block size and pre-roll')
 if not all(math.isfinite(v) for v in x+y):raise ValueError('Non-finite render')
 delta=[p-q for p,q in zip(x,y)];peak=max(map(abs,delta),default=0);rms=math.sqrt(sum(v*v for v in delta)/max(1,len(delta)))
 return {'samples':len(x),'bit_identical':a.read_bytes()==b.read_bytes(),'max_abs_error':peak,'rms_error':rms,'residual_dbfs':20*math.log10(rms) if rms else '-inf'}
def main():
 p=argparse.ArgumentParser();s=p.add_subparsers(dest='command',required=True);f=s.add_parser('fixtures');f.add_argument('directory',type=pathlib.Path);f.add_argument('--rate',type=int,default=48000);c=s.add_parser('compare');c.add_argument('original',type=pathlib.Path);c.add_argument('port',type=pathlib.Path);args=p.parse_args()
 try:print(json.dumps(fixtures(args.directory,args.rate) if args.command=='fixtures' else compare(args.original,args.port),indent=2))
 except (OSError,ValueError) as e:p.exit(1,str(e)+'\n')
if __name__=='__main__':main()
