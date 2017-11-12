#include <stdio.h>
#include <stdlib.h>

int strlength(char* str) {

    int i=0;

    while(str[i]!='\0') {
        i++;
    }

    return i;
}

void main() {
    char *string=malloc(sizeof(char) * 1);
    string[0]='\0';
    char chain[51];

    int j=0;
    char saisie;

    scanf("%c",&saisie);
    while(saisie >= 'a' && saisie <= 'z'){
        realloc(string,(sizeof(char) * j) +10);
        printf("Realloc: %d",(sizeof(char) * j) +2);
        string[j]=saisie;
        string[j+1]='\0';
        printf("\tstring[%d]: %c, string[%d]: %d",j,string[j],j+1,string[j+1]);
        j++;
        printf("\tstring: %s\n",string);
        scanf("%c",&saisie);
    }

    free(string);

    /*int taille=strlength(string);
    int i,var;

    for(var = 0 ; var<taille ; var+50) {
        for(i = 0 ; i<50 ; i++) {
            chain[i]=(char)string[taille-1];
			//printf("\n%d: %c",i,chain[i]);
            taille--;
            if(taille==0 || i==49)
                chain[i+1]='\0';
        }
        printf("%s",chain);
        printf("\n");
    }*/
}
