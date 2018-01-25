#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <graph.h>
#include <time.h>
#define WIDTH 500
#define HEIGHT 500
#define seconde 1000000

int forcexit(int *touche) {

    if(*touche == XK_Escape)
        return 1;
    else
        return 0;

}

void draw_target(int x, int y) {

    ChoisirCouleurDessin(CouleurParNom("red"));
    DessinerArc(x, y, 60, 60, 360, 360);
    DessinerArc(x+10, y+10, 40, 40, 360, 360);
    DessinerArc(x+20, y+20, 20, 20, 360, 360);
    ChoisirCouleurDessin(CouleurParNom("black"));
}

void draw_viseur(int x, int y) {

    DessinerSegment(x+15, y, x+15, y+30);
    DessinerSegment(x, y+15, x+30, y+15);
    DessinerArc(x, y, 30, 30, 360, 360);
}

int main() {

    int touche = 0, x = 0, y = 0, c = 0;
    int target = 0, target_y, target_x;
    char buf[100];
    unsigned long temps = Microsecondes();
    unsigned long curtime = 0;
    srand(time(NULL));

    x = WIDTH/2-15;
    y = HEIGHT/2-15;
    InitialiserGraphique();
    CreerFenetre(500,300,WIDTH,HEIGHT);
    EffacerEcran(CouleurParNom("light grey"));
    ChoisirEcran(1);
    EffacerEcran(CouleurParNom("light grey"));
    ChoisirEcran(0);

    while(target != 4) {

        if (ToucheEnAttente()) {
            touche = Touche();
        }

        if(forcexit(&touche))
            break;

        target_x = rand() % (HEIGHT - 60);
        target_y = rand() % (WIDTH - 60);
        draw_target(target_x, target_y);
        draw_viseur(x, y);

        while(!forcexit(&touche)) {

            if (ToucheEnAttente()) {
                touche = Touche();

                if(touche == XK_Left)
                    x-=5;
                if(touche == XK_Right)
                    x+=5;
                if(touche == XK_Up)
                    y-=5;
                if(touche == XK_Down)
                    y+=5;
                if(touche == XK_space && x >= target_x-30 && x <= target_x+30 && y >= target_y-30 && y <= target_y+30) {
                    target++;
                    break;
                }
            }

            ChoisirEcran(1);
            EffacerEcran(CouleurParNom("light grey"));

            draw_target(target_x, target_y);

            draw_viseur(x, y);

            unsigned long tmp = (Microsecondes() - temps)/1000000;
            sprintf(buf,"%d",tmp);
            EcrireTexte(WIDTH-20,HEIGHT-20,buf,1);
            sprintf(buf,"%d",target);
            EcrireTexte(20, HEIGHT-20, buf, 1);
            CopierZone(1, 0, 0, 0, WIDTH, HEIGHT, 0, 0);

            usleep(100);
        }
    }

    ChoisirEcran(0);
    EffacerEcran(CouleurParNom("light grey"));
    temps = Microsecondes() - temps;
    snprintf(buf,100,"Nombre de cibles: %d  Votre temps: %03ld", target, temps/1000000);
    EcrireTexte(20, HEIGHT/2, buf, 2);
    sleep(1);
    FermerGraphique();
    return EXIT_SUCCESS;

}
