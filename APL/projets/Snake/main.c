#include "main.h"
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
  usleep(400000);
  CopierZone(1, 0, 0, 0, width, height, 0, 0);
  ChargerImage("src/digits/2pause.png", (width/2) - 67/2, (height/2) - 50, 0, 0, 67, 67);
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  usleep(400000);
  CopierZone(1, 0, 0, 0, width, height, 0, 0);
  ChargerImage("src/digits/1pause.png", (width/2) - 50/2, (height/2) - 50, 0, 0, 67, 67);
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  usleep(400000);

  *temps += Microsecondes() - tmp;
  while(ToucheEnAttente())
    Touche();
  *touche = 0;
}

void nextLevel (Game *G, Bodies *B, Apple *A, Wall *W, unsigned long *temps) {

  G->level++;
  B->snake.nbrseg = B->initSize;
  B->snake.seg = realloc(B->snake.seg, (B->snake.nbrseg) * sizeof(Segment));
  B->snake.speed -= B->snake.speed/6;
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
  RemplirRectangle(0, (G.height*G.tcase)-55, G.width*G.tcase, (G.height*G.tcase));
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

  // Affichage level
  ChoisirCouleurDessin(CouleurParNom("black"));
  ChargerImage("src/fonts/level.png", width/2-35, height-32, 0, 0, 67, 12);
  sprintf(png, "%d", G.level+1);
  EcrireTexte(width/2+40, height-18, png, 2);
}

void gameOver (Game *G) {

  int width = 60*14;
  int height = 40*14;
  char png[17] = "src/digits/X.png";
  char buf[6];
  int var = -1, decal = 0;

  FermerGraphique();
  InitialiserGraphique();
  CreerFenetre(500, 300, width, height);

  // Affichage du score final et du level atteint
  ChoisirEcran(9);
  EffacerEcran(choisirCouleur(G->theme, 'd'));
  ChargerImageFond("src/gameover.png");
  png[11] = (G->score / 10000) + '0';
  if(png[11] != '0') {
    ChargerImage(png, 445, height/2+14, 0, 0, 23, 31);
    decal += 28;
  }
  png[11] = (G->score / 1000 % 10) + '0';
  if(png[11] != '0') {
    ChargerImage(png, decal+445, height/2+14, 0, 0, 23, 31);
    decal += 28;
  }
  png[11] = (G->score / 100 % 10) + '0';
  if(png[11] != '0') {
    ChargerImage(png, decal+445, height/2+14, 0, 0, 23, 31);
    decal += 28;
  }
  png[11] = (G->score / 10 % 10) + '0';
  if(png[11] != '0') {
    ChargerImage(png, decal+445, height/2+14, 0, 0, 23, 31);
    decal += 28;
  }
  png[11] = (G->score % 10) + '0';
  ChargerImage(png, decal+445, height/2+14, 0, 0, 23, 31);
  if(G->level+1 >= 10) {
    png[11] = (G->level+1)/10 + '0';
    ChargerImage(png, 454, height-194, 0, 0, 23, 31);
    png[11] = (G->level+1)%10 + '0';
    ChargerImage(png, 28+454, height-194, 0, 0, 23, 31);
  }
  else {
    png[11] = (G->level+1)%10 + '0';
    ChargerImage(png, 454, height-194, 0, 0, 23, 31);
  }

  #ifdef DEV
    DessinerRectangle(5, height-70, 64, 64); // Pseudo
    DessinerRectangle(width-70, height-70, 64, 64); // Reset settings
  #endif

  CopierZone(9, 0, 0, 0, width, height, 0, 0);
  while(ToucheEnAttente())
    Touche();
  while(SourisCliquee());
  ChoisirEcran(0);
  while(!ToucheEnAttente()) {
    usleep(50000);
    var++;
    if(var%15 == 0 && var > 30) {
      ChargerImage("src/presskey.png", 220, 460, 0, 0, 426, 20);
    }
    if(var%15 == 8) {
      CopierZone(9, 0, 0, 0, width, height, 0, 0);
    }
    if(var < 40) {
      while(ToucheEnAttente())
        Touche();
    }
    SourisCliquee();
    if(_X >= 5 && _X <= 69 && _Y >= height-70 && _Y <= height-6) {
      changePseudo(G);
      while(SourisCliquee()); // On vide la file d'attente
      _X = 0;
      _Y = 0;
      return;
    }
    if(_X >= width-70 && _X <= width-6 && _Y >= height-70 && _Y <= height-6) {
      G->opt = 1;
      return;
    }
  }
}

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
  ChoisirCouleurDessin(choisirCouleur(G.theme, 'r'));
  if(B.snake.dir == UP) {
    RemplirRectangle(B.snake.seg[0].x+3, B.snake.seg[0].y+4, 3, 3);
    RemplirRectangle(B.snake.seg[0].x+9, B.snake.seg[0].y+4, 3, 3);
  }
  if(B.snake.dir == DOWN) {
    RemplirRectangle(B.snake.seg[0].x+3, B.snake.seg[0].y+8, 3, 3);
    RemplirRectangle(B.snake.seg[0].x+9, B.snake.seg[0].y+8, 3, 3);
  }
  if(B.snake.dir == LEFT) {
    RemplirRectangle(B.snake.seg[0].x+4, B.snake.seg[0].y+3, 3, 3);
    RemplirRectangle(B.snake.seg[0].x+4, B.snake.seg[0].y+9, 3, 3);
  }
  if(B.snake.dir == RIGHT) {
    RemplirRectangle(B.snake.seg[0].x+8, B.snake.seg[0].y+3, 3, 3);
    RemplirRectangle(B.snake.seg[0].x+8, B.snake.seg[0].y+9, 3, 3);
  }

  // Dessin des Segments des Bots
  for(i = 0 ; i < B.nbrBot ; i++) {
    ChoisirCouleurDessin(choisirCouleur(G.theme, 'r'));
    for(j = 0; j < B.bot[i].nbrseg ; j++)
      RemplirRectangle(B.bot[i].seg[j].x+1, B.bot[i].seg[j].y+1, G.tcase-1, G.tcase-1);

    // Dessin des Yeux des Bots
    ChoisirCouleurDessin(choisirCouleur(G.theme, 'd'));
    if(B.bot[i].dir == UP) {
      RemplirRectangle(B.bot[i].seg[0].x+3, B.bot[i].seg[0].y+4, 3, 3);
      RemplirRectangle(B.bot[i].seg[0].x+9, B.bot[i].seg[0].y+4, 3, 3);
    }
    if(B.bot[i].dir == DOWN) {
      RemplirRectangle(B.bot[i].seg[0].x+3, B.bot[i].seg[0].y+8, 3, 3);
      RemplirRectangle(B.bot[i].seg[0].x+9, B.bot[i].seg[0].y+8, 3, 3);
    }
    if(B.bot[i].dir == LEFT) {
      RemplirRectangle(B.bot[i].seg[0].x+4, B.bot[i].seg[0].y+3, 3, 3);
      RemplirRectangle(B.bot[i].seg[0].x+4, B.bot[i].seg[0].y+9, 3, 3);
    }
    if(B.bot[i].dir == RIGHT) {
      RemplirRectangle(B.bot[i].seg[0].x+8, B.bot[i].seg[0].y+3, 3, 3);
      RemplirRectangle(B.bot[i].seg[0].x+8, B.bot[i].seg[0].y+9, 3, 3);
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

  // Chargement du Temps - Score - Level
  timer(G, A, temps);
  if(Microsecondes()/300000%2 == 0)
    ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);

  ChoisirEcran(0);
  CopierZone(1, 0, 0, 0, width, height, 0, 0);
}

void gameModes(Game *G, Bodies *B, Apple *A, Wall *W, int argc, char *argv[]) {

  if(argc < 2)
    return;

  if(argc == 2 && !strcmp(argv[1], "zombie")) {
    G->opt = 2;
    G->width = 100;
    G->height = 60;
    B->nbrBot = 40;
    B->initSpeed = 100000;
    B->initSize = 20;
    A->initSpawn = 0;
    W->initSpawn = 20;
  }
}

int main (int argc, char *argv[]) {

  if(argc > 1 && !strcmp(argv[1], "reset")) {
    remove("src/settings");
    remove("src/scores");
  }
  
  unsigned long temps = Microsecondes();
  srand(time(NULL));

  Game G;
  Bodies B;
  Apple A;
  Wall W;

  initGame(&G, &B, &A, &W, argc, argv);

  int touche, old_dir = 4;

  while(1) {

    while(!verif(&G, &B, W) && touche != XK_Escape) {

      usleep(B.snake.speed);
      
      if(ToucheEnAttente()) {
        touche = Touche();

        while(ToucheEnAttente())
          Touche();

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

    if(touche != XK_Escape)
      gameOver(&G);
    FermerGraphique();
    setScore(G);
    dispMenu(&G, &B, &A, &W);
    temps = Microsecondes();
    old_dir = B.snake.dir;
    touche = 0;
  }
}
