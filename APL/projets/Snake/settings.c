#include "settings.h"
//#define DEV

// Affichage des paramètres
void dispSettings (Game *G, Bodies *B, Apple *A, Wall *W) {

	while(SourisCliquee());
	_X = 0;
	_Y = 0;

	int width = 60 * 14;
	int height = 40 * 14;
	int touche = 0, decalW, decalH, decalB, decalA;
	char buf[5];

	while(touche != XK_Escape) {

		if(G->dispApple)
			ChargerImageFond("src/backgrounds/settings_bg2.png");
		else
			ChargerImageFond("src/backgrounds/settings_bg1.png");

		#ifdef DEV
		DessinerSegment(width/2, 0, width/2, height);
		DessinerSegment(0, height/2, width, height/2);
			DessinerRectangle(377, 310, 81, 48); // Switch bouton
			DessinerRectangle(9, height-74, 64, 64); // Pseudo
			DessinerRectangle(width-74, height-74, 64, 64); // Reset settings
			DessinerRectangle(92, 226, 35, 35); // Width
			DessinerRectangle(228, 226, 35, 35);
			DessinerRectangle(567, 226, 35, 35); // Height
			DessinerRectangle(703, 226, 35, 35);
			DessinerRectangle(92, 398, 35, 35); // Starting size
			DessinerRectangle(228, 398, 35, 35);
			DessinerRectangle(567, 398, 35, 35); // Apples
			DessinerRectangle(703, 398, 35, 35);
			if(SourisCliquee())
				printf("X: %d | Y: %d\n", _X, _Y);
			DessinerRectangle(225, 502, 386, 58); // AdvSettings
		#endif

		// Décalage du texte (détail)
			(G->width >= 100) ? (decalW = 6) : (decalW = 0);
			(G->height >= 100) ? (decalH = 6) : (decalH = 0);
			(B->initSize < 10) ? (decalB = 6) : (decalB = 0);
			(A->initSpawn >= 10) ? (decalA = 6) : (decalA = 0);

			ChoisirCouleurDessin(CouleurParNom("black"));
			sprintf(buf, "%d", G->width);
			EcrireTexte(166-decalW, 254, buf, 2);
			sprintf(buf, "%d", G->height);
			EcrireTexte(642-decalH, 254, buf, 2);
			sprintf(buf, "%d", B->initSize);
			EcrireTexte(166+decalB, 426, buf, 2);
			sprintf(buf, "%d", A->initSpawn);
			EcrireTexte(647-decalA, 426, buf, 2);

			SourisCliquee();

			if(_X >= 9 && _X <= 9+64 && _Y >= height-74 && _Y <= height-10) {
				changePseudo(G);
				ChoisirEcran(2);
			while(SourisCliquee()); // On vide la file d'attente
			_X = 0;
			_Y = 0;
		}
		if(_X >= width-74 && _X <= width-10 && _Y >= height-74 && _Y <= height-10) {
			setDefaultSettings(G, B, A, W);
			FILE *fichier = fopen("src/settings", "r");
			readSettings(fichier, G, B, A, W);
			fclose(fichier);
		}

		if(_X >= 377 && _X <= 377+81 && _Y >= 310 && _Y <= 310+48) {
			if(!G->dispApple)
				G->dispApple = 1;
			else
				G->dispApple = 0;
		}

		if(_X >= 92 && _X <= 92+35 && _Y >= 226 && _Y <= 226+35 && G->width > 32)
			G->width -= 2;
		if(_X >= 228 && _X <= 228+35 && _Y >= 226 && _Y <= 226+35) {
			G->width += 2;
			if(G->width > 140 && G->tcase == 10)
				G->width = 140;
			if(G->width > 120 && G->tcase == 14)
				G->width = 120;
			if(G->width > 100 && G->tcase == 18)
				G->width = 100;
		}

		if(_X >= 567 && _X <= 567+35 && _Y >= 226 && _Y <= 226+35 && G->height > 26)
			G->height -= 2;
		if(_X >= 703 && _X <= 703+35 && _Y >= 226 && _Y <= 226+35) {
			G->height += 2;
			if(G->height > 90 && G->tcase == 10)
				G->height = 90;
			if(G->height > 70 && G->tcase == 14)
				G->height = 70;
			if(G->height > 50 && G->tcase == 18)
				G->height = 50;
		}

		if(_X >= 92 && _X <= 92+35 && _Y >= 398 && _Y <= 398+35 && B->initSize > 1)
			B->initSize--;
		if(_X >= 228 && _X <= 228+35 && _Y >= 398 && _Y <= 398+35 && B->initSize < 99)
			B->initSize++;

		if(_X >= 567 && _X <= 567+35 && _Y >= 398 && _Y <= 398+35 && A->initSpawn > 1)
			A->initSpawn--;
		if(_X >= 703 && _X <= 703+35 && _Y >= 398 && _Y <= 398+35 && A->initSpawn < 99)
			A->initSpawn++;

		if(_X >= 225 && _X <= 611 && _Y >= 502 && _Y <= height)
			advSettings(G, B, W);

		_X = 0;
		_Y = 0;
		CopierZone(2, 0, 0, 0, width, height, 0, 0);
		usleep(50000);
		if(ToucheEnAttente())
			touche = Touche();
	}
	setNewSettings(*G, *B, *A, *W);
	while(SourisCliquee());
	_X = 0;
	_Y = 0;
}

// Fenêtre des paramètres avancés
void advSettings (Game *G, Bodies *B, Wall *W) {

	while(SourisCliquee());
	_X = 0;
	_Y = 0;

	int width = 60 * 14;
	int height = 40 * 14;
	int touche = 0, decalB = 0, decalW = 0;
	char buf[10];

	ChoisirCouleurDessin(CouleurParNom("black"));

	while(touche != XK_Escape) {

		ChargerImageFond("src/backgrounds/advsettings_bg.png");

		#ifdef DEV
			DessinerRectangle(90, 226+29, 35, 35); // Bots
			DessinerRectangle(226, 226+29, 35, 35);
			DessinerRectangle(574, 227+29, 35, 35); // Walls
			DessinerRectangle(710, 227+29, 35, 35);
			DessinerRectangle(92, 398+60, 35, 35); // Cell
			DessinerRectangle(228, 398+60, 35, 35);
			DessinerRectangle(574, 398+60, 35, 35); // Speed
			DessinerRectangle(710, 398+60, 35, 35);
			DessinerRectangle(324, 347, 35, 35); // Theme
			DessinerRectangle(475, 347, 35, 35);
			if(SourisCliquee())
				printf("X: %d | Y: %d\n", _X, _Y);
		#endif

		// Décalage du texte (détail)
		(B->nbrBot >= 10) ? (decalB = 6) : (decalB = 0);
		(W->initSpawn >= 10) ? (decalW = 6) : (decalW = 0);

		sprintf(buf, "%d", B->nbrBot);
		EcrireTexte(170-decalB, 284, buf, 2);
		sprintf(buf, "%d", W->initSpawn);
		EcrireTexte(655-decalW, 284, buf, 2);
		sprintf(buf, "%d", G->tcase);
		EcrireTexte(164, 486, buf, 2);
		sprintf(buf, "%d", B->initSpeed%10);
		EcrireTexte(655, 486, buf, 2);
		if(G->theme == 1)
			EcrireTexte(418-TailleChaineEcran("Retro", 2)/2, 375, "Retro", 2);
		if(G->theme == 2)
			EcrireTexte(418-TailleChaineEcran("Christmas", 2)/2, 375, "Christmas", 2);
		if(G->theme == 3)
			EcrireTexte(418-TailleChaineEcran("Modern", 2)/2, 375, "Modern", 2);
		if(G->theme == 4)
			EcrireTexte(418-TailleChaineEcran("Random", 2)/2, 375, "Random", 2);
		if(G->theme == 5)
			EcrireTexte(418-TailleChaineEcran("Fallout", 2)/2, 375, "Fallout", 2);
		if(G->theme == 6)
			EcrireTexte(418-TailleChaineEcran("Zombie", 2)/2, 375, "Zombie", 2);

		SourisCliquee();

		if(_X >= 90 && _X <= 90+35 && _Y >= 255 && _Y <= 255+35 && B->nbrBot > 0)
			B->nbrBot--;
		if(_X >= 226 && _X <= 226+35 && _Y >= 255 && _Y <= 255+35 && B->nbrBot < 10)
			B->nbrBot++;

		if(_X >= 574 && _X <= 574+35 && _Y >= 256 && _Y <= 256+35 && W->initSpawn > 0)
			W->initSpawn--;
		if(_X >= 710 && _X <= 710+35 && _Y >= 256 && _Y <= 256 +35 && W->initSpawn < 99)
			W->initSpawn++;

		if(_X >= 92 && _X <= 92+35 && _Y >= 458 && _Y <= 458+35 && G->tcase > 10)
			G->tcase-=4;
		if(_X >= 228 && _X <= 228+35 && _Y >= 458 && _Y <= 458+35 && G->tcase < 18)
			G->tcase+=4;

		if(_X >= 574 && _X <= 574+35 && _Y >= 458 && _Y <= 458+35 && B->initSpeed < 97001)
				B->initSpeed+=8999;
		if(_X >= 710 && _X <= 710+35 && _Y >= 458 && _Y <= 458+35 && B->initSpeed > 25009)
				B->initSpeed-=8999;

		if(_X >= 324 && _X <= 324+35 && _Y >= 347 && _Y <= 347+35) {
			G->theme--;
			if(G->theme == 0)
				G->theme = 6;
		}
		if(_X >= 475 && _X <= 475+35 && _Y >= 347 && _Y <= 347+35) {
			G->theme++;
			if(G->theme == 7)
				G->theme = 1;
		}

		_X = 0;
		_Y = 0;
		CopierZone(2, 0, 0, 0, width, height, 0, 0);
		usleep(50000);
		if(ToucheEnAttente())
			touche = Touche();
	}
	while(SourisCliquee());
	_X = 0;
	_Y = 0;
}

// On remet les paramètres par défaut
void setDefaultSettings () {

	FILE *fichier = fopen("src/settings", "a");
	fichier = fopen("src/settings", "r+");

  // Attribution VARIABLES DEFAUT
	fprintf(fichier, "%d\n", 60);
	fprintf(fichier, "%d\n", 40);
	fprintf(fichier, "%d\n", 14);
	fprintf(fichier, "%d\n", 0);
	fprintf(fichier, "%s\n", getenv("USER"));
	fprintf(fichier, "%d\n", 3);
	fprintf(fichier, "%d\n", 10);
	fprintf(fichier, "%d\n", 70004);
	fprintf(fichier, "%d\n", 0);
	fprintf(fichier, "%d\n", 5);
	fprintf(fichier, "%d\n", 0);

	fclose(fichier);
}

// On sauvegarde dans le fichier les nouveaux paramètres
void setNewSettings (Game G, Bodies B, Apple A, Wall W) {

	if(G.opt > 1)
		return;

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

// On lit les paramètres sauvegardés dans le fichier
void readSettings(FILE *fichier, Game *G, Bodies *B, Apple *A, Wall *W) {

	G->opt = 0;
	int i;
	for(i = 0; i < 11; i++) {
		if(i == 0)
			fscanf(fichier, "%d", &G->width);
		if(i == 1)
			fscanf(fichier, "%d", &G->height);
		if(i == 2)
			fscanf(fichier, "%d", &G->tcase);
		if(i == 3)
			fscanf(fichier, "%d", &G->dispApple);
		if(i == 4)
			fscanf(fichier, "%s", G->pseudo);
		if(i == 5)
			fscanf(fichier, "%u", &G->theme);
		if(i == 6)
			fscanf(fichier, "%d", &B->initSize);
		if(i == 7)
			fscanf(fichier, "%d", &B->initSpeed);
		if(i == 8)
			fscanf(fichier, "%d", &B->nbrBot);
		if(i == 9)
			fscanf(fichier, "%d", &A->initSpawn);
		if(i == 10)
			fscanf(fichier, "%d", &W->initSpawn);
		while(fgetc(fichier) != '\n');
	}
}

// Changement du pseudo
void changePseudo (Game *G) {

	int width = 60*14, height = 40*14;
	int i = 0, touche = -1;
	char pseudo[11];
	_X = 0;
	_Y = 0;

	strncpy(pseudo, G->pseudo, 11);
	while((int)pseudo[i] >= 32 && (int)pseudo[i] <= 126)
		i++;

	ChoisirEcran(3);

	while(touche != XK_Return || i < 1) {

		EffacerEcran(CouleurParComposante(21, 97, 49));
		ChargerImageFond("src/backgrounds/username.png");
		EcrireTexte(352, 308, pseudo, 2);
		if(Microsecondes()/500000%2 == 0)
			RemplirRectangle(352+TailleChaineEcran(pseudo, 2), 286, 2, 24);
		CopierZone(3, 0, 0, 0, width, height, 0, 0);

		if(ToucheEnAttente())
			touche = Touche();
		if(touche == XK_Escape)
			return;

		if((int)touche == 65288 && i > 0) {
			pseudo[i-1] = '\0';
			i--;
			touche = 0;
		}
		if((int)touche >= 32 && (int)touche <= 126 && i < 10) {
			pseudo[i] = touche;
			i++;
			pseudo[i] = '\0';
			touche = 0;
		}
		SourisCliquee();
		if(_X >= 5 && _X <= 69 && _Y >= height-70 && _Y <= height-6)
			return;
		if(_X >= width-71 && _X <= width-7 && _Y >= height-71 && _Y <= height-7)
			touche = XK_Return;
	}

	strncpy(G->pseudo, pseudo, 11);
}

// b : Background | d : Dessin | t : timer/score | r : bots
couleur choisirCouleur (Theme T, char type) {

	static couleur C1, C2, C3;
	static int random = 0;
	
	if(random != -1) {
		C1 = CouleurParComposante(rand()%255, rand()%255, rand()%255);
		C2 = CouleurParComposante(rand()%255, rand()%255, rand()%255);
		C3 = CouleurParComposante(rand()%255, rand()%255, rand()%255);
		random = -1;
	}

	couleur C;

	if(T == RETRO) {
		if(type == 'b')
			C = CouleurParComposante(150, 194, 11);
		if(type == 'd')
			C = CouleurParComposante(0, 10, 20);
		if(type == 't')
			C = CouleurParComposante(120, 174, 0);
		if(type == 'r')
			C = CouleurParComposante(122, 0, 14);
	}
	if(T == CHRISTMAS) {
		if(type == 'b')
			C = CouleurParComposante(200, 62, 62);
		if(type == 'd')
			C = CouleurParComposante(230, 230, 230);
		if(type == 't')
			C = CouleurParComposante(170, 18, 18);
		if(type == 'r')
			C = CouleurParComposante(63, 150, 80);
	}
	if(T == MODERN) {
		if(type == 'b')
			C = CouleurParComposante(24, 89, 60);
		if(type == 'd')
			C = CouleurParComposante(200, 145, 0);
		if(type == 't')
			C = CouleurParComposante(4, 69, 40);
		if(type == 'r')
			C = CouleurParComposante(255, 65, 30);
	}
	if(T == RANDOM) {
		if(type == 'b')
			C = C1;
		if(type == 'd')
			C = CouleurParComposante(rand()%255, rand()%255, rand()%255);
		if(type == 't')
			C = C2;
		if(type == 'r')
			C = C3;
	}
	if(T == FALLOUT) {
		if(type == 'b')
			C = CouleurParComposante(37, 57, 122);
		if(type == 'd')
			C = CouleurParComposante(218, 160, 13);
		if(type == 't')
			C = CouleurParComposante(241, 177, 15);
		if(type == 'r')
			C = CouleurParComposante(64, 154, 213);
	}
	if(T == ZOMBIE) {
		if(type == 'b')
			C = CouleurParComposante(67,70,55);
		if(type == 'd')
			C = CouleurParComposante(217,30,24);
		if(type == 't')
			C = CouleurParComposante(42,55,40);
		if(type == 'r')
			C = CouleurParComposante(85,114,57);
	}
	/*if(T == EXEMPLE) {
		if(type == 'b')
			C = CouleurParComposante(EXEMPLE);
		if(type == 'd')
			C = CouleurParComposante(EXEMPLE);
		if(type == 't')
			C = CouleurParComposante(EXEMPLE);
		if(type == 'r')
			C = CouleurParComposante(EXEMPLE;
	}*/

	return C;
}