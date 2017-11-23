#include <stdio.h>
#include <stdlib.h>

int isreverse(int tab1[], int tab2[], int taille){
  if(*tab1 == tab2[taille-1]){
    if(taille-1 == 0)
      return 1;
    return isreverse(tab1+1,tab2,taille-1);
  }
  return 0;
}

void main(){
  int tab1[4]={4,1,2,3};
  int tab2[4]={3,1,1,4};
  printf("%d\n", isreverse(tab1,tab2,4));
}
