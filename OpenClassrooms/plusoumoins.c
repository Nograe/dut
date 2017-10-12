#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mystere() {

    int nombreMystere = 0, nombreEntre = 0, coups=0;
    char choix;
    int MAX=100, MIN=1, level=1;
    printf("Niveau de difficulte ? \n   Easy-Default (1) \n   Medium (2) \n   Genius (3)\n");
    scanf("%d", &level);

    if(level==3){
        MAX=10000;
    } else if(level==2){
        MAX=1000;
    }

    // Génération du nombre aléatoire

    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

    /* La boucle du programme. Elle se répète tant que l'utilisateur n'a pas trouvé le nombre mystère */

    do {
        // On demande le nombre
        printf("Quel est le nombre ? ");
        scanf("%d", &nombreEntre);
        coups++;

        // On compare le nombre entré avec le nombre mystère

        if (nombreMystere > nombreEntre)
            printf("C'est plus !\n\n");
        else if (nombreMystere < nombreEntre)
            printf("C'est moins !\n\n");
        else
            printf ("Bravo, vous avez trouve le nombre mystere en %d coups !\n", coups);
    } while (nombreEntre != nombreMystere);

    printf("\nUne autre partie ? \n   C'est parti ! (y) \n   Quitter le programme. (q) \n");
    scanf(" %c", &choix);

    if(choix == 'y') {
        mystere();
        return;
    } else {
        return;
    }
}

int main ( int argc, char** argv ) {

    mystere();

    return 0;
}
