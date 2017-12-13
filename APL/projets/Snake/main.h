#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include <time.h>
#include "snake.h"
#define WIDTH 50*12
#define HEIGHT 50*12
#define CASE 12

int forcexit(int touche);
void move_forward (Body *B);
void body_init (Body *B);
void draw (Body B, Apple A, unsigned long temps);
void eat_apple(Body *B, Apple *A);
