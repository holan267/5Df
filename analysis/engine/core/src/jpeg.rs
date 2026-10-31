//! JPEG output: rotation by EXIF orientation and the tags latent_app.py writes.
use crate::Result;
use jpeg_encoder::{ColorType, Encoder, SamplingFactor};

/// The develop() output turned upright. Pillow's ROTATE_270 is a quarter turn clockwise.
pub fn rotate(rgb: Vec<u8>, width: usize, height: usize, orientation: u32) -> (Vec<u8>, usize, usize) {
    let at = |x: usize, y: usize| &rgb[(y * width + x) * 3..][..3];
    let mut out = Vec::with_capacity(rgb.len());
    match orientation {
        3 => {
            for y in (0..height).rev() {
                for x in (0..width).rev() {
                    out.extend_from_slice(at(x, y));
                }
            }
            (out, width, height)
        }
        6 => {
            for x in 0..width {
                for y in (0..height).rev() {
                    out.extend_from_slice(at(x, y));
                }
            }
            (out, height, width)
        }
        8 => {
            for x in (0..width).rev() {
                for y in 0..height {
                    out.extend_from_slice(at(x, y));
                }
            }
            (out, height, width)
        }
        _ => (rgb, width, height),
    }
}

/// APP1 payload: one little-endian IFD of ASCII tags, sorted by tag.
fn exif(tags: &[(u16, &str)]) -> Vec<u8> {
    let mut out = b"Exif\0\0II*\0\x08\0\0\0".to_vec();
    let tiff = 6;
    out.extend((tags.len() as u16).to_le_bytes());
    let mut tail = 8 + 2 + 12 * tags.len() + 4;
    let mut body = Vec::new();
    for (tag, text) in tags {
        let n = text.len() + 1;
        out.extend(tag.to_le_bytes());
        out.extend(2u16.to_le_bytes());
        out.extend((n as u32).to_le_bytes());
        if n <= 4 {
            let mut v = [0u8; 4];
            v[..text.len()].copy_from_slice(text.as_bytes());
            out.extend(v);
        } else {
            out.extend((tail as u32).to_le_bytes());
            body.extend(text.as_bytes());
            body.push(0);
            tail += n;
        }
    }
    out.extend(0u32.to_le_bytes());
    debug_assert_eq!(out.len() - tiff, 8 + 2 + 12 * tags.len() + 4);
    out.extend(body);
    out
}

/// 4:2:0 and the standard tables, as Pillow's defaults.
pub fn encode(rgb: &[u8], width: usize, height: usize, quality: u8, tags: &[(u16, &str)]) -> Result<Vec<u8>> {
    let mut out = Vec::with_capacity(rgb.len() / 4);
    let mut e = Encoder::new(&mut out, quality);
    e.set_sampling_factor(SamplingFactor::R_4_2_0);
    e.add_app_segment(1, &exif(tags)).map_err(|e| e.to_string())?;
    e.encode(rgb, width as u16, height as u16, ColorType::Rgb).map_err(|e| e.to_string())?;
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::rotate;

    // Pixels of a 3 x 2 picture, numbered in reading order, in the red channel.
    fn turned(orientation: u32) -> (Vec<u8>, usize, usize) {
        let rgb = (0..6u8).flat_map(|v| [v, 0, 0]).collect();
        let (out, w, h) = rotate(rgb, 3, 2, orientation);
        (out.chunks_exact(3).map(|p| p[0]).collect(), w, h)
    }

    #[test]
    fn rotations_are_pillows() {
        assert_eq!(turned(1), (vec![0, 1, 2, 3, 4, 5], 3, 2));
        assert_eq!(turned(3), (vec![5, 4, 3, 2, 1, 0], 3, 2));
        assert_eq!(turned(6), (vec![3, 0, 4, 1, 5, 2], 2, 3));    // ROTATE_270, clockwise
        assert_eq!(turned(8), (vec![2, 5, 1, 4, 0, 3], 2, 3));    // ROTATE_90
    }
}
