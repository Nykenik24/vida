#include "vida2d.h"
#include <stdio.h>
#include <stdlib.h>

vida2D_t *vida2d_new_ctx(const char *window_title, unsigned int width,
                         unsigned int height) {
  vida2D_t *ctx = malloc(sizeof(vida2D_t));
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
    return 0;
  }
  ctx->window = SDL_CreateWindow(window_title, width, height, 0);
  ctx->renderer = SDL_CreateRenderer(ctx->window, NULL);
  ctx->running = 1;
  return ctx;
}

void vida2d_close(vida2D_t *ctx) {
  if (!ctx)
    return;

  SDL_DestroyRenderer(ctx->renderer);
  SDL_DestroyWindow(ctx->window);
  SDL_Quit();

  free(ctx);
}

void vida2d_poll_events(vida2D_t *ctx) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_EVENT_QUIT)
      ctx->running = 0;
  }
}

void vida2d_clear(vida2D_t *ctx) {
  SDL_SetRenderDrawColor(ctx->renderer, 30, 30, 30, 255);
  SDL_RenderClear(ctx->renderer);
}

void vida2d_draw(vida2D_t *ctx) { SDL_RenderPresent(ctx->renderer); }
