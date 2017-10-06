#include <stdio.h>

void sd();
void sg();
void sc();
void carre();
void losange();
void cinq();
void main();

void choix() {
    char ch;
    scanf(" %c",&ch);
    while( ch!='h' && ch!='q' && !(ch>='a' && ch<='f') ) {
        printf("Erreur de saisie. Votre choix ?\n");
        scanf(" %c",&ch);
    }

    if(ch=='a') {
        sd();
        return;
    }
    if(ch=='b') {
        sg();
        return;
    }
    if(ch=='c') {
        sc();
        return;
    }
    if(ch=='d') {
        carre();
        return;
    }
    if(ch=='e') {
        losange();
        return;
    }
    if(ch=='f') {
        cinq();
        return;
    }
    if(ch=='h') {
        main();
        return;
    }
    if(ch=='q') {
        return;
    }
}

void sd() {
    int t;
    printf("Hauteur ?\n");
    scanf("%d",&t);
    while(t<=0) {
        printf("Erreur de saisie. Hauteur ?\n");
        scanf("%d",&t);
    }

    int i,j;
    for(i=1; i<=t; i++) {
        for(j=1; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\nAutre choix ?\n");
    choix();
}

void sg() {
    int t;
    printf("Hauteur ?\n");
    scanf("%d",&t);
    while(t<=0) {
        printf("Erreur de saisie. Hauteur ?\n");
        scanf("%d",&t);
    }

    int i,j,x;
    int var=0;
    for(j=t; j>0; j--) {
        for(i=1; i<j; i++) {
            printf(" ");
        }
        for(x=0; x<=var; x++) {
            printf("*");
        }
        printf("\n");
        var++;
    }

    printf("\nAutre choix ?\n");
    choix();
}

void sc() {
    int t;
    printf("Hauteur ?\n");
    scanf("%d",&t);
    while(t<=0) {
        printf("Erreur de saisie. Hauteur ?\n");
        scanf("%d",&t);
    }

    int i,j,x,z;
    int var=0;
    for(j=t; j>0; j--) {
        for(i=1; i<j; i++) {
            printf(" ");
        }
        for(x=0; x<=var*2; x++) {
            printf("*");
        }
        printf("\n");
        var++;
    }
    for(z=1; z<=t-1; z++) {
        printf(" ");
    }
    printf("*\n");

    printf("\nAutre choix ?\n");
    choix();
}

void carre() {
    int t;
    printf("Cote ?\n");
    scanf("%d",&t);
    while(t<=0) {
        printf("Erreur de saisie. Cote ?\n");
        scanf("%d",&t);
    }

    int i,x;
    for(i=1; i<=t; i++) {
        if(i==1) {
            for(x=1; x<=t; x++) {
                printf("*");
            }
        } else if(i==t) {
            for(x=1; x<=t; x++) {
                printf("*");
            }
        } else {
            for(x=1; x<=t; x++) {
                if(x==1) {
                    printf("*");
                } else if(x==t) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    printf("\nAutre choix ?\n");
    choix();
}

void losange() {
    int t;
    printf("Cote ?\n");
    scanf("%d",&t);
    while(t<=0) {
        printf("Erreur de saisie. Cote ?\n");
        scanf("%d",&t);
    }

    int i,j;
    int var=0;
    for(j=t; j>0; j--) {
        for(i=1; i<j; i++) {
            printf(" ");
        }
        printf("/");
        for(i=0; i<var*2; i++) {
            printf(" ");
        }
        var++;
        printf("\\\n");
    }
    var--;
    for(j=1; j<=t; j++) {
        for(i=1; i<j; i++) {
            printf(" ");
        }
        printf("\\");
        for(i=0; i<var*2; i++) {
            printf(" ");
        }
        var--;
        printf("/\n");
    }

    printf("\nAutre choix ?\n");
    choix();
}

void cinq() {
    int t;
    printf("Taille ?\n");
    scanf("%d",&t);
    while(t<3) {
        printf("Erreur de saisie. Taille ?\n");
        scanf("%d",&t);
    }

    int i,j;
    for(i=0; i<t; i++) {
        printf("*");
    }
    printf("\n");
    for(i=1; i<t-1; i++) {
        printf("*\n");
        if(i==t-2) {
            printf("*");
        }
    }
    for(i=1; i<t; i++) {
        printf("*");
    }
    printf("\n");
    for(i=1; i<=t-2; i++) {
        for(j=1; j<t; j++) {
            printf(" ");
        }
        printf("*\n");
    }
    for(i=0; i<t; i++) {
        printf("*");
    }
    printf("\n");

    printf("\nAutre choix ?\n");
    choix();
}

void main() {
    printf("Instructions:\n");
    printf("   Afficher sapin droite (a)\n");
    printf("   Afficher sapin gauche (b)\n");
    printf("   Afficher sapin complet (c)\n");
    printf("   Afficher carre (d)\n");
    printf("   Afficher losange (e)\n");
    printf("   Afficher cinq (f)\n");
    printf("   Afficher instructions (h)\n");
    printf("   Quitter (q)\n");
<<<<<<< HEAD
    printf("\nVotre choix ?\n");
=======
    printf("\nVotre choix?\n");
>>>>>>> fd670b2e0e6be527978a8a42970d18bb11e02a42
    choix();
}
