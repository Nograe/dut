#include <stdio.h>
#include <stdlib.h>

typedef enum {
    Pique = 1,
    Carreau,
    Trefle,
    Coeur
} CouleurCarte;

typedef struct {
    int valeur;
    CouleurCarte couleur;
} Carte;

typedef struct {
    Carte paquet[52];
    int reste;
} Deck;

typedef struct {
	char *name;
	Carte main[5];
	int restemain;
	int argent;
	int mise;
	int couche;
} Player;

void printcarte (Carte c) {
    printf("Valeur: %d\t Couleur: %d\n", c.valeur, c.couleur);
}

void printdeck (Deck d) {
    int i, nbr = d.reste;

    for(i = 0; i < nbr ; i++)
        printcarte(d.paquet[i]);
}

void initdeck (Deck *d) {
    int i = 1, j = 0, k = 0;
    while(i <= 13) {
        for(j = 1 ; j <= 4 ; j++) {
            d->paquet[k].valeur = i;
            d->paquet[k].couleur = j;
            k++;
        }
        i++;
    }
    d->reste = 52;
}

void melangedeck (Deck *d) {

}

void printmain (Player p) {

    int i, nbr = p.restemain;

    for(i = 0; i < nbr ; i++)
        printcarte(p.main[i]);
}

void givetoplayer (Player *p, Deck *d) {

	int cartejoueur = p->restemain;
	int cartedeck = d->reste - 1;

    p->main[cartejoueur].valeur = d->paquet[cartedeck].valeur;
    p->main[cartejoueur].couleur = d->paquet[cartedeck].couleur;

    p->restemain = p->restemain+1;
    d->reste = d->reste-1;
}

int main () {
    Carte j1,j2;

    j1.valeur = 12;
    j1.couleur = Trefle;
    //printcarte(j1);

    Deck maindeck;
    initdeck(&maindeck);
    //printdeck(maindeck);

	Player joueur1;
	joueur1.restemain = 0;
	givetoplayer(&joueur1, &maindeck);
	printmain(joueur1);
	printdeck(maindeck);

	return (0);
}
