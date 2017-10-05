#include<stdio.h>
#include<stdlib.h>

void triTab(int tab[], int tailleTab){
    int i,j;
    int var=0;
    for(i=0; i<tailleTab-1; i++){
        if(tab[i]<tab[i+1]){
            var=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=var;
        }
    }
    for(j=0; j<tailleTab-1; j++){
        if(tab[i]<tab[i+1]){
            triTab(tab,5);
            return;
        }
    }
}

void main()
{
    int i;
    int tab[5]={1,6,3,9,5};
    triTab(tab,5);
    for(i=0; i<5; i++){
        printf("%d",tab[i]);
    }
    return;
}
