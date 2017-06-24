#include <stdio.h>

void move(int tab[], int taille, int a, int b);
void sort(int tab[], int taille);

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

void sort(int tab[], int taille){
  
  int i;
  int var=0;
  
  for(i=0; i<taille; i++){
    if(tab[i]<0){
      move(tab,taille,var,i);
      var++;
    }
  }
}

void main(){
  int i;
  int tab[9]={1,-1,3,-5,0,6,-2,8,9};
  sort(tab,9);
  
  for(i=0; i<9; i++){
    printf("i: %d\n", tab[i]);
  }
  

}
