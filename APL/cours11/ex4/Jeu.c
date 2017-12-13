#include "Player.h"
#include "Deck.h"

typedef struct {
    Deck deck_jeu;
    Player *joueurs;
    int nbr_joueurs;
    int start_player;
} Jeu;
