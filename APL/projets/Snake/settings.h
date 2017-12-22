#ifndef DEF_SETTINGS

#define DEF_SETTINGS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include "struct.h"

void dispSettings (Game *G, Body *B, Apple *A, Wall *W, Settings *S);
void setSettings (Game *G, Body *B, Apple *A, Wall *W, Settings S);

#endif