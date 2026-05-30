#ifndef INCLUDE_VIDA2D_STATUS_H_
#define INCLUDE_VIDA2D_STATUS_H_

typedef enum {
  V2D_STATUS_OK,
  V2D_STATUS_ERR,
} vida2d_status_t;

#define V2D_BOOL_TO_STATUS(BOOL) ((BOOL) == 1 ? V2D_STATUS_OK : V2D_STATUS_ERR)
#define V2D_CHECK(BOOL)                                                        \
  if (!(BOOL)) {                                                               \
    return V2D_STATUS_ERR;                                                     \
  }

#endif // !INCLUDE_VIDA2D_STATUS_H_
