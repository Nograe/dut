#ifndef DEF_SNAKE

#define DEF_SNAKE

typedef enum {
  UP = 1,
  DOWN,
  LEFT,
  RIGHT
} Direction;

typedef struct {
  int x;
  int y;
} Segment;

typedef struct {
  Segment *s_seg;
  Direction dir;
  int speed;
  int nbrseg;
} Body;

typedef struct {
  int *x;
  int *y;
  int *exist;
  int eaten;
  int spawn;
} Apple;

typedef struct {
  int *x;
  int *y;
  int spawn;
} Wall;

#endif