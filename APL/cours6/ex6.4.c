#include <stdio.h>

void inverse(int tab[], int taille){

  int i;
  int temp;

  for(i=0; i<taille/2; i++){

    temp=tab[i];
    tab[i]=tab[taille-i-1];
    tab[taille-i-1]=temp;

  }

}

void main(){
  int i;
  int tab[9]={1,2,3,4,5,6,7,8,9};
  inverse(tab,9);
  
  for(i=0; i<9; i++){
    printf("i: %d\n", tab[i]);
  }
  

}
