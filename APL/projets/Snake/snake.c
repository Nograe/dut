#include "snake.h"
//#define DEV
//#define DEBUG

void changeDir (Bodies *B, int *touche, int old_dir) {

  *touche = Touche();

  while(ToucheEnAttente())
    Touche();

  if(*touche == XK_Up || *touche == XK_z)
    B->snake.dir = UP;
  if(*touche == XK_Down || *touche == XK_s)
    B->snake.dir = DOWN;
  if(*touche == XK_Right || *touche == XK_d)
    B->snake.dir = RIGHT;
  if(*touche == XK_Left || *touche == XK_q)
    B->snake.dir = LEFT;

  if(old_dir+B->snake.dir == 3 || old_dir+B->snake.dir == 7)
    B->snake.dir = old_dir;
}

void moveForward (Game G, Bodies *B, Apple A, Wall W) {

  int i, j, old_dir;

  // Chaque segment prend la valeur du segment précédent, excepté le premier
  for(i = B->snake.nbrseg-1 ; i >= 1 ; i--)
    B->snake.seg[i] = B->snake.seg[i-1];

  // Déplacement du segment en tête en fonction de la direction
  if(B->snake.dir == UP)
    B->snake.seg[0].y -= G.tcase;
  if(B->snake.dir == DOWN)
    B->snake.seg[0].y += G.tcase;
  if(B->snake.dir == LEFT)
    B->snake.seg[0].x -= G.tcase;
  if(B->snake.dir == RIGHT)
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
    dirBot(G, B, A, W, i);
  }

  for(i = 0 ; i < B->nbrBot; i++) {
    if(B->bot[i].seg[0].x == (-G.tcase))
      continue;
    if(B->bot[i].dir == UP)
      B->bot[i].seg[0].y -= G.tcase;
    if(B->bot[i].dir == DOWN)
      B->bot[i].seg[0].y += G.tcase;
    if(B->bot[i].dir == LEFT)
      B->bot[i].seg[0].x -= G.tcase;
    if(B->bot[i].dir == RIGHT)
      B->bot[i].seg[0].x += G.tcase;
  }
}

void bodyInit (Game G, Bodies *B) {

  int i, j, var;
  int posx = G.width * G.tcase / 2;
  int posy = (G.height-4) * G.tcase / 2;

  for(i = 0 ; i < B->snake.nbrseg ; i++) {
    B->snake.seg[i].x = posx;
    B->snake.seg[i].y = posy;
    posx -= G.tcase;
  }
  B->snake.dir = RIGHT;

  for(i = 0 ; i < B->nbrBot ; i++) {

    var = rand()%4 + 1;
    if(var == 1) {
      B->bot[i].seg[0].x = rand() % (G.width-4) * G.tcase + 2*G.tcase;
      B->bot[i].seg[0].y = G.tcase;
      B->bot[i].dir = DOWN;
    }
    if(var == 2) {
      B->bot[i].seg[0].x = G.width * G.tcase - G.tcase*2;
      B->bot[i].seg[0].y = rand() % (G.height-9) * G.tcase + 2*G.tcase;
      B->bot[i].dir = LEFT;
    }
    if(var == 3) {
      B->bot[i].seg[0].x = rand() % (G.width-4) * G.tcase + 2*G.tcase;
      B->bot[i].seg[0].y = (G.height-1) * G.tcase - 56;
      B->bot[i].dir = UP;
    }
    if(var == 4) {
      B->bot[i].seg[0].x = G.tcase;
      B->bot[i].seg[0].y = rand() % (G.height-9) * G.tcase + 2*G.tcase;
      B->bot[i].dir = RIGHT;
    }
    for(j = 1; j < B->bot[i].nbrseg; j++)
      B->bot[i].seg[j].x = (-G.tcase);
    //printf("x: %d | y: %d | dir: %d\n", B->bot[i].seg[0].x, B->bot[i].seg[0].y, B->bot[i].dir);
  }
}

void dirBot (Game G, Bodies *B, Apple A, Wall W, int botNum) {

  Direction D = 0;
  Direction prevDir = B->bot[botNum].dir;
  int i;

  int posx = B->bot[botNum].seg[0].x;
  int posy = B->bot[botNum].seg[0].y;

  // Vérification des Wall
  for(i = 0; i < W.spawn; i++) {

    if(prevDir == UP && posx == W.x[i] && posy - W.y[i] < 3*G.tcase) {
      B->bot[botNum].dir = rand()%2+3;
      #ifdef DEV
        printf("Bot x:%d | y: %d to wall %d | x: %d | y: %d\n", posx, posy, i, W.x[i], W.y[i]);
        Touche();
      #endif
      return;
    }
    if(prevDir == DOWN && posx == W.x[i] && W.y[i] - posy < 3*G.tcase) {
      B->bot[botNum].dir = rand()%2+3;
      #ifdef DEV
        printf("Bot x:%d | y: %d to wall %d | x: %d | y: %d\n", posx, posy, i, W.x[i], W.y[i]);
        Touche();
      #endif
      return;
    }
    if(prevDir == LEFT && posy == W.y[i] && posx - W.x[i] < 3*G.tcase) {
      B->bot[botNum].dir = rand()%2+1;
      #ifdef DEV
        printf("Bot x:%d | y: %d to wall %d | x: %d | y: %d\n", posx, posy, i, W.x[i], W.y[i]);
        Touche();
      #endif
      return;
    }
    if(prevDir == RIGHT && posy == W.y[i] && W.x[i] - posx < 3*G.tcase) {
      B->bot[botNum].dir = rand()%2+1;
      #ifdef DEV
        printf("Bot x:%d | y: %d to wall %d | x: %d | y: %d\n", posx, posy, i, W.x[i], W.y[i]);
        Touche();
      #endif
      return;
    }
  }

  // Vérification du joueur
  int sx, sy;
  for(i = 0; i < B->snake.nbrseg; i++) {
    sx = B->snake.seg[i].x;
    sy = B->snake.seg[i].y;
    if(prevDir == UP && posx == sx && posy - sy < 3*G.tcase) {
      B->bot[botNum].dir = rand()%2+3;
      #ifdef DEV
        printf("Bot x:%d | y: %d to snake | x: %d | y: %d\n", posx, posy, i, sx, sy);
        Touche();
      #endif
      return;
    }
    if(prevDir == DOWN && posx == sx && sy - posy < 3*G.tcase) {
      B->bot[botNum].dir = rand()%2+3;
      #ifdef DEV
        printf("Bot x:%d | y: %d to snake | x: %d | y: %d\n", posx, posy, i, sx, sy);
        Touche();
      #endif
      return;
    }
    if(prevDir == LEFT && posy == sy && posx - sx < 3*G.tcase) {
      B->bot[botNum].dir = rand()%2+1;
      #ifdef DEV
        printf("Bot x:%d | y: %d to snake | x: %d | y: %d\n", posx, posy, i, sx, sy);
        Touche();
      #endif
      return;
    }
    if(prevDir == RIGHT && posy == sy && sx - posx < 3*G.tcase) {
      B->bot[botNum].dir = rand()%2+1;
      #ifdef DEV
        printf("Bot x:%d | y: %d to snake | x: %d | y: %d\n", posx, posy, i, sx, sy);
        Touche();
      #endif
      return;
    }
  }

  // Une pomme est sur la même ligne ou la même colonne
  for(i = 0; i < A.spawn; i++) {

    if(A.x[i] == (-G.tcase))
      continue;

    if(posx == A.x[i] && (prevDir == LEFT || prevDir == RIGHT) && rand()%2 == 0) {
      if(posy > A.y[i])
        B->bot[botNum].dir = UP;
      if(posy < A.y[i])
        B->bot[botNum].dir = DOWN;
      return;
    }
    if(posy == A.y[i] && (prevDir == UP || prevDir == DOWN) && rand()%2 == 0) {
      if(posx > A.x[i])
        B->bot[botNum].dir = LEFT;
      if(posx < A.x[i])
        B->bot[botNum].dir = RIGHT;
      return;
    }
  }

  // Vérification des bordures
  if(prevDir == UP && posy <= G.tcase*4) {
    B->bot[botNum].dir = rand()%2+3;
    return;
  }
  if(prevDir == DOWN && posy >= (G.height * G.tcase)-55-G.tcase*4) {
    B->bot[botNum].dir = rand()%2+3;
    return;
  }
  if(prevDir == LEFT && posx <= G.tcase*4) {
    B->bot[botNum].dir = rand()%2+1;
    return;
  }
  if(prevDir == RIGHT && posx >= (G.width * G.tcase)-G.tcase*4) {
    B->bot[botNum].dir = rand()%2+1;
    return;
  }

  if(rand()%20 == 0) {
    do {
      D = rand() % 4 + 1;
    } while(prevDir + D == 3 || prevDir + D == 7);
    B->bot[botNum].dir = D;
  }
}

int verif (Game *G, Bodies *B, Wall W) {

  int i, j;
  // Verification collision Wall / Bot
  for(i = 0 ; i < B->nbrBot; i++) {
    for(j = 0 ; j < W.spawn ; j++) {
      if(B->bot[i].seg[0].x == W.x[j] && B->bot[i].seg[0].y == W.y[j]) 
        B->bot[i].seg[0].x = (-G->tcase);
    }
  }

  // Vérification bordures / Bot
  int botx, boty;
  for(i = 0; i < B->nbrBot; i++) {
    if(B->bot[i].seg[0].x == (-G->tcase))
      continue;
    botx = B->bot[i].seg[0].x;
    boty = B->bot[i].seg[0].y;
    if(botx < G->tcase || botx > (G->width-2) * G->tcase || boty < G->tcase || boty > (G->height-1)*G->tcase-55)
      B->bot[i].seg[0].x = (-G->tcase);
  }

  #ifdef DEV
  return 0;
  #endif

  // Verification bordures
  int x = B->snake.seg[0].x;
  int y = B->snake.seg[0].y;
  if(x < G->tcase || x > (G->width-2) * G->tcase || y < G->tcase || y > (G->height-1)*G->tcase-55)
    return 1;

  // Verification collision Body
  for(i = 4 ; i < B->snake.nbrseg ; i++) {
    if(x == B->snake.seg[i].x && y == B->snake.seg[i].y) {
      //printf("Collision bloc %d : %d | %d\n", i+1, x, y);
      //ChoisirCouleurDessin(choisirCouleur(G->theme, 'd'));
      //RemplirRectangle(B->snake.seg[i].x, B->snake.seg[i].y, G->tcase - 2, G->tcase - 2);
      return 1;
    }
  }

  // Verification collision Wall / Snake
  for(i = 0 ; i < W.spawn ; i++) {
    if(x == W.x[i] && y == W.y[i])
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
      if(B->bot[i].seg[0].x == B->snake.seg[j].x && B->bot[i].seg[0].y == B->snake.seg[j].y) {
        G->score+=10;
        B->bot[i].seg[0].x = (-G->tcase);
      }
  }

  // Suppression du bot
  for(i = 0; i < B->nbrBot; i++) {
    if(B->bot[i].seg[0].x == (-G->tcase)) {
      for(j = 0; j < B->bot[i].nbrseg; j++)
        B->bot[i].seg[j].x = (-G->tcase);
    }
  }

  return 0;
}

void verifApple (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps) {

	if(G->opt == 2)
		return;

  	if(A->eaten == A->spawn)
    return nextLevel(G, B, A, W, temps);

  int i, j;
  for(i = 0 ; i < A->spawn ; i++) {
    if(A->x[i] == (-G->tcase))
      continue;
    if(B->snake.seg[0].x == A->x[i] && B->snake.seg[0].y == A->y[i]) {
      G->score += 5;
      A->x[i] = (-G->tcase);
      A->eaten++;
      B->snake.nbrseg += 2;
      B->snake.seg = realloc(B->snake.seg, sizeof(Segment) * (B->snake.nbrseg + 1));
      for(j = B->snake.nbrseg-2 ; j < B->snake.nbrseg ; j++)
        B->snake.seg[j] = B->snake.seg[j-1];
    }
  }

  for(i = 0; i < B->nbrBot; i++) {
    for(j = 0; j < A->spawn; j++) {
      if(A->x[j] == (-G->tcase))
        continue;
      if(B->bot[i].seg[0].x == A->x[j] && B->bot[i].seg[0].y == A->y[j]) {
        if(G->score >= 2)
          G->score -= 2;
        else if(G->score = 1)
          G->score--;
        A->x[j] = (-G->tcase);
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

    verif = 1;
    posx = rand() % (G.width-2) * G.tcase + G.tcase;
    posy = rand() % (G.height-4) * G.tcase + G.tcase;
    A->x[j] = posx;
    A->y[j] = posy;

    // Vérification du spawn avec le score | timer
    if(posy > (G.height * G.tcase)-55-G.tcase)
      continue;

    // Vérification du spawn avec les autres Apple et la ligne de départ
    for(i = 0; i < j; i++) {
      if(A->x[j] == A->x[i] && A->y[j] == A->y[i]) 
        verif = 0;
    }

    if(A->y[j] == B.snake.seg[0].y)
      continue;

    if(verif)
      j++;
  }
}

void randomWall (Game G, Bodies B, Apple A, Wall *W) {

  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  int posx, posy, i, j = 0, verif = 1;

  while (j < W->spawn) {

    verif = 1;
    posx = rand() % (G.width-2) * G.tcase + G.tcase;
    posy = rand() % (G.height-4) * G.tcase + G.tcase;
    W->x[j] = posx;
    W->y[j] = posy; 

  // Vérification du spawn avec le score | timer
    if( posy > (G.height * G.tcase)-55-G.tcase )
      continue;

  // Vérification du spawn avec les autres Wall | Body | Apple (On évite le spawn-kill)
    for(i = 0 ; i < j ; i++) {
      if(W->x[j] == W->x[i] && W->y[j] == W->y[i]) 
        verif = 0;
    }

    for(i = 0 ; i < A.spawn ; i++){
      if(W->x[j] == A.x[i] && W->y[j] == A.y[i]){
        verif = 0;
      }
    }

    if(W->y[j] == B.snake.seg[0].y)
      continue;

    for(i = 0; i < B.nbrBot; i++) {
      if(W->x[j] == B.bot[i].seg[0].x && W->y[j] == B.bot[i].seg[0].y)
        continue;
    }

    if(verif)
      j++;
  }
}
