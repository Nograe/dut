#ifndef DEF_SNAKE

#define DEF_SNAKE
#include "struct.h"

void move_forward (Game G, Bodies *B);
void body_init (Game G, Bodies *B);
int verif (Game G, Bodies B, Wall W);
void verif_apple (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps, Settings S);
void randomApple (Game G, Bodies B, Apple *A);
void randomWall (Game G, Bodies B, Apple A, Wall *W);

#endif