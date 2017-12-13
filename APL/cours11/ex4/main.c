#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct {
    Deck deck_jeu;
    Player *joueurs;
    int nbr_joueurs;
    int start_player;
} Jeu;

void printcarte (Carte c) {
    printf("Valeur: %d\t Couleur: %d\n", c.valeur, c.couleur);
}

void printdeck (Deck d) {
    int i, nbr = d.reste;

    for(i = 0; i < nbr ; i++) {
        printcarte(d.paquet[i]);
    }
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

void melangedeck (Deck *d, int repet) {


    int i, x, y;
    int temp_color, temp_value;

    for(i = 0 ; i < repet ; i++) {

		x = rand()%52;
		y = rand()%52;

        temp_value = d->paquet[x].valeur;
        temp_color = d->paquet[x].couleur;

        d->paquet[x].valeur = d->paquet[y].valeur;
        d->paquet[x].couleur = d->paquet[y].couleur;
        //printf("Carte %d   Couleur %d   Valeur: %d\n", x, d->paquet[x].couleur, d->paquet[x].valeur);

        d->paquet[y].valeur = temp_value;
        d->paquet[y].couleur = temp_color;
        //printf("Carte %d   Couleur %d   Valeur: %d\n", y, d->paquet[y].couleur, d->paquet[y].valeur);
    }
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

    d->paquet[cartedeck].valeur = 0;
    d->paquet[cartedeck].couleur = 0;

    p->restemain = p->restemain+1;
    d->reste = d->reste-1;
}

void echange (Player *p, Deck *d, int i){

  int carte = rand() % 52;

  while(d->paquet[carte].valeur == 0)
    carte = rand() % 52;

  Carte temp;
  
  p->main[i] = temp;
  p->main[i] = d->paquet[carte];
  d->paquet[carte] = temp;
}

Jeu initgame (char players[][10], int player_isbot[], int nbrplayer, int bid){

    Jeu partie;
    
    partie.joueurs = malloc(sizeof(Player) * nbrplayer);

    int i;
    for(i = 0 ; i < nbrplayer ; i++){
      partie.joueurs[i].name = players[i];
      partie.joueurs[i].restemain = 0;
      partie.joueurs[i].mise = bid;
      partie.joueurs[i].argent = bid;
      partie.joueurs[i].couche = 0;      
    }

    return partie;
}

void distrib (Jeu *p, int nbrcartes){

  int i, player = p->nbr_joueurs;

  while(player != 0){
    for( i = 0 ; i < 5 ; i++)
      givetoplayer(&(p->joueurs[player-1]), &(p->deck_jeu));
    player--;
  }
}

int compare (Jeu p) {

  return best(p.joueurs[0], p.joueurs[1]);
}

int best (Player p1, Player p2) {
  
  return 1;
}

int main () {
    srand(time(NULL));

    Carte j1,j2;

    j1.valeur = 12;
    j1.couleur = Trefle;
    //printcarte(j1);

    Deck maindeck;
    initdeck(&maindeck);
    //printdeck(maindeck);
    melangedeck(&maindeck, 100);
    //printdeck(maindeck);

    Player joueur1;
    joueur1.restemain = 0;
    givetoplayer(&joueur1, &maindeck);
    //printmain(joueur1);
    //printf("Première carte Deck:"); printcarte(maindeck.paquet[maindeck.reste-1]);
    echange(&joueur1, &maindeck, 0);
    //printmain(joueur1);
    
    char players[2][10] = {"matt","joueur1"};
    int isbot[2] = {0,1};
    int nbrplayer = 2;
    int bid = 150;
    Jeu partie = initgame(players, isbot, nbrplayer, bid);

    

    return (0);
}
