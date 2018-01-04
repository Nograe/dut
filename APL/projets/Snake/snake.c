#include "snake.h"
#include "main.h"
#include "menu.h"

void move_forward (Game G, Bodies *B, Wall W) {

  // Sauvegarde dans le segment "invisible" du dernier segment
  B->snake.s_seg[B->snake.nbrseg] = B->snake.s_seg[B->snake.nbrseg-1];

  int i, j, old_dir;

  // Chaque segment prend la valeur du segment précédent, excepté le premier
  for(i = B->snake.nbrseg-1 ; i >= 1 ; i--)
    B->snake.s_seg[i] = B->snake.s_seg[i-1];

  // Déplacement du segment en tête en fonction de la direction
  if(B->snake.dir == 1)
    B->snake.s_seg[0].y -= G.tcase;
  if(B->snake.dir == 2)
    B->snake.s_seg[0].y += G.tcase;
  if(B->snake.dir == 3)
    B->snake.s_seg[0].x -= G.tcase;
  if(B->snake.dir == 4)
    B->snake.s_seg[0].x += G.tcase;

  // Déplacement de chaque segments de chaque bot
  for(i = 0 ; i < B->nbrBot ; i++) {
    for(j = 4; j >= 1; j--)
      B->bot[i].s_seg[j] = B->bot[i].s_seg[j-1];
  }

  // Direction de chaque bot selon proximité du joueur/obstacles, random sinon
  for(i = 0 ; i < B->nbrBot ; i++) {
    dirBot(B, W, i);
  }

  for(i = 0 ; i < B->nbrBot ; i++) {
    switch(B->bot[i].dir) {
      case 1:
      B->bot[i].s_seg[0].y -= G.tcase;
      break;
      case 2:
      B->bot[i].s_seg[0].y += G.tcase;
      break;
      case 3:
      B->bot[i].s_seg[0].x -= G.tcase;
      break;
      case 4:
      B->bot[i].s_seg[0].x += G.tcase;
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
    B->snake.s_seg[i].x = posx;
    B->snake.s_seg[i].y = posy;
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

    for(j = 0; j < 5; j++) {
      B->bot[i].s_seg[j].x = posx;
      B->bot[i].s_seg[j].y = posy;
      posx -= G.tcase;
    }
    B->bot[i].dir = rand() % 3 + 1;
  }
}

void dirBot (Bodies *B, Wall W, int botNum) {

  Direction D = 0;
  Direction prevDir = B->bot[botNum].dir;
  int i, distWall = 0;

  int posx = B->bot[botNum].s_seg[0].x;
  int posy = B->bot[botNum].s_seg[0].y;

  // Vérification des obstacles et du joueur
  for(i = 0; i < W.spawn; i++) {

    if(prevDir == UP && W.x[i] == posx-1) {
      distWall = W.y[i] - posy;
    }
    if(prevDir == DOWN && W.x[i] == posx-1) {
      distWall = posy - W.y[i];
    }
    if(prevDir == LEFT && W.y[i] == posy) {
      distWall = posx - W.x[i];
    }
    if(prevDir == RIGHT && W.y[i] == posy) {
      distWall = W.x[i] - posx;
    }

    //printf("Wall %d | distWall: %d\n", i, distWall);
  }

  // Mouvement aléatoire sinon
  if(rand()%10 == 0) {
    do {
      D = rand() % 4 + 1;
    } while(prevDir + D == 3 || prevDir + D == 7);
    B->bot[botNum].dir = D;
  }

}

int verif (Game G, Bodies B, Wall W) {

  // Verification bordures
  int x = B.snake.s_seg[0].x;
  int y = B.snake.s_seg[0].y;
  if(x <= 0 || x >= (G.width * G.tcase) || y <= 0 || y >= (G.height * G.tcase)-55) {
    //printf("Coords: %d | %d", x, y);
    return 1;
  }

  // Téléportation bots
  int i, botx, boty;
  for(i = 0; i < B.nbrBot; i++) {
    botx = B.bot[i].s_seg[0].x;
    boty = B.bot[i].s_seg[0].y;
    if(botx <= 0) {
      B.bot[i].s_seg[0].x = (G.width * G.tcase) - (G.tcase-1);
    }
    if(botx >= (G.width * G.tcase)) {
      B.bot[i].s_seg[0].x = 1;
    }
    if(boty <= 0) {
      B.bot[i].s_seg[0].y = ((G.height * G.tcase)-55) - (G.tcase);
    }
    if(boty >= (G.height * G.tcase)-55) {
      B.bot[i].s_seg[0].y = 1;
    }
  }

  // Verification collision Body
  for(i = 4 ; i <= B.snake.nbrseg ; i++) {
    if(x == B.snake.s_seg[i].x && y == B.snake.s_seg[i].y) {
      //printf("Collision bloc %d : %d | %d\n", i+1, x, y);
      ChoisirCouleurDessin(choisirCouleur(G.variant, 'd'));
      RemplirRectangle(B.snake.s_seg[i].x, B.snake.s_seg[i].y, G.tcase - 2, G.tcase - 2);
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

void verif_apple (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps, Settings S) {

  if(A->eaten == A->spawn)
    return next_level(G, B, A, W, temps, S);

  int i, j;
  for(i = 0 ; i < A->spawn ; i++) {
    if(B->snake.s_seg[0].x == A->x[i]+1 && B->snake.s_seg[0].y == A->y[i]+1){
      G->score += 5;
      A->x[i] = -G->tcase;
      A->y[i] = -G->tcase;
      A->eaten++;
      B->snake.nbrseg += 2;
      B->snake.s_seg = realloc(B->snake.s_seg, sizeof(Segment) * (B->snake.nbrseg + 1));
      for(j = B->snake.nbrseg-2 ; j < B->snake.nbrseg ; j++)
        B->snake.s_seg[j] = B->snake.s_seg[j-1];
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
    A->exist[j] = 1;
    posx = A->x[j]; posy = A->y[j];

    // Vérification du spawn avec le score | timer
    if( posy > (G.height * G.tcase)-55-G.tcase )
      continue;

    // Vérification du spawn avec Body
    for(i = 0 ; i < B.snake.nbrseg ; i++){
      if(A->x[j]+1 == B.snake.s_seg[i].x && A->y[j]+1 == B.snake.s_seg[i].y)
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

    if(W->y[j]+1 == B.snake.s_seg[0].y)
      continue;

    if(verif)
      j++;
  }
}
