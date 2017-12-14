#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include <time.h>
#include "snake.h"
#define WIDTH 60*12
#define HEIGHT 40*12
#define CASE 12

int forcexit(int touche);
void verifpause (Body *B, Apple *A, int *touche, unsigned long *temps);
void next_level (Body *B, Apple *A, unsigned long *temps);
void move_forward (Body *B);
void draw (Body B, Apple A, unsigned long temps);
int verif (Body S);
void body_init (Body *B);
int verif_apple (Body *B, Apple *A);
void random_apple (Body B, Apple *A);
void eat_apple(Body *B, Apple *A);
