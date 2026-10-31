//! Rust side of cpp/libraw_shim.cpp. The structs mirror LrMeta and LrImage.
use std::ffi::{c_char, c_int, c_void, CStr};
use std::ptr;

#[repr(C)]
pub struct Meta {
    pub make: [u8; 64],
    pub model: [u8; 64],
    pub raw_width: u32,
    pub raw_height: u32,
    pub width: u32,
    pub height: u32,
    pub top_margin: u32,
    pub left_margin: u32,
    pub crop_left: u32,
    pub crop_top: u32,
    pub crop_width: u32,
    pub crop_height: u32,
    pub flip: i32,
    pub colors: i32,
    pub filters: u32,
    pub black: u32,
    pub cblack: [u32; 4],
    pub maximum: u32,
    pub linear_max: [u32; 4],
    pub cam_mul: [f32; 4],
    pub pre_mul: [f32; 4],
    pub cam_xyz: [[f32; 3]; 4],
}

#[repr(C)]
struct LrImage {
    data: *const u8,
    size: u32,
    width: u32,
    height: u32,
    colors: u32,
    bits: u32,
    kind: u32,
    handle: *mut c_void,
}

extern "C" {
    fn lr_open(data: *const u8, size: usize, err: *mut c_int) -> *mut c_void;
    fn lr_close(r: *mut c_void);
    fn lr_strerror(err: c_int) -> *const c_char;
    fn lr_meta(r: *mut c_void, m: *mut Meta);
    fn lr_decode(r: *mut c_void, half: c_int, black: c_int, white: c_int, out: *mut LrImage) -> c_int;
    fn lr_thumb(r: *mut c_void, out: *mut LrImage) -> c_int;
    fn lr_image_free(img: *mut LrImage);
}

pub struct Thumb {
    pub data: Vec<u8>,
    pub jpeg: bool,
    pub width: u32,
    pub height: u32,
}

fn message(err: c_int) -> String {
    unsafe { CStr::from_ptr(lr_strerror(err)) }.to_string_lossy().into_owned()
}

/// An open, unpacked raw. `data` must outlive it: LibRaw reads from the buffer.
pub struct Raw(*mut c_void);

impl Raw {
    pub fn open(data: &[u8]) -> Result<Raw, String> {
        let mut err = 0;
        let r = unsafe { lr_open(data.as_ptr(), data.len(), &mut err) };
        if r.is_null() { Err(message(err)) } else { Ok(Raw(r)) }
    }

    pub fn meta(&self) -> Meta {
        let mut m = std::mem::MaybeUninit::<Meta>::uninit();
        unsafe {
            lr_meta(self.0, m.as_mut_ptr());
            m.assume_init()
        }
    }

    /// Demosaiced camera RGB, u16 and 3 channels, as (pixels, width, height).
    pub fn decode(&mut self, half: bool, black: i32, white: i32) -> Result<(Vec<u16>, usize, usize), String> {
        let mut img = LrImage { data: ptr::null(), size: 0, width: 0, height: 0, colors: 0, bits: 0, kind: 0, handle: ptr::null_mut() };
        let err = unsafe { lr_decode(self.0, half as c_int, black, white, &mut img) };
        if err != 0 {
            return Err(message(err));
        }
        let (w, h) = (img.width as usize, img.height as usize);
        let rgb = unsafe { std::slice::from_raw_parts(img.data as *const u16, w * h * 3) }.to_vec();
        unsafe { lr_image_free(&mut img) };
        Ok((rgb, w, h))
    }

    /// The embedded preview: a JPEG file, or 8-bit RGB.
    pub fn thumb(&mut self) -> Result<Thumb, String> {
        let mut img = LrImage { data: ptr::null(), size: 0, width: 0, height: 0, colors: 0, bits: 0, kind: 0, handle: ptr::null_mut() };
        let err = unsafe { lr_thumb(self.0, &mut img) };
        if err != 0 {
            return Err(message(err));
        }
        let data = unsafe { std::slice::from_raw_parts(img.data, img.size as usize) }.to_vec();
        let t = Thumb { data, jpeg: img.kind == 1, width: img.width, height: img.height };
        unsafe { lr_image_free(&mut img) };
        Ok(t)
    }
}

impl Drop for Raw {
    fn drop(&mut self) {
        unsafe { lr_close(self.0) }
    }
}
