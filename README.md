# vida2d

LÖVE-based game framework made in C, for C.

**REALLY W.I.P., don't expect much.**

## Usage

### Building from source

First, build the library:
```bash
cmake -B build && cmake --build build
```

Then, use the generated library in `lib/`, or try out the examples at `bin/`.

### Example

```c
#include "vida2d.h"
#include "vida2d/render.h"
#include "vida2d/vec.h"

int main(void) {
  vida2D_t *ctx = vida2d_new_ctx("vida2d test", 800, 600);

  if (!ctx)
    return 1;

  while (ctx->running) {
    vida2d_poll_events(ctx);
    vida2d_clear(ctx);

    vida2d_vec2_t first_pos = vida2d_vec2(25, 25);
    vida2d_set_color(ctx, vida2d_red);
    vida2d_draw_rect(ctx, V2D_DRAW_FILLED, vida2d_vec2(25, 25),
                     vida2d_vec2(50, 50));

    vida2d_set_color(ctx, vida2d_green);
    vida2d_draw_rect(ctx, V2D_DRAW_FILLED, vida2d_vec_transformx(first_pos, 75),
                     vida2d_vec2(50, 50));

    vida2d_set_color(ctx, vida2d_blue);
    vida2d_draw_rect(ctx, V2D_DRAW_FILLED,
                     vida2d_vec_transformx(first_pos, 75 * 2),
                     vida2d_vec2(50, 50));

    vida2d_draw(ctx);
  }

  vida2d_close(ctx);
  return 0;
}
```
