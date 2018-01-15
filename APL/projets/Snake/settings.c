#include "settings.h"
//#define DEV

void dispSettings (Game *G, Bodies *B, Apple *A, Wall *W) {

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

		if(_X >= 388 && _X <= 388+81 && _Y >= 310 && _Y <= 310+48) {
			if(!G->dispApple)
				G->dispApple = 1;
			else
				G->dispApple = 0;
			verif = 1;
		}

		if(_X >= 92 && _X <= 92+35 && _Y >= 226 && _Y <= 226+35) {
			G->width -= 2;
			if(G->width < 30)
				G->width = 30;
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

		if(_X >= 277 && _X <= 277+305 && _Y >= 519 && _Y <= 519+28) {
			advSettings(G, B, W);
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
}

// Fenêtre des paramètres avancés
void advSettings (Game *G, Bodies *B, Wall *W) {

	int width = 60 * 14;
	int height = 40 * 14;
	int touche = 0, decalB = 0, decalW = 0, verif = 0;
	char buf[10];

	ChoisirCouleurDessin(CouleurParNom("black"));

	while(touche != XK_Escape) {

		ChargerImageFond("src/advsettings.png");		

		#ifdef DEV
			DessinerRectangle(90, 226+29, 35, 35);
			DessinerRectangle(226, 226+29, 35, 35);
			DessinerRectangle(590, 227+29, 35, 35);
			DessinerRectangle(726, 227+29, 35, 35);
			DessinerRectangle(92, 398+60, 35, 35);
			DessinerRectangle(228, 398+60, 35, 35);
			DessinerRectangle(590, 398+60, 35, 35);
			DessinerRectangle(726, 398+60, 35, 35);
			DessinerRectangle(334, 347, 35, 35);
			DessinerRectangle(485, 347, 35, 35);
		#endif

		// Décalage du texte (détail)
		(B->nbrBot >= 10) ? (decalB = 6) : (decalB = 0);
		(W->initSpawn >= 10) ? (decalW = 10) : (decalW = 0);

		sprintf(buf, "%d", B->nbrBot);
		EcrireTexte(170-decalB, 284, buf, 2);
		sprintf(buf, "%d", W->initSpawn);
		EcrireTexte(675-decalW, 284, buf, 2);
		sprintf(buf, "%d", G->tcase);
		EcrireTexte(164, 486, buf, 2);
		sprintf(buf, "%d", B->initSpeed%10);
		EcrireTexte(670, 486, buf, 2);
		if(G->theme == 1)
			EcrireTexte(392, 375, "Retro", 2);
		if(G->theme == 2)
			EcrireTexte(392, 375, "à définir", 2);
		if(G->theme == 3)
			EcrireTexte(392, 375, "Modern", 2);
		if(G->theme == 4)
			EcrireTexte(392, 375, "Random", 2);

		SourisCliquee();

		if(_X >= 90 && _X <= 90+35 && _Y >= 255 && _Y <= 255+35){
			B->nbrBot--;
			if(B->nbrBot < 0)
				B->nbrBot = 0;
			verif = 1;
		}
		if(_X >= 226 && _X <= 226+35 && _Y >= 255 && _Y <= 255+35) {
			B->nbrBot++;
			if(B->nbrBot > 99)
				B->nbrBot = 99;
			verif = 1;
		}

		if(_X >= 590 && _X <= 590+35 && _Y >= 256 && _Y <= 256+35) {
			W->initSpawn--;
			if(B->nbrBot < 0)
				B->nbrBot = 0;
			verif = 1;
		}
		if(_X >= 726 && _X <= 726+35 && _Y >= 256 && _Y <= 256 +35) {
			W->initSpawn++;
			if(B->nbrBot > 99)
				B->nbrBot = 99;
			verif = 1;
		}

		if(_X >= 92 && _X <= 92+35 && _Y >= 458 && _Y <= 458+35 && G->tcase > 10) {
			G->tcase-=4;
			verif = 1;
		}
		if(_X >= 228 && _X <= 228+35 && _Y >= 458 && _Y <= 458+35 && G->tcase < 18) {
			G->tcase+=4;
			verif = 1;
		}

		if(_X >= 590 && _X <= 590+35 && _Y >= 458 && _Y <= 458+35 && B->initSpeed < 97001) {
				B->initSpeed+=8999;
				verif = 1;
		}
		if(_X >= 726 && _X <= 726+35 && _Y >= 458 && _Y <= 458+35 && B->initSpeed > 25009) {
				B->initSpeed-=8999;
				verif = 1;
		}

		if(_X >= 334 && _X <= 334+35 && _Y >= 347 && _Y <= 347+35) {
			G->theme--;
			if(G->theme == 0)
				G->theme = 4;
			verif = 1;
		}
		if(_X >= 485 && _X <= 485+35 && _Y >= 347 && _Y <= 347+35) {
			G->theme++;
			if(G->theme == 5)
				G->theme = 1;
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
}

void setDefaultSettings () {

	FILE *fichier = fopen("src/settings", "a");
	fichier = fopen("src/settings", "r+");

  // Attribution VARIABLES DEFAUT
	fprintf(fichier, "%d\n", 60);
	fprintf(fichier, "%d\n", 40);
	fprintf(fichier, "%d\n", 14);
	fprintf(fichier, "%d\n", 0);
	fprintf(fichier, "%s\n", "TheDev");
	fprintf(fichier, "%d\n", 3);
	fprintf(fichier, "%d\n", 10);
	fprintf(fichier, "%d\n", 70004);
	fprintf(fichier, "%d\n", 0);
	fprintf(fichier, "%d\n", 5);
	fprintf(fichier, "%d\n", 0);

	fclose(fichier);
}

void setNewSettings (Game G, Bodies B, Apple A, Wall W) {

	remove("src/settings");
	FILE *fichier = fopen("src/settings", "a");
	fichier = fopen("src/settings", "r+");

  // Attribution nouveaux paramètres
	fprintf(fichier, "%d\n", G.width);
	fprintf(fichier, "%d\n", G.height);
	fprintf(fichier, "%d\n", G.tcase);
	fprintf(fichier, "%d\n", G.dispApple);
	fprintf(fichier, "%s\n", G.pseudo);
	fprintf(fichier, "%d\n", G.theme);
	fprintf(fichier, "%d\n", B.initSize);
	fprintf(fichier, "%d\n", B.initSpeed);
	fprintf(fichier, "%d\n", B.nbrBot);
	fprintf(fichier, "%d\n", A.initSpawn);
	fprintf(fichier, "%d\n", W.initSpawn);

	fclose(fichier);
}