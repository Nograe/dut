#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <graph.h>

int main()
{
  InitialiserGraphique();
  CreerFenetre(500,300,480,270);
  EffacerEcran(CouleurParNom("light steel blue"));
  int temps = 86400, touche = 0;
  int hour, minute, seconds;
  int ref = Microsecondes();

  while(touche != XK_space){

    if (ToucheEnAttente()){
      touche = Touche();
    }
    int tmp = temps - (Microsecondes() - ref)/1000000;
    printf("Microsecondes: %ld\n",Microsecondes());
    hour = tmp / 3600;
    minute = (tmp%3600) / 60;
    seconds = (tmp%60);
    printf("%d:%d:%d\n",hour,minute,seconds);
    sleep(1);

  }

  FermerGraphique();
  return EXIT_SUCCESS;

}
