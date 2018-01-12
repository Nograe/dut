#ifndef DEF_STRUCT

#define DEF_STRUCT

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
  Segment *seg;
  Direction dir;
  int speed;
  int nbrseg;
} Body;

typedef struct {
  Body snake;
  Body *bot;
  int nbrBot;
  int initSize;
  int initSpeed;
} Bodies;

typedef struct {
  int *x;
  int *y;
  int eaten;
  int spawn;
  int initSpawn;
} Apple;

typedef struct {
  int *x;
  int *y;
  int spawn;
  int initSpawn;
} Wall;

typedef enum {
  RETRO = 1,
  CLASSIC,
  MODERN,
  RANDOM
} Theme;

typedef struct {
  int width;
  int height;
  int tcase;
  int score;
  int level;
  int dispApple;
  char pseudo[11];
  Theme theme;
} Game;

#endif