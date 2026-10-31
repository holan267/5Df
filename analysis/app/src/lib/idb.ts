// Small key-value store for the kit folder handle and the measured film descriptions.
let db: Promise<IDBDatabase> | null = null;

function open() {
  return db || (db = new Promise((resolve, reject) => {
    const r = indexedDB.open("latent-darkroom", 1);
    r.onupgradeneeded = () => r.result.createObjectStore("kv");
    r.onsuccess = () => resolve(r.result);
    r.onerror = () => reject(r.error);
  }));
}

async function run<T>(mode: IDBTransactionMode, fn: (s: IDBObjectStore) => IDBRequest<T>) {
  const d = await open();
  return new Promise<T>((resolve, reject) => {
    const t = d.transaction("kv", mode), req = fn(t.objectStore("kv"));
    t.oncomplete = () => resolve(req.result);
    t.onerror = () => reject(t.error);
  });
}

export const idb = {
  get: <T,>(key: string) => run<T | undefined>("readonly", (s) => s.get(key)).catch(() => undefined),
  set: (key: string, value: unknown) => run("readwrite", (s) => s.put(value, key)).catch(() => {}),
};
