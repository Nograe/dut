#include <stdio.h>

int max(int tab[], int taille){

  int i;
  int max=tab[0];

  for(i=1; i<taille; i++){

    if(tab[i]>max){
      max=tab[i];
    }

  }
  return max;
}

void main(){

  int tab[9]={1, 2, 3, 0, 8, 5, 8, 3, 2};
  printf("%d",max(tab, 9));

}
