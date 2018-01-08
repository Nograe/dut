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
		(G->width >= 100) ? (decalW = 6) : (decalW = 0);
		(G->height >= 100) ? (decalH = 6) : (decalH = 0);
		(B->snake.nbrseg >= 100) ? (decalB = 6) : (decalB = 0);
		(A->spawn >= 10) ? (decalA = 6) : (decalA = 0);

		ChargerImage("src/fonts/settings_title.png", 14 * 16.5, 14 * 5, 0, 0, 390, 45);

		ChargerImage("src/fonts/width.png", 220, 200, 0, 0, 69, 18);
		ChargerImage("src/minus.png", 185, 200+32, 0, 0, 32, 32);
		ChargerImage("src/plus.png", 285, 200+32, 0, 0, 32, 32);
		sprintf(buf, "%d", G->width);
		EcrireTexte(240-decalW, 255, buf, 2);

		ChargerImage("src/fonts/height.png", 550, 200, 0, 0, 85, 20);
		ChargerImage("src/minus.png", 525, 200+32, 0, 0, 32, 32);
		ChargerImage("src/plus.png", 625, 200+32, 0, 0, 32, 32);
		sprintf(buf, "%d", G->height);
		EcrireTexte(580-decalH, 255, buf, 2);

		ChargerImage("src/fonts/startingsize.png", 155, 370, 0, 0, 175, 17);
		ChargerImage("src/minus.png", 185, 370+32, 0, 0, 32, 32);
		ChargerImage("src/plus.png", 285, 370+32, 0, 0, 32, 32);
		sprintf(buf, "%d", B->initSize);
		EcrireTexte(240-decalB, 425, buf, 2);

		ChargerImage("src/fonts/apples.png", 550, 370, 0, 0, 93, 17);
		ChargerImage("src/minus.png", 530, 370+32, 0, 0, 32, 32);
		ChargerImage("src/plus.png", 620, 370+32, 0, 0, 32, 32);
		sprintf(buf, "%d", A->initSpawn);
		EcrireTexte(585-decalA, 425, buf, 2);

		ChargerImage("src/fonts/advancedsettings.png", (width-264)/2, height-35, 0, 0, 264, 25);

		SourisCliquee();

		if(_X >= (width-264)/2 && _X <= (width-264)/2+264 && _Y >= height-35 && _Y <= height-10) {
			advSettings(G, B, S);
			continue;
		}

		if(_X >= 185 && _X <= 185+32 && _Y >= 232 && _Y <= 232+32) {
			G->width -= 2;
			if(G->width < 24 && G->tcase == 14)
				G->width = 24;
		}
		if(_X >= 285 && _X <= 285+32 && _Y >= 232 && _Y <= 232+32) {
			G->width += 2;
			if(G->width > 140 && G->tcase == 10)
				G->width = 140;
			if(G->width > 120 && G->tcase == 14)
				G->width = 120;
			if(G->width > 100 && G->tcase == 18)
				G->width = 100;
		}

		if(_X >= 525 && _X <= 525+32 && _Y >= 232 && _Y <= 232+32) {
			G->height -= 2;
			if(G->height < 24 && G->tcase == 14)
				G->height = 24;
		}
		if(_X >= 625 && _X <= 625+32 && _Y >= 232 && _Y <= 232+32) {
			G->height += 2;
			if(G->height > 90 && G->tcase == 10)
				G->height = 90;
			if(G->height > 70 && G->tcase == 14)
				G->height = 70;
			if(G->height > 50 && G->tcase == 18)
				G->height = 50;
		}

		if(_X >= 185 && _X <= 185+32 && _Y >= 402 && _Y <= 402 +32) {
			B->initSize -= 1;
			if(B->initSize < 1)
				B->initSize = 1;
		}
		if(_X >= 285 && _X <= 285+32 && _Y >= 402 && _Y <= 402+32) {
			B->initSize += 1;
		}

		if(_X >= 525 && _X <= 525+32 && _Y >= 402 && _Y <= 402+32) {
			A->initSpawn -= 1;
			if(A->initSpawn < 1)
				A->initSpawn = 1;
		}
		if(_X >= 625 && _X <= 625+32 && _Y >= 402 && _Y <= 402+32) {
			A->initSpawn += 1;
			if(A->initSpawn > 90)
				A->initSpawn = 90;
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

	EffacerEcran(CouleurParNom("forestgreen"));
	ChargerImage("src/fonts/advsettings_title.png", 14 * 11.75, 14 * 4, 0, 0, 523, 45);
	ChoisirCouleurDessin(CouleurParNom("black"));
}