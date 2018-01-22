#ifndef DEF_SNAKE

#define DEF_SNAKE
#include <graph.h>
#include "struct.h"
#include "main.h"
#include "menu.h"

void changeDir (Bodies *B, int *touche, int old_dir);
void moveBodies (Game G, Bodies *B, Apple A, Wall W);
void bodyInit (Game G, Bodies *B);
void dirBot (Game G, Bodies *B, Apple A, Wall W, int botNum);
int verif (Game *G, Bodies *B, Wall W);
void verifApple (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps);
void randomApple (Game G, Bodies B, Apple *A);
void randomWall (Game G, Bodies B, Apple A, Wall *W);

#endif