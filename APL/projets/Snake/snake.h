#ifndef DEF_SNAKE

#define DEF_SNAKE
#include "struct.h"

void move_forward (Game G, Bodies *B, Wall W);
void body_init (Game G, Bodies *B);
void dirBot (Bodies *B, Wall W, int botNum);
int verif (Game G, Bodies B, Wall W);
void verif_apple (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps, Settings S);
void randomApple (Game G, Bodies B, Apple *A);
void randomWall (Game G, Bodies B, Apple A, Wall *W);

#endif