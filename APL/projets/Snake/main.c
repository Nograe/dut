#include "main.h"

int forcexit(int touche) {

  if(touche == XK_Escape)
    return 1;
  else
    return 0;
}

void verifpause (Game G, Body B, Apple A, Wall W, int *touche, unsigned long *temps) {

  if(*touche != XK_space)
    return;

  unsigned long tmp = Microsecondes();
  int width = G.width * G.tcase;
  int height = G.height * G.tcase;

  EcrireTexte(width/2 - 40, height/2 -20, "PAUSE", 2);
  EcrireTexte(width/2 - 42, height/2, "Press SPACE", 0);

  do {
    *touche = Touche();
  } while (*touche != XK_space);

  int diff = Microsecondes() - tmp;

  draw(G, B, A, W, *temps+diff);
  EcrireTexte(width/2 - 20, height/2 -20, "3", 2);
  sleep(1);
  draw(G, B, A, W, *temps+diff+1000000);
  EcrireTexte(width/2 - 20, height/2 -20, "2", 2);
  sleep(1);
  draw(G, B, A, W, *temps+diff+2000000);
  EcrireTexte(width/2 - 20,height/2 -20,"1",2);
  sleep(1);

  *temps += diff+3000000;
  while(ToucheEnAttente() == 1)
    Touche();
  *touche = 0;
}

void next_level (Game *G, Body *B, Apple *A, Wall *W, unsigned long *temps) {

  G->level++;
  B->dir = 4;
  B->speed -= 6500;
  A->spawn++;
  A->eaten = 0;
  A->x = malloc(A->spawn * sizeof(int));
  A->y = malloc(A->spawn * sizeof(int));
  W->spawn++;
  W->x = malloc(W->spawn * sizeof(int));
  W->y = malloc(W->spawn * sizeof(int));

  int width = G->width * G->tcase;
  int height = G->height * G->tcase;

  body_init(*G, B);
  randomApple(*G, *B, A);
  randomWall(*G, *B, *A, W);

  EffacerEcran(CouleurParNom("goldenrod"));
  ChoisirCouleurDessin(CouleurParNom("darkred"));
  EcrireTexte(width / 2, height / 2 - 20, "NEXT LEVEL!", 2);
  EcrireTexte(width / 2 + 1, height / 2 - 20, "NEXT LEVEL!", 2);
  sleep(1);
  draw(*G, *B, *A, *W, *temps);

  int touche = XK_space;
  verifpause(*G, *B, *A, *W, &touche, temps);
}

void printscore (Game G) {

  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  char buf[6];

  ChoisirEcran(1);
  ChoisirCouleurDessin(CouleurParNom("black"));

  EcrireTexte(width / 3, height / 2, "YOUR SCORE: ", 2);
  sprintf(buf, "%d", G.score);
  EcrireTexte(width / 3 + TailleChaineEcran("YOUR SCORE: 0", 2), height / 2, buf, 2);

  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("seagreen"));
  CopierZone(1, 0, 0, 0, width, height, 0, 0);

  sleep(2);
}

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

void draw (Game G, Body B, Apple A, Wall W, unsigned long temps) {

  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  int i;
  unsigned long tmp = (Microsecondes() - temps)/1000000;
  char buf[10];

  ChoisirEcran(1);
  EffacerEcran(CouleurParNom("goldenrod"));
  ChoisirCouleurDessin(CouleurParNom("seagreen"));

  for(i = 0 ; i < B.nbrseg ; i++) {
    RemplirRectangle(B.s_seg[i].x, B.s_seg[i].y, G.tcase - 2, G.tcase - 2);
  }

  // Chargement des Apple
  for(i = 0 ; i < A.spawn ; i++)
    ChargerImage("src/apple_14.png",A.x[i]-1,A.y[i]-1,0,0,13,13);

  // Chargement des Wall
  for(i = 0 ; i < W.spawn ; i++)
    ChargerImage("src/wall_14.png",W.x[i],W.y[i],0,0,14,14);

  // Chargement du Temps - Score
  ChoisirCouleurDessin(CouleurParNom("black"));
  sprintf(buf,"%ld",tmp);
  EcrireTexte(width - (G.tcase * 2), height - (G.tcase * 2), buf, 2);
  sprintf(buf, "%d", G.score);
  EcrireTexte(G.tcase * 2, height - (G.tcase * 2), buf, 2);

  ChoisirEcran(0);
  CopierZone(1, 0, 0, 0, width, height, 0, 0);
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
  if(x <= 0 || x >= (G.width * G.tcase) || y <= 0 || y >= (G.height * G.tcase)) {
    //printf("Coords: %d | %d", x, y);
    return 1;
  }

  // Verification collision Body
  int i;
  for(i = 4 ; i <= B.nbrseg ; i++) {
    if(x == B.s_seg[i].x && y == B.s_seg[i].y) {
      //printf("Collision bloc %d : %d | %d\n", i+1, x, y);
      ChoisirCouleurDessin(CouleurParNom("red"));
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

int verif_apple (Game *G, Body *B, Apple *A) {

  if(A->eaten == A->spawn)
    return 1;

  int i;
  for(i = 0 ; i < A->spawn ; i++) {
    if(B->s_seg[0].x == A->x[i]+1 && B->s_seg[0].y == A->y[i]+1){
      A->x[i] = -G->tcase;
      A->y[i] = -G->tcase;
      eat_apple(G, B, A);
    }
  }

  return 0;
}

void randomApple (Game G, Body B, Apple *A) {

  int posx, posy, i, j;
  for(i = 0 ; i < A->spawn ; i++){
    posx = rand() % (G.width * G.tcase);
    posy = rand() % (G.height * G.tcase);
    A->x[i] = (posx - posx % G.tcase);
    A->y[i] = (posy - posy % G.tcase);
  }

  for(i = 0 ; i < B.nbrseg ; i++){
    for(j = 0 ; j < A->spawn ; j++) {
      if(A->x[j] == B.s_seg[i].x && A->y[j] == B.s_seg[i].y)
        return randomApple (G, B, A);
    }
  }
}

void randomWall (Game G, Body B, Apple A, Wall *W) {

  int posx, posy, i, j;
  for(i = 0 ; i < W->spawn ; i++){
    posx = rand() % (G.width * G.tcase);
    posy = rand() % (G.height * G.tcase);
    W->x[i] = (posx - posx % G.tcase);
    W->y[i] = (posy - posy % G.tcase);
  }

  // Vérification du spawn avec Body / Apple
  for(i = 0 ; i < B.nbrseg ; i++){
    for(j = 0 ; j < W->spawn ; j++) {
      if(W->x[j] == B.s_seg[i].x && W->y[j] == B.s_seg[i].y)
        return randomWall (G, B, A, W);
    }
  }
  for(i = 0 ; i < A.spawn ; i++){
    for(j = 0 ; j < W->spawn ; j++) {
      if(W->x[j] == B.s_seg[i].x && W->y[j] == B.s_seg[i].y)
        return randomWall (G, B, A, W);
    }
  }
}

void eat_apple (Game *G, Body *B, Apple *A) {

  G->score += 5;
  B->nbrseg += 2;
  A->eaten++;

  B->s_seg = realloc(B->s_seg, sizeof(Segment) * (B->nbrseg + 1));

  int i = B->nbrseg-2;
  for(; i < B->nbrseg ; i++){
    //printf("[%d] prend : [%d]\n", i, B->nbrseg-2-1);
    B->s_seg[i] = B->s_seg[i-1];
  }
}

int main () {

  unsigned long temps = Microsecondes();
  srand(time(NULL));

  Settings S;
  Game G;
  Body B;
  Apple A;
  Wall W;

  initgame(&G, &B, &A, &W, &S);

  int touche, old_dir = 4;

  while(1) {

    while(!verif(G, B, W) && touche != XK_Escape) {

      if(verif_apple(&G, &B, &A)) {
        next_level(&G, &B, &A, &W, &temps);
        old_dir = B.dir;
      }

      draw(G, B, A, W, temps);

      usleep(B.speed);

      if(ToucheEnAttente()) {
        touche = Touche();

        switch(touche) {
          case XK_Up:
          B.dir = UP;
          break;
          case XK_Down:
          B.dir = DOWN;
          break;
          case XK_Left:
          B.dir = LEFT;
          break;
          case XK_Right:
          B.dir = RIGHT;
          break;
        }

        if(old_dir+B.dir == 3 || old_dir+B.dir == 7)
          B.dir = old_dir;

        old_dir = B.dir;
      }

      verifpause(G, B, A, W, &touche, &temps);

      move_forward(G, &B);
    }

    printscore(G);
    FermerGraphique();
    dispMenu(&G, &B, &A, &W, &S);
    temps = Microsecondes();
    old_dir = B.dir;
    touche = 0;
  }
}
