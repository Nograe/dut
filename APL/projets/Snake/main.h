#ifndef DEF_MAIN

#define DEF_MAIN
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include <time.h>
#include <string.h>
#include "struct.h"
#include "settings.h"
#include "menu.h"

void verifPause (Game G, Apple A, int *touche, unsigned long *temps);
void nextLevel (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps);
void printData (Game G, unsigned long temps);
void gameOver (Game *G);
void draw (Game G, Bodies B, Apple A, Wall W, unsigned long temps);
void gameModes (Game *G, Bodies *B, Apple *A, Wall *W, int argc, char *argv[]);

#endif