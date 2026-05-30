#ifndef INCLUDE_VIDA2D_H_
#define INCLUDE_VIDA2D_H_

#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int running;
} vida2D_t;

// Initialize a new Vida2D context.
vida2D_t *vida2d_new_ctx(const char *window_title, unsigned width,
                         unsigned height);
// Close (quit & free) a Vida2D context.
void vida2d_close(vida2D_t *ctx);
// Poll SDL events.
void vida2d_poll_events(vida2D_t *ctx);
// Clear the screen.
void vida2d_clear(vida2D_t *ctx);
// Update the screen with rendering made since the last call.
void vida2d_draw(vida2D_t *ctx);

#endif // !INCLUDE_VIDA2D_H_
