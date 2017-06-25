#include <stdio.h>

void fct(int *t, int taille){

  int i;

  for(i=0; i<taille; i++){
    printf("%d ",*(t+i));
  }
      printf("\n");

}

void main(){
  
  int tab[3][4]={{0,1,2,3},{10,11,12,13},{20,21,22,23}};
  fct(tab,12);

}
