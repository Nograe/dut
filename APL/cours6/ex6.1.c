#include <stdio.h>

void init(int tab[], int taille){

  int i;

  for(i=0; i<taille; i++){

    tab[i]=3;

  }

}

void main(){

  int tab[5];
  init(tab, 5);

}
