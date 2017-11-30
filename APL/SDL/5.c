#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#define WIDTH 500
#define HEIGHT 500

int forcexit(int *touche){

  if(*touche == XK_space)
    return 1;
  else
    return 0;
  
}

void draw_target(int x, int y){
  
  ChoisirCouleurDessin(CouleurParNom("red"));
  DessinerArc(x, y, 60, 60, 360, 360);
  ChoisirCouleurDessin(CouleurParNom("black"));
}

void draw_viseur(int x, int y){

  DessinerSegment(x+15, y, x+15, y+30);
  DessinerSegment(x, y+15, x+30, y+15);
  DessinerArc(x, y, 30, 30, 360, 360);
}

int main()
{
  InitialiserGraphique();
  CreerFenetre(500,300,WIDTH,HEIGHT);

  int touche = 0, x = 0, y = 0, c = 0;
  EffacerEcran(CouleurParNom("light steel blue"));
  int target = 0, target_y, target_x;
  srand(time(NULL));

  while(touche != XK_space){

    if (ToucheEnAttente()){
      touche = Touche();
    }

    target_x = rand() % (HEIGHT - 60) + 60;
    target_y = rand() % (WIDTH - 60) + 60;
    draw_target(target_x, target_y);
    
    x = WIDTH/2-15;
    y = HEIGHT/2-15;
    draw_viseur(x, y);
      
    while(!target){
    
      touche = Touche();
      if(forcexit(&touche))
	break;

      EffacerEcran(CouleurParNom("light steel blue"));
      if(touche == XK_Left){
	x-=5;
	draw_viseur(x, y);
      }

      if(touche == XK_Right){
	x+=5;
	draw_viseur(x, y);
      }
      
      if(touche == XK_Up){
	y-=5;
	draw_viseur(x, y);
      }
      
      if(touche == XK_Down){
	y+=5;
	draw_viseur(x, y);
      }
      draw_target(target_x, target_y);
    }
  }

  FermerGraphique();
  return EXIT_SUCCESS;

}
