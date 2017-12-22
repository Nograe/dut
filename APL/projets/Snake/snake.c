#include "snake.h"
#include "main.h"
#include "menu.h"

void move_forward (Game G, Body *B) {

  B->s_seg[B->nbrseg] = B->s_seg[B->nbrseg-1];
  int i;
  for(i = B->nbrseg-1 ; i >= 1 ; i--) {
    B->s_seg[i] = B->s_seg[i-1];
  }

  switch(B->dir) {
    case 1:
    B->s_seg[0].y -= G.tcase;
    break;
    case 2:
    B->s_seg[0].y += G.tcase;
    break;
    case 3:
    B->s_seg[0].x -= G.tcase;
    break;
    case 4:
    B->s_seg[0].x += G.tcase;
    break;
  }
}

void body_init (Game G, Body *B) {

  int i;
  int posx = G.width * G.tcase / 2 + 1;
  int posy = G.height * G.tcase / 2 + 1;
  for(i = 0 ; i < B->nbrseg ; i++) {
    B->s_seg[i].x = posx;
    B->s_seg[i].y = posy;
    posx -= G.tcase;
  }
  B->dir = 4;
}

int verif (Game G, Body B, Wall W) {

  // Verification bordures
  int x = B.s_seg[0].x;
  int y = B.s_seg[0].y;
  if(x <= 0 || x >= (G.width * G.tcase) || y <= 0 || y >= (G.height * G.tcase)-55) {
    //printf("Coords: %d | %d", x, y);
    return 1;
  }

  // Verification collision Body
  int i;
  for(i = 4 ; i <= B.nbrseg ; i++) {
    if(x == B.s_seg[i].x && y == B.s_seg[i].y) {
      //printf("Collision bloc %d : %d | %d\n", i+1, x, y);
      ChoisirCouleurDessin(choisirCouleur(G.variant, 'd'));
      RemplirRectangle(B.s_seg[i].x, B.s_seg[i].y, G.tcase - 2, G.tcase - 2);
      return 1;
    }
  }

  // Verification collision Wall
  for(i = 0 ; i < W.spawn ; i++) {
    if(x == W.x[i]+1 && y == W.y[i]+1)
      return 1;
  }

  return 0;
}

void verif_apple (Game *G, Body *B, Apple *A, Wall *W, unsigned long *temps, Settings S) {

  if(A->eaten == A->spawn)
    return next_level(G, B, A, W, temps, S);

  int i, j;
  for(i = 0 ; i < A->spawn ; i++) {
    if(B->s_seg[0].x == A->x[i]+1 && B->s_seg[0].y == A->y[i]+1){
      G->score += 5;
      A->x[i] = -G->tcase;
      A->y[i] = -G->tcase;
      A->eaten++;
      B->nbrseg += 2;
      B->s_seg = realloc(B->s_seg, sizeof(Segment) * (B->nbrseg + 1));
      for(j = B->nbrseg-2 ; j < B->nbrseg ; j++)
        B->s_seg[j] = B->s_seg[j-1];
    }
  }
}

void randomApple (Game G, Body B, Apple *A) {

  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  int posx, posy, i, j = 0, verif = 1;

  while (j < A->spawn) {

    #ifdef DEBUG
    printf("Apple: %d\n", j);
    #endif

    verif = 1;
    posx = rand() % (G.width * G.tcase);
    posy = rand() % (G.height * G.tcase);
    A->x[j] = (posx - posx % G.tcase);
    A->y[j] = (posy - posy % G.tcase);
    A->exist[j] = 1;
    posx = A->x[j]; posy = A->y[j];

    // Vérification du spawn avec le score | timer
    if( posy > (G.height * G.tcase)-55-G.tcase )
      continue;

    // Vérification du spawn avec Body
    for(i = 0 ; i < B.nbrseg ; i++){
      if(A->x[j]+1 == B.s_seg[i].x && A->y[j]+1 == B.s_seg[i].y)
        verif = 0;
    }

    if(verif)
      j++;
  }
}

void randomWall (Game G, Body B, Apple A, Wall *W) {

  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  int posx, posy, i, j = 0, verif = 1;

  while (j < W->spawn) {

    #ifdef DEBUG
    printf("Wall: %d\n", j);
    #endif

    verif = 1;
    posx = rand() % (G.width * G.tcase);
    posy = rand() % (G.height * G.tcase);
    W->x[j] = (posx - posx % G.tcase);
    W->y[j] = (posy - posy % G.tcase);
    posx = W->x[j]; posy = W->y[j]; 

  // Vérification du spawn avec le score | timer
    if( posy > (G.height * G.tcase)-55-G.tcase )
      continue;

  // Vérification du spawn avec Wall | Body | Apple (On évite le spawn-kill)
    for(i = 0 ; i < j ; i++) {
      if(W->x[j] == W->x[i] && W->y[j] == W->y[i]) 
        verif = 0;
    }

    for(i = 0 ; i < A.spawn ; i++){
      if(W->x[j] == A.x[i] && W->y[j] == A.y[i]){
        verif = 0;
      }
    }

    if(W->y[j]+1 == B.s_seg[0].y)
      continue;

    if(verif)
      j++;
  }
}
