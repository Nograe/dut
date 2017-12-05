#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include "menu.h"
#include "snake.h"
#define WIDTH 400
#define HEIGHT 400

int forcexit(int touche) {

	if(touche == XK_Escape)
		return 1;
	else
		return 0;
}

void move_forward (Body *B, int nbr) {

	EffacerEcran(CouleurParNom("light grey"));
	ChoisirCouleurDessin(CouleurParNom("yellow"));

	int i;
	for(i = nbr-1 ; i >= 1 ; i--) {
		B->s_seg[i] = B->s_seg[i-1];
	}

	switch(B->s_dir) {
	case 1:
		B->s_seg[0].y-=12;
		break;
	case 2:
		B->s_seg[0].y+=12;
		break;
	case 3:
		B->s_seg[0].x-=12;
		break;
	case 4:
		B->s_seg[0].x+=12;
		break;
	}

	for(i = 0 ; i < nbr ; i++) {
		RemplirRectangle(B->s_seg[i].x, B->s_seg[i].y, 10, 10);
		//printf("Coords [%d]: %d | %d\n", i, B->s_seg[i].x, B->s_seg[i].y);
	}
}

void body_init (Body *B, int nbr) {
	int i;
	int posx = POSX;
	int posy = POSY;
	for(i = 0 ; i < nbr ; i++) {
		B->s_seg[i].x = posx;
		B->s_seg[i].y = posy;
		posx-=12;
		posy-=12;
	}
	B->s_dir = 2;
}

int verifhead (int x, int y) {

	if(x <= 10 || x >= WIDTH-10 || y <= 10 || y >= HEIGHT-10) {
		//printf("Coords: %d | %d", x, y);
		return 1;
	}
	return 0;
}

int main () {

	InitialiserGraphique();
	CreerFenetre(500,300,WIDTH,HEIGHT);
	EffacerEcran(CouleurParNom("light grey"));

	Body snake_body;
	snake_body.s_seg = malloc(4 * sizeof(Segment));
	body_init(&snake_body, 4);

	int touche, old_dir = 2;

	while(!forcexit(touche)) {

		while(!ToucheEnAttente() && !verifhead(snake_body.s_seg[0].x, snake_body.s_seg[0].y)) {
			move_forward(&snake_body, 4);
			usleep(150000);
		}

		if(verifhead(snake_body.s_seg[0].x, snake_body.s_seg[0].y))
			break;

		touche = Touche();

		if(touche == XK_Up)
			snake_body.s_dir = UP;
		if(touche == XK_Down)
			snake_body.s_dir = DOWN;
		if(touche == XK_Left)
			snake_body.s_dir = LEFT;
		if(touche == XK_Right)
			snake_body.s_dir = RIGHT;

		if(old_dir+snake_body.s_dir == 3 || old_dir+snake_body.s_dir == 7)
			snake_body.s_dir = old_dir;

		old_dir = snake_body.s_dir;
	}

	FermerGraphique();
	return EXIT_SUCCESS;
}
