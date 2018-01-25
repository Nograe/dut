#include <stdio.h>
#include <stdlib.h>
#include "C:\libs\bibliotheque-graphique-iut-1.1\src\include\graph.h"

int main()
{
  InitialiserGraphique();
  CreerFenetre(500,300,480,270);

  /*
    int clic = SourisCliquee();
    while(clic != 1)
      clic = SourisCliquee();
   */
  int touche = Touche();
  while(touche != XK_space){
    touche = Touche();
  }

  FermerGraphique();
  return EXIT_SUCCESS;

}
