#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include <time.h>
#include "snake.h"
#define WIDTH 400
#define HEIGHT 400

void move_forward (Body *B);
void body_init (Body *B);
int forcexit (int touche);
