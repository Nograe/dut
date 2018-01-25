#include <stdio.h>

int check(int tab[], int length){

  int i;
  int verif;

  for(i = 0 ; i < length ; i++){
    if(tab[i] != i)
      return 0;
  }

  return 1;
  
}

void main(){

  /*int tab[6] = {0,1,2,3,4,5};

  printf("%d",check(tab,6));
  */

}
