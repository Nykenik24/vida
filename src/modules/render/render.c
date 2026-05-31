#include "vida2d/render.h"
#include "vida2d.h"
#include "vida2d/color.h"
#include "vida2d/status.h"
#include "vida2d/vec.h"

vida2d_status_t vida2d_draw_point(vida2d_vec2_t pos) {
  return SDL_RenderPoint(vida2d_get_global_ctx()->renderer, pos.x, pos.y);
}

vida2d_status_t vida2d_draw_line(vida2d_vec2_t start, vida2d_vec2_t end) {
  return SDL_RenderLine(vida2d_get_global_ctx()->renderer, start.x, start.y,
                        end.x, end.y);
}

vida2d_status_t vida2d_draw_rect(vida2d_draw_mode_t mode, vida2d_vec2_t pos,
                                 vida2d_vec2_t size) {
  vida2D_t *ctx = vida2d_get_global_ctx();
  SDL_FRect rect;
  rect.x = pos.x;
  rect.y = pos.y;
  rect.w = size.x;
  rect.h = size.y;

  bool ret = true;
  switch (mode) {
  case V2D_DRAW_EMPTY:
    ret = SDL_RenderRect(ctx->renderer, &rect);
  case V2D_DRAW_FILLED:
    ret = SDL_RenderFillRect(ctx->renderer, &rect);
  }

  return ret;
}

vida2d_status_t vida2d_draw_triangle(vida2d_draw_mode_t mode, vida2d_vec2_t p1,
                                     vida2d_vec2_t p2, vida2d_vec2_t p3) {
  vida2D_t *ctx = vida2d_get_global_ctx();
  switch (mode) {
  case V2D_DRAW_EMPTY:
    V2D_CHECK(SDL_RenderLine(ctx->renderer, p1.x, p1.y, p2.x, p2.y));
    V2D_CHECK(SDL_RenderLine(ctx->renderer, p2.x, p2.y, p3.x, p3.y));
    V2D_CHECK(SDL_RenderLine(ctx->renderer, p3.x, p3.y, p1.x, p1.y));
    return V2D_STATUS_OK;

  case V2D_DRAW_FILLED: {
    vida2d_color_t c;
    SDL_GetRenderDrawColor(ctx->renderer, &c.r, &c.g, &c.b, &c.a);

    SDL_FColor fc = {
        c.r / 255.0f,
        c.g / 255.0f,
        c.b / 255.0f,
        c.a / 255.0f,
    };

    SDL_Vertex verts[3] = {
        {{p1.x, p1.y}, fc, {0, 0}},
        {{p2.x, p2.y}, fc, {0, 0}},
        {{p3.x, p3.y}, fc, {0, 0}},
    };

    return SDL_RenderGeometry(ctx->renderer, NULL, verts, 3, NULL, 0);
  }
  }
}

vida2d_status_t vida2d_draw_circle(vida2d_draw_mode_t mode,
                                   vida2d_vec2_t center, float radius) {
  vida2D_t *ctx = vida2d_get_global_ctx();
  switch (mode) {
  case V2D_DRAW_EMPTY: {
    int x = radius, y = 0, err = 0;
    float cx = center.x;
    float cy = center.y;
    SDL_Renderer *r = ctx->renderer;
    while (x >= y) {
      V2D_CHECK(SDL_RenderPoint(r, cx + x, cy + y));
      V2D_CHECK(SDL_RenderPoint(r, cx + y, cy + x));
      V2D_CHECK(SDL_RenderPoint(r, cx - y, cy + x));
      V2D_CHECK(SDL_RenderPoint(r, cx - x, cy + y));
      V2D_CHECK(SDL_RenderPoint(r, cx - x, cy - y));
      V2D_CHECK(SDL_RenderPoint(r, cx - y, cy - x));
      V2D_CHECK(SDL_RenderPoint(r, cx + y, cy - x));
      V2D_CHECK(SDL_RenderPoint(r, cx + x, cy - y));
      if (err <= 0) {
        y++;
        err += 2 * y + 1;
      }
      if (err > 0) {
        x--;
        err -= 2 * x + 1;
      }
    }
    return V2D_STATUS_OK;
  }

  case V2D_DRAW_FILLED: {
    for (int dy = -radius; dy <= radius; dy++) {
      int dx = (int)SDL_sqrt(radius * radius - dy * dy);
      V2D_CHECK(SDL_RenderLine(ctx->renderer, center.x - dx, center.y + dy,
                               center.x + dx, center.y + dy));
    }
    return V2D_STATUS_OK;
  }
  }
}

vida2d_status_t vida2d_set_color(vida2d_color_t color) {
  return SDL_SetRenderDrawColor(vida2d_get_global_ctx()->renderer, color.r,
                                color.g, color.b, color.a);
}
