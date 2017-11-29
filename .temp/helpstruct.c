#include <stdio.h>

typedef struct{
   int age;
   char *prenom;
   char *pseudo;
} Personne;

typedef enum{
   PACIFIC=1,
   NORMAL,
   HARDCORE
} Level;

void InitJoueur(Personne *joueur){
   
   joueur->age = 18;
   joueur->prenom = "Prenom";
   joueur->pseudo = "Pseudo";
   
}

int main (int argc, char *argv[]){
   
   Personne joueur1,joueur2;
   InitJoueur(&joueur1);
   InitJoueur(&joueur2);
   
   Level jeu = PACIFIC;
   
   printf("%d %s %s %d",joueur1.age, joueur1.prenom, joueur1.pseudo,jeu);
   
   return 0;
}
