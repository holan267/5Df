// C ABI over LibRaw for the Rust side (wasm/src/raw.rs). LibRaw throws C++ exceptions and
// Rust is built with panic=abort, so nothing may unwind past this file.
#include <cstdint>
#include <cstring>
#include <new>

#include "libraw/libraw.h"

extern "C" {

struct LrMeta {
  char make[64], model[64];
  uint32_t raw_width, raw_height, width, height, top_margin, left_margin;
  uint32_t crop_left, crop_top, crop_width, crop_height;
  int32_t flip, colors;
  uint32_t filters;
  uint32_t black, cblack[4], maximum, linear_max[4];
  float cam_mul[4], pre_mul[4], cam_xyz[4][3];
};

struct LrImage {
  const void *data;   // owned by `handle`, until lr_image_free
  uint32_t size, width, height, colors, bits, type;
  void *handle;
};

LibRaw *lr_open(const uint8_t *data, size_t size, int *err) {
  LibRaw *r = new (std::nothrow) LibRaw(LIBRAW_OPTIONS_NONE);
  if (!r) {
    *err = LIBRAW_UNSUFFICIENT_MEMORY;
    return nullptr;
  }
  try {
    *err = r->open_buffer(data, size);
    if (*err == LIBRAW_SUCCESS) *err = r->unpack();
  } catch (...) {
    *err = LIBRAW_UNSPECIFIED_ERROR;
  }
  if (*err != LIBRAW_SUCCESS) {
    delete r;
    return nullptr;
  }
  return r;
}

void lr_close(LibRaw *r) { delete r; }

const char *lr_strerror(int err) { return libraw_strerror(err); }

// As rawpy reads them: from rawdata.color, once unpacked.
void lr_meta(LibRaw *r, LrMeta *m) {
  const libraw_data_t &d = r->imgdata;
  const libraw_colordata_t &c = d.rawdata.color;
  std::memset(m, 0, sizeof *m);
  std::strncpy(m->make, d.idata.make, sizeof m->make - 1);
  std::strncpy(m->model, d.idata.model, sizeof m->model - 1);
  m->raw_width = d.sizes.raw_width;
  m->raw_height = d.sizes.raw_height;
  m->width = d.sizes.width;
  m->height = d.sizes.height;
  m->top_margin = d.sizes.top_margin;
  m->left_margin = d.sizes.left_margin;
  m->crop_left = d.sizes.raw_inset_crops[0].cleft;
  m->crop_top = d.sizes.raw_inset_crops[0].ctop;
  m->crop_width = d.sizes.raw_inset_crops[0].cwidth;
  m->crop_height = d.sizes.raw_inset_crops[0].cheight;
  m->flip = d.sizes.flip;
  m->colors = d.idata.colors;
  m->filters = d.idata.filters;
  m->black = c.black;
  m->maximum = c.maximum;
  for (int i = 0; i < 4; i++) {
    m->cblack[i] = c.cblack[i];
    m->linear_max[i] = c.linear_max[i];
    m->cam_mul[i] = c.cam_mul[i];
    m->pre_mul[i] = c.pre_mul[i];
    for (int j = 0; j < 3; j++) m->cam_xyz[i][j] = c.cam_xyz[i][j];
  }
}

// latent_develop.load_rgb's postprocess(). Everything is set each time: params stay
// between calls, and one handle decodes at more than one size.
int lr_decode(LibRaw *r, int half, int black, int white, LrImage *out) {
  libraw_output_params_t &p = r->imgdata.params;
  p.output_color = 0;
  p.gamm[0] = 1.0;
  p.gamm[1] = 1.0;
  p.no_auto_bright = 1;
  p.use_camera_wb = 0;
  p.use_auto_wb = 0;
  for (int i = 0; i < 4; i++) p.user_mul[i] = 1.0f;
  p.user_black = black;
  p.user_sat = white;
  p.output_bps = 16;
  p.half_size = half;
  p.highlight = 0;
  p.user_flip = 0;
  p.user_qual = 3;  // AHD
  try {
    int err = r->dcraw_process();
    if (err != LIBRAW_SUCCESS) return err;
    libraw_processed_image_t *img = r->dcraw_make_mem_image(&err);
    if (!img) return err;
    r->free_image();
    *out = {img->data, img->data_size, img->width, img->height, img->colors, img->bits, (uint32_t)img->type, img};
    return LIBRAW_SUCCESS;
  } catch (...) {
    return LIBRAW_UNSPECIFIED_ERROR;
  }
}

int lr_thumb(LibRaw *r, LrImage *out) {
  try {
    int err = r->unpack_thumb();
    if (err != LIBRAW_SUCCESS) return err;
    libraw_processed_image_t *img = r->dcraw_make_mem_thumb(&err);
    if (!img) return err;
    *out = {img->data, img->data_size, img->width, img->height, img->colors, img->bits, (uint32_t)img->type, img};
    return LIBRAW_SUCCESS;
  } catch (...) {
    return LIBRAW_UNSPECIFIED_ERROR;
  }
}

void lr_image_free(LrImage *img) {
  LibRaw::dcraw_clear_mem(static_cast<libraw_processed_image_t *>(img->handle));
}

}  // extern "C"
