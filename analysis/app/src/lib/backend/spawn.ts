interface Pending { resolve(v: any): void; reject(e: Error): void }

export type Worked = ReturnType<typeof spawn>;

export function spawn(onStatus: (text: string) => void) {
  const w = new Worker(new URL("../../engine/engine.worker.ts", import.meta.url), { type: "module" });
  const pending = new Map<number, Pending>();
  let next = 0;
  w.onmessage = ({ data }) => {
    if (data.status) { onStatus(data.status); return; }
    const p = pending.get(data.id)!; pending.delete(data.id);
    if (data.error !== undefined) p.reject(new Error(data.error)); else p.resolve(data.out);
  };
  w.onerror = (e) => {
    for (const p of pending.values()) p.reject(new Error(e.message || "worker failed to start"));
    pending.clear();
  };
  const call = <T,>(op: string, args: object = {}, transfer: Transferable[] = []) => new Promise<T>((resolve, reject) => {
    const id = next++; pending.set(id, { resolve, reject }); w.postMessage({ id, op, args }, transfer);
  });
  return { call, stop: () => w.terminate() };
}
