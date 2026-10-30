import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;

// args: outFile [function address ...]
public class Decomp extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        opts.setRespectReadOnly(true);
        DecompInterface di = new DecompInterface();
        di.setOptions(opts);
        di.openProgram(currentProgram);
        try (PrintWriter dc = new PrintWriter(new FileWriter(args[0]))) {
            Iterable<Function> fs = currentProgram.getFunctionManager().getFunctions(true);
            if (args.length > 1) {
                java.util.List<Function> sel = new java.util.ArrayList<>();
                for (int i = 1; i < args.length; i++) sel.add(getFunctionAt(toAddr(Long.decode(args[i]))));
                fs = sel;
            }
            for (Function f : fs) {
                DecompileResults res = di.decompileFunction(f, 60, monitor);
                dc.println("// ===== " + f.getName() + " @ " + f.getEntryPoint());
                dc.println(res != null && res.decompileCompleted() ? res.getDecompiledFunction().getC()
                        : "// decompile failed: " + (res == null ? "null" : res.getErrorMessage()));
            }
        }
        di.dispose();
    }
}
