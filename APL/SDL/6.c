#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#define WIDTH 480
#define HEIGHT 270

//Dessine un cadre aux bords arrondis
void Cadre(char *chaine){
  int taille = TailleChaineEcran(chaine, 2);
  int hauteur = TailleSupPolice(2);
  int posleft = WIDTH/2 - taille/2 - 10;
  int posup = HEIGHT/2 - hauteur - 10;

  ChoisirCouleurDessin(CouleurParNom("dark green"));
  DessinerArc(posleft, posup, 30, 30, 90, 90);
  DessinerArc(posleft+taille-15, posup, 30, 30, 0, 90);
  DessinerArc(posleft, posup + hauteur - 10, 30, 30, 180, 90);
  DessinerArc(posleft+taille-15, posup + hauteur - 10, 30, 30, 270, 90);
  
  DessinerSegment(posleft+15, posup, posleft+taille,posup);
  DessinerSegment(posleft, posup+hauteur/2+5, posleft, posup+hauteur+8);
  DessinerSegment(posleft+15, posup+42, posleft+taille, posup+42);
  DessinerSegment(posleft+taille+15, posup+hauteur/2+5, posleft+taille+15, posup+hauteur+8);
  ChoisirCouleurDessin(CouleurParNom("black"));
  
}

int main(int argc, char *argv[]) {
    InitialiserGraphique();
    CreerFenetre(500,300,WIDTH,HEIGHT);

    EffacerEcran(CouleurParComposante(119,165,146));

    int taille = TailleChaineEcran(argv[1], 2);
    printf("Taille: %d\n",taille);
    Cadre(argv[1]);
    EcrireTexte(WIDTH/2 - taille/2, HEIGHT/2, argv[1], 2);
    
    while(!SourisCliquee());
    FermerGraphique();
    return EXIT_SUCCESS;
}
