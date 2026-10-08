import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class ExportJD extends GhidraScript {
 public void run() throws Exception {
  for(long off:new long[]{0x24230L,0x27f80L,0x28920L}){disassemble(toAddr(off));if(getFunctionAt(toAddr(off))==null)createFunction(toAddr(off),null);}
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);PrintWriter p=new PrintWriter(new File(getScriptArgs()[0]));FunctionIterator it=currentProgram.getFunctionManager().getFunctions(true);
  while(it.hasNext()){Function f=it.next();String n=f.getName(true);if(f.getEntryPoint().getOffset()==0x24230L||f.getEntryPoint().getOffset()==0x27f80L||f.getEntryPoint().getOffset()==0x28920L){p.println("// ADDRESS "+f.getEntryPoint()+" "+n);DecompileResults r=d.decompileFunction(f,60,monitor);if(r.decompileCompleted())p.println(r.getDecompiledFunction().getC());p.flush();}}p.close();d.dispose();
 }
}
