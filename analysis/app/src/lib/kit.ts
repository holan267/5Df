import type { DirectoryHandle, KitFile } from "@/lib/types";

export const KIT_FILE = /(^|\/)([^/]+\.CR2|[^/]+\.ARW|firmware\.bin|film\.json|traits\.json|tables\.bin|curves\.bin|(paper|grain)\d+\.bin)$/i;
export const RAW_FILE = /\.(cr2|arw)$/i;

export async function walk(dir: DirectoryHandle, prefix = "", depth = 0, out: KitFile[] = []) {
  for await (const [name, h] of dir.entries()) {
    if (name.startsWith(".")) continue;
    if (h.kind === "directory") { if (depth < 5) await walk(h as DirectoryHandle, prefix + name + "/", depth + 1, out); }
    else if (KIT_FILE.test(name)) out.push({ path: prefix + name, file: await (h as FileSystemFileHandle).getFile() });
  }
  return out;
}

// webkitRelativePath starts with the picked folder's own name.
export function fromInput(files: File[]) {
  const list = files.map((file) => ({ path: file.webkitRelativePath.replace(/^[^/]*\//, ""), file }))
    .filter((k) => KIT_FILE.test(k.path));
  return { list, top: files.length ? files[0].webkitRelativePath.split("/")[0] : "" };
}
