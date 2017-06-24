#include <stdio.h>

int count(int tab[], int taille){

  int i;
  int var=taille;

  for(i=0; i<taille; i++){
    if(tab[i]==0)
      var--;
  }
  return var;
}

void main(){

  int tab[5];
  count(tab, 5);

}
