#include "menu.h"
#include "main.h"
#include "snake.h"

void initgame (Game *G, Body *B, Apple *A, Wall *W, Settings *S) {

  // Attribution VARIABLES DEFAUT

	S->setG.tcase = 14;
	S->setG.width = 60;
	S->setG.height = 40;
	S->setG.score = 0;
	S->setG.level = 0;

	S->setB.nbrseg = 10;
	S->setB.speed = 90000;

	S->setA.eaten = 0;
	S->setA.spawn = 5;

	S->setW.spawn = 10;

	dispMenu(G, B, A, W, S);
}

void dispMenu (Game *G, Body *B, Apple *A, Wall *W, Settings *S) {

	int width = 60 * 14;
	int height = 40 * 14;
	int tcase = 14;
	int touche, old = 1;

	InitialiserGraphique();
	CreerFenetre(500, 300, width, height);

	//DessinerSegment(width/2, 0, width/2, height);
	//DessinerSegment(0, height/2, width, height/2);

	while (!SourisCliquee()) {

		ChoisirEcran(2);

		EffacerEcran(CouleurParNom("forestgreen"));
		ChargerImage("src/snake.png", tcase * 15.5, tcase * 4, 0, 0, 421, 72);
		ChargerImage("src/play.png", tcase * 25.5, tcase * 14, 0, 0, 128, 52);
		ChargerImage("src/highscores.png", tcase * 19, tcase * 21, 0, 0, 328, 52);
		ChargerImage("src/settings.png", tcase * 22, tcase * 28, 0, 0, 225, 52);
		ChargerImage("src/quit.png", tcase * 26.5, tcase * 35, 0, 0, 91, 42);

		SourisPosition();

		touche = 0;
		if(ToucheEnAttente())
			touche = Touche();

		if(touche == XK_Escape)
			quit();
		if(touche == XK_Down) {
			if(old == 3)
				old = 4;
			if(old == 2)
				old = 3;
			if(old == 1)
				old = 2;
		}
		if(touche == XK_Up) {
			if(old == 2)
				old = 1;
			if(old == 3)
				old = 2;
			if(old == 4)
				old = 3;
		}
		if(touche == XK_Return) {
			if(old == 1)
				dispPlay(G, B, A, W, *S);
			if(old == 2)
				dispHighscore(G, B, A, W, S);
			if(old == 3)
				dispSettings(G, B, A, W, S);
			if(old == 4)
				quit();
			return;
		}

		if(_X >= (tcase * 25.5) && _X <= (tcase * 25.5 + 128) && _Y >= (tcase * 14) && _Y <= (tcase * 14 + 52) || old == 1) {
			ChargerImage("src/select.png", tcase * 23, tcase * 14.5, 0, 0, 19, 28);
			old = 1;
		}
		if(_X >= (tcase * 19) && _X <= (tcase * 19 + 328) && _Y >= (tcase * 21) && _Y <= (tcase * 21 + 52) || old == 2) {
			ChargerImage("src/select.png", tcase * 16.5, tcase * 21.5, 0, 0, 19, 28);
			old = 2;
		}
		if(_X >= (tcase * 22) && _X <= (tcase * 22 + 225) && _Y >= (tcase * 28) && _Y <= (tcase * 28 + 52) || old == 3) {
			ChargerImage("src/select.png", tcase * 19.5, tcase * 28.5, 0, 0, 19, 28);
			old = 3;
		}
		if(_X >= (tcase * 26.5) && _X <= (tcase * 26.5 + 91) && _Y >= (tcase * 35) && _Y <= (tcase * 35 + 42) || old == 4) {
			ChargerImage("src/select.png", tcase * 24, tcase * 35.5, 0, 0, 19, 28);
			old = 4;
		}

		CopierZone(2, 0, 0, 0, width, height, 0, 0);

		if(SourisCliquee()) {
			if(_X >= (tcase * 25.5) && _X <= (tcase * 25.5 + 128) && _Y >= (tcase * 14) && _Y <= (tcase * 14 + 52))
				return dispPlay(G, B, A, W, *S);
			if(_X >= (tcase * 19) && _X <= (tcase * 19 + 328) && _Y >= (tcase * 21) && _Y <= (tcase * 21 + 52))
				return dispHighscore(G, B, A, W, S);
			if(_X >= (tcase * 22) && _X <= (tcase * 22 + 225) && _Y >= (tcase * 28) && _Y <= (tcase * 28 + 52))
				return dispSettings(G, B, A, W, S);
			if(_X >= (tcase * 26.5) && _X <= (tcase * 26.5 + 91) && _Y >= (tcase * 35) && _Y <= (tcase * 35 + 42))
				quit();
		}
	}
}

void dispPlay (Game *G, Body *B, Apple *A, Wall *W, Settings S) {

	FermerGraphique();

	// Initialisation des paramètres / snake / pommes / murs / création de la fenêtre
	setSettings(G, B, A, W, S);
  body_init(*G, B);
  randomApple(*G, *B, A);
  randomWall(*G, *B, *A, W);
	InitialiserGraphique();
	CreerFenetre(500, 300, G->width * G->tcase, G->height * G->tcase);
}

void dispHighscore (Game *G, Body *B, Apple *A, Wall *W, Settings *S) {

	FermerGraphique();
	InitialiserGraphique();
	CreerFenetre(500, 300, 60*14, 40*14);
	ChoisirEcran(0);

	while(!SourisCliquee()) {
		ChargerImage("src/highscores.png", 14 * 19, 14 * 21, 0, 0, 328, 52);
	}

	FermerGraphique();
	dispMenu(G, B, A, W, S);
}

void dispSettings (Game *G, Body *B, Apple *A, Wall *W, Settings *S) {

	FermerGraphique();
	InitialiserGraphique();
	CreerFenetre(500, 300, 60*14, 40*14);
	ChoisirEcran(0);

	while(!SourisCliquee()) {
		ChargerImage("src/settings.png", 14 * 22, 14 * 28, 0, 0, 225, 52);
	}

	FermerGraphique();
	dispMenu(G, B, A, W, S);
}

void quit () {

	FermerGraphique();
	printf("▁ ▂ ▄ ▅ ▆ ▇ █ Merci d'avoir joué ! █ ▇ ▆ ▅ ▄ ▂ ▁\n");
	exit(0);
}

void setSettings (Game *G, Body *B, Apple *A, Wall *W, Settings S) {

	*G = S.setG;

	B->nbrseg = S.setB.nbrseg;
	B->speed = S.setB.speed;
	B->s_seg = malloc((B->nbrseg+1) * sizeof(Segment));

	A->eaten = S.setA.eaten;
	A->spawn = S.setA.spawn;
	A->x = malloc(A->spawn * sizeof(int));
	A->y = malloc(A->spawn * sizeof(int));

	W->spawn = S.setW.spawn;
	W->x = malloc(W->spawn * sizeof(int));
	W->y = malloc(W->spawn * sizeof(int));
}