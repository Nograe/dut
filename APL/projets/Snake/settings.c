#include "settings.h"
//#define DEV

void dispSettings (Game *G, Bodies *B, Apple *A, Wall *W, Settings *S) {

	int width = 60 * 14;
	int height = 40 * 14;
	int touche = 0, decalW, decalH, decalB, decalA, verif = 0;
	char buf[5];
	char src[21] = "src/bg_settingsX.png";

	while(touche != XK_Escape) {

		if(!G->dispApple)
			src[15] = '1';
		else
			src[15] = '2';
		ChargerImageFond(src);

		#ifdef DEV
			DessinerSegment(width/2, 0, width/2, height);
			DessinerSegment(0, height/2, width, height/2);		
			DessinerRectangle(92, 226, 35, 35);
			DessinerRectangle(228, 226, 35, 35);
			DessinerRectangle(590, 226, 35, 35);
			DessinerRectangle(726, 226, 35, 35);
			DessinerRectangle(92, 398, 35, 35);
			DessinerRectangle(228, 398, 35, 35);
			DessinerRectangle(590, 398, 35, 35);
			DessinerRectangle(726, 398, 35, 35);
			printf("X: %d | Y: %d\n", _X, _Y);
			DessinerRectangle(277, 519, 305, 28);
		#endif

		ChoisirCouleurDessin(CouleurParNom("black"));

		// Décalage du texte (détail)
		(G->width >= 100) ? (decalW = 6) : (decalW = 0);
		(G->height >= 100) ? (decalH = 6) : (decalH = 0);
		(B->initSize >= 100) ? (decalB = 6) : (decalB = 0);
		(A->initSpawn >= 10) ? (decalA = 6) : (decalA = 0);

		sprintf(buf, "%d", G->width);
		EcrireTexte(166-decalW, 254, buf, 2);
		sprintf(buf, "%d", G->height);
		EcrireTexte(665-decalH, 254, buf, 2);
		sprintf(buf, "%d", B->initSize);
		EcrireTexte(166-decalB, 426, buf, 2);
		sprintf(buf, "%d", A->initSpawn);
		EcrireTexte(670-decalA, 426, buf, 2);

		if(_X >= 277 && _X <= 277+305 && _Y >= 519 && _Y <= 519+28) {
			advSettings(G, B, S);
			continue;
		}

		if(_X >= 388 && _X <= 388+81 && _Y >= 310 && _Y <= 310+48) {
			if(!G->dispApple)
				G->dispApple = 1;
			else
				G->dispApple = 0;
			verif = 1;
		}

		if(_X >= 92 && _X <= 92+35 && _Y >= 226 && _Y <= 226+35) {
			G->width -= 2;
			if(G->width < 24 && G->tcase == 14)
				G->width = 24;
			verif = 1;
		}
		if(_X >= 228 && _X <= 228+35 && _Y >= 226 && _Y <= 226+35) {
			G->width += 2;
			if(G->width > 140 && G->tcase == 10)
				G->width = 140;
			if(G->width > 120 && G->tcase == 14)
				G->width = 120;
			if(G->width > 100 && G->tcase == 18)
				G->width = 100;
			verif = 1;
		}

		if(_X >= 590 && _X <= 590+35 && _Y >= 226 && _Y <= 226+35) {
			G->height -= 2;
			if(G->height < 24 && G->tcase == 14)
				G->height = 24;
			verif = 1;
		}
		if(_X >= 726 && _X <= 726+35 && _Y >= 226 && _Y <= 226+35) {
			G->height += 2;
			if(G->height > 90 && G->tcase == 10)
				G->height = 90;
			if(G->height > 70 && G->tcase == 14)
				G->height = 70;
			if(G->height > 50 && G->tcase == 18)
				G->height = 50;
			verif = 1;
		}

		if(_X >= 92 && _X <= 92+35 && _Y >= 398 && _Y <= 398 +35) {
			B->initSize -= 1;
			if(B->initSize < 1)
				B->initSize = 1;
			verif = 1;
		}
		if(_X >= 228 && _X <= 228+35 && _Y >= 398 && _Y <= 398+35) {
			B->initSize += 1;
			verif = 1;
		}

		if(_X >= 590 && _X <= 590+35 && _Y >= 398 && _Y <= 398+35) {
			A->initSpawn -= 1;
			if(A->initSpawn < 1)
				A->initSpawn = 1;
			verif = 1;
		}
		if(_X >= 726 && _X <= 726+35 && _Y >= 398 && _Y <= 398+35) {
			A->initSpawn += 1;
			if(A->initSpawn > 90)
				A->initSpawn = 90;
			verif = 1;
		}

		_X = 0;
		_Y = 0;
		CopierZone(2, 0, 0, 0, width, height, 0, 0);
		while(!verif && !SourisCliquee() && !ToucheEnAttente());
		verif = 0;

		if(ToucheEnAttente())
			touche = Touche();
	}

	while(SourisCliquee());
	SourisPosition();
	return;
}

// Fenêtre des paramètres avancés
void advSettings (Game *G, Bodies *B, Settings *S) {

	int width = 60 * 14;
	int height = 40 * 14;
	/*
	Vitesse
	Theme
	NbrWalls
			NbrBots
			TailleCase
	*/

	EffacerEcran(CouleurParNom("forestgreen"));
	ChoisirCouleurDessin(CouleurParNom("black"));
	CopierZone(2, 0, 0, 0, width, height, 0, 0);
	sleep(2);
}