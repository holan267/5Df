// The per-pixel pipeline, core/src/develop.rs on the GPU: matrix, halation, gamut compression,
// shaper, tetrahedral cube, grain, output table. Float32 throughout; `?check=1` compares it
// with the CPU path. Buffers hold what the engine's heap holds, so u16 and i16 values are
// picked out of u32 words (wasm is little-endian).

struct Params {
  m0: vec4f, m1: vec4f, m2: vec4f,
  clip: vec4f,
  halo0: vec4f, halo1: vec4f,    // film layer -> RGB offset, with the strength applied
  width: u32, height: u32,
  flags: u32,                    // see the constants
  y0: u32,                       // first row of this dispatch
}

const GAMUT = 1u;
const HALATION = 2u;
const LATTICE = 4u;              // grain on the 16-bit output
const SIMPLE = 8u;               // grain on the 8-bit output
const MONO = 16u;

const GRID = 65u;
const GAMUT_BASE = 0x8001u;      // in tables: the shaper, then 3 x 1024 gamut curves
const LATTICE_BASE = 3072u;      // in grain: 3 x 1024 input tables, then 17^3 x 6
const MAP_W = 360u;
const MAP_H = 213u;

@group(0) @binding(0) var<uniform> u: Params;
@group(0) @binding(1) var<storage, read> rgb: array<u32>;      // u16 [y][x][3]
@group(0) @binding(2) var<storage, read> noise: array<u32>;    // i16 [stream][y][x]
@group(0) @binding(3) var<storage, read> cube: array<f32>;     // [b][g][r][3]
@group(0) @binding(4) var<storage, read> tables: array<f32>;
@group(0) @binding(5) var<storage, read> out8: array<u32>;     // [3][4096]
@group(0) @binding(6) var<storage, read> grain: array<f32>;    // lattice, or amp [3][256]
@group(0) @binding(7) var<storage, read> maps: array<f32>;     // [2][213][360]
@group(0) @binding(8) var picture_out: texture_storage_2d<rgba8unorm, write>;

fn u16_at(k: u32) -> u32 { return (rgb[k >> 1] >> ((k & 1) * 16)) & 0xFFFF; }

fn noise_at(k: u32) -> i32 { return i32(noise[k >> 1] << ((1 - (k & 1)) * 16)) >> 16; }

fn gamut_compress(lin: vec3f) -> vec3f {
  let mx = max(max(lin.x, lin.y), lin.z);
  if (!(mx > 0.0)) { return lin; }
  let thresholds = vec3f(f32(0xD0A), f32(0xCD9), f32(0xE14)) / 4096.0;
  var res = lin;
  for (var c = 0u; c < 3; c++) {
    let d = (mx - lin[c]) / mx;
    if (d > thresholds[c] || mx >= 8.0) {
      let base = GAMUT_BASE + c * 1024;
      let r = floor(d * 4096.0);
      let div = floor(r / 16.0);
      let i = u32(clamp(i32(div), 0, 0x3FF));
      let frac = r - div * 16.0;
      var v = tables[base + 0x3FF];
      if (i < 0x3FF) {
        let t = tables[base + i];
        v = t + floor((frac * (tables[base + i + 1] - t) + 8.0) / 16.0);
      }
      res[c] = mx - mx * v / 4096.0;
    }
  }
  return res;
}

fn shaper(l: f32) -> f32 {
  let v = clamp(l * 65536.0, 0.0, f32(0x80000 - 1)) / 16.0;
  let fl = floor(v);
  let i = u32(fl);
  return (tables[i] + (v - fl) * (tables[i + 1] - tables[i])) / 512.0;
}

// One tetrahedron: walks c000 -> a -> b -> c111, node offsets in units of one node.
struct Walk { base: u32, a: u32, b: u32, end: u32, x: vec3f }

fn walk(c: vec3f, n: u32) -> Walk {
  let i = min(vec3u(floor(c)), vec3u(n - 2));
  let f = c - vec3f(i);
  let sr = 1u;
  let sg = n;
  let sb = n * n;
  var w: Walk;
  w.base = i.z * sb + i.y * sg + i.x;
  w.end = sb + sg + sr;
  if (f.x >= f.y && f.y >= f.z) { w.a = sr; w.b = sr + sg; w.x = f.xyz; }
  else if (f.x >= f.z && f.z > f.y) { w.a = sr; w.b = sr + sb; w.x = f.xzy; }
  else if (f.z > f.x && f.x >= f.y) { w.a = sb; w.b = sb + sr; w.x = f.zxy; }
  else if (f.y > f.x && f.x >= f.z) { w.a = sg; w.b = sg + sr; w.x = f.yxz; }
  else if (f.y >= f.z && f.z > f.x) { w.a = sg; w.b = sg + sb; w.x = f.yzx; }
  else { w.a = sb; w.b = sb + sg; w.x = f.zyx; }
  return w;
}

fn sample_cube(g: vec3f) -> vec3f {
  let w = walk(g, GRID);
  var res: vec3f;
  for (var c = 0u; c < 3; c++) {
    let p0 = cube[(w.base) * 3 + c];
    let pa = cube[(w.base + w.a) * 3 + c];
    let pb = cube[(w.base + w.b) * 3 + c];
    let pe = cube[(w.base + w.end) * 3 + c];
    res[c] = p0 + w.x.x * (pa - p0) + w.x.y * (pb - pa) + w.x.z * (pe - pb);
  }
  return res;
}

fn lattice_value(w: Walk, c: u32) -> i32 {
  let at = LATTICE_BASE + c;
  let p0 = grain[at + w.base * 6];
  let pa = grain[at + (w.base + w.a) * 6];
  let pb = grain[at + (w.base + w.b) * 6];
  let pe = grain[at + (w.base + w.end) * 6];
  return i32(floor(p0 + w.x.x * (pa - p0) + w.x.y * (pb - pa) + w.x.z * (pe - pb)));
}

fn grain16(v: vec3i, n: vec3i) -> vec3i {
  var coords: vec3f;
  for (var c = 0u; c < 3; c++) {
    let s = v[c];
    let idx = select((s >> 7) + 0x1F8, s >> 1, s < 0x400);
    let e = u32(grain[c * 1024 + u32(min(idx, 1023))]);
    coords[c] = f32(e >> 11) + f32(e & 0x7FF) / 2048.0;
  }
  let w = walk(coords, 17u);
  let lm0 = lattice_value(w, 0u);
  let lm1 = lattice_value(w, 1u);
  let lm3 = lattice_value(w, 3u);
  var d: vec3i;
  if ((u.flags & MONO) != 0) {
    d = vec3i(lm0 * n.x, lm1 * n.x, lm3 * n.x) >> vec3u(7);
  } else {
    let lm2 = lattice_value(w, 2u);
    let lm4 = lattice_value(w, 4u);
    let lm5 = lattice_value(w, 5u);
    d = vec3i(lm0 * n.x, lm1 * n.x + lm2 * n.y, lm3 * n.x + lm4 * n.y + lm5 * n.z) >> vec3u(7);
  }
  return clamp(v + d, vec3i(0), vec3i(0xFFFF));
}

fn map_at(plane: u32, r: u32, c: u32) -> f32 { return maps[(plane * MAP_H + r) * MAP_W + c]; }

fn halation(x: u32, y: u32) -> vec3f {
  let px = clamp((f32(x) + 0.5) * f32(MAP_W) / f32(u.width) - 0.5, 0.0, f32(MAP_W - 1));
  let py = clamp((f32(y) + 0.5) * f32(MAP_H) / f32(u.height) - 0.5, 0.0, f32(MAP_H - 1));
  let c0 = min(u32(px), MAP_W - 2);
  let r0 = min(u32(py), MAP_H - 2);
  let cf = px - f32(c0);
  let rf = py - f32(r0);
  var m: vec2f;
  for (var p = 0u; p < 2; p++) {
    let top = map_at(p, r0, c0) * (1.0 - cf) + map_at(p, r0, c0 + 1) * cf;
    let bottom = map_at(p, r0 + 1, c0) * (1.0 - cf) + map_at(p, r0 + 1, c0 + 1) * cf;
    m[p] = top * (1.0 - rf) + bottom * rf;
  }
  return m.x * u.halo0.xyz + m.y * u.halo1.xyz;
}

@compute @workgroup_size(16, 16)
fn develop(@builtin(global_invocation_id) id: vec3u) {
  let x = id.x;
  let y = id.y + u.y0;
  if (x >= u.width || y >= u.height) { return; }
  let i = y * u.width + x;
  let cam = min(vec3f(f32(u16_at(i * 3)), f32(u16_at(i * 3 + 1)), f32(u16_at(i * 3 + 2))) / 65535.0, u.clip.xyz);
  var lin = vec3f(dot(cam, u.m0.xyz), dot(cam, u.m1.xyz), dot(cam, u.m2.xyz));
  if ((u.flags & HALATION) != 0) { lin += halation(x, y); }
  if ((u.flags & GAMUT) != 0) { lin = gamut_compress(lin); }
  let g = vec3f(shaper(lin.x), shaper(lin.y), shaper(lin.z));
  var o16 = vec3i(clamp(sample_cube(g), vec3f(0.0), vec3f(65535.0)));

  var n = vec3i(0);
  if ((u.flags & (LATTICE | SIMPLE)) != 0) {
    let plane = u.width * u.height;
    n.x = noise_at(i);
    if ((u.flags & MONO) == 0) { n.y = noise_at(plane + i); n.z = noise_at(2 * plane + i); }
  }
  if ((u.flags & LATTICE) != 0) { o16 = grain16(o16, n); }

  let i12 = (vec3u(o16) * 0xFFF + 0x8000) >> vec3u(16);
  var px = vec3i(i32(out8[i12.x]), i32(out8[4096 + i12.y]), i32(out8[8192 + i12.z]));
  if ((u.flags & SIMPLE) != 0) {
    let amp = vec3i(i32(grain[u32(px.x)]), i32(grain[256 + u32(px.y)]), i32(grain[512 + u32(px.z)]));
    px = clamp(px + ((n.x * amp + 0x400) >> vec3u(11)), vec3i(0), vec3i(255));
  }
  textureStore(picture_out, vec2u(x, y), vec4f(vec3f(px) / 255.0, 1.0));
}

// Display: the picture in sensor orientation, stood up, one texel per canvas pixel.

@group(0) @binding(0) var picture: texture_2d<f32>;
@group(0) @binding(1) var<uniform> view: vec4u;     // width, height, orientation

@vertex
fn fullscreen(@builtin(vertex_index) i: u32) -> @builtin(position) vec4f {
  return vec4f(f32(i & 1) * 4.0 - 1.0, f32(i & 2) * 2.0 - 1.0, 0.0, 1.0);
}

@fragment
fn show(@builtin(position) pos: vec4f) -> @location(0) vec4f {
  let c = u32(pos.x);
  let r = u32(pos.y);
  let w = view.x;
  let h = view.y;
  var at = vec2u(c, r);
  switch view.z {
    case 3u { at = vec2u(w - 1 - c, h - 1 - r); }
    case 6u { at = vec2u(r, h - 1 - c); }
    case 8u { at = vec2u(w - 1 - r, c); }
    default {}
  }
  return vec4f(textureLoad(picture, at, 0).rgb, 1.0);
}
