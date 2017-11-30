#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
 
int main()
{
    InitialiserGraphique();
    CreerFenetre(500,300,470,280);

    couleur fill = CouleurParNom("light steel blue");
    EffacerEcran(fill);
    couleur trace = CouleurParNom("dark cyan");
    ChoisirCouleurDessin(trace);
    RemplirRectangle(200,100,70,50);

    Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}
