#ifndef INCLUDE_VIDA2D_STATUS_H_
#define INCLUDE_VIDA2D_STATUS_H_

typedef enum {
  V2D_STATUS_ERR,
  V2D_STATUS_OK,
} vida2d_status_t;

#define V2D_CHECK(BOOL)                                                        \
  if (!(BOOL)) {                                                               \
    return V2D_STATUS_ERR;                                                     \
  }

#endif // !INCLUDE_VIDA2D_STATUS_H_
