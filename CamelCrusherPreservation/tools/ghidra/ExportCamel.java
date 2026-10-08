import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class ExportCamel extends GhidraScript {
 public void run() throws Exception {
  DecompInterface d=new DecompInterface(); d.openProgram(currentProgram);
  PrintWriter p=new PrintWriter(new File(getScriptArgs()[0]));
  FunctionIterator it=currentProgram.getFunctionManager().getFunctions(true);
  while(it.hasNext()) { Function f=it.next(); String n=f.getName(true);
   if(n.contains("CamelCrusher")||n.contains("MMFilter")||n.contains("CAFilter")||n.contains("EnvelopeFollower")||n.contains("FileIO")||n.contains("Compressor")||n.contains("Distort")||n.contains("Tube")||n.contains("Mech")||n.contains("Biquad")||n.contains("IirFilter")||n.contains("Moog")||n.contains("MS20")||n.contains("OTA")||n.contains("SVF")||n.contains("Param")||n.contains("Program")||n.contains("Chunk")) {
    p.println("// ADDRESS "+f.getEntryPoint()+" NAME "+n);
    DecompileResults r=d.decompileFunction(f,60,monitor);
    p.println(r.decompileCompleted()?r.getDecompiledFunction().getC():"// FAILED "+r.getErrorMessage()); p.flush();
   }
  } p.close(); d.dispose();
 }
}
