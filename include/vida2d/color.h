#ifndef INCLUDE_VIDA2D_COLOR_H_
#define INCLUDE_VIDA2D_COLOR_H_

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
} vida2d_color_t;

#define V2D_OPAQUE 255
#define V2D_TRANSPARENT 0
#define V2D_TRANSLUCID 127

static inline vida2d_color_t vida2d_color(int r, int g, int b, int a) {
  return (vida2d_color_t){
      .r = r,
      .g = g,
      .b = b,
      .a = a,
  };
}

static inline vida2d_color_t vida2d_opaque_color(int r, int g, int b) {
  return (vida2d_color_t){
      .r = r,
      .g = g,
      .b = b,
      .a = V2D_OPAQUE,
  };
}

extern const vida2d_color_t vida2d_white;
extern const vida2d_color_t vida2d_black;
extern const vida2d_color_t vida2d_red;
extern const vida2d_color_t vida2d_green;
extern const vida2d_color_t vida2d_blue;

#endif // !INCLUDE_VIDA2D_COLOR_H_
