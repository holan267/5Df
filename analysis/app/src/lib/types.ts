export interface Paper { index: number; name: string; bw: boolean }

export interface Film {
  code: string;
  family: string;
  papers: Paper[];
  push: number[];
  grades: number[];
  kelvin: [number, number];
  halation: boolean;
}

export interface RawFile { id: string; name: string; uploaded?: boolean }

export interface RenderInfo {
  model: string;
  wb: number[];
  shot_kelvin: number;
  kelvin: number;
  mired: number;
  exposure: number;
  baseline_exposure: number;
  cubes: [string, string];
  weight: number;
  bw_curves: boolean;
  grain: string | null;
  halation: number;
  card_path: string;
  width: number;
  height: number;
  ms: number;
}

export interface Trait {
  brand: string;
  name: string;
  iso: number;
  family: string;
  tags: string[];
  summary: string;
  scores: Record<string, number | null>;
  measures: { kelvin: number; curve_stops: number[]; curve: number[] };
}
export type Traits = Record<string, Trait>;
export interface TraitsReply { ready: boolean; error?: string | null; films?: Traits }

export interface Rendered { blob: Blob; info: RenderInfo; name: string }

export interface Backend {
  files(): Promise<RawFile[]>;
  traits(): Promise<TraitsReply>;
  thumb(id: string): Promise<string>;
  upload(file: File): Promise<string>;
  render(query: string, download: boolean, signal?: AbortSignal): Promise<Rendered | null>;
}

export interface KitFile { path: string; file: File }
export interface Started { films: Film[]; files: RawFile[] }

// File System Access API, Chrome and Edge only.
export interface DirectoryHandle extends FileSystemDirectoryHandle {
  entries(): FileSystemDirectoryHandleAsyncIterator<[string, FileSystemFileHandle | DirectoryHandle]>;
  queryPermission(opts: { mode: "read" }): Promise<PermissionState>;
  requestPermission(opts: { mode: "read" }): Promise<PermissionState>;
}
declare global {
  interface Window { showDirectoryPicker?(opts: { id: string }): Promise<DirectoryHandle> }
}
