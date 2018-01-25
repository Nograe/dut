#include <stdio.h>

void fct(int *t, int taille){

  int i;

  for(i=0; i<taille; i++){
    printf("%d ",*(t+i));
  }
      printf("\n");

}

void main(){
  
  int tab[10]={0,1,2,3,4,5,6,7,8,9};
  fct(tab,10);

}
