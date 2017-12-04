#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include "menu.h"
#include "snake.h"

void forward (Body *B, int *c) {

    EffacerEcran(CouleurParNom("light grey"));

    if(*c > 100)
        return;

	int i;
	for(i = 0 ; i < 4 ; i++) {
		B->s_seg[i].x = POSX + *c;
		B->s_seg[i].y = POSY;
		*c+=12;
	}

	ChoisirCouleurDessin(CouleurParNom("yellow"));

	for(i = 0 ; i < 4 ; i++)
		RemplirRectangle(B->s_seg[i].x, B->s_seg[i].y, 10, 10);

    sleep(1);
    return forward(B, c-(12*2));
}

int main () {

	InitialiserGraphique();
	CreerFenetre(500,300,400,400);
	EffacerEcran(CouleurParNom("light grey"));

	Body snake_body;
	snake_body.s_seg = malloc(4 * sizeof(Segment));

    int c = 0;
    forward(&snake_body, &c);

	Touche();
	FermerGraphique();
	return 0;
}
