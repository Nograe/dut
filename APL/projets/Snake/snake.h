#define POSX WIDTH/2
#define POSY HEIGHT/2

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
  Direction s_dir;
  int speed;
  int nbrseg;
} Body;

typedef struct {
  int *x;
  int *y;
  int eaten;
  int total;
  int spawn;
} Apple;
