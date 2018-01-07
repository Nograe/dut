#include "main.h"

int forcexit(int touche) {

  if(touche == XK_Escape)
    return 1;
  else
    return 0;
}

void verifpause (Body *B, Apple *A, int *touche, unsigned long *temps) {

  if(*touche != XK_space)
    return;

  unsigned long tmp = Microsecondes();

  EcrireTexte(WIDTH/2 -40,HEIGHT/2 -20,"PAUSE",2);
  EcrireTexte(WIDTH/2 -42,HEIGHT/2,"Press SPACE",0);

  do {
    *touche = Touche();
  } while (*touche != XK_space && *touche != XK_Escape);

  int diff = Microsecondes() - tmp;

  draw(*B, *A, *temps+diff);
  EcrireTexte(WIDTH/2 -40,HEIGHT/2 -20,"3",2);
  sleep(1);
  draw(*B, *A, *temps+diff+1000000);
  EcrireTexte(WIDTH/2 -40,HEIGHT/2 -20,"2",2);
  sleep(1);
  draw(*B, *A, *temps+diff+2000000);
  EcrireTexte(WIDTH/2 -40,HEIGHT/2 -20,"1",2);
  sleep(1);

  *temps += diff+3000000;
  *touche = 0;
}

void move_forward (Body *B) {

  B->s_seg[B->nbrseg] = B->s_seg[B->nbrseg-1];
  int i;
  for(i = B->nbrseg-1 ; i >= 1 ; i--) {
    B->s_seg[i] = B->s_seg[i-1];
  }

  switch(B->s_dir) {
  case 1:
    B->s_seg[0].y -= CASE;
    break;
  case 2:
    B->s_seg[0].y += CASE;
    break;
  case 3:
    B->s_seg[0].x -= CASE;
    break;
  case 4:
    B->s_seg[0].x += CASE;
    break;
  }
}

void draw (Body B, Apple A, unsigned long temps) {

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
  if(A.golden)
    ChargerImage("golden_apple.png",A.x,A.y,0,0,13,13);
  else
    ChargerImage("apple.png",A.x,A.y,0,0,13,13);

  // Temps - Score
  sprintf(buf,"%ld",tmp);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(WIDTH-30,HEIGHT-20,buf,1);
  sprintf(buf,"%d",A.nbr);
  EcrireTexte(20,HEIGHT-20,buf,1);

  ChoisirEcran(0);
  EffacerEcran(CouleurParNom("yellowgreen"));
  CopierZone(1, 0, 0, 0, WIDTH, HEIGHT, 0, 0);
}

void body_init (Body *B) {
  int i;
  int posx = POSX;
  int posy = POSY;
  for(i = 0 ; i < B->nbrseg ; i++) {
    B->s_seg[i].x = posx;
    B->s_seg[i].y = posy;
    posx-=12;
  }
  B->s_dir = 4;
}

int verif (Body S) {

  int x = S.s_seg[0].x;
  int y = S.s_seg[0].y;
  if(x <= -12 || x >= WIDTH || y <= -12 || y >= HEIGHT) {
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

void verif_apple (Body *B, Apple *A){
  
  if(B->s_seg[0].x == A->x && B->s_seg[0].y == A->y)
    return eat_apple(B, A);
  
  return;
}

void random_apple (Body *B, Apple *A) {

  A->golden = 0;

  int posx = rand() % WIDTH;
  int posy = rand() % HEIGHT;
  A->x = (posx - posx % CASE);
  A->y = (posy - posy % CASE);

  int random = rand() % 5;
  if(random == 1)
    A->golden = 1;

  int i;
  for(i = 0 ; i < B->nbrseg ; i++){
    if(A->x == B->s_seg[i].x && A->y == B->s_seg[i].y)
      return random_apple (B, A);
  }
}

void eat_apple (Body *B, Apple *A) {
  
  int score = 2;
  int addseg = 2;

  if(A->golden){
    score = 5;
    addseg = 4;
  }

  A->nbr += score;
  B->nbrseg += addseg;

  B->s_seg = realloc(B->s_seg, sizeof(Segment) * (B->nbrseg + 1));

  int i = B->nbrseg-addseg;
  for(; i < B->nbrseg ; i++){
    printf("[%d] prend : [%d]\n", i, B->nbrseg-addseg-1);
    B->s_seg[i] = B->s_seg[B->nbrseg-addseg-1];
  }
  
  return random_apple(B, A);
}

int main () {

  InitialiserGraphique();
  CreerFenetre(500,300,WIDTH,HEIGHT);
  EffacerEcran(CouleurParNom("light grey"));

  srand(time(NULL));
  unsigned long temps = Microsecondes();
  Apple A;
  A.nbr = 0;
  A.spawn = 5;
  Body snake_body;
  snake_body.nbrseg = 10;
  snake_body.speed = 90000;
  snake_body.s_seg = malloc((snake_body.nbrseg+1) * sizeof(Segment));

  body_init(&snake_body);
  random_apple(&snake_body, &A);

  int touche, old_dir = 4;

  while(!forcexit(touche)) {

    verif_apple(&snake_body, &A);
    
    draw(snake_body, A, temps);

    if(ToucheEnAttente()) {
      touche = Touche();
    
      if(touche == XK_Up)
	snake_body.s_dir = UP;
      if(touche == XK_Down)
	snake_body.s_dir = DOWN;
      if(touche == XK_Left)
	snake_body.s_dir = LEFT;
      if(touche == XK_Right)
	snake_body.s_dir = RIGHT;
    

      if(old_dir+snake_body.s_dir == 3 || old_dir+snake_body.s_dir == 7)
	snake_body.s_dir = old_dir;
      
      old_dir = snake_body.s_dir;
    }

    if(verif(snake_body)) {
      break;
    }

    verifpause(&snake_body, &A, &touche, &temps);

    move_forward(&snake_body);

    usleep(snake_body.speed);
  }


  FermerGraphique();
  return EXIT_SUCCESS;
}
