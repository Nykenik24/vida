#ifndef INCLUDE_VIDA2D_VECTOR_H_
#define INCLUDE_VIDA2D_VECTOR_H_

typedef struct {
  float x;
  float y;
} vida2d_vec2_t;

static inline vida2d_vec2_t vida2d_vec2(float x, float y) {
  return (vida2d_vec2_t){x, y};
}

static inline vida2d_vec2_t
vida2d_vec_transform(vida2d_vec2_t vec, float transform_x, float transform_y) {
  return vida2d_vec2(vec.x + transform_x, vec.y + transform_y);
}

static inline vida2d_vec2_t vida2d_vec_transformx(vida2d_vec2_t vec,
                                                  float transform_x) {
  return vida2d_vec2(vec.x + transform_x, vec.y);
}

static inline vida2d_vec2_t vida2d_vec_transformy(vida2d_vec2_t vec,
                                                  float transform_y) {
  return vida2d_vec2(vec.x, vec.y + transform_y);
}

#endif // !INCLUDE_VIDA2D_VECTOR_H_
