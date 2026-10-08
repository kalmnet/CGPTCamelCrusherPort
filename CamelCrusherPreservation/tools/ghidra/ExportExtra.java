import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
public class ExportExtra extends GhidraScript {
 public void run() throws Exception {
  DecompInterface d=new DecompInterface(); d.openProgram(currentProgram);
  PrintWriter p=new PrintWriter(new File(getScriptArgs()[0]));
  FunctionIterator it=currentProgram.getFunctionManager().getFunctions(true);
  while(it.hasNext()) { Function f=it.next(); String n=f.getName(true);
   if(n.contains("CAPlugin::random")||n.contains("CAPluginVST::process")||n.contains("CVST2AUPlugin::SaveState")||n.contains("CVST2AUPlugin::RestoreState")||n.contains("CVST2AUPlugin::GetParameterInfo")||n.contains("CVST2AUPlugin::GetParameterTranslated")||n.contains("CVST2AUPlugin::SetParameterTranslated")) {
    p.println("// ADDRESS "+f.getEntryPoint()+" NAME "+n);
    DecompileResults r=d.decompileFunction(f,60,monitor);
    p.println(r.decompileCompleted()?r.getDecompiledFunction().getC():"// FAILED "+r.getErrorMessage()); p.flush();
   }
  } p.close(); d.dispose();
 }
}
