#ifndef DEF_SNAKE

#define DEF_SNAKE
#include "struct.h"

void move_forward (Game G, Body *B);
void body_init (Game G, Body *B);
int verif (Game G, Body S, Wall W);
void verif_apple (Game *G, Body *B, Apple *A, Wall *W, unsigned long *temps, Settings S);
void randomApple (Game G, Body B, Apple *A);
void randomWall (Game G, Body B, Apple A, Wall *W);

#endif