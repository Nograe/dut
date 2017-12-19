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

  ChoisirCouleurDessin(choisirCouleur(G.variant, 'p'));
  EcrireTexte(width/2 - 40, height/2 -20, "PAUSE", 2);
  EcrireTexte(width/2 - 42, height/2, "Press SPACE", 0);

  do {
    *touche = Touche();
  } while (*touche != XK_space);

  int diff = Microsecondes() - tmp;

  draw(G, B, A, W, *temps+diff);
  EcrireTexte(width/2 - 20, height/2 -20, "3", 2);
  usleep(600000);
  draw(G, B, A, W, *temps+diff+600000);
  EcrireTexte(width/2 - 20, height/2 -20, "2", 2);
  usleep(600000);
  draw(G, B, A, W, *temps+diff+1200000);
  EcrireTexte(width/2 - 20,height/2 -20,"1",2);
  usleep(600000);

  *temps += diff+1800000;
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

  EffacerEcran(choisirCouleur(G->variant, 'b'));
  ChoisirCouleurDessin(choisirCouleur(G->variant, 'p'));
  EcrireTexte(width / 2, height / 2 - 20, "NEXT LEVEL!", 2);
  EcrireTexte(width / 2 + 1, height / 2 - 20, "NEXT LEVEL!", 2);
  sleep(1);
  draw(*G, *B, *A, *W, *temps);

  int touche = XK_space;
  verifpause(*G, *B, *A, *W, &touche, temps);
}

void timer (Game G, unsigned long temps) {

  int var = (Microsecondes() - temps)/1000000;
  int sec = var % 60;
  int min = var / 60;
  char png[17] = "src/digits/X.png";

  #ifdef DEV
  ChoisirCouleurDessin(CouleurParNom("red"));
  DessinerRectangle((G.width * G.tcase) - 145, (G.height * G.tcase) - 55, 145, 55);
  DessinerRectangle(0, (G.height * G.tcase) - 55, 165, 55);
  #endif

  png[11] = (min / 10) + '0';
  ChargerImage(png, G.width * G.tcase - 135, G.height * G.tcase - 40, 0, 0, 23, 31);
  png[11] = (min % 10) + '0';
  ChargerImage(png, G.width * G.tcase - 107, G.height * G.tcase - 40, 0, 0, 23, 31);
  if(var % 2 == 0)
    ChargerImage("src/digits/:.png", G.width * G.tcase - 85, G.height * G.tcase - 40, 0, 0, 23, 31);
  png[11] = (sec / 10) + '0';
  ChargerImage(png, G.width * G.tcase - 63, G.height * G.tcase - 40, 0, 0, 23, 31);
  png[11] = (sec % 10) + '0';
  ChargerImage(png, G.width * G.tcase - 35, G.height * G.tcase - 40, 0, 0, 23, 31);

  png[11] = (G.score / 10000) + '0';
  ChargerImage(png, 14, G.height * G.tcase - 40, 0, 0, 23, 31);
  png[11] = (G.score / 1000 % 10) + '0';
  ChargerImage(png, 42, G.height * G.tcase - 40, 0, 0, 23, 31);
  png[11] = (G.score / 100 % 10) + '0';
  ChargerImage(png, 70, G.height * G.tcase - 40, 0, 0, 23, 31);
  png[11] = (G.score / 10 % 10) + '0';
  ChargerImage(png, 98, G.height * G.tcase - 40, 0, 0, 23, 31);
  png[11] = (G.score % 10) + '0';
  ChargerImage(png, 126, G.height * G.tcase - 40, 0, 0, 23, 31);
}

/* void printscore (Game G) {

  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  char buf[6];

  ChoisirEcran(1);
  ChoisirCouleurDessin(choisirCouleur("black"));

  EcrireTexte(width / 3, height / 2, "YOUR SCORE: ", 2);
  sprintf(buf, "%d", G.score);
  EcrireTexte(width / 3 + TailleChaineEcran("YOUR SCORE: 0", 2), height / 2, buf, 2);

  ChoisirEcran(0);
  EffacerEcran(choisirCouleur("seagreen"));
  CopierZone(1, 0, 0, 0, width, height, 0, 0);

  sleep(2);
} */

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
  char bufapple[17] = "src/apple_1X.png";
  char bufwall[16] = "src/wall_1X.png";
  bufapple[11] = G.tcase%10 + '0';
  bufwall[10] = G.tcase%10 + '0';

  ChoisirEcran(1);
  EffacerEcran(choisirCouleur(G.variant, 'b'));
  ChoisirCouleurDessin(choisirCouleur(G.variant, 'd'));

  for(i = 0 ; i < B.nbrseg ; i++) {
    RemplirRectangle(B.s_seg[i].x, B.s_seg[i].y, G.tcase - 2, G.tcase - 2);
  }

  // Chargement des Apple
  for(i = 0 ; i < A.spawn ; i++)
    ChargerImage(bufapple, A.x[i], A.y[i], 0, 0, G.tcase, G.tcase);

  // Chargement des Wall
  for(i = 0 ; i < W.spawn ; i++)
    ChargerImage(bufwall, W.x[i], W.y[i], 0, 0, G.tcase, G.tcase);

  // Chargement du Temps - Score
  timer(G, temps);

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
    if( (posx >= 0 && posx <= 165 && posy >= height - 55 - G.tcase && posy <= height) || (posx >= width - 145 - G.tcase && posx <= width && posy >= height - 55 - G.tcase && posy <= height) )
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
    if( (posx >= 0 && posx <= 165 && posy >= height - 55 - G.tcase && posy <= height) || (posx >= width - 145 - G.tcase && posx <= width && posy >= height - 55 - G.tcase && posy <= height) )
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

    FermerGraphique();
    setScore(G);
    dispMenu(&G, &B, &A, &W, &S);
    temps = Microsecondes();
    old_dir = B.dir;
    touche = 0;
  }
}
