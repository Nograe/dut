#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include <time.h>
#include "snake.h"
#include "menu.h"

int forcexit(int touche);
void verifpause (Game G, Body *B, Apple *A, int *touche, unsigned long *temps);
void next_level (Game G, Body *B, Apple *A, unsigned long *temps);
void move_forward (Game G, Body *B);
void draw (Game G, Body B, Apple A, unsigned long temps);
void body_init (Game G, Body *B);
int verif (Game G, Body S);
int verif_apple (Body *B, Apple *A);
void random_apple (Game G, Body B, Apple *A);
void eat_apple (Body *B, Apple *A);