//! Lite film packs, tools/latent_lite.py (the format is described there; the two change
//! together), and the cube selection of latent_develop.py.
use crate::Result;
use serde::Deserialize;

pub const GRID: usize = 65;
pub const NODES: usize = GRID * GRID * GRID;
pub const GRAIN_BLOCK: usize = 0xFE58;
const GRAIN_PRE: usize = 6;
const GRAIN_LATTICE: usize = 6 + 3 * 1024;

/// B&W papers after the first have no cubes of their own: only push_rows, empty.
#[derive(Deserialize)]
pub struct Paper {
    pub file: Option<String>,
    #[serde(default)]
    pub delta: f64,
    pub push_rows: Vec<usize>,
    #[serde(default)]
    pub push_w: Vec<Vec<f64>>,
    #[serde(default)]
    pub light_w: Vec<Vec<f64>>,
}

#[derive(Deserialize)]
pub struct Film {
    pub code: String,
    pub light_mired: Vec<f64>,
    pub push: Vec<i32>,
    pub grade: Vec<u32>,
    pub extra: Vec<i32>,
    pub papers: Vec<Paper>,
    pub curve_map: Vec<usize>,
}

/// What select_cubes() picks.
#[derive(Debug, PartialEq)]
pub struct Selection {
    pub i0: usize,
    pub i1: usize,
    pub weight: f64,
    /// Offset of the 3 x 4096 LTVC curves in curves.bin, for B&W papers.
    pub curves: Option<usize>,
}

pub fn inflate(blob: &[u8]) -> Result<Vec<u8>> {
    miniz_oxide::inflate::decompress_to_vec_zlib(blob).map_err(|e| format!("bad zlib data: {e:?}"))
}

/// tables.bin.
pub fn tables(blob: &[u8]) -> Result<Vec<u16>> {
    Ok(inflate(blob)?.chunks_exact(2).map(|b| u16::from_le_bytes([b[0], b[1]])).collect())
}

/// The 4096-entry output table, 12 bits in, 8 bits out, from the pack's words.
pub fn output_table(tables: &[u16]) -> Vec<u8> {
    tables[0x8001..0x8801].iter().flat_map(|w| w.to_le_bytes()).collect()
}

/// Smooth, strictly increasing form of the output table.
pub fn output_curve(tables: &[u16]) -> Vec<f64> {
    const K: usize = 9;
    let out8 = output_table(tables);
    let at = |i: usize| out8[i.saturating_sub(K).min(4095)] as f64;   // padded with the edge values
    let w = 1.0 / (2 * K + 1) as f64;
    let mut best = f64::NEG_INFINITY;
    (0..4096)
        .map(|n| {
            let mut sum = 0.0;
            for j in 0..2 * K + 1 {
                sum += at(n + j) * w;
            }
            best = best.max(sum + n as f64 * 1e-6);
            best
        })
        .collect()
}

/// [basis][channel][z][y][x] floats: u32 n_over, u32 over[], u8 zz[k * 3 * NODES].
pub fn decode_basis(blob: &[u8], delta: f64, k: usize) -> Result<Vec<f32>> {
    let raw = inflate(blob)?;
    let word = |o: usize| raw.get(o..o + 4).map(|b| u32::from_le_bytes(b.try_into().unwrap()));
    let n_over = word(0).ok_or("short paper file")? as usize;
    let size = 3 * NODES;
    let body = 4 + 4 * n_over;
    if raw.len() != body + k * size {
        return Err(format!("paper file is {} bytes, expected {}", raw.len(), body + k * size));
    }
    let mut out = vec![0f32; k * size];
    let mut q = vec![0i32; size];
    let mut used = 0;
    for b in 0..k {
        for (i, v) in q.iter_mut().enumerate() {
            let mut zz = raw[body + b * size + i] as i32;
            if zz == 255 {
                zz = word(4 + 4 * used).ok_or("over table ran out")? as i32;
                used += 1;
            }
            *v = (zz >> 1) ^ -(zz & 1);
        }
        for channel in q.chunks_exact_mut(NODES) {
            cumsum3(channel);
        }
        for (o, v) in out[b * size..(b + 1) * size].iter_mut().zip(&q) {
            *o = (*v as f64 * delta) as f32;
        }
    }
    Ok(out)
}

/// Cumulative sums along x, y and z of one [z][y][x] channel.
fn cumsum3(c: &mut [i32]) {
    for row in c.chunks_exact_mut(GRID) {
        for x in 1..GRID {
            row[x] = row[x].wrapping_add(row[x - 1]);
        }
    }
    for plane in c.chunks_exact_mut(GRID * GRID) {
        for i in GRID..GRID * GRID {
            plane[i] = plane[i].wrapping_add(plane[i - GRID]);
        }
    }
    for i in GRID * GRID..NODES {
        c[i] = c[i].wrapping_add(c[i - GRID * GRID]);
    }
}

/// np.interp(y, curve, arange(4096)) / 4095 * 65535.
fn from_levels(y: f64, curve: &[f64]) -> f64 {
    let n = curve.len();
    let v = if y < curve[0] {
        0.0
    } else if y >= curve[n - 1] {
        (n - 1) as f64
    } else {
        let j = curve.partition_point(|v| *v <= y) - 1;
        if curve[j] == y { j as f64 } else { (y - curve[j]) / (curve[j + 1] - curve[j]) + j as f64 }
    };
    v / 4095.0 * 65535.0
}

/// LitePack.cube16: one cube from a paper's bases, [b][g][r][channel] float32 0..65535.
pub fn cube16(film: &Film, basis: &[f32], curve: &[f64], idx: usize) -> Result<Vec<f32>> {
    let (n_light, n_push) = (film.light_mired.len(), film.push.len());
    let (grade_i, push_i, light_i) = (idx / (n_push * n_light), (idx / n_light) % n_push, idx % n_light);
    let paper = film.papers.get(grade_i).ok_or_else(|| format!("no cube at index {idx}"))?;
    let row = paper.push_rows.iter().position(|p| *p == push_i).ok_or_else(|| format!("no cube at index {idx}"))?;
    let size = 3 * NODES;
    let mut y = vec![0f32; size];
    let mut b = 0;
    for pw in &paper.push_w[row] {
        for lw in &paper.light_w[light_i] {
            let w = (pw * lw) as f32;
            for (o, v) in y.iter_mut().zip(&basis[b * size..(b + 1) * size]) {
                *o += w * v;
            }
            b += 1;
        }
    }
    let mut out = vec![0f32; size];
    for c in 0..3 {
        for n in 0..NODES {
            out[n * 3 + c] = from_levels(y[c * NODES + n] as f64, curve) as f32;
        }
    }
    Ok(out)
}

/// Studio.cube: per-node blend of two cubes. numpy keeps float32 here.
pub fn blend(c0: &[f32], c1: &[f32], w: f64) -> Vec<f32> {
    let (a, b) = ((1.0 - w) as f32, w as f32);
    c0.iter().zip(c1).map(|(p, q)| a * p + b * q).collect()
}

/// grain<i>.bin -> the LTGRAIN4 blocks of paper i, one per push, concatenated.
pub fn decode_grain(blob: &[u8], n_push: usize) -> Result<Vec<u8>> {
    let (flag, rest) = blob.split_first().ok_or("empty grain file")?;
    let raw = inflate(rest)?;
    if raw.len() != n_push * GRAIN_BLOCK {
        return Err(format!("grain file holds {} bytes, expected {}", raw.len(), n_push * GRAIN_BLOCK));
    }
    if *flag != 0 {
        let mut out = raw;
        for i in GRAIN_BLOCK..out.len() {
            out[i] = out[i].wrapping_add(out[i - GRAIN_BLOCK]);
        }
        return Ok(out);
    }
    let n = raw.len() / 2;
    let mut w: Vec<i16> = (0..n).map(|i| i16::from_le_bytes([raw[i], raw[n + i]])).collect();
    let words = GRAIN_BLOCK / 2;
    for i in words..n {
        w[i] = w[i].wrapping_add(w[i - words]);
    }
    for block in w.chunks_exact_mut(words) {
        for table in block[GRAIN_PRE..GRAIN_LATTICE].chunks_exact_mut(1024) {
            for i in 1..1024 {
                table[i] = table[i].wrapping_add(table[i - 1]);
            }
        }
        let lattice = &mut block[GRAIN_LATTICE..];
        for step in [17 * 17 * 6, 17 * 6, 6] {
            let extent = step * 17;
            for run in lattice.chunks_exact_mut(extent) {
                for i in step..extent {
                    run[i] = run[i].wrapping_add(run[i - step]);
                }
            }
        }
    }
    Ok(w.iter().flat_map(|v| v.to_le_bytes()).collect())
}

fn light_steps(mireds: &[f64], m: f64) -> (usize, usize, f64) {
    let last = mireds.len() - 1;
    if m <= mireds[0] {
        return (0, 0, 0.0);
    }
    if m >= mireds[last] {
        return (last, last, 0.0);
    }
    let j = mireds.iter().position(|v| *v >= m).unwrap();
    (j - 1, j, (m - mireds[j - 1]) / (mireds[j] - mireds[j - 1]))
}

pub fn select_cubes(film: &Film, paper: usize, push: i32, grade: usize, mired: f64) -> Result<Selection> {
    if paper >= film.grade.len() {
        return Err(format!("paper index must be 0..{}", film.grade.len() as i64 - 1));
    }
    let mut push_i = film.push.iter().position(|p| *p == push).ok_or_else(|| format!("push must be one of {:?}", film.push))?;
    let (mut paper_i, mut curves) = (paper, None);
    if film.grade[paper] & 0x80 != 0 {
        // B&W papers share the cube row of the first flagged paper at push index 0; the
        // chosen paper, push and grade select an LTVC block of output curves instead.
        if grade >= film.extra.len() {
            return Err(format!("grade must be 0..{}", film.extra.len() as i64 - 1));
        }
        let i = film.curve_map[(paper * film.push.len() + push_i) * film.extra.len() + grade];
        if i == 0 {
            return Err("no paper curve for this paper/push/grade".into());
        }
        curves = Some((i - 1) * 0x3000);
        paper_i = film.grade.iter().position(|g| g & 0x80 != 0).unwrap();
        push_i = 0;
    }
    let (i0, i1, weight) = light_steps(&film.light_mired, mired);
    let base = (paper_i * film.push.len() + push_i) * film.light_mired.len();
    Ok(Selection { i0: base + i0, i1: base + i1, weight, curves })
}
