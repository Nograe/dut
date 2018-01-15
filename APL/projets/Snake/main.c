#include "main.h"
#include "menu.h"
//#define DEBUG
//#define DEV

void verifPause (Game G, Bodies B, Apple A, Wall W, int *touche, unsigned long *temps) {

  if(*touche != XK_space)
    return;

  unsigned long tmp = Microsecondes();
  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  int i;
  char buf[10];
  *touche = 0;

  ChoisirEcran(0);

  // Affichage du level
  ChoisirCouleurDessin(choisirCouleur(G.theme, 't'));
  if(G.dispApple) {
    sprintf(buf, "Apples: %d/%d", A.eaten, A.spawn);
    RemplirRectangle(width/2-TailleChaineEcran(buf, 2)/2-20, 0, TailleChaineEcran(buf, 2)+40, 40);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(width/2-TailleChaineEcran(buf, 2)/2, 30, buf, 2);
  }

  #ifdef DEV
  while(*touche != XK_space && *touche != XK_Escape) {

    if(ToucheEnAttente())
      *touche = Touche();

    static int varA = -1, varW = -1, varS = -1, varB = -1;
    SourisPosition();
    for(i = 0; i < A.spawn; i++) {
      if(_X > A.x[i] && _X < A.x[i]+G.tcase && _Y > A.y[i] && _Y < A.y[i]+G.tcase) {
        if(varA != i)
          printf("Apple %d | x: %d | y: %d\n", i, A.x[i], A.y[i]);
        varA = i;
        varW = -1;
        varS = -1;
        varB = -1;
      }
    }
    for(i = 0; i < W.spawn; i++) {
      if(_X > W.x[i] && _X < W.x[i]+G.tcase && _Y > W.y[i] && _Y < W.y[i]+G.tcase) {
        if(varW != i)
          printf("Wall %d | x: %d | y: %d\n", i, W.x[i], W.y[i]);
        varW = i;
        varA = -1;
        varS = -1;
        varB = -1;
      }
    }
    for(i = 0; i < B.snake.nbrseg; i++) {
      if(_X > B.snake.seg[i].x && _X < B.snake.seg[i].x+G.tcase && _Y > B.snake.seg[i].y && _Y < B.snake.seg[i].y+G.tcase) {
        if(varS != i)
          printf("Segment %d | x: %d | y: %d\n", i, B.snake.seg[i].x, B.snake.seg[i].y);
        varS = i;
        varA = -1;
        varW = -1;
        varB = -1;
      }
    }
    for(i = 0; i < B.nbrBot; i++) {
      if(_X > B.bot[i].seg[0].x && _X < B.bot[i].seg[0].x+G.tcase && _Y > B.bot[i].seg[0].y && _Y < B.bot[i].seg[0].y+G.tcase) {
        if(varB != i)
          printf("Bot %d | x: %d | y: %d\n", i, B.bot[i].seg[0].x, B.bot[i].seg[0].y);
        varB = i;
        varA = -1;
        varW = -1;
        varS = -1;
      }
    }
    for(i = 0; i < W.spawn; i++) {
      ChoisirCouleurDessin(CouleurParNom("red"));
      DessinerRectangle(W.x[i], W.y[i]-3*G.tcase, G.tcase, 2*G.tcase);
      DessinerRectangle(W.x[i], W.y[i]+2*G.tcase, G.tcase, 2*G.tcase);
      DessinerRectangle(W.x[i]-3*G.tcase-1, W.y[i], 2*G.tcase, G.tcase);
      DessinerRectangle(W.x[i]+2*G.tcase, W.y[i], 2*G.tcase, G.tcase);
    }
  }
  #else
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  ChargerImage("src/fonts/pause.png", width/2-72/2, height/2-72+50/2, 0, 0, 72, 72);
  while(*touche != XK_space && *touche != XK_Escape)
    *touche = Touche();
  #endif

  CopierZone(1, 0, 0, 0, width, height, 0, 0);
  ChargerImage("src/digits/3pause.png", (width/2) - 67/2, (height/2) - 50, 0, 0, 67, 67);
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  usleep(600000);
  CopierZone(1, 0, 0, 0, width, height, 0, 0);
  ChargerImage("src/digits/2pause.png", (width/2) - 67/2, (height/2) - 50, 0, 0, 67, 67);
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  usleep(600000);
  CopierZone(1, 0, 0, 0, width, height, 0, 0);
  ChargerImage("src/digits/1pause.png", (width/2) - 50/2, (height/2) - 50, 0, 0, 67, 67);
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  usleep(600000);

  *temps += Microsecondes() - tmp;
  while(ToucheEnAttente())
    Touche();
  *touche = 0;
}

void nextLevel (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps) {

  G->level++;
  B->snake.nbrseg = B->initSize;
  B->snake.seg = realloc(B->snake.seg, (B->snake.nbrseg) * sizeof(Segment));
  B->snake.speed -= 6500;
  int i;
  for(i = 0; i < B->nbrBot; i++) {
    B->bot[i].nbrseg++;
    B->bot[i].seg = realloc(B->bot[i].seg, (B->bot[i].nbrseg) * sizeof(Segment));
  }
  A->spawn++;
  A->eaten = 0;
  A->x = realloc(A->x, A->spawn * sizeof(int));
  A->y = realloc(A->y, A->spawn * sizeof(int));
  W->spawn++;
  W->x = realloc(W->x, W->spawn * sizeof(int));
  W->y = realloc(W->y, W->spawn * sizeof(int));

  int width = G->width * G->tcase;
  int height = G->height * G->tcase;
  char buf[10];

  bodyInit(*G, B);
  randomApple(*G, *B, A);
  randomWall(*G, *B, *A, W);
  draw(*G, *B, *A, *W, *temps);

  int touche = XK_space;
  verifPause(*G, *B, *A, *W, &touche, temps);
}

void timer (Game G, Apple A, unsigned long temps) {

  int var = (Microsecondes() - temps)/1000000;
  int sec = var % 60;
  int min = var / 60;
  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  char png[17] = "src/digits/X.png";
  char buf[10];

  #ifdef DEV
  ChoisirCouleurDessin(CouleurParNom("red"));
  DessinerRectangle((width) - 145, (height) - 55, 145, 55);
  DessinerRectangle(0, (height) - 55, 165, 55);
  #endif

  ChoisirCouleurDessin(choisirCouleur(G.theme, 't'));
  RemplirRectangle(0, 0, G.width*G.tcase, G.tcase);
  RemplirRectangle(0, 0, G.tcase, G.height*G.tcase);
  RemplirRectangle(G.width*G.tcase-G.tcase+1, 0, G.tcase, G.height*G.tcase);

  // Affichage temps
  png[11] = (min / 10) + '0';
  ChargerImage(png, width - 135, height - 40, 0, 0, 23, 31);
  png[11] = (min % 10) + '0';
  ChargerImage(png, width - 107, height - 40, 0, 0, 23, 31);
  png[11] = (sec / 10) + '0';
  ChargerImage(png, width - 63, height - 40, 0, 0, 23, 31);
  png[11] = (sec % 10) + '0';
  ChargerImage(png, width - 35, height - 40, 0, 0, 23, 31);

  // Affichage score
  png[11] = (G.score / 10000) + '0';
  ChargerImage(png, 14, height - 40, 0, 0, 23, 31);
  png[11] = (G.score / 1000 % 10) + '0';
  ChargerImage(png, 42, height - 40, 0, 0, 23, 31);
  png[11] = (G.score / 100 % 10) + '0';
  ChargerImage(png, 70, height - 40, 0, 0, 23, 31);
  png[11] = (G.score / 10 % 10) + '0';
  ChargerImage(png, 98, height - 40, 0, 0, 23, 31);
  png[11] = (G.score % 10) + '0';
  ChargerImage(png, 126, height - 40, 0, 0, 23, 31);
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
  int i, j, posx, posy, pvposx, pvposy, nxposx, nxposy;
  char bufapple[17] = "src/apple_1X.png";
  char bufwall[16] = "src/wall_1X.png";
  bufapple[11] = G.tcase%10 + '0';
  bufwall[10] = G.tcase%10 + '0';

  ChoisirEcran(1);
  EffacerEcran(choisirCouleur(G.theme, 'b'));
  ChoisirCouleurDessin(choisirCouleur(G.theme, 't'));
  RemplirRectangle(0, (G.height*G.tcase)-55, G.width*G.tcase, (G.height*G.tcase));

  // Dessin des Segments du Snake
  for(i = 0 ; i < B.snake.nbrseg ; i++) {
    ChoisirCouleurDessin(choisirCouleur(G.theme, 'd'));
    posx = B.snake.seg[i].x;
    posy = B.snake.seg[i].y;
    j = 0;
    if(i > 0 && i < B.snake.nbrseg-1) {
      pvposx = B.snake.seg[i-1].x;
      pvposy = B.snake.seg[i-1].y;
      nxposx = B.snake.seg[i+1].x;
      nxposy = B.snake.seg[i+1].y;
      if((pvposx == posx + G.tcase && pvposy == posy && nxposx == posx && nxposy == posy + G.tcase) || (nxposx == posx + G.tcase && nxposy == posy && pvposx == posx && pvposy == posy + G.tcase)) {
        RemplirArc(posx, posy, G.tcase*2-1, G.tcase*2-1, 90, 90);
        j = 1;
      }
      if((pvposx == posx - G.tcase && pvposy == posy && nxposx == posx && nxposy == posy + G.tcase) || (nxposx == posx - G.tcase && nxposy == posy && pvposx == posx && pvposy == posy + G.tcase)) {
        RemplirArc(posx-G.tcase+1, posy, G.tcase*2-1, G.tcase*2-1, 0, 90);
        j = 1;
      }
      if((pvposx == posx && pvposy == posy - G.tcase && nxposx == posx + G.tcase && nxposy == posy) || (nxposx == posx && nxposy == posy - G.tcase && pvposx == posx + G.tcase && pvposy == posy)) {
        RemplirArc(posx, posy-G.tcase+1, G.tcase*2-1, G.tcase*2-1, 180, 90);
        j = 1;
      }
      if((pvposx == posx && pvposy == posy - G.tcase && nxposx == posx - G.tcase && nxposy == posy) || (nxposx == posx && nxposy == posy - G.tcase && pvposx == posx - G.tcase && pvposy == posy)) {
        RemplirArc(posx-G.tcase+1, posy-G.tcase+1, G.tcase*2-1, G.tcase*2-1, 270, 90);
        j = 1;
      }
    }
    if(j != 1)
      RemplirRectangle(posx+1, posy+1, G.tcase-1, G.tcase-1);
  }

  // Dessin des Yeux du Snake
  ChoisirCouleurDessin(CouleurParNom("black"));
  if(B.snake.dir == UP) {
    RemplirRectangle(B.snake.seg[0].x+2, B.snake.seg[0].y+2, 3, 3);
    RemplirRectangle(B.snake.seg[0].x+7, B.snake.seg[0].y+2, 3, 3);
  }
  if(B.snake.dir == DOWN) {
    RemplirRectangle(B.snake.seg[0].x+2, B.snake.seg[0].y+6, 3, 3);
    RemplirRectangle(B.snake.seg[0].x+7, B.snake.seg[0].y+6, 3, 3);
  }
  if(B.snake.dir == LEFT) {
    RemplirRectangle(B.snake.seg[0].x+2, B.snake.seg[0].y+2, 3, 3);
    RemplirRectangle(B.snake.seg[0].x+2, B.snake.seg[0].y+7, 3, 3);
  }
  if(B.snake.dir == RIGHT) {
    RemplirRectangle(B.snake.seg[0].x+6, B.snake.seg[0].y+2, 3, 3);
    RemplirRectangle(B.snake.seg[0].x+6, B.snake.seg[0].y+7, 3, 3);
  }

  // Dessin des Segments des Bots
  ChoisirCouleurDessin(choisirCouleur(G.theme, 'r'));
  for(i = 0 ; i < B.nbrBot ; i++) {
    for(j = 0; j < B.bot[i].nbrseg ; j++)
      RemplirRectangle(B.bot[i].seg[j].x+1, B.bot[i].seg[j].y+1, G.tcase - 2, G.tcase - 2);
  }

  // Dessin des Yeux des Bots
  ChoisirCouleurDessin(CouleurParNom("brown4"));
  for(i = 0 ; i < B.nbrBot ; i++) {
    if(B.bot[i].dir == UP) {
      RemplirRectangle(B.bot[i].seg[0].x+2, B.bot[i].seg[0].y+2, 3, 3);
      RemplirRectangle(B.bot[i].seg[0].x+7, B.bot[i].seg[0].y+2, 3, 3);
    }
    if(B.bot[i].dir == DOWN) {
      RemplirRectangle(B.bot[i].seg[0].x+2, B.bot[i].seg[0].y+6, 3, 3);
      RemplirRectangle(B.bot[i].seg[0].x+7, B.bot[i].seg[0].y+6, 3, 3);
    }
    if(B.bot[i].dir == LEFT) {
      RemplirRectangle(B.bot[i].seg[0].x+2, B.bot[i].seg[0].y+2, 3, 3);
      RemplirRectangle(B.bot[i].seg[0].x+2, B.bot[i].seg[0].y+7, 3, 3);
    }
    if(B.bot[i].dir == RIGHT) {
      RemplirRectangle(B.bot[i].seg[0].x+6, B.bot[i].seg[0].y+2, 3, 3);
      RemplirRectangle(B.bot[i].seg[0].x+6, B.bot[i].seg[0].y+7, 3, 3);
    }
  }

  // Chargement des Apple
  for(i = 0 ; i < A.spawn ; i++) {
    if(A.x[i] == -G.tcase)
      continue;
    ChargerImage(bufapple, A.x[i], A.y[i], 0, 0, G.tcase, G.tcase);
  }

  // Chargement des Wall
  for(i = 0 ; i < W.spawn ; i++)
    ChargerImage(bufwall, W.x[i], W.y[i], 0, 0, G.tcase, G.tcase);

  // Chargement du Temps - Score
  timer(G, A, temps);
  if(Microsecondes()/300000%2 == 0)
    ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);

  // Affichage Level
  ChoisirCouleurDessin(CouleurParNom("black"));
  sprintf(bufapple, " Level: %d", G.level+1);
  EcrireTexte(width/2-TailleChaineEcran(bufapple, 2)/2, height-15, bufapple, 2);

  ChoisirEcran(0);
  CopierZone(1, 0, 0, 0, width, height, 0, 0);
}

int main () {

  unsigned long temps = Microsecondes();
  srand(time(NULL));

  Game G;
  Bodies B;
  Apple A;
  Wall W;

  initGame(&G, &B, &A, &W);

  int touche, old_dir = 4;

  while(1) {

    while(!verif(&G, &B, W) && touche != XK_Escape) {

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

      verifPause(G, B, A, W, &touche, &temps);
      moveForward(G, &B, A, W);
      verifApple(&G, &B, &A, &W, &temps);
      draw(G, B, A, W, temps);
      old_dir = B.snake.dir;
    }

    FermerGraphique();
    setScore(G);
    dispMenu(&G, &B, &A, &W);
    temps = Microsecondes();
    old_dir = B.snake.dir;
    touche = 0;
  }
}
