#include <stdio.h>

int count(int tab[], int taille){
  
  int i,j;
  int var=taille;
  
  for(i=0; i<taille; i++){
    for(j=i; j<taille; j++){
      if(tab[i]==tab[j] && i!=j){
	var--;
	j=taille;
      }
    }
  }
  
  return var;
  
}

void main(){
  int i;
  int tab[10]={-2,0,-1,9,-1,5,2,-1,-2,-1};
  printf("%d",count(tab,10));
}
