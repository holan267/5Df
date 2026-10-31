// WebGPU side of a render. Data stays in the engine's heap: a resource is uploaded when its
// tag changes, and the compute pass in develop.wgsl does the rest. Types are `any` because
// nothing else in the app needs @types/webgpu.
import wgsl from "@/engine/develop.wgsl?raw";
import type { Engine, GpuPlan, Resource } from "@/engine/wasm";

const SLOTS = ["rgb", "noise", "cube", "tables", "out8", "grain", "maps"] as const;
type Slot = (typeof SLOTS)[number];

const FLAG = { gamut: 1, halation: 2, lattice: 4, simple: 8, mono: 16 };
const STORAGE = 0x80 | 0x08;       // GPUBufferUsage STORAGE | COPY_DST
const UNIFORM = 0x40 | 0x08;       // UNIFORM | COPY_DST
const READBACK = 0x01 | 0x08;      // MAP_READ | COPY_DST
const TARGET = 0x08 | 0x04 | 0x01; // GPUTextureUsage STORAGE_BINDING | TEXTURE_BINDING | COPY_SRC
const WORKGROUP = 16;

export interface Frame { texture: any; width: number; height: number; orientation: number }

export class Gpu {
  private device: any;
  private context: any;
  private compute: any;
  private display: any;
  private buffers = new Map<Slot, { buffer: any; tag: string; size: number }>();
  private uniforms: any;
  private view: any;
  private empty: any;
  current: Frame | null = null;
  previous: Frame | null = null;
  lost = false;

  private constructor(device: any, context: any, compute: any, display: any) {
    this.device = device;
    this.context = context;
    this.compute = compute;
    this.display = display;
    this.uniforms = device.createBuffer({ size: 112, usage: UNIFORM });
    this.view = device.createBuffer({ size: 16, usage: UNIFORM });
    this.empty = device.createBuffer({ size: 4, usage: STORAGE });
    device.lost.then(() => { this.lost = true; });
  }

  static async create(canvas: OffscreenCanvas) {
    const gpu = (navigator as any).gpu;
    if (!gpu) return null;
    const adapter = await gpu.requestAdapter({ powerPreference: "high-performance" });
    if (!adapter) return null;
    const device = await adapter.requestDevice({
      requiredLimits: {
        maxStorageBufferBindingSize: adapter.limits.maxStorageBufferBindingSize,
        maxBufferSize: adapter.limits.maxBufferSize,
      },
    });
    const context = (canvas as any).getContext("webgpu");
    if (!context) return null;
    const format = gpu.getPreferredCanvasFormat();
    context.configure({ device, format, alphaMode: "opaque" });
    const module = device.createShaderModule({ code: wgsl });
    const [compute, display] = await Promise.all([
      device.createComputePipelineAsync({ layout: "auto", compute: { module, entryPoint: "develop" } }),
      device.createRenderPipelineAsync({
        layout: "auto",
        vertex: { module, entryPoint: "fullscreen" },
        fragment: { module, entryPoint: "show", targets: [{ format }] },
      }),
    ]);
    return new Gpu(device, context, compute, display);
  }

  /** Whether the picture's buffers and textures are within this device's limits. */
  fits(plan: GpuPlan) {
    const { maxStorageBufferBindingSize, maxBufferSize, maxTextureDimension2D } = this.device.limits;
    const largest = Math.max(...Object.values(plan.res).map((r) => r?.bytes ?? 0));
    return largest <= Math.min(maxStorageBufferBindingSize, maxBufferSize) && Math.max(plan.width, plan.height) <= maxTextureDimension2D;
  }

  private upload(slot: Slot, r: Resource | null, heap: () => Uint8Array) {
    if (!r) return;
    const have = this.buffers.get(slot);
    if (have?.tag === r.tag && have.size === r.bytes) return;
    const size = Math.ceil(r.bytes / 4) * 4;
    let entry = have;
    if (!entry || entry.buffer.size !== size) {
      entry?.buffer.destroy();
      entry = { buffer: this.device.createBuffer({ size, usage: STORAGE }), tag: "", size: 0 };
      this.buffers.set(slot, entry);
    }
    this.device.queue.writeBuffer(entry.buffer, 0, heap(), r.ptr, r.bytes);
    entry.tag = r.tag;
    entry.size = r.bytes;
  }

  private params(plan: GpuPlan, y0: number) {
    const b = new ArrayBuffer(112);
    const f = new Float32Array(b), u = new Uint32Array(b);
    plan.matrix.forEach((row, i) => f.set(row, i * 4));
    f.set(plan.clip, 12);
    if (plan.halo) { f.set(plan.halo[0], 16); f.set(plan.halo[1], 20); }
    u[24] = plan.width;
    u[25] = plan.height;
    u[26] = (plan.gamut ? FLAG.gamut : 0) | (plan.halo ? FLAG.halation : 0)
      | (plan.grain === "lattice" ? FLAG.lattice : 0) | (plan.grain === "simple" ? FLAG.simple : 0) | (plan.mono ? FLAG.mono : 0);
    u[27] = y0;
    return b;
  }

  /** Develops into a new texture, a band of rows per submit. */
  async develop(plan: GpuPlan, engine: Engine, rows = plan.height) {
    const { device } = this;
    for (const s of SLOTS) this.upload(s, plan.res[s], engine.heap);
    const texture = device.createTexture({ size: [plan.width, plan.height], format: "rgba8unorm", usage: TARGET });
    const buffer = (s: Slot) => ({ buffer: plan.res[s] ? this.buffers.get(s)!.buffer : this.empty });
    const group = device.createBindGroup({
      layout: this.compute.getBindGroupLayout(0),
      entries: [
        { binding: 0, resource: { buffer: this.uniforms } },
        ...SLOTS.map((s, i) => ({ binding: i + 1, resource: buffer(s) })),
        { binding: 8, resource: texture.createView() },
      ],
    });
    for (let y0 = 0; y0 < plan.height; y0 += rows) {
      device.queue.writeBuffer(this.uniforms, 0, this.params(plan, y0));
      const enc = device.createCommandEncoder();
      const pass = enc.beginComputePass();
      pass.setPipeline(this.compute);
      pass.setBindGroup(0, group);
      pass.dispatchWorkgroups(Math.ceil(plan.width / WORKGROUP), Math.ceil(Math.min(rows, plan.height - y0) / WORKGROUP));
      pass.end();
      device.queue.submit([enc.finish()]);
      if (rows < plan.height) await device.queue.onSubmittedWorkDone();
    }
    return { texture, width: plan.width, height: plan.height, orientation: plan.orientation };
  }

  /** What develop() made becomes the shown picture; the one before stays for compare. */
  commit(frame: Frame) {
    this.previous?.texture.destroy();
    this.previous = this.current;
    this.current = frame;
    this.show(frame);
  }

  show(frame: Frame) {
    const { device, context } = this;
    const quarter = frame.orientation === 6 || frame.orientation === 8;
    const canvas = context.canvas as OffscreenCanvas;
    const [w, h] = quarter ? [frame.height, frame.width] : [frame.width, frame.height];
    if (canvas.width !== w || canvas.height !== h) { canvas.width = w; canvas.height = h; }
    device.queue.writeBuffer(this.view, 0, new Uint32Array([frame.width, frame.height, frame.orientation, 0]));
    const group = device.createBindGroup({
      layout: this.display.getBindGroupLayout(0),
      entries: [{ binding: 0, resource: frame.texture.createView() }, { binding: 1, resource: { buffer: this.view } }],
    });
    const enc = device.createCommandEncoder();
    const pass = enc.beginRenderPass({
      colorAttachments: [{ view: context.getCurrentTexture().createView(), loadOp: "clear", clearValue: [0, 0, 0, 1], storeOp: "store" }],
    });
    pass.setPipeline(this.display);
    pass.setBindGroup(0, group);
    pass.draw(3);
    pass.end();
    device.queue.submit([enc.finish()]);
  }

  /** Tightly packed RGBA. */
  async read(frame: Frame) {
    const { device } = this;
    const bytesPerRow = Math.ceil(frame.width * 4 / 256) * 256;
    const staging = device.createBuffer({ size: bytesPerRow * frame.height, usage: READBACK });
    const enc = device.createCommandEncoder();
    enc.copyTextureToBuffer({ texture: frame.texture }, { buffer: staging, bytesPerRow }, [frame.width, frame.height]);
    device.queue.submit([enc.finish()]);
    await staging.mapAsync(1);
    const mapped = new Uint8Array(staging.getMappedRange());
    const out = new Uint8Array(frame.width * frame.height * 4);
    for (let y = 0; y < frame.height; y++) {
      out.set(mapped.subarray(y * bytesPerRow, y * bytesPerRow + frame.width * 4), y * frame.width * 4);
    }
    staging.destroy();
    return out;
  }

  /** The heap-sized buffers of a picture that was only exported. */
  releaseLarge() {
    for (const s of ["rgb", "noise"] as const) {
      this.buffers.get(s)?.buffer.destroy();
      this.buffers.delete(s);
    }
  }

  async done() {
    await this.device.queue.onSubmittedWorkDone();
  }

  /** For ?check=1: what a driver reset does. */
  destroy() {
    this.device.destroy();
  }
}
