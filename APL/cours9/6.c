#include <stdio.h>
#include <stdlib.h>

int sumtab(int tab[], int taille){
  if(taille == 0)
    return 0;
  
  if(tab[taille-1] >= 0)
    return tab[taille-1]+sumtab(tab, taille-1);
  
  return sumtab(tab, taille-1);
}

void main(){
  int tab[8]={18,-62,-26,50,33,91,-17,72};
  printf("%d",sumtab(tab,8));
}
