//! The camera -> cube-input matrix, tools/latent_color.py. All in doubles, as the firmware.
use crate::firmware::Firmware;
use crate::Result;

pub type M3 = [[f64; 3]; 3];

const CAMERA_TABLE: usize = 0x9A9080;
const BRADFORD: usize = 0x9A8CD0;
const XYZ_TO_RGB: usize = 0x9A8D18;
const D50: [f64; 3] = [0.9642956764295677, 1.0, 0.8251046025104602];
const D65: [f64; 3] = [0.9504559270516716, 1.0, 1.0890577507598784];
const LATENT_EXPOSURE_OFFSET: f64 = 0.943;

fn m3(f: &[f64]) -> M3 {
    [[f[0], f[1], f[2]], [f[3], f[4], f[5]], [f[6], f[7], f[8]]]
}

fn mul(a: &M3, b: &M3) -> M3 {
    let mut out = [[0.0; 3]; 3];
    for i in 0..3 {
        for j in 0..3 {
            out[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
        }
    }
    out
}

pub fn mv(a: &M3, v: [f64; 3]) -> [f64; 3] {
    [0, 1, 2].map(|i| a[i][0] * v[0] + a[i][1] * v[1] + a[i][2] * v[2])
}

pub fn inv(m: &M3) -> M3 {
    let [[a, b, c], [d, e, f], [g, h, i]] = *m;
    let det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
    [
        [(e * i - f * h) / det, (c * h - b * i) / det, (b * f - c * e) / det],
        [(f * g - d * i) / det, (a * i - c * g) / det, (c * d - a * f) / det],
        [(d * h - e * g) / det, (b * g - a * h) / det, (a * e - b * d) / det],
    ]
}

fn bradford(mb: &M3, src: [f64; 3], dst: [f64; 3]) -> M3 {
    let (s, d) = (mv(mb, src), mv(mb, dst));
    let diag = [[d[0] / s[0], 0.0, 0.0], [0.0, d[1] / s[1], 0.0], [0.0, 0.0, d[2] / s[2]]];
    mul(&inv(mb), &mul(&diag, mb))
}

pub struct CameraTable {
    pub model: String,
    pub color_matrix: M3,
    pub black: u32,
    pub white: u32,
    pub baseline: f64,
}

pub fn camera_table(fw: &Firmware) -> Result<CameraTable> {
    let [black, white] = [fw.u32(CAMERA_TABLE + 0x50)?, fw.u32(CAMERA_TABLE + 0x54)?];
    Ok(CameraTable {
        model: fw.text(fw.u32(CAMERA_TABLE)? as usize)?,
        color_matrix: m3(&fw.f64s(CAMERA_TABLE + 8, 9)?),
        black,
        white,
        baseline: fw.f64s(CAMERA_TABLE + 0x68, 1)?[0],
    })
}

/// FUN_009944b0 for any XYZ->camera ColorMatrix. `baseline` in EV.
pub fn colour_matrix(fw: &Firmware, cm: &M3, baseline: f64, wb: [f64; 3]) -> Result<M3> {
    let [wb_r, wb_g, wb_b] = wb;
    let mb = m3(&fw.f64s(BRADFORD, 9)?);
    let t = m3(&fw.f64s(XYZ_TO_RGB, 9)?);
    let minv = inv(cm);
    let [x, y, z] = mv(&minv, [wb_g / wb_r, 1.0, wb_g / wb_b]);
    let white_xyz = [x / y, 1.0, z / y];
    let m = mul(&t, &mul(&bradford(&mb, D50, D65), &mul(&bradford(&mb, white_xyz, D50), &minv)));
    let scale = (baseline + LATENT_EXPOSURE_OFFSET).exp2();
    Ok(m.map(|row| row.map(|v| v * scale)))
}
