import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class DumpStart extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        long start = Long.decode(args[0]);
        long len = Long.decode(args[1]);
        String outPath = args[2];
        Address base = currentProgram.getMinAddress();
        Address a = base.add(start);
        new DisassembleCommand(a, null, true).applyTo(currentProgram, monitor);
        try (PrintWriter pw = new PrintWriter(new FileWriter(outPath))) {
            Listing l = currentProgram.getListing();
            Address end = a.add(len);
            for (CodeUnit cu : l.getCodeUnits(new AddressSet(a, end), true)) {
                pw.println(cu.getAddress() + "  " + cu.toString());
            }
        }
    }
}
