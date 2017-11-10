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
    char string[1000];
    scanf("%s",string);
    char chain[51];

    int taille=strlength(string);
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
    }
}
