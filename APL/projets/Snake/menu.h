#ifndef DEF_MENU

#define DEF_MENU
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <graph.h>
#include "snake.h"
#include "settings.h"
#include "main.h"

void initGame (Game *G, Bodies *B, Apple *A, Wall *W, int argc, char *argv[]);
void dispMenu (Game *G, Bodies *B, Apple *A, Wall *W);
void dispPlay (Game *G, Bodies *B, Apple *A, Wall *W);
void dispHighscore (Game *G, Bodies *B, Apple *A, Wall *W);
void setScore (Game G);
int verifScore (char *pseudo, int score);
void quit (char *pseudo);

#endif
