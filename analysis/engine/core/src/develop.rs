//! The per-pixel pipeline, latent_develop.develop(). This is the CPU path: the reference for
//! the WebGPU shader and the fallback without a GPU.
use crate::grain::Grain;
use crate::halation::Offsets;
use crate::lite::GRID;
use std::ops::{Add, Div, Mul, Sub};

const GAMUT_THRESHOLDS: [f32; 3] = [0xD0A as f32 / 4096.0, 0xCD9 as f32 / 4096.0, 0xE14 as f32 / 4096.0];

/// f32, or f64 once halation offsets are in: numpy carries that type through gamut compression.
pub trait Real: Copy + PartialOrd + Add<Output = Self> + Sub<Output = Self> + Mul<Output = Self> + Div<Output = Self> {
    fn lit(v: f64) -> Self;
    fn of(v: f32) -> Self;
    fn wide(self) -> f64;
    fn floor(self) -> Self;
}

impl Real for f32 {
    fn lit(v: f64) -> f32 { v as f32 }
    fn of(v: f32) -> f32 { v }
    fn wide(self) -> f64 { self as f64 }
    fn floor(self) -> f32 { f32::floor(self) }
}

impl Real for f64 {
    fn lit(v: f64) -> f64 { v }
    fn of(v: f32) -> f64 { v as f64 }
    fn wide(self) -> f64 { self }
    fn floor(self) -> f64 { f64::floor(self) }
}

pub struct Tables {
    pub shaper: Vec<f32>,
    pub gamut: [Vec<f32>; 3],
    pub out8: Vec<u8>,
    /// The shaper, then the three gamut curves: the shader's `tables`.
    pub flat: Vec<f32>,
}

impl Tables {
    pub fn new(words: &[u16]) -> Tables {
        let curve = |s: usize| -> Vec<f32> { words[s..s + 0x400].iter().map(|v| *v as f32).collect() };
        let shaper: Vec<f32> = words[..0x8001].iter().map(|v| *v as f32).collect();
        let gamut = [curve(0x8C01), curve(0x9001), curve(0x9401)];
        let flat = shaper.iter().chain(gamut.iter().flatten()).copied().collect();
        Tables { shaper, gamut, out8: crate::lite::output_table(words), flat }
    }
}

pub fn gamut_compress<T: Real>(lin: [T; 3], curves: &[Vec<f32>; 3]) -> [T; 3] {
    let mx = if lin[1] > lin[0] { lin[1] } else { lin[0] };
    let mx = if lin[2] > mx { lin[2] } else { mx };
    let zero = T::lit(0.0);
    if !(mx > zero) {
        return lin;
    }
    let (c16, c4096) = (T::lit(16.0), T::lit(4096.0));
    let mut out = lin;
    for c in 0..3 {
        let d = (mx - lin[c]) / mx;
        if d > T::of(GAMUT_THRESHOLDS[c]) || mx >= T::lit(8.0) {
            let t = &curves[c];
            let r = (d * c4096).floor();
            let div = (r / c16).floor();
            let i = (div.wide() as i32).clamp(0, 0x3FF) as usize;
            let frac = r - div * c16;
            let v = if i < 0x3FF {
                // numpy's // on floats; a division by 16 is exact, so this is the same floor.
                T::of(t[i]) + ((frac * T::of(t[i + 1] - t[i]) + T::lit(8.0)) / c16).floor()
            } else {
                T::of(t[0x3FF])
            };
            out[c] = mx - mx * v / c4096;
        }
    }
    out
}

/// Linear (1.0 = 0x10000) -> cube grid coordinate 0..64. numpy: `v - i` of a float array and
/// an int32 array is float64, so the result is float64 whatever comes in.
#[inline]
pub fn shaper<T: Real>(lin: [T; 3], table: &[f32]) -> [f64; 3] {
    let (hi, zero) = (T::lit((0x80000 - 1) as f64), T::lit(0.0));
    lin.map(|l| {
        let s = l * T::lit(65536.0);
        let s = if s < zero { zero } else if s > hi { hi } else { s };
        let v = (s / T::lit(16.0)).wide();
        let i = v.floor() as usize;
        let f = v - i as f64;
        (table[i] as f64 + f * (table[i + 1] - table[i]) as f64) / 512.0
    })
}

/// Interpolation in an n^3 lattice [b][g][r][C], red fastest. The coordinates are float64 and
/// the node differences float32, as in numpy; the result lands in a float32 array.
#[inline]
pub fn tetrahedral<const C: usize>(cube: &[f32], n: usize, c: [f64; 3]) -> [f32; C] {
    let split = |v: f64| {
        let i = (v.floor() as usize).min(n - 2);
        (i, v - i as f64)
    };
    let ((ir, fr), (ig, fg), (ib, fb)) = (split(c[0]), split(c[1]), split(c[2]));
    let base = (ib * n * n + ig * n + ir) * C;
    let at = |db: usize, dg: usize, dr: usize| &cube[base + (db * n * n + dg * n + dr) * C..][..C];
    // Each tetrahedron walks c000 -> one axis -> two axes -> c111.
    let ((a, b), x1, x2, x3) = if fr >= fg && fg >= fb {
        ((at(0, 0, 1), at(0, 1, 1)), fr, fg, fb)
    } else if fr >= fb && fb > fg {
        ((at(0, 0, 1), at(1, 0, 1)), fr, fb, fg)
    } else if fb > fr && fr >= fg {
        ((at(1, 0, 0), at(1, 0, 1)), fb, fr, fg)
    } else if fg > fr && fr >= fb {
        ((at(0, 1, 0), at(0, 1, 1)), fg, fr, fb)
    } else if fg >= fb && fb > fr {
        ((at(0, 1, 0), at(1, 1, 0)), fg, fb, fr)
    } else {
        ((at(1, 0, 0), at(1, 1, 0)), fb, fg, fr)
    };
    let (c000, c111) = (at(0, 0, 0), at(1, 1, 1));
    std::array::from_fn(|i| {
        (c000[i] as f64 + x1 * (a[i] - c000[i]) as f64 + x2 * (b[i] - a[i]) as f64 + x3 * (c111[i] - b[i]) as f64) as f32
    })
}

pub struct Frame<'a> {
    pub rgb: &'a [u16],
    pub width: usize,
    pub height: usize,
    pub clip: [f32; 3],
    pub matrix: [[f32; 3]; 3],
    pub tables: &'a Tables,
    pub out8: [&'a [u8]; 3],
    pub cube: &'a [f32],
    pub gamut: bool,
    pub halo: Option<&'a Offsets>,
    pub grain: Option<(&'a Grain, &'a [i16])>,
}

impl Frame<'_> {
    /// Camera RGB -> linear. Before gamut compression, and float32 like numpy's.
    #[inline]
    pub fn linear(&self, px: &[u16]) -> [f32; 3] {
        let cam = [0, 1, 2].map(|c| (px[c] as f32 / 65535.0).min(self.clip[c]));
        self.matrix.map(|m| cam[0] * m[0] + cam[1] * m[1] + cam[2] * m[2])
    }

    #[inline]
    fn noise(&self, plane: &[i16], streams: usize, y: usize, x: usize) -> [i32; 3] {
        let i = y * self.width + x;
        let at = |s: usize| plane[s * self.width * self.height + i] as i32;
        if streams == 1 { [at(0), 0, 0] } else { [at(0), at(1), at(2)] }
    }

    /// Grid coordinates -> one output pixel.
    #[inline]
    pub fn finish(&self, g: [f64; 3], y: usize, x: usize, out: &mut [u8]) {
        let tetra: [f32; 3] = tetrahedral::<3>(self.cube, GRID, g);
        let mut o16 = tetra.map(|v| v.clamp(0.0, 65535.0) as i32);
        let mut n = [0; 3];
        if let Some((grain, plane)) = self.grain {
            n = self.noise(plane, grain.streams(), y, x);
            if !grain.simple {
                o16 = grain.apply16(o16, n);
            }
        }
        let mut px = [0, 1, 2].map(|c| {
            let i12 = (o16[c] as u32 * 0xFFF + 0x8000) >> 16;
            self.out8[c][i12 as usize]
        });
        if let Some((grain, _)) = self.grain {
            if grain.simple {
                px = grain.apply8(px, n[0]);
            }
        }
        out.copy_from_slice(&px);
    }

    /// RGB8, [y][x][3], in sensor orientation.
    pub fn develop(&self) -> Vec<u8> {
        let mut out = vec![0u8; self.width * self.height * 3];
        for (y, (row, dst)) in self.rgb.chunks_exact(self.width * 3).zip(out.chunks_exact_mut(self.width * 3)).enumerate() {
            for (x, (px, o)) in row.chunks_exact(3).zip(dst.chunks_exact_mut(3)).enumerate() {
                let lin = self.linear(px);
                let g = match self.halo {
                    Some(h) => {
                        let off = h.at(y, x);
                        let lin = [0, 1, 2].map(|c| lin[c] as f64 + off[c]);
                        shaper(if self.gamut { gamut_compress(lin, &self.tables.gamut) } else { lin }, &self.tables.shaper)
                    }
                    None => shaper(if self.gamut { gamut_compress(lin, &self.tables.gamut) } else { lin }, &self.tables.shaper),
                };
                self.finish(g, y, x, o);
            }
        }
        out
    }
}
