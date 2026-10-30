import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.*;
public class Blocks extends GhidraScript {
    public void run() throws Exception {
        for (MemoryBlock b : currentProgram.getMemory().getBlocks())
            println(b.getName() + " " + b.getStart() + "-" + b.getEnd() + " r" + b.isRead() + " w" + b.isWrite() + " x" + b.isExecute() + " vol" + b.isVolatile());
    }
}
