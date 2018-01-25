#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
 
int main()
{
  InitialiserGraphique();
  CreerFenetre(500,300,480,270);

  int touche = 0, x = 0, y = 0, v = 0, c = 0;
  EffacerEcran(CouleurParNom("light steel blue"));

  while(touche != XK_space){

    if (ToucheEnAttente()){
      touche = Touche();
    }

    if(touche == XK_Return){
      EffacerEcran(CouleurParNom("light steel blue"));
      v = 0;
      touche = 0;
    }
    
    touche = Touche();

    if(touche == XK_a)
      v = 0;

    if(touche == XK_z)
      v = 1;

    if(touche == XK_e)
      v = 2;

    if(touche == XK_r)
      v = 3;

    SourisPosition();

    if (v == 0) {
      x = _X;
      y = _Y;
      ChoisirCouleurDessin(CouleurParNom("dark blue"));
      DessinerRectangle(_X-25,_Y-25,50,50);
    } else if (v == 1) {
      x = _X;
      y = _Y;
      ChoisirCouleurDessin(CouleurParNom("dark green"));
      RemplirArc(_X-25,_Y-25,50,50,360,360);
    } else if (v == 2) {
      x = _X;
      y = _Y;
      ChoisirCouleurDessin(CouleurParNom("purple"));
      EcrireTexte(_X-13,_Y+5,">0<",1);
    } else if (v == 3) {
      x = _X;
      y = _Y;
      ChoisirCouleurDessin(0);
      ChargerImage("cercles.png",_X-103/2,_Y-36/2,0,0,103,36);
    }

  }

  FermerGraphique();
  return EXIT_SUCCESS;

}
