#ifndef DEF_MENU

#define DEF_MENU
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <graph.h>
#include "snake.h"

void initGame (Game *G, Bodies *B, Apple *A, Wall *W);
void dispMenu (Game *G, Bodies *B, Apple *A, Wall *W);
void dispPlay (Game *G, Bodies *B, Apple *A, Wall *W);
void dispHighscore (Game *G, Bodies *B, Apple *A, Wall *W);
void quit (Game G, Bodies B, Apple A, Wall W);
void dispHighscore (Game *G, Bodies *B, Apple *A, Wall *W);
void setScore (Game G);
int verifScore (char *pseudo, int score);
couleur choisirCouleur (Theme T, char type);

#endif
