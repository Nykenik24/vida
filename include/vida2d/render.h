#ifndef INCLUDE_VIDA2D_RENDER_H_
#define INCLUDE_VIDA2D_RENDER_H_

#include "vida2d.h"
#include "vida2d/color.h"
#include "vida2d/status.h"
#include "vida2d/vec.h"

typedef enum {
  V2D_DRAW_FILLED,
  V2D_DRAW_EMPTY,
} vida2d_draw_mode_t;

vida2d_status_t vida2d_draw_point(vida2D_t *ctx, vida2d_vec2_t pos);

vida2d_status_t vida2d_draw_line(vida2D_t *ctx, vida2d_vec2_t start,
                                 vida2d_vec2_t end);

vida2d_status_t vida2d_draw_rect(vida2D_t *ctx, vida2d_draw_mode_t mode,
                                 vida2d_vec2_t pos, vida2d_vec2_t size);

vida2d_status_t vida2d_draw_triangle(vida2D_t *ctx, vida2d_draw_mode_t mode,
                                     vida2d_vec2_t p1, vida2d_vec2_t p2,
                                     vida2d_vec2_t p3);

vida2d_status_t vida2d_draw_circle(vida2D_t *ctx, vida2d_draw_mode_t mode,
                                   vida2d_vec2_t center, float radius);

vida2d_status_t vida2d_set_color(vida2D_t *ctx, vida2d_color_t color);

#endif // !INCLUDE_VIDA2D_RENDER_H_
