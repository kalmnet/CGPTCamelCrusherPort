import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
public class ExportWindowsDsp extends GhidraScript {
 public void run() throws Exception {
  PrintWriter names=new PrintWriter(new File(getScriptArgs()[0]+".symbols"));
  SymbolIterator symbols=currentProgram.getSymbolTable().getAllSymbols(true);
  while(symbols.hasNext()){Symbol s=symbols.next();names.println(s.getAddress()+" "+s.getName(true));}names.close();
  DecompInterface d=new DecompInterface();d.openProgram(currentProgram);PrintWriter p=new PrintWriter(new File(getScriptArgs()[0]));
  FunctionIterator it=currentProgram.getFunctionManager().getFunctions(true);
  while(it.hasNext()){Function f=it.next();long va=f.getEntryPoint().getOffset();if((va>=0x18001bb00L&&va<0x180023d00L)||(va>=0x18000b900L&&va<0x18000d300L)){p.println("// ADDRESS "+f.getEntryPoint()+" "+f.getName(true));DecompileResults r=d.decompileFunction(f,30,monitor);if(r.decompileCompleted())p.println(r.getDecompiledFunction().getC());p.flush();}}
  p.close();d.dispose();
 }
}
