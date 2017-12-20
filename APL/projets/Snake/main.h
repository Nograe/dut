#ifndef DEF_MAIN

#define DEF_MAIN
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include <time.h>
#include <string.h>
#include "snake.h"
#include "menu.h"

//#define DEV
//#define DEBUG

int forcexit(int touche);
void verifpause (Game G, Body B, Apple A, Wall W, int *touche, unsigned long *temps);
void next_level (Game *G, Body *B, Apple *A, Wall *W, unsigned long *temps, Settings S);
void move_forward (Game G, Body *B);
void draw (Game G, Body B, Apple A, Wall W, unsigned long temps);
void body_init (Game G, Body *B);
int verif (Game G, Body S, Wall W);
void verif_apple (Game *G, Body *B, Apple *A, Wall *W, unsigned long *temps, Settings S);
void randomApple (Game G, Body B, Apple *A);
void randomWall (Game G, Body B, Apple A, Wall *W);

#endif