#include "vida2d.h"
#include "vida2d/status.h"
#include <stdio.h>
#include <stdlib.h>

vida2d_status_t vida2d_init(const char *window_title, unsigned int width,
                            unsigned int height) {
  vida2D_t *ctx = vida2d_get_global_ctx();
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
    return V2D_STATUS_ERR;
  }
  ctx->window = SDL_CreateWindow(window_title, width, height, 0);
  ctx->renderer = SDL_CreateRenderer(ctx->window, NULL);
  ctx->running = 1;
  return V2D_STATUS_OK;
}

vida2D_t *vida2d_get_global_ctx(void) {
  static vida2D_t ctx;
  return &ctx;
}

void vida2d_close(void) {
  vida2D_t *ctx = vida2d_get_global_ctx();
  if (!ctx)
    return;

  SDL_DestroyRenderer(ctx->renderer);
  SDL_DestroyWindow(ctx->window);
  SDL_Quit();
}

void vida2d_poll_events(void) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_EVENT_QUIT)
      vida2d_get_global_ctx()->running = 0;
  }
}

void vida2d_clear(void) {
  vida2D_t *ctx = vida2d_get_global_ctx();
  SDL_SetRenderDrawColor(ctx->renderer, 30, 30, 30, 255);
  SDL_RenderClear(ctx->renderer);
}

void vida2d_present(void) {
  SDL_RenderPresent(vida2d_get_global_ctx()->renderer);
}

bool vida2d_running(void) { return vida2d_get_global_ctx()->running; }
