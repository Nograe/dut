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

void move_forward (Body *B) {

    B->s_seg[B->nbrseg] = B->s_seg[B->nbrseg-1];
    int i;
    for(i = B->nbrseg-1 ; i >= 1 ; i--) {
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
}

void draw (Body B) {

    ChoisirEcran(1);
    ChoisirCouleurDessin(CouleurParNom("khaki"));

    int i;
    for(i = 0 ; i < B.nbrseg ; i++) {
        RemplirRectangle(B.s_seg[i].x, B.s_seg[i].y, 10, 10);
    }

    EffacerEcran(CouleurParNom("yellowgreen"));
    CopierZone(1, 0, 0, 0, WIDTH, HEIGHT, 0, 0);
}

void body_init (Body *B) {
    int i;
    int posx = 20;
    int posy = 30;
    for(i = 0 ; i < B->nbrseg ; i++) {
        B->s_seg[i].x = posx;
        B->s_seg[i].y = posy;
        posx-=12;
    }
    B->s_dir = 4;
}

int verif (Body S) {

    int x = S.s_seg[0].x;
    int y = S.s_seg[0].y;
    if(x <= 10 || x >= WIDTH-10 || y <= 10 || y >= HEIGHT-10) {
        //printf("Coords: %d | %d", x, y);
        return 1;
    }

    int i;
    for(i = 4 ; i <= S.nbrseg ; i++) {
        if(x == S.s_seg[i].x && y == S.s_seg[i].y)
            return 1;
    }

    return 0;
}

int main () {

    InitialiserGraphique();
    CreerFenetre(500,300,WIDTH,HEIGHT);
    EffacerEcran(CouleurParNom("light grey"));

    Body snake_body;
    snake_body.nbrseg = 14;
    snake_body.s_seg = malloc((snake_body.nbrseg+1) * sizeof(Segment));
    body_init(&snake_body);

    int touche, old_dir = 4;

    while(!forcexit(touche)) {

        while(!ToucheEnAttente() && !verif(snake_body)) {
            draw(snake_body);
            usleep(150000);
            move_forward(&snake_body);
        }

        if(verif(snake_body))
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
