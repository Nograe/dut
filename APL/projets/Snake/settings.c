#include "settings.h"

void dispSettings (Game *G, Bodies *B, Apple *A, Wall *W, Settings *S) {

	int width = 60 * 14;
	int height = 40 * 14;
	int touche = 0, decalW, decalH, decalB, decalA;
	char buf[5];

	while(touche != XK_Escape) {

		if(ToucheEnAttente())
			touche = Touche();

		EffacerEcran(CouleurParNom("forestgreen"));
		ChoisirCouleurDessin(CouleurParNom("black"));

		#ifdef DEV
			DessinerSegment(width/2, 0, width/2, height);
			DessinerSegment(0, height/2, width, height/2);
		#endif

		// Décalage du texte (détail)
		(S->setG.width >= 100) ? (decalW = 6) : (decalW = 0);
		(S->setG.height >= 100) ? (decalH = 6) : (decalH = 0);
		(S->setB.snake.nbrseg >= 100) ? (decalB = 6) : (decalB = 0);
		(S->setA.spawn >= 10) ? (decalA = 6) : (decalA = 0);

		ChargerImage("src/fonts/settings_title.png", 14 * 16.5, 14 * 5, 0, 0, 390, 45);

		ChargerImage("src/fonts/width.png", 220, 200, 0, 0, 69, 18);
		ChargerImage("src/minus.png", 185, 200+32, 0, 0, 32, 32);
		ChargerImage("src/plus.png", 285, 200+32, 0, 0, 32, 32);
		sprintf(buf, "%d", S->setG.width);
		EcrireTexte(240-decalW, 255, buf, 2);

		ChargerImage("src/fonts/height.png", 550, 200, 0, 0, 85, 20);
		ChargerImage("src/minus.png", 525, 200+32, 0, 0, 32, 32);
		ChargerImage("src/plus.png", 625, 200+32, 0, 0, 32, 32);
		sprintf(buf, "%d", S->setG.height);
		EcrireTexte(580-decalH, 255, buf, 2);

		ChargerImage("src/fonts/startingsize.png", 155, 370, 0, 0, 175, 17);
		ChargerImage("src/minus.png", 185, 370+32, 0, 0, 32, 32);
		ChargerImage("src/plus.png", 285, 370+32, 0, 0, 32, 32);
		sprintf(buf, "%d", S->setB.snake.nbrseg);
		EcrireTexte(240-decalB, 425, buf, 2);

		ChargerImage("src/fonts/apples.png", 550, 370, 0, 0, 93, 17);
		ChargerImage("src/minus.png", 530, 370+32, 0, 0, 32, 32);
		ChargerImage("src/plus.png", 620, 370+32, 0, 0, 32, 32);
		sprintf(buf, "%d", S->setA.spawn);
		EcrireTexte(585-decalA, 425, buf, 2);

		ChargerImage("src/fonts/advancedsettings.png", (width-264)/2, height-35, 0, 0, 264, 25);

		SourisCliquee();

		if(_X >= (width-264)/2 && _X <= (width-264)/2+264 && _Y >= height-35 && _Y <= height-10)
			advSettings(G, B, S);

		if(_X >= 185 && _X <= 185+32 && _Y >= 232 && _Y <= 232+32) {
			S->setG.width -= 2;
			if(S->setG.width < 24 && S->setG.tcase == 14)
				S->setG.width = 24;
		}
		if(_X >= 285 && _X <= 285+32 && _Y >= 232 && _Y <= 232+32) {
			S->setG.width += 2;
			if(S->setG.width > 140 && S->setG.tcase == 10)
				S->setG.width = 140;
			if(S->setG.width > 120 && S->setG.tcase == 14)
				S->setG.width = 120;
			if(S->setG.width > 100 && S->setG.tcase == 18)
				S->setG.width = 100;
		}

		if(_X >= 525 && _X <= 525+32 && _Y >= 232 && _Y <= 232+32) {
			S->setG.height -= 2;
			if(S->setG.height < 24 && S->setG.tcase == 14)
				S->setG.height = 24;
		}
		if(_X >= 625 && _X <= 625+32 && _Y >= 232 && _Y <= 232+32) {
			S->setG.height += 2;
			if(S->setG.height > 90 && S->setG.tcase == 10)
				S->setG.height = 90;
			if(S->setG.height > 70 && S->setG.tcase == 14)
				S->setG.height = 70;
			if(S->setG.height > 50 && S->setG.tcase == 18)
				S->setG.height = 50;
		}

		if(_X >= 185 && _X <= 185+32 && _Y >= 402 && _Y <= 402 +32) {
			S->setB.snake.nbrseg -= 1;
			if(S->setB.snake.nbrseg < 1)
				S->setB.snake.nbrseg = 1;
		}
		if(_X >= 285 && _X <= 285+32 && _Y >= 402 && _Y <= 402+32) {
			S->setB.snake.nbrseg += 1;
		}

		if(_X >= 525 && _X <= 525+32 && _Y >= 402 && _Y <= 402+32) {
			S->setA.spawn -= 1;
			if(S->setA.spawn < 1)
				S->setA.spawn = 1;
		}
		if(_X >= 625 && _X <= 625+32 && _Y >= 402 && _Y <= 402+32) {
			S->setA.spawn += 1;
			if(S->setA.spawn > 90)
				S->setA.spawn = 90;
		}

		_X = 0;
		_Y = 0;
		CopierZone(2, 0, 0, 0, width, height, 0, 0);
	}

	while(SourisCliquee());
	SourisPosition();
	return;
}

// Fenêtre des paramètres avancés
void advSettings (Game *G, Bodies *B, Settings *S) {
	/*
	Vitesse
	Theme
	NbrWalls
	NbrBots
			TailleCase
	*/
}

// On initialise tous les paramètres (pré)définis
void setSettings (Game *G, Bodies *B, Apple *A, Wall *W, Settings S) {

	*G = S.setG;

	B->snake.nbrseg = S.setB.snake.nbrseg;
	B->snake.speed = S.setB.snake.speed;
	B->snake.s_seg = malloc((B->snake.nbrseg+1) * sizeof(Segment));
	B->nbrBot = S.setB.nbrBot;
	B->bot = malloc(B->nbrBot * sizeof(Body));
	int i;
	for(i = 0; i < B->nbrBot; i++) {
    B->bot[i].nbrseg = 5;
		B->bot[i].s_seg = malloc(5 * sizeof(Segment));
	}

	A->eaten = S.setA.eaten;
	A->spawn = S.setA.spawn;
	A->x = malloc(A->spawn * sizeof(int));
	A->y = malloc(A->spawn * sizeof(int));

	W->spawn = S.setW.spawn;
	W->x = malloc(W->spawn * sizeof(int));
	W->y = malloc(W->spawn * sizeof(int));
}