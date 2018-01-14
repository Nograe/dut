#ifndef DEF_SETTINGS

#define DEF_SETTINGS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include "struct.h"

void dispSettings (Game *G, Bodies *B, Apple *A, Wall *W);
void advSettings (Game *G, Bodies *B, Wall *W);
void setDefaultSettings ();

#endif