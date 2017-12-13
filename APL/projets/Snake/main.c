#include "main.h"

int forcexit(int touche) {

  if(touche == XK_Escape)
    return 1;
  else
    return 0;
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
  EffacerEcran(CouleurParNom("yellowgreen"));
  ChoisirCouleurDessin(CouleurParNom("khaki"));

  for(i = 0 ; i < B.nbrseg ; i++) {
    RemplirRectangle(B.s_seg[i].x, B.s_seg[i].y, 10, 10);
  }

  ChoisirCouleurDessin(CouleurParNom("red"));
  RemplirRectangle(A.x, A.y, 10, 10);
  //ChargerImage("apple.png",A.x,A.y,0,0,10,10);

  sprintf(buf,"%ld",tmp);
  ChoisirCouleurDessin(CouleurParNom("black"));
  EcrireTexte(WIDTH-20,HEIGHT-20,buf,1);
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

int verif_apple (Body B, Apple A){
  
  if(B.s_seg[0].x == A.x && B.s_seg[0].y == A.y)
    return 1;
  
  return 0;
}

void random_apple (Apple *A) {

  int posx = rand() % HEIGHT;
  int posy = rand() % WIDTH;
  A->x = (posx - posx % CASE);
  A->y = (posy - posy % CASE);

  //printf("posx: %d | posy: %d", A->x, A->y);

  //ChargerImage("goldenapple.png",A->x,A->y,0,0,10,10);
}

void eat_apple (Body *B, Apple *A) {
  
  A->nbr += 5;
  
  B->nbrseg += 2;
  B->s_seg = realloc(B->s_seg, sizeof(Segment) * (B->nbrseg + 1));

  int i = B->nbrseg-2;
  for(; i < 
  
  return random_apple(A);
}

int main () {

  InitialiserGraphique();
  CreerFenetre(500,300,WIDTH,HEIGHT);
  EffacerEcran(CouleurParNom("light grey"));

  srand(time(NULL));
  unsigned long temps = Microsecondes();
  Apple A;
  A.nbr = 0;
  Body snake_body;
  snake_body.nbrseg = 14;
  snake_body.speed = 90000;
  snake_body.s_seg = malloc((snake_body.nbrseg+1) * sizeof(Segment));
  body_init(&snake_body);

  int touche, old_dir = 4;

  random_apple(&A);

  while(!forcexit(touche)) {

    if(verif_apple(snake_body, A)){
      eat_apple(&snake_body, &A);
      snake_body.s_seg = realloc(snake_body.s_seg, sizeof(Segment) * (snake_body.nbrseg+1));
    }
    
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
    move_forward(&snake_body);

    usleep(snake_body.speed);
  }


  FermerGraphique();
  return EXIT_SUCCESS;
}
