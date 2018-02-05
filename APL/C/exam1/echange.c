#include <stdio.h>

void echange(int tab1[], int tab2[], int length){
  
  int i;
  int tmp=0;

  for(i = 0 ; i < length ; i++){
    if(i%2 == 0){
      tmp = tab1[i];
      tab1[i] = tab2[i+1];
      tab2[i+1] = tmp;
    }
  }

}

void main(){

  /*int tab1[8] = {1,2,5,7,3,4,8,9};
  int tab2[8] = {3,0,2,8,2,1,7,6};

  int length = 8;

  int i;
  
  echange(tab1, tab2, length);

  for(i = 0 ; i < length ; i++)
    printf("tab1[%d]: %d  |  tab2[%d]: %d\n",i,tab1[i],i,tab2[i]);
  */

}
