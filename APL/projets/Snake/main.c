#include "main.h"
#include "menu.h"

int forcexit(int touche) {

  if(touche == XK_Escape)
    return 1;
  else
    return 0;
}

void verifpause (Game G, Bodies B, Apple A, Wall W, int *touche, unsigned long *temps) {

  if(*touche != XK_space)
    return;

  unsigned long tmp = Microsecondes();
  int width = G.width * G.tcase;
  int height = G.height * G.tcase;

  ChoisirCouleurDessin(choisirCouleur(G.variant, 'p'));
  EcrireTexte(width/2 - 40, height/2 -20, "PAUSE", 2);
  EcrireTexte(width/2 - 42, height/2, "Press SPACE", 0);
  ChargerImage("src/digits/:.png", G.width * G.tcase - 85, G.height * G.tcase - 40, 0, 0, 23, 31);

  do {
    *touche = Touche();
  } while (*touche != XK_space);

  int diff = Microsecondes() - tmp;

  draw(G, B, A, W, *temps+diff);
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  ChargerImage("src/digits/3.png", (width/2) - 23/2, (height/2) - 31, 0, 0, 23, 31);
  usleep(600000);
  draw(G, B, A, W, *temps+diff+600000);
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  ChargerImage("src/digits/2.png", (width/2) - 23/2, (height/2) - 31, 0, 0, 23, 31);
  usleep(600000);
  draw(G, B, A, W, *temps+diff+1200000);
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  ChargerImage("src/digits/1.png", (width/2) - 27/2, (height/2) - 31, 0, 0, 23, 31);
  usleep(600000);

  *temps += diff+1800000;
  while(ToucheEnAttente())
    Touche();
  *touche = 0;
}

void next_level (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps, Settings S) {

  G->level++;
  B->snake.nbrseg = S.setB.snake.nbrseg;
  B->snake.dir = 4;
  B->snake.speed -= 6500;
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

  ChoisirCouleurDessin(choisirCouleur(G.variant, 't'));
  RemplirRectangle(0, (G.height*G.tcase)-55, G.width*G.tcase, (G.height*G.tcase));

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

void draw (Game G, Bodies B, Apple A, Wall W, unsigned long temps) {

  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  int i, j;
  unsigned long tmp = (Microsecondes() - temps)/1000000;
  char bufapple[17] = "src/apple_1X.png";
  char bufwall[16] = "src/wall_1X.png";
  bufapple[11] = G.tcase%10 + '0';
  bufwall[10] = G.tcase%10 + '0';

  ChoisirEcran(1);
  EffacerEcran(choisirCouleur(G.variant, 'b'));

  // Chargement du Snake
  ChoisirCouleurDessin(choisirCouleur(G.variant, 'd'));
  for(i = 0 ; i < B.snake.nbrseg ; i++)
    RemplirRectangle(B.snake.s_seg[i].x, B.snake.s_seg[i].y, G.tcase - 2, G.tcase - 2);

  // Chargement des Bots
  ChoisirCouleurDessin(choisirCouleur(G.variant, 'r'));
  for(i = 0 ; i < B.nbrBot ; i++) {
    for(j = 0; j < 5 ; j++)
      RemplirRectangle(B.bot[i].s_seg[j].x, B.bot[i].s_seg[j].y, G.tcase - 2, G.tcase - 2);
  }

  // Yeux
  ChoisirCouleurDessin(CouleurParNom("black"));
  if(B.snake.dir == UP) {
    RemplirRectangle(B.snake.s_seg[0].x+2, B.snake.s_seg[0].y+2, 3, 3);
    RemplirRectangle(B.snake.s_seg[0].x+7, B.snake.s_seg[0].y+2, 3, 3);
  }
  if(B.snake.dir == DOWN) {
    RemplirRectangle(B.snake.s_seg[0].x+2, B.snake.s_seg[0].y+6, 3, 3);
    RemplirRectangle(B.snake.s_seg[0].x+7, B.snake.s_seg[0].y+6, 3, 3);
  }
  if(B.snake.dir == LEFT) {
    RemplirRectangle(B.snake.s_seg[0].x+2, B.snake.s_seg[0].y+2, 3, 3);
    RemplirRectangle(B.snake.s_seg[0].x+2, B.snake.s_seg[0].y+7, 3, 3);
  }
  if(B.snake.dir == RIGHT) {
    RemplirRectangle(B.snake.s_seg[0].x+6, B.snake.s_seg[0].y+2, 3, 3);
    RemplirRectangle(B.snake.s_seg[0].x+6, B.snake.s_seg[0].y+7, 3, 3);
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

int main () {

  unsigned long temps = Microsecondes();
  srand(time(NULL));

  Settings S;
  Game G;
  Bodies B;
  Apple A;
  Wall W;

  initgame(&G, &B, &A, &W, &S);

  int touche, old_dir = 4;

  while(1) {

    while(!verif(G, B, W) && touche != XK_Escape) {

      usleep(B.snake.speed);
      
      if(ToucheEnAttente()) {
        touche = Touche();

        if(touche == XK_Up || touche == XK_z)
          B.snake.dir = UP;
        if(touche == XK_Down || touche == XK_s)
          B.snake.dir = DOWN;
        if(touche == XK_Right || touche == XK_d)
          B.snake.dir = RIGHT;
        if(touche == XK_Left || touche == XK_q)
          B.snake.dir = LEFT;

        if(old_dir+B.snake.dir == 3 || old_dir+B.snake.dir == 7)
          B.snake.dir = old_dir;
      }

      verifpause(G, B, A, W, &touche, &temps);
      move_forward(G, &B);
      verif_apple(&G, &B, &A, &W, &temps, S);
      draw(G, B, A, W, temps);
      old_dir = B.snake.dir;
    }

    FermerGraphique();
    setScore(G);
    dispMenu(&G, &B, &A, &W, &S);
    temps = Microsecondes();
    old_dir = B.snake.dir;
    touche = 0;
  }
}
