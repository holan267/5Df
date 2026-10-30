import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;

// Split the payload into read-only code/rodata and writable data at the lowest
// written address, add the BSS block, then re-export decompilation.
// args: bssStart bssEnd outDir
public class Refine extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Address bssStart = toAddr(Long.decode(args[0]));
        Address bssEnd = toAddr(Long.decode(args[1]));
        String outDir = args[2];
        Memory mem = currentProgram.getMemory();
        MemoryBlock blk = mem.getBlock(currentProgram.getMinAddress());

        Address floor = toAddr(Long.decode(args[3]));
        Address minWrite = null;
        java.util.TreeSet<Long> lowWrites = new java.util.TreeSet<>();
        ReferenceIterator it = currentProgram.getReferenceManager().getReferenceIterator(blk.getStart());
        while (it.hasNext()) {
            Reference r = it.next();
            Address to = r.getToAddress();
            if (!r.getReferenceType().isWrite() || !blk.contains(to)) continue;
            if (to.compareTo(floor) < 0) { lowWrites.add(to.getOffset() & ~0xFL); continue; }
            if (minWrite == null || to.compareTo(minWrite) < 0) minWrite = to;
        }
        if (minWrite == null) minWrite = blk.getEnd();
        Address split = toAddr(minWrite.getOffset() & ~0xFL);
        println("lowest written address " + minWrite + ", split at " + split + ", writable cells below floor " + lowWrites.size());
        mem.split(blk, split);
        mem.getBlock(split).setName("data");
        mem.getBlock(currentProgram.getMinAddress()).setWrite(false);
        // Keep 16-byte cells that code writes into below the floor writable.
        for (long cell : lowWrites) {
            Address a = toAddr(cell);
            println("writable cell in text: " + a);
            MemoryBlock b = mem.getBlock(a);
            if (!b.getStart().equals(a)) { mem.split(b, a); b = mem.getBlock(a); }
            Address next = a.add(16);
            if (b.contains(next)) mem.split(b, next);
            mem.getBlock(a).setWrite(true);
        }
        mem.createUninitializedBlock("bss", bssStart, bssEnd.subtract(bssStart), false);
        analyzeChanges(currentProgram);

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        try (PrintWriter dc = new PrintWriter(new FileWriter(outDir + "/decompiled_ro.c"))) {
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
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
