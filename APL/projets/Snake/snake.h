#ifndef DEF_SNAKE

#define DEF_SNAKE
#include "struct.h"

void moveForward (Game G, Bodies *B, Apple A, Wall W);
void bodyInit (Game G, Bodies *B);
void dirBot (Game G, Bodies *B, Apple A, Wall W, int botNum);
int verif (Game *G, Bodies *B, Wall W);
void verifApple (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps, Settings S);
void randomApple (Game G, Bodies B, Apple *A);
void randomWall (Game G, Bodies B, Apple A, Wall *W);

#endif