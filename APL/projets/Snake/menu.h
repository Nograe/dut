#ifndef DEF_MENU

#define DEF_MENU
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <graph.h>
#include "snake.h"

void initgame (Game *G, Body *B, Apple *A, Wall *W, Settings *S);
void dispMenu (Game *G, Body *B, Apple *A, Wall *W, Settings *S);
void dispPlay (Game *G, Body *B, Apple *A, Wall *W, Settings S);
void dispHighscore (Game *G, Body *B, Apple *A, Wall *W, Settings *S);
void quit ();
void dispHighscore (Game *G, Body *B, Apple *A, Wall *W, Settings *S);
void setScore (Game G);
int verifScore (char *pseudo, int score);
couleur choisirCouleur (Theme T, char type);

#endif
