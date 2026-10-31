//! Halation, tools/latent_effects.py.
use crate::color::M3;
use crate::firmware::Firmware;
use crate::Result;

const KNEE_TABLE: usize = 0x9A8D68;
const HALO_PROFILES: usize = 0x9A90F0;
const KERNELS: [usize; 4] = [0x9A9274, 0x9A92BA, 0x9A9300, 0x9A9346];   // h and v, narrow then wide
const HALO_WEIGHTS: usize = 0x9A9418;
pub const HALO_LEVELS: [u32; 3] = [0x55, 0xAB, 0x100];
const HALO_HIGHLIGHT_GAIN: f32 = 80.0;
const HALO_MEAN_GAIN: f32 = 1.35;
pub const MAP_W: usize = 360;
pub const MAP_H: usize = 213;

pub struct Profile {
    p: [[f64; 3]; 2],
    pub c: [[f32; 3]; 2],
}

/// 0x34-byte records: char code[4], i32 p0[3], i32 p1[3], i32 c[6] (c0/c1 interleaved).
pub fn profile(fw: &Firmware, code: &str) -> Result<Option<Profile>> {
    let mut addr = HALO_PROFILES;
    while fw.bytes(addr, 1)?[0] != 0x11 {
        if fw.bytes(addr, 4)? == code.as_bytes() {
            let v = fw.i32s(addr + 4, 12)?;
            let p = |i: usize| v[i] as f64 / 32768.0;
            let c = |i: usize| (v[i] as f64 / 65536.0) as f32;
            return Ok(Some(Profile {
                p: [[p(0), p(1), p(2)], [p(3), p(4), p(5)]],
                c: [[c(6), c(8), c(10)], [c(7), c(9), c(11)]],
            }));
        }
        addr += 0x34;
    }
    Ok(None)
}

fn kernel(fw: &Firmware, addr: usize) -> Result<Vec<f64>> {
    let k = fw.u16s(addr, 35)?;
    let first = k.iter().position(|v| *v != 0).ok_or("empty halation kernel")?;
    let last = k.iter().rposition(|v| *v != 0).unwrap();
    Ok(k[first..=last].iter().map(|v| *v as f64).collect())
}

/// A rows x cols plane.
#[derive(Clone)]
struct Plane {
    rows: usize,
    cols: usize,
    v: Vec<f64>,
}

/// Symmetric convolution of one line, renormalised by the taps inside (firmware edge rule).
fn conv_line(a: &[f64], k: &[f64], out: &mut [f64], wsum: &mut [f64]) {
    let (n, r) = (a.len() as isize, (k.len() / 2) as isize);
    out.fill(0.0);
    wsum.fill(0.0);
    for (j, w) in k.iter().enumerate() {
        let s = j as isize - r;
        for i in (-s).max(0)..n.min(n - s) {
            out[i as usize] += w * a[(i + s) as usize];
            wsum[i as usize] += w;
        }
    }
    for (o, w) in out.iter_mut().zip(wsum.iter()) {
        *o /= w;
    }
}

fn conv_norm(p: &Plane, kh: &[f64], kv: &[f64]) -> Plane {
    let mut h = p.clone();
    let mut wsum = vec![0.0; p.cols];
    for (src, dst) in p.v.chunks_exact(p.cols).zip(h.v.chunks_exact_mut(p.cols)) {
        conv_line(src, kh, dst, &mut wsum);
    }
    let mut out = h.clone();
    let (mut a, mut b) = (vec![0.0; p.rows], vec![0.0; p.rows]);
    let mut wsum = vec![0.0; p.rows];
    for x in 0..p.cols {
        for y in 0..p.rows {
            a[y] = h.v[y * p.cols + x];
        }
        conv_line(&a, kv, &mut b, &mut wsum);
        for y in 0..p.rows {
            out.v[y * p.cols + x] = b[y];
        }
    }
    out
}

fn axis_weights(n_src: usize, n_dst: usize) -> Vec<(usize, f64)> {
    (0..n_dst)
        .map(|i| {
            let pos = ((i as f64 + 0.5) * n_src as f64 / n_dst as f64 - 0.5).clamp(0.0, (n_src - 1) as f64);
            let i0 = if n_src > 1 { (pos.floor() as usize).min(n_src - 2) } else { 0 };
            (i0, pos - i0 as f64)
        })
        .collect()
}

fn resize_bilinear(a: &Plane, rows: usize, cols: usize) -> Plane {
    let (rw, cw) = (axis_weights(a.rows, rows), axis_weights(a.cols, cols));
    let mut v = Vec::with_capacity(rows * cols);
    for &(r0, rf) in &rw {
        let r1 = (r0 + 1).min(a.rows - 1);
        for &(c0, cf) in &cw {
            let c1 = (c0 + 1).min(a.cols - 1);
            let at = |c: usize| a.v[r0 * a.cols + c] * (1.0 - rf) + a.v[r1 * a.cols + c] * rf;
            v.push(at(c0) * (1.0 - cf) + at(c1) * cf);
        }
    }
    Plane { rows, cols, v }
}

pub struct Halation {
    knee: Vec<f32>,
    vec: [[f32; 3]; 2],
    clip: [f32; 3],
    kernels: [Vec<f64>; 4],
    weights: [f64; 2],
}

/// The two 360 x 213 maps, [plane][y][x], in linear units.
pub type Maps = Vec<f64>;

impl Halation {
    /// `matrix` includes the exposure.
    pub fn new(fw: &Firmware, profile: &Profile, matrix: &M3, clip: [f32; 3]) -> Result<Halation> {
        let knee = fw.u16s(KNEE_TABLE, 257)?.iter().map(|v| *v as f32 / 256.0).collect();
        let row = |p: &[f64; 3]| [0, 1, 2].map(|j| (p[0] * matrix[0][j] + p[1] * matrix[1][j] + p[2] * matrix[2][j]) as f32);
        let w = fw.i32s(HALO_WEIGHTS, 2)?;
        Ok(Halation {
            knee,
            vec: [row(&profile.p[0]), row(&profile.p[1])],
            clip,
            kernels: [kernel(fw, KERNELS[0])?, kernel(fw, KERNELS[1])?, kernel(fw, KERNELS[2])?, kernel(fw, KERNELS[3])?],
            weights: [w[0] as f64, w[1] as f64],
        })
    }

    pub fn build_map(&self, rgb: &[u16], width: usize, height: usize) -> Maps {
        let col_edge = |i: usize| i * width / MAP_W;
        let mut col_cell = vec![0usize; width];
        for c in 0..MAP_W {
            col_cell[col_edge(c)..col_edge(c + 1)].fill(c);
        }
        let mut sums = vec![[0f64; 3]; MAP_H * MAP_W];
        let mut rows = [0usize; MAP_H];
        let mut colsum = vec![[0f64; 3]; MAP_W];
        for (y, line) in rgb.chunks_exact(width * 3).take(height).enumerate() {
            colsum.fill([0.0; 3]);
            for (px, cell) in line.chunks_exact(3).zip(&col_cell) {
                let v = [0, 1, 2].map(|c| (px[c] as f32 / 65535.0).min(self.clip[c]));
                // numpy: t and the knee's interpolation go through float64 from `t - ti` on.
                let g = v[1];
                let t = ((g - 0.97f32) / 0.03f32 * 256.0).clamp(0.0, 256.0);
                let ti = (t as i32).min(255) as usize;
                let dk = self.knee[ti + 1] - self.knee[ti];
                let knee = self.knee[ti] as f64 + (t as f64 - ti as f64) * dk as f64;
                let hi = (HALO_HIGHLIGHT_GAIN * g) as f64 * knee;
                for c in 0..3 {
                    colsum[*cell][c] += (HALO_MEAN_GAIN * v[c]) as f64 + hi * self.clip[c] as f64;
                }
            }
            let row = y * MAP_H / height;
            rows[row] += 1;
            for (s, c) in sums[row * MAP_W..(row + 1) * MAP_W].iter_mut().zip(&colsum) {
                for i in 0..3 {
                    s[i] += c[i];
                }
            }
        }
        let mut out = Vec::with_capacity(2 * MAP_H * MAP_W);
        for vec in &self.vec {
            let mut m = Plane { rows: MAP_H, cols: MAP_W, v: Vec::with_capacity(MAP_H * MAP_W) };
            for y in 0..MAP_H {
                for x in 0..MAP_W {
                    let count = (rows[y] * (col_edge(x + 1) - col_edge(x))) as f64;
                    let s = sums[y * MAP_W + x];
                    let [a, b, c] = [s[0] / count, s[1] / count, s[2] / count];
                    let plane = 2.0 * (vec[0] as f64 * a + vec[1] as f64 * b + vec[2] as f64 * c);
                    m.v.push(plane.clamp(0.0, 65535.0 / 512.0));
                }
            }
            out.extend(self.blur(&m).v);
        }
        out
    }

    fn blur(&self, m: &Plane) -> Plane {
        let [kh_n, kv_n, kh_w, kv_w] = &self.kernels;
        // Half resolution (2x2 mean, last row repeated), wide kernels, back up.
        let hr = (m.rows + 1) / 2;
        let hc = m.cols / 2;
        let at = |y: usize, x: usize| m.v[y.min(m.rows - 1) * m.cols + x];
        let mut half = Plane { rows: hr, cols: hc, v: Vec::with_capacity(hr * hc) };
        for y in 0..hr {
            for x in 0..hc {
                let sum = at(2 * y, 2 * x) + at(2 * y, 2 * x + 1) + at(2 * y + 1, 2 * x) + at(2 * y + 1, 2 * x + 1);
                half.v.push(sum / 4.0);
            }
        }
        let very_wide = resize_bilinear(&conv_norm(&half, kh_w, kv_w), m.rows, m.cols);
        let narrow = conv_norm(m, kh_n, kv_n);
        let wide = conv_norm(m, kh_w, kv_w);
        let [w_n, w_w] = self.weights;
        let v = (0..m.v.len())
            .map(|i| ((0x38E4 as f64 * very_wide.v[i] + w_n * narrow.v[i] + w_w * wide.v[i]) / 32768.0).clamp(0.0, 0x7FFF as f64 / 512.0))
            .collect();
        Plane { rows: m.rows, cols: m.cols, v }
    }
}

/// The offsets of a frame: maps resized to its width, and each row's two map rows.
pub struct Offsets {
    planes: [Vec<f64>; 2],
    rows: Vec<(usize, f64)>,
    width: usize,
    c: [[f64; 3]; 2],
    strength: f64,
}

impl Offsets {
    pub fn new(maps: &[f64], profile: &Profile, level: u32, height: usize, width: usize) -> Offsets {
        let plane = |i: usize| {
            let m = Plane { rows: MAP_H, cols: MAP_W, v: maps[i * MAP_H * MAP_W..(i + 1) * MAP_H * MAP_W].to_vec() };
            resize_bilinear(&m, MAP_H, width).v
        };
        let rows = (0..height)
            .map(|y| {
                let pos = ((y as f64 + 0.5) * MAP_H as f64 / height as f64 - 0.5).clamp(0.0, (MAP_H - 1) as f64);
                let r0 = (pos.floor() as usize).min(MAP_H - 2);
                (r0, pos - r0 as f64)
            })
            .collect();
        Offsets {
            planes: [plane(0), plane(1)],
            rows,
            width,
            c: profile.c.map(|r| r.map(|v| v as f64)),
            strength: level as f64 / 256.0,
        }
    }

    #[inline]
    pub fn at(&self, y: usize, x: usize) -> [f64; 3] {
        let (r0, rf) = self.rows[y];
        let m = |p: &[f64]| p[r0 * self.width + x] * (1.0 - rf) + p[(r0 + 1) * self.width + x] * rf;
        let (a, b) = (m(&self.planes[0]), m(&self.planes[1]));
        [0, 1, 2].map(|i| self.strength * (a * self.c[0][i] + b * self.c[1][i]))
    }
}
