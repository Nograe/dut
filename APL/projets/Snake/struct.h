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
  Segment *s_seg;
  Direction dir;
  int speed;
  int nbrseg;
} Body;

typedef struct {
  Body snake;
  Body *bot;
  int nbrBot;
} Bodies;

typedef struct {
  int *x;
  int *y;
  int eaten;
  int spawn;
} Apple;

typedef struct {
  int *x;
  int *y;
  int spawn;
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
  Theme theme;
} Game;

typedef struct {
  Game setG;
  Bodies setB;
  Apple setA;
  Wall setW;
} Settings;

#endif