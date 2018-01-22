#include "menu.h"
//#define DEV

// Initialisation / Lecture des fichiers 'scores' et 'settings'
void initGame (Game *G, Bodies *B, Apple *A, Wall *W, int argc, char *argv[]) {

	// Vérification (création si NULL) du fichier 'scores' et 'settings'
	FILE *fichier = NULL;
	fichier = fopen("src/scores", "a");
	fclose(fichier);
	fichier = fopen("src/settings", "a");

	fseek(fichier, SEEK_SET, SEEK_END);
	if(fichier == NULL || ftell(fichier)<20)
		setDefaultSettings();

	fichier = fopen("src/settings", "r");
	G->opt = 0;
	readSettings(fichier, G, B, A, W);
	fclose(fichier);

	// Vérification du mode de jeu (voir Annexe)
   gameModes(G, B, A, W, argc, argv);
	dispMenu(G, B, A, W);
}

// Affichage du Menu
void dispMenu (Game *G, Bodies *B, Apple *A, Wall *W) {

	int width = 60 * 14;
	int height = 40 * 14;
	int touche, old = 1;

	InitialiserGraphique();
	CreerFenetre(500, 300, width, height);
	ChoisirEcran(2);

	while (1) {

		ChargerImageFond("src/menu_bg.png");

	#ifdef DEV
		DessinerSegment(width/2, 0, width/2, height);
		DessinerSegment(0, height/2, width, height/2);
		DessinerRectangle(340, 190, 160, 80);
		DessinerRectangle(245, 290, 350, 70);
		DessinerRectangle(295, 385, 250, 70);
		DessinerRectangle(360, 470, 120, 60);
	#endif

		SourisPosition();

		touche = 0;
		if(ToucheEnAttente())
			touche = Touche();
		if(G->opt == 1) {
			G->opt = 0;
			dispHighscore(G, B, A, W);
			CopierZone(2, 0, 0, 0, width, height, 0, 0);
		}

		if(touche == XK_Escape)
			quit(G->pseudo);
		if(touche == XK_Down || touche == XK_s) {
			if(old == 3)
				old = 4;
			if(old == 2)
				old = 3;
			if(old == 1)
				old = 2;
		}
		if(touche == XK_Up || touche == XK_z) {
			if(old == 2)
				old = 1;
			if(old == 3)
				old = 2;
			if(old == 4)
				old = 3;
		}
		if(touche == XK_Return) {
			if(old == 1)
				return dispPlay(G, B, A, W);
			if(old == 2)
				dispHighscore(G, B, A, W);
			if(old == 3)
				dispSettings(G, B, A, W);
			if(old == 4)
				quit(G->pseudo);
		}

		if(_X >= 340 && _X <= 340+160 && _Y >= 190 && _Y <= 190+80 || old == 1) {
			ChargerImage("src/fonts/select.png", 340-19, 215, 0, 0, 19, 28);
			old = 1;
		}
		if(_X >= 245 && _X <= 245+350 && _Y >= 290 && _Y <= 290+70 || old == 2) {
			ChargerImage("src/fonts/select.png", 245-19, 313, 0, 0, 19, 28);
			old = 2;
		}
		if(_X >= 295 && _X <= 295+250 && _Y >= 385 && _Y <= 385+70 || old == 3) {
			ChargerImage("src/fonts/select.png", 295-19, 403, 0, 0, 19, 28);
			old = 3;
		}
		if(_X >= 360 && _X <= 360+120 && _Y >= 470 && _Y <= 470+60 || old == 4) {
			ChargerImage("src/fonts/select.png", 360-19, 487, 0, 0, 19, 28);
			old = 4;
		}

		CopierZone(2, 0, 0, 0, width, height, 0, 0);

		if(SourisCliquee()) {
			if(_X >= 340 && _X <= 340+160 && _Y >= 190 && _Y <= 190+80)
				return dispPlay(G, B, A, W);
			if(_X >= 245 && _X <= 245+350 && _Y >= 290 && _Y <= 290+70) {
				dispHighscore(G, B, A, W);
				continue;
			}
			if(_X >= 295 && _X <= 295+250 && _Y >= 385 && _Y <= 385+70) {
				dispSettings(G, B, A, W);
				continue;
			}
			if(_X >= 360 && _X <= 360+120 && _Y >= 470 && _Y <= 470+60)
				quit(G->pseudo);
			_X = 0;
			_Y = 0;
			ChargerImageFond("src/menu_bg.png");
			CopierZone(2, 0, 0, 0, width, height, 0, 0);
		}
		usleep(50000);
	}
}

// Initialisation des variables pour une partie
void dispPlay (Game *G, Bodies *B, Apple *A, Wall *W) {

	FermerGraphique();

	// Initialisation des Snake / Bots / Apple / Wall / Création de la fenêtre
	G->score = 0;
	G->level = 0;

	B->snake.speed = B->initSpeed;
	B->snake.nbrseg = B->initSize;
	B->snake.seg = malloc((B->snake.nbrseg) * sizeof(Segment));
	B->bot = malloc(B->nbrBot * sizeof(Body));
	int i;
	for(i = 0; i < B->nbrBot; i++) {
    B->bot[i].nbrseg = 5;
		B->bot[i].seg = malloc((B->bot[i].nbrseg) * sizeof(Segment));
	}
	bodyInit(*G, B);

	A->eaten = 0;
	A->spawn = A->initSpawn;
	A->x = malloc(A->spawn * sizeof(int));
	A->y = malloc(A->spawn * sizeof(int));
	randomApple(*G, *B, A);

	W->spawn = W->initSpawn;
	W->x = malloc(W->spawn * sizeof(int));
	W->y = malloc(W->spawn * sizeof(int));
	randomWall(*G, *B, *A, W);

	InitialiserGraphique();
	CreerFenetre(500, 300, G->width * G->tcase, G->height * G->tcase);
}

// Affichage des meilleurs scores
void dispHighscore (Game *G, Bodies *B, Apple *A, Wall *W) {

	int width = 60 * 14;
	int height = 40 * 14;
	int touche = 0, temp, temp_l, posy = 120, posx = 485;
	char buf[6], player[11];

	ChoisirEcran(4);
	ChargerImageFond("src/hs_bg.png");
	ChoisirCouleurDessin(CouleurParNom("black"));

	FILE* fichier = NULL;
	fichier = fopen("src/scores", "r");

	int c = 0;
	int line = 0, i = 0, j = 0;

	// On compte les lignes
	while(c != EOF) {
		c = fgetc(fichier);
		if((char)c == '\n')
			line++;
	}

	// La 1re dimension stocke le score, la 2e stocke la ligne
	int (*scores)[2];
	scores = malloc(line * sizeof(*scores));

	// Récupération des scores
	fseek(fichier, 0, SEEK_SET);
	for(i = 0 ; i < line ; i++) {
		scores[i][1] = i;
		fscanf(fichier, "%d", &scores[i][0]);
		while(fgetc(fichier) != '\n');
	}

	// Tri des scores
	for(i = 0; i < line; i++) {
		for(j = i+1; j < line; j++) {
			if(scores[i][0] > scores[j][0]) {
				temp = scores[i][0];
				temp_l = scores[i][1];
				scores[i][0] = scores[j][0];
				scores[i][1] = scores[j][1];
				scores[j][0] = temp;
				scores[j][1] = temp_l;
			}
		}
	}

	#ifdef DEV
	DessinerRectangle(5, height-70, 64, 64);
	DessinerRectangle(width-71, height-71, 64, 64);
	#endif

	if(line > 10)
		posx = 320;

	// Récupération et affichage du pseudo | score
	for(i = line-1 ; i >= 0 ; i--) {
		fseek(fichier, 0, SEEK_SET);
		for(temp = 0 ; temp < scores[i][1] ; temp++ ) {
			while(fgetc(fichier) != '\n');
		}
		fscanf(fichier, "%*d %s", player);
		player[10] = '\0';
		sprintf(buf, "%d", scores[i][0]);
		if(posy > (height - 42) && posx == 650)
			break;
		if(posy >= height - 42) {
			posy = 120;
			posx = 650;
		}
		posy += 42;
		EcrireTexte(posx - 150, posy, player, 2);
		EcrireTexte(posx, posy, buf, 2);
	}

	posx = 292;
	if(line > 10)
		posx = 127;
	if(line >= 1)
		ChargerImage("src/crown.png", posx, 132, 0, 0, 32, 32);
	if(line >= 2)
		EcrireTexte(posx+10, 204, "2.", 2);
	if(line >= 3)
		EcrireTexte(posx+10, 246, "3.", 2);

	CopierZone(4, 0, 0, 0, width, height, 0, 0);

	while(touche != XK_Escape) {
		while(!SourisCliquee() && !ToucheEnAttente());
		if(_X >= 5 && _X <= 69 && _Y >= height-70 && _Y <= height-6 && line > 0) {
			remove("src/scores");
			fichier = fopen("src/scores", "a");
			return dispHighscore(G, B, A, W);
		}
		if(_X >= width-71 && _X <= width-7 && _Y >= height-71 && _Y <= height-7) {
			changePseudo(G);
			setNewSettings(*G, *B, *A, *W);
			CopierZone(4, 0, 0, 0, width, height, 0, 0);
			while(SourisCliquee());
		}
		_X = 0;
		_Y = 0;
		if(ToucheEnAttente())
			touche = Touche();
	}
	ChoisirEcran(2);
	fclose(fichier);
	while(SourisCliquee());
}

// Enregistrement du score après la fin de partie
void setScore (Game G) {

	// On quitte si le score est inférieur à 1 ou si le pseudo est déjà inscrit avec le même score
	if(G.score < 1 || verifScore(G.pseudo, G.score))
		return;

	FILE* fichier = NULL;
	fichier = fopen("src/scores", "a");

	// Le score et le nom d'utilisateur sont inscrits
	fprintf(fichier, "%d %s\n", G.score, G.pseudo);

	fclose(fichier);
}

// On vérifie que le pseudo n'est pas déjà inscrit avec le même score
int verifScore (char *pseudo, int score) {

	int c = 0;
	char ps[11];
	int tmp;
	FILE* fichier = NULL;
	fichier = fopen("src/scores", "r");

	// Si le score et le pseudo correspondent à une entrée, on n'inscrit rien
	while(c != EOF) {

		fscanf(fichier, "%d %s", &tmp, ps);
		if(tmp == score && !strcmp(pseudo, ps))
			return 1;

		fseek(fichier, 1, SEEK_CUR);

		c = fgetc(fichier);
		if(c != EOF)
			fseek(fichier, -1, SEEK_CUR);
	}

	fclose(fichier);
	return 0;
}

// On quitte le programme
void quit (char *pseudo) {

	FermerGraphique();
	printf("\n▁ ▂ ▄ ▅ ▆ ▇ █ Merci d'avoir joué %s ! █ ▇ ▆ ▅ ▄ ▂ ▁\n\n", pseudo);
	exit(EXIT_SUCCESS);
}
