#ifndef INCLUDE_VIDA2D_H_
#define INCLUDE_VIDA2D_H_

#include "SDL3/SDL_video.h"
#include "vida2d/status.h"
#include <SDL3/SDL.h>

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int running;
} vida2D_t;

// Initialize Vida2D.
vida2d_status_t vida2d_init(const char *window_title, unsigned width,
                            unsigned height);
// Close Vida2D.
void vida2d_close(void);
// Returns the static context used across the program.
// Only for advanced/internal use; you will probably never need
// to use this function.
vida2D_t *vida2d_get_global_ctx(void);
// Poll SDL events.
void vida2d_poll_events(void);
// Clear the screen.
void vida2d_clear(void);
// Update the screen with rendering made since the last call.
void vida2d_present(void);
// Returns true if Vida2D is running.
bool vida2d_running(void);

#endif // !INCLUDE_VIDA2D_H_
