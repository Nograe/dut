#include "main.h"

int forcexit(int touche) {

  if(touche == XK_Escape)
    return 1;
  else
    return 0;
}

void verifpause (Game G, Body *B, Apple *A, int *touche, unsigned long *temps) {

  if(*touche != XK_space)
    return;

  unsigned long tmp = Microsecondes();

  EcrireTexte(G.width/2 - 40, G.height/2 -20, "PAUSE", 2);
  EcrireTexte(G.width/2 - 42, G.height/2, "Press SPACE", 0);

  do {
    *touche = Touche();
  } while (*touche != XK_space);

  int diff = Microsecondes() - tmp;

  draw(G, *B, *A, *temps+diff);
  EcrireTexte(G.width/2 - 20,G.height/2 -20,"3",2);
  sleep(1);
  draw(G, *B, *A, *temps+diff+1000000);
  EcrireTexte(G.width/2 - 20,G.height/2 -20,"2",2);
  sleep(1);
  draw(G, *B, *A, *temps+diff+2000000);
  EcrireTexte(G.width/2 - 20,G.height/2 -20,"1",2);
  sleep(1);

  *temps += diff+3000000;
  while(ToucheEnAttente() == 1)
    Touche();
  *touche = 0;
}

void next_level (Game G, Body *B, Apple *A, unsigned long *temps) {

  B->dir = 4;
  A->spawn++;
  A->eaten = 0;
  A->x = malloc(A->spawn * sizeof(int));
  A->y = malloc(A->spawn * sizeof(int));
  B->speed -= 5000;
  random_apple(G, *B, A);

  body_init(G, B);
  EffacerEcran(CouleurParNom("goldenrod"));
  ChoisirCouleurDessin(CouleurParNom("darkred"));
  EcrireTexte(G.width / 2, G.height / 2 - 20, "NEXT LEVEL!", 2);
  EcrireTexte(G.width / 2 + 1, G.height / 2 - 20, "NEXT LEVEL!", 2);
  sleep(2);
  draw(G, *B, *A, *temps);

  int touche = XK_space;
  verifpause(G, B, A, &touche, temps);
}

void printscore (Game G, Apple A) {

  char buf[6];

  ChoisirEcran(1);
  ChoisirCouleurDessin(CouleurParNom("black"));

  EcrireTexte(G.width / 3, G.height / 2, "YOUR SCORE: ", 2);
  sprintf(buf,"%d",A.total*5);
  EcrireTexte(G.width / 3 + TailleChaineEcran("YOUR SCORE: 0", 2), G.height / 2, buf, 2);

  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("seagreen"));
  CopierZone(1, 0, 0, 0, G.width, G.height, 0, 0);

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

void draw (Game G, Body B, Apple A, unsigned long temps) {

  int i;
  unsigned long tmp = (Microsecondes() - temps)/1000000;
  char buf[10];

  ChoisirEcran(1);
  EffacerEcran(CouleurParNom("goldenrod"));
  ChoisirCouleurDessin(CouleurParNom("seagreen"));

  for(i = 0 ; i < B.nbrseg ; i++) {
    RemplirRectangle(B.s_seg[i].x, B.s_seg[i].y, 10, 10);
  }


  // Apple
  for(i = 0 ; i < A.spawn ; i++)
    ChargerImage("apple.png",A.x[i]-1,A.y[i]-1,0,0,13,13);

  // Temps - Score
  sprintf(buf,"%ld",tmp);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(G.width-30,G.height-20,buf,1);
  sprintf(buf,"%d",A.total*5);
  EcrireTexte(20,G.height-20,buf,1);

  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("seagreen"));
  CopierZone(1, 0, 0, 0, G.width, G.height, 0, 0);
}

void body_init (Game G, Body *B) {
  int i;
  int posx = G.width / 2;
  int posy = G.height / 2;
  for(i = 0 ; i < B->nbrseg ; i++) {
    B->s_seg[i].x = posx;
    B->s_seg[i].y = posy;
    posx -= 12;
  }
  B->dir = 4;
}

int verif (Game G, Body S) {

  int x = S.s_seg[0].x;
  int y = S.s_seg[0].y;
  if(x <= -12 || x >= G.width || y <= -12 || y >= G.height) {
    //printf("Coords: %d | %d", x, y);
    return 1;
  }

  int i;
  for(i = 4 ; i <= S.nbrseg ; i++) {
    if(x == S.s_seg[i].x && y == S.s_seg[i].y) {
      //printf("Collision bloc %d : %d | %d\n", i+1, x, y);
      ChoisirCouleurDessin(CouleurParNom("red"));
      RemplirRectangle(S.s_seg[i].x, S.s_seg[i].y, 10, 10);
      sleep(3);
      return 1;
    }
  }

  return 0;
}

int verif_apple (Body *B, Apple *A) {

  int i;
  for(i = 0 ; i < A->spawn ; i++) {
    if(B->s_seg[0].x == A->x[i] && B->s_seg[0].y == A->y[i]){
      A->x[i] = -13;
      A->y[i] = -13;
      eat_apple(B, A);
      return 0;
    }
  }

  if(A->eaten == A->spawn)
    return 1;

  return 0;
}

void random_apple (Game G, Body B, Apple *A) {

  int posx, posy, i, j;
  for(i = 0 ; i < A->spawn ; i++){
    posx = rand() % G.width;
    posy = rand() % G.height;
    A->x[i] = (posx - posx % G.tcase);
    A->y[i] = (posy - posy % G.tcase);
  }

  for(i = 0 ; i < B.nbrseg ; i++){
    for(j = 0 ; j < A->spawn ; j++) {
      if(A->x[j] == B.s_seg[i].x && A->y[j] == B.s_seg[i].y)
        return random_apple (G, B, A);
    }
  }
}

void eat_apple (Body *B, Apple *A) {

  A->eaten++;
  A->total++;
  B->nbrseg += 2;

  B->s_seg = realloc(B->s_seg, sizeof(Segment) * (B->nbrseg + 1));

  int i = B->nbrseg-2;
  for(; i < B->nbrseg ; i++){
    //printf("[%d] prend : [%d]\n", i, B->nbrseg-2-1);
    B->s_seg[i] = B->s_seg[B->nbrseg-2-1];
  }
}


int main () {

  unsigned long temps = Microsecondes();

  Game G;
  G.tcase = 12;
  G.width = 60 * G.tcase;
  G.height = 40 * G.tcase;

  Body snake_body;
  snake_body.nbrseg = 10;
  snake_body.speed = 90000;
  snake_body.s_seg = malloc((snake_body.nbrseg+1) * sizeof(Segment));

  Apple A;
  A.eaten = 0;
  A.total = 0;
  A.spawn = 5;
  A.x = malloc(A.spawn * sizeof(int));
  A.y = malloc(A.spawn * sizeof(int));
  
  InitialiserGraphique();
  CreerFenetre(500,300,G.width,G.height);
  EffacerEcran(CouleurParNom("light grey"));

  srand(time(NULL));
  body_init(G, &snake_body);
  random_apple(G, snake_body, &A);

  int touche, old_dir = 4;

  while(!forcexit(touche)) {

    if(verif_apple(&snake_body, &A)) {
      next_level(G, &snake_body, &A, &temps);
      old_dir = snake_body.dir;
    }
    
    draw(G, snake_body, A, temps);

    usleep(snake_body.speed);

    if(ToucheEnAttente()) {
      touche = Touche();

      switch(touche) {
        case XK_Up:
        snake_body.dir = UP;
        break;
        case XK_Down:
        snake_body.dir = DOWN;
        break;
        case XK_Left:
        snake_body.dir = LEFT;
        break;
        case XK_Right:
        snake_body.dir = RIGHT;
        break;
      }

      if(old_dir+snake_body.dir == 3 || old_dir+snake_body.dir == 7)
       snake_body.dir = old_dir;

     old_dir = snake_body.dir;
   }

   if(verif(G, snake_body))
    break;

  verifpause(G, &snake_body, &A, &touche, &temps);

  move_forward(G, &snake_body);
}

printscore(G, A);

FermerGraphique();
return EXIT_SUCCESS;
}
