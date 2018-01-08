#include "snake.h"
#include "main.h"
#include "menu.h"

void move_forward (Game G, Bodies *B, Wall W) {

  // Sauvegarde dans le segment "invisible" du dernier segment
  B->snake.seg[B->snake.nbrseg] = B->snake.seg[B->snake.nbrseg-1];

  int i, j, old_dir;

  // Chaque segment prend la valeur du segment précédent, excepté le premier
  for(i = B->snake.nbrseg-1 ; i >= 1 ; i--)
    B->snake.seg[i] = B->snake.seg[i-1];

  // Déplacement du segment en tête en fonction de la direction
  if(B->snake.dir == 1)
    B->snake.seg[0].y -= G.tcase;
  if(B->snake.dir == 2)
    B->snake.seg[0].y += G.tcase;
  if(B->snake.dir == 3)
    B->snake.seg[0].x -= G.tcase;
  if(B->snake.dir == 4)
    B->snake.seg[0].x += G.tcase;


  // Déplacement de chaque segment de chaque bot
  for(i = 0 ; i < B->nbrBot; i++) {
    if(B->bot[i].seg[0].x == (-G.tcase)) {
      //printf("Bot %d in wall\n", i);
      continue;
    }
    for(j = B->bot[i].nbrseg-1; j >= 1; j--)
      B->bot[i].seg[j] = B->bot[i].seg[j-1];
  }

  // Direction de chaque bot selon proximité du joueur/obstacles, random sinon
  for(i = 0 ; i < B->nbrBot; i++) {
    if(B->bot[i].seg[0].x == (-G.tcase))
      continue;
    dirBot(G, B, W, i);
  }

  for(i = 0 ; i < B->nbrBot; i++) {
    if(B->bot[i].seg[0].x == (-G.tcase))
      continue;
    switch(B->bot[i].dir) {
      case 1:
      B->bot[i].seg[0].y -= G.tcase;
      break;
      case 2:
      B->bot[i].seg[0].y += G.tcase;
      break;
      case 3:
      B->bot[i].seg[0].x -= G.tcase;
      break;
      case 4:
      B->bot[i].seg[0].x += G.tcase;
      break;
    }
  }
}

void body_init (Game G, Bodies *B) {

  int i, j;
  int posx = G.width * G.tcase / 2 + 1;
  int posy = G.height * G.tcase / 2 + 1;

  #ifdef DEV
  printf("Snake: x: %d | y: %d\n", posx, posy);
  #endif

  for(i = 0 ; i < B->snake.nbrseg ; i++) {
    B->snake.seg[i].x = posx;
    B->snake.seg[i].y = posy;
    posx -= G.tcase;
  }
  B->snake.dir = 4;

  for(i = 0 ; i < B->nbrBot ; i++) {
    posx = rand() % (G.width * G.tcase);
    posy = rand() % (G.height * G.tcase);
    posx = (posx - (posx % G.tcase)) + 1;
    posy = (posy - (posy % G.tcase)) + 1;

    #ifdef DEV
    printf("Bot %d | x: %d | y: %d\n", i, posx, posy);
    #endif

    for(j = 0; j < B->bot[i].nbrseg; j++) {
      B->bot[i].seg[j].x = posx;
      B->bot[i].seg[j].y = posy;
      posx -= G.tcase;
    }
    B->bot[i].dir = rand() % 4 + 1;
    if(B->bot[i].dir = 3)
      B->bot[i].dir = rand() % 2 + 1;
  }
}

void dirBot (Game G, Bodies *B, Wall W, int botNum) {

  Direction D = 0;
  Direction prevDir = B->bot[botNum].dir;
  int i, distWall, distPx, distPy;

  int posx = B->bot[botNum].seg[0].x;
  int posy = B->bot[botNum].seg[0].y;

  // Vérification des obstacles
  for(i = 0; i < W.spawn; i++) {

    distWall = 0;
    if(prevDir == UP && W.x[i] == posx-1) {
      distWall = posy - W.y[i];
    }
    if(prevDir == DOWN && W.x[i] == posx-1) {
      distWall = W.y[i] - posy;
    }
    if(prevDir == LEFT && W.y[i] == posy-1) {
      distWall = posx - W.x[i];
    }
    if(prevDir == RIGHT && W.y[i] == posy-1) {
      distWall = W.x[i] - posx;
    }

    if(distWall <= G.tcase*3 && distWall > G.tcase*2) {
      //printf("Bot: %d | Wall %d | distWall: %d\n", botNum, i, distWall);
      if(prevDir == UP || prevDir == DOWN) {
        if(rand()%2 == 0)
          B->bot[botNum].dir = LEFT;
        else
          B->bot[botNum].dir = RIGHT;
      }
      if(prevDir == LEFT || prevDir == RIGHT) {
        if(rand()%2 == 0)
          B->bot[botNum].dir = UP;
        else
          B->bot[botNum].dir = DOWN;
      }  
      return;
    }
  }

  // Recherche du joueur sinon
  /* int Sx = B->snake.seg[0].x;
  int Sy = B->snake.seg[0].y;
  if(abs(posx - Sx) < abs(Sx - posx))
   distPx = abs(posx - Sx);
  else
    distPx = abs(Sx - posx);
  if(abs(posy - Sy) < abs(Sy - posy))
   distPy = abs(posy - Sy);
  else
    distPy = abs(Sy - posy); */

  if(rand()%10 == 0) {
    do {
      D = rand() % 4 + 1;
    } while(prevDir + D == 3 || prevDir + D == 7);
    B->bot[botNum].dir = D;
  }

}

int verif (Game G, Bodies *B, Wall W) {

  int i, j;
  // Verification collision Wall / Bot
  for(i = 0 ; i < B->nbrBot; i++) {
    for(j = 0 ; j < W.spawn ; j++) {
      if(B->bot[i].seg[0].x == W.x[j]+1 && B->bot[i].seg[0].y == W.y[j]+1) 
        B->bot[i].seg[0].x = (-G.tcase);
    }
  }

  // Téléportation bots
  int botx, boty;
  for(i = 0; i < B->nbrBot; i++) {
    if(B->bot[i].seg[0].x == (-G.tcase))
      continue;
    botx = B->bot[i].seg[0].x;
    boty = B->bot[i].seg[0].y;
    if(botx <= 0)
      B->bot[i].seg[0].x = (G.width * G.tcase) - (G.tcase-1);
    if(botx >= (G.width * G.tcase))
      B->bot[i].seg[0].x = 1;
    if(boty <= 0)
      B->bot[i].seg[0].y = ((G.height * G.tcase)-55) - (G.tcase);
    if(boty >= (G.height * G.tcase)-55)
      B->bot[i].seg[0].y = 1;
  }

  #ifdef TEST
  return 0;
  #endif

  // Verification bordures
  int x = B->snake.seg[0].x;
  int y = B->snake.seg[0].y;
  if(x <= 0 || x >= (G.width * G.tcase) || y <= 0 || y >= (G.height * G.tcase)-55) {
    return 1;
  }

  // Verification collision Body
  for(i = 4 ; i <= B->snake.nbrseg ; i++) {
    if(x == B->snake.seg[i].x && y == B->snake.seg[i].y) {
      //printf("Collision bloc %d : %d | %d\n", i+1, x, y);
      ChoisirCouleurDessin(choisirCouleur(G.theme, 'd'));
      RemplirRectangle(B->snake.seg[i].x, B->snake.seg[i].y, G.tcase - 2, G.tcase - 2);
      return 1;
    }
  }

  // Verification collision Wall / Snake
  for(i = 0 ; i < W.spawn ; i++) {
    if(x == W.x[i]+1 && y == W.y[i]+1)
      return 1;
  }

  // Verification collision Snake / Bot
  for(i = 0; i < B->nbrBot; i++) {
    for(j = 0; j < B->bot[i].nbrseg; j++) {
      if(B->snake.seg[0].x == B->bot[i].seg[j].x && B->snake.seg[0].y == B->bot[i].seg[j].y)
        return 1;
    }
  }

  // Verification collision Bot / Snake
  for(i = 0; i < B->nbrBot; i++) {
    for(j = 0; j < B->snake.nbrseg; j++)
      if(B->bot[i].seg[0].x == B->snake.seg[j].x && B->bot[i].seg[0].y == B->snake.seg[j].y)
        B->bot[i].seg[0].x = (-G.tcase);
  }

  // Suppression du bot
  for(i = 0; i < B->nbrBot; i++) {
    if(B->bot[i].seg[0].x == (-G.tcase)) {
      for(j = 0; j < B->bot[i].nbrseg; j++)
        B->bot[i].seg[j].x = (-G.tcase);
    }
  }

  return 0;
}

void verif_apple (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps, Settings S) {

  if(A->eaten == A->spawn)
    return nextLevel(G, B, A, W, temps, S);

  int i, j;
  for(i = 0 ; i < A->spawn ; i++) {
    if(B->snake.seg[0].x == A->x[i]+1 && B->snake.seg[0].y == A->y[i]+1) {
      G->score += 5;
      A->x[i] = -G->tcase;
      A->eaten++;
      B->snake.nbrseg += 2;
      B->snake.seg = realloc(B->snake.seg, sizeof(Segment) * (B->snake.nbrseg + 1));
      for(j = B->snake.nbrseg-2 ; j < B->snake.nbrseg ; j++)
        B->snake.seg[j] = B->snake.seg[j-1];
    }
  }

  for(i = 0; i < B->nbrBot; i++) {
    for(j = 0; j < A->spawn; j++) {
      if(B->bot[i].seg[0].x == A->x[j]+1 && B->bot[i].seg[0].y == A->y[j]+1) {
        if(G->score >= 2)
          G->score -= 2;
        else if(G->score = 1)
          G->score--;
        A->x[j] = -G->tcase;
        A->eaten++;
      }
    }
  }
}

void randomApple (Game G, Bodies B, Apple *A) {

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
    posx = A->x[j]; posy = A->y[j];

    // Vérification du spawn avec le score | timer
    if( posy > (G.height * G.tcase)-55-G.tcase )
      continue;

    // Vérification du spawn avec Body
    for(i = 0 ; i < B.snake.nbrseg ; i++){
      if(A->x[j]+1 == B.snake.seg[i].x && A->y[j]+1 == B.snake.seg[i].y)
        verif = 0;
    }

    if(verif)
      j++;
  }
}

void randomWall (Game G, Bodies B, Apple A, Wall *W) {

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

    if(W->y[j]+1 == B.snake.seg[0].y)
      continue;

    if(verif)
      j++;
  }
}
