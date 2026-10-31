//! Grain, tools/latent_effects.py.
use crate::develop::tetrahedral;
use crate::firmware::Firmware;
use crate::Result;

const GAUSS_TABLE: usize = 0x9A8F7C;

pub fn fnv1a_seed(text: &str) -> u32 {
    text.bytes().fold(0x811C9DC5u32, |h, c| (h ^ c as u32).wrapping_mul(0x01000193)) | 1
}

fn xorshift(mut x: u32) -> u32 {
    x ^= x << 13;
    x ^= x >> 17;
    x ^ (x << 5)
}

/// Noise planes, [stream][y][x], as FUN_009912ec builds them row by row. Rows -2 and -1 only
/// prime the vertical filter. A filtered value is at most 21 * 36 = 756, so i16 holds it.
pub fn grain_noise(fw: &Firmware, seed: u32, height: usize, width: usize, streams: usize) -> Result<Vec<i16>> {
    let gauss: Vec<i32> = fw.bytes(GAUSS_TABLE, 256)?.iter().map(|b| *b as i8 as i32).collect();
    let groups = (width + 3) / 4;
    let mut out = Vec::with_capacity(streams * height * width);
    // Horizontal filter output of the last three rows.
    let mut h = [vec![0i32; 4 * groups], vec![0i32; 4 * groups], vec![0i32; 4 * groups]];
    let mut s = vec![0i32; 4 * groups + 2];
    for k in 0..streams as u32 {
        for row in -2..height as i64 {
            let mut x = (row as u32).wrapping_mul(0x9E3779B9) ^ seed ^ k.wrapping_mul(0x2545F491);
            x ^= x >> 16;
            x = x.wrapping_mul(0x85EBCA6B);
            x ^= x >> 13;
            x = x.wrapping_mul(0xC2B2AE35);
            let degenerate = x == 0;
            x = xorshift(x ^ (x >> 16));
            s[0] = gauss[(x & 0xFF) as usize];
            s[1] = gauss[((x >> 8) & 0xFF) as usize];
            if degenerate {
                x = 0x40AEC71F;
                s[0] = -8;
                s[1] = 5;
            }
            for g in 0..groups {
                x = xorshift(x);
                for j in 0..4 {
                    s[2 + 4 * g + j] = gauss[((x >> (8 * j)) & 0xFF) as usize];
                }
            }
            h.rotate_left(1);
            for (i, v) in h[2].iter_mut().enumerate() {
                *v = s[i] + 4 * s[i + 1] + s[i + 2];
            }
            if row >= 0 {
                out.extend((0..width).map(|i| (h[0][i] + 4 * h[1][i] + h[2][i]) as i16));
            }
        }
    }
    Ok(out)
}

pub struct Grain {
    pub mono: bool,
    pub simple: bool,
    pub amp: Vec<i32>,        // [channel][level] when simple
    pub pre: Vec<i32>,        // [channel][1024]
    pub lattice: Vec<f32>,    // [17][17][17][6]
    pub gpu: Vec<f32>,        // the shader's `grain`: amp, or pre then lattice
}

impl Grain {
    pub fn new(blk: &[u8], level: usize) -> Result<Grain> {
        if blk.len() != crate::lite::GRAIN_BLOCK || &blk[..8] != b"LTGRAIN4" {
            return Err("bad LTGRAIN4 block".into());
        }
        let (mono, simple) = (blk[8] & 1 != 0, blk[8] & 2 != 0);
        let mut g = Grain { mono, simple, amp: vec![], pre: vec![], lattice: vec![], gpu: vec![] };
        if simple {
            let lvl = if level < 12 { level } else { 5 };
            g.amp = blk[0xC + lvl * 0x300..][..0x300].iter().map(|b| *b as i32).collect();
            g.gpu = g.amp.iter().map(|v| *v as f32).collect();
        } else {
            g.pre = blk[0xC..][..6144].chunks_exact(2).map(|b| u16::from_le_bytes([b[0], b[1]]) as i32).collect();
            g.lattice = blk[0x180C..][..17 * 17 * 17 * 12].chunks_exact(2).map(|b| i16::from_le_bytes([b[0], b[1]]) as f32).collect();
            g.gpu = g.pre.iter().map(|v| *v as f32).chain(g.lattice.iter().copied()).collect();
        }
        Ok(g)
    }

    pub fn streams(&self) -> usize {
        if self.mono { 1 } else { 3 }
    }

    /// Lattice mode, on the 16-bit cube output. `n` is the pixel's noise, one per stream.
    #[inline]
    pub fn apply16(&self, v: [i32; 3], n: [i32; 3]) -> [i32; 3] {
        let coords = [0, 1, 2].map(|c| {
            let idx = if v[c] < 0x400 { v[c] >> 1 } else { (v[c] >> 7) + 0x1F8 };
            let e = self.pre[c * 1024 + idx.min(1023) as usize];
            (e >> 11) as f64 + (e & 0x7FF) as f64 / 2048.0
        });
        let lm = tetrahedral::<6>(&self.lattice, 17, coords).map(|t| t.floor() as i32);
        let d = if self.mono {
            [(lm[0] * n[0]) >> 7, (lm[1] * n[0]) >> 7, (lm[3] * n[0]) >> 7]
        } else {
            [(lm[0] * n[0]) >> 7, (lm[1] * n[0] + lm[2] * n[1]) >> 7, (lm[3] * n[0] + lm[4] * n[1] + lm[5] * n[2]) >> 7]
        };
        [0, 1, 2].map(|c| (v[c] + d[c]).clamp(0, 0xFFFF))
    }

    /// Simple mode, on the 8-bit output.
    #[inline]
    pub fn apply8(&self, v: [u8; 3], n0: i32) -> [u8; 3] {
        [0, 1, 2].map(|c| {
            let a = self.amp[c * 256 + v[c] as usize];
            (v[c] as i32 + ((n0 * a + 0x400) >> 11)).clamp(0, 255) as u8
        })
    }
}
