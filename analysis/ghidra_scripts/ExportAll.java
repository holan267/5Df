import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import java.io.*;
import java.util.*;

// args: codeEnd(hex addr) outDir
public class ExportAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        long codeEnd = Long.decode(args[0]);
        String outDir = args[1];
        Memory mem = currentProgram.getMemory();
        Address base = currentProgram.getMinAddress();
        Address end = base.getNewAddress(codeEnd);

        // Seed: entry plus every ARM push {...,lr} prologue in the code region.
        List<Address> seeds = new ArrayList<>();
        seeds.add(base);
        for (Address a = base; a.compareTo(end) < 0; a = a.add(4)) {
            int w = mem.getInt(a);
            if ((w & 0xFFFF4000) == 0xE92D4000) seeds.add(a);
        }
        for (Address a : seeds) {
            if (getInstructionAt(a) == null)
                new DisassembleCommand(a, null, true).applyTo(currentProgram, monitor);
            if (getFunctionAt(a) == null)
                new CreateFunctionCmd(a).applyTo(currentProgram, monitor);
        }
        analyzeAll(currentProgram);

        // Strings and the functions that reference them.
        try (PrintWriter pw = new PrintWriter(new FileWriter(outDir + "/strings_xrefs.txt"))) {
            for (Data d : currentProgram.getListing().getDefinedData(true)) {
                if (!(d.getValue() instanceof String)) continue;
                Set<String> users = new TreeSet<>();
                for (Reference r : getReferencesTo(d.getAddress())) {
                    Function f = getFunctionContaining(r.getFromAddress());
                    users.add(f == null ? r.getFromAddress().toString() : f.getName());
                }
                pw.println(d.getAddress() + "\t\"" + d.getValue() + "\"\t" + users);
            }
        }

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        try (PrintWriter fl = new PrintWriter(new FileWriter(outDir + "/functions.tsv"));
             PrintWriter dc = new PrintWriter(new FileWriter(outDir + "/decompiled.c"))) {
            fl.println("entry\tname\tsize\tcallers\tcallees");
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                fl.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + f.getBody().getNumAddresses()
                        + "\t" + f.getCallingFunctions(monitor).size() + "\t" + f.getCalledFunctions(monitor).size());
                DecompileResults res = di.decompileFunction(f, 60, monitor);
                dc.println("// ===== " + f.getName() + " @ " + f.getEntryPoint());
                if (res != null && res.decompileCompleted())
                    dc.println(res.getDecompiledFunction().getC());
                else
                    dc.println("// decompile failed: " + (res == null ? "null" : res.getErrorMessage()));
            }
        }
        di.dispose();
    }
}
