#include "main.h"
//#define DEBUG
//#define DEV

// Cette fonction permet de gérer le menu pause
void verifPause (Game G, Apple A, int *touche, unsigned long *temps) {

  if(*touche != XK_space)
    return;

  unsigned long tmp = Microsecondes();
  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  char buf[10];
  *touche = 0;

  ChoisirEcran(1);

  // Affichage du level
  ChoisirCouleurDessin(choisirCouleur(G.theme, 't'));
  if(G.dispApple) {
    sprintf(buf, "Apples: %d/%d", A.eaten, A.spawn);
    RemplirRectangle(width/2-TailleChaineEcran(buf, 2)/2-20, 0, TailleChaineEcran(buf, 2)+40, 40);
    ChoisirCouleurDessin(CouleurParNom("black"));
    EcrireTexte(width/2-TailleChaineEcran(buf, 2)/2, 30, buf, 2);
  }
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  CopierZone(1, 2, 0, 0, width, height, 0, 0);

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
  ChoisirEcran(2);
  ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);
  ChargerImage("src/fonts/pause.png", width/2-72/2, height/2-72+50/2, 0, 0, 72, 72);
  while(*touche != XK_space && *touche != XK_Escape) {
    if(Microsecondes()/500000%2 == 0)
      CopierZone(2, 0, width/2-72/2, height/2-72+50/2, 72, 72, width/2-72/2, height/2-72+50/2);
    else
      CopierZone(1, 0, 0, 0, width, height, 0, 0);
    if(ToucheEnAttente())
      *touche = Touche();
  }
  #endif

  ChoisirEcran(0);
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

// On passe un niveau, remise de tous les paramètres initiaux
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

  bodyInit(*G, B);
  randomApple(*G, *B, A);
  randomWall(*G, *B, *A, W);
  draw(*G, *B, *A, *W, *temps);

  int touche = XK_space;
  verifPause(*G, *A, &touche, temps);
}

// Afficher le temps, le level et le score
void printData (Game G, unsigned long temps) {

  int var = (Microsecondes() - temps)/1000000;
  int sec = var % 60;
  int min = var / 60;
  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  char png[17] = "src/digits/X.png";

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

// Afficher l'écran de fin de jeu, avec bouton pseudo et highscores
void gameOver (Game *G) {

  int width = 60*14;
  int height = 40*14;
  char png[17] = "src/digits/X.png";
  int decal = 0, touche = 0;

  FermerGraphique();
  InitialiserGraphique();
  CreerFenetre(500, 300, width, height);

  // Affichage du score final et du level atteint
  ChoisirEcran(9);
  EffacerEcran(choisirCouleur(G->theme, 'd'));
  ChargerImageFond("src/backgrounds/gameover.png");
  png[11] = (G->score / 10000) + '0';
  if(G->score >= 10000) {
    ChargerImage(png, 449, height/2+14, 0, 0, 23, 31);
    decal += 28;
  }
  png[11] = (G->score / 1000 % 10) + '0';
  if(G->score >= 1000) {
    ChargerImage(png, decal+449, height/2+14, 0, 0, 23, 31);
    decal += 28;
  }
  png[11] = (G->score / 100 % 10) + '0';
  if(G->score >= 100) {
    ChargerImage(png, decal+449, height/2+14, 0, 0, 23, 31);
    decal += 28;
  }
  png[11] = (G->score / 10 % 10) + '0';
  if(G->score >= 10) {
    ChargerImage(png, decal+449, height/2+14, 0, 0, 23, 31);
    decal += 28;
  }
  png[11] = (G->score % 10) + '0';
  ChargerImage(png, decal+449, height/2+14, 0, 0, 23, 31);

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
  while(SourisCliquee());
  _X = 0;
  _Y = 0;
  ChoisirEcran(0);

  while(touche != XK_Escape) {
    usleep(50000);
    if(Microsecondes()/400000%2 == 1) {
      ChargerImage("src/fonts/presskey.png", 220, 460, 0, 0, 426, 20);
    }
    if(Microsecondes()/400000%2 == 0) {
      CopierZone(9, 0, 0, 0, width, height, 0, 0);
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

    if(ToucheEnAttente())
      touche = Touche();
  }
}

// Affichage de l'écran de jeu
void draw (Game G, Bodies B, Apple A, Wall W, unsigned long temps) {

  int width = G.width * G.tcase;
  int height = G.height * G.tcase;
  int i, j, posx, posy, pvposx, pvposy, nxposx, nxposy;
  char bufapple[23] = "src/icons/apple_1X.png";
  char bufwall[22] = "src/icons/wall_1X.png";
  bufapple[17] = G.tcase%10 + '0';
  bufwall[16] = G.tcase%10 + '0';

  ChoisirEcran(1);
  EffacerEcran(choisirCouleur(G.theme, 'b'));

  // Dessin des Segments du Snake, et dessin des segments qui sont en angle
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
  printData(G, temps);
  if(Microsecondes()/300000%2 == 0)
    ChargerImage("src/digits/:.png", width - 85, height - 40, 0, 0, 23, 31);

  ChoisirEcran(0);
  CopierZone(1, 0, 0, 0, width, height, 0, 0);
}

// Gestion des modes de jeu
void gameModes(Game *G, Bodies *B, Apple *A, Wall *W, int argc, char *argv[]) {

  if(argc < 2)
    return;

  if(argc == 2 && !strcmp(argv[1], "zombie")) {
    G->opt = 2;
    G->width = 100;
    G->height = 60;
    strncpy(G->pseudo, "Survivant", 11);
    B->nbrBot = 40;
    B->initSpeed = 100007;
    B->initSize = 20;
    A->initSpawn = 0;
    W->initSpawn = 20;
  }

  if(argc == 2 && !strcmp(argv[1], "minimoys")) {
    G->opt = 3;
    strncpy(G->pseudo, "Arthur", 11);
    B->nbrBot = 20;
    B->initSpeed = 50004;
    B->initSize = 1;
    A->initSpawn = 1;
  }

  if(argc == 2 && !strcmp(argv[1], "flash")) {
    G->opt = 3;
    strncpy(G->pseudo, "Flash", 11);
    B->nbrBot = 0;
    B->initSpeed = 20004;
    B->initSize = 10;
    A->initSpawn = 1;
  }

  /*if(argc == 2 && !strcmp(argv[1], "EXEMPLE")) {
      ...
    Modification des paramètres
      ...
  }*/
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

  int touche, old_dir = B.snake.dir;

  while(1) {

    while(!verif(&G, &B, W) && touche != XK_Escape) {

      usleep(B.snake.speed);
      
      if(ToucheEnAttente())
        changeDir(&B, &touche, old_dir);

      verifPause(G, A, &touche, &temps);
      moveBodies(G, &B, A, W);
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
