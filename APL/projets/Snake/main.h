#ifndef DEF_MAIN

#define DEF_MAIN
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include <time.h>
#include <string.h>
#include "struct.h"

void verifPause (Game G, Bodies B, Apple A, Wall W, int *touche, unsigned long *temps);
void nextLevel (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps, Settings S);
void timer (Game G, unsigned long temps);
void draw (Game G, Bodies B, Apple A, Wall W, unsigned long temps);

#endif