#include <stdio.h>
#include <stdlib.h>

int strlength(char* str) {

    int i=0;

    while(str[i]!='\0') {
        i++;
    }

    return i;
}

void reverse(int tab[],int taille,int neg) {
    int i;
    int temp;

    for(i=neg; i<taille/2; i++) {
        temp=tab[i];
        tab[i]=tab[taille-i-1];
        tab[taille-i-1]=temp;
    }
}

void printtab(int tab[],int taille) {

    int i;

    for(i=0; i<taille; i++) {
        printf("%d",tab[i]);
    }
    printf("\n");
}


char* inttostr(int nb) {

    char *chain;
    int tab[1000]= {0};
    int i=0,j=0;

    if(nb==0) {
        chain=malloc(2);
        chain[0]='0';
        chain[1]='\0';
        return chain;
    }


    if(nb<0) {
        nb=-nb;
        i=1;
        while(nb!=0) {
            tab[i]=nb%10;
            nb=nb/10;
            i++;
        }
        reverse(tab,i+1,1);
        chain=malloc(sizeof(char) * i);

        chain[0]='-';
        for(j=1; j<=i; j++) {
            chain[j]=tab[j]+'0';
        }

        chain[i]='\0';
        return chain;
    }


    while(nb!=0) {
//printf("tab[%d]:%d\n",i,nb%10);
        tab[i]=nb%10;
        nb=nb/10;
        i++;
    }
    reverse(tab,i,0);

    i++;
    chain=malloc(sizeof(char) * i);

    for(j=0; j<=i; j++) {
        chain[j]=tab[j]+'0';
//printf("c: %c x=%d\n",chain[j],j);
    }

    chain[i-1]='\0';
    return chain;

}

void main() {
    char *test=inttostr(-50354);
    int i;
    printf("%s\n",test);
    /*
    for(i=0; i<strlength(test)+1; i++)
      printf("'%c'",test[i]);
    */
}
