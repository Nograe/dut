#include <stdio.h>

void move(int tab[], int taille, int a, int b){

  int i;
  int temp=0;
  int var=0;

  if(a>b || b>=taille){
    return;
  }

  temp=tab[a];
  tab[a]=tab[b];

  for(i=a+1; i<=b; i++){
    var=tab[i];
    tab[i]=temp;
    temp=var;
  }
}

void main(){
  int i;
  int tab[8]={1,2,3,4,5,6,7,8};
  move(tab,9,2,6);
  
  for(i=0; i<8; i++){
    printf("i: %d\n", tab[i]);
  }


}
