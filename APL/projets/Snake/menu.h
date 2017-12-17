#ifndef DEF_MENU

#define DEF_MENU
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include "snake.h"

typedef enum {
	RETRO = 1,
	CLASSIC,
	MODERN,
	SOLARIZED
} Theme;

typedef struct {
	int width;
	int height;
	int tcase;
	Theme g_theme;
	int score;
	int level;
} Game;

typedef struct {
	Game setG;
	Body setB;
	Apple setA;
	Wall setW;
} Settings;

void initgame (Game *G, Body *B, Apple *A, Wall *W, Settings *S);
void dispMenu (Game *G, Body *B, Apple *A, Wall *W, Settings *S);
void dispPlay (Game *G, Body *B, Apple *A, Wall *W, Settings S);
void dispHighscore ();
void dispSettings (Game *G, Body *B, Apple *A, Wall *W, Settings *S);
void quit ();
void setSettings (Game *G, Body *B, Apple *A, Wall *W, Settings S);

#endif
