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

    if (ToucheEnAttente())
      touche = Touche();

    if(touche == XK_Return){
      EffacerEcran(CouleurParNom("light steel blue"));
      v = 0;
      touche = 0;
    }

    c = SourisCliquee();

    if (c && v == 0) {
      x = _X;
      y = _Y;
      ChoisirCouleurDessin(CouleurParNom("dark blue"));
      DessinerRectangle(_X-25,_Y-25,50,50);
      v = 1;
    } else if (c && v == 1) {
      x = _X;
      y = _Y;
      ChoisirCouleurDessin(CouleurParNom("dark green"));
      RemplirArc(_X-25,_Y-25,50,50,360,360);
      v = 2;
    } else if (c && v == 2) {
      x = _X;
      y = _Y;
      ChoisirCouleurDessin(CouleurParNom("purple"));
      EcrireTexte(_X-13,_Y+5,">0<",1);
      v = 3;
    } else if (c && v == 3) {
      x = _X;
      y = _Y;
      ChoisirCouleurDessin(0);
      ChargerImage("cercles.png",_X-103/2,_Y-36/2,0,0,103,36);
      v = 0;
    }

  }

  FermerGraphique();
  return EXIT_SUCCESS;

}
