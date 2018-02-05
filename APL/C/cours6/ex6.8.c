#include <stdio.h>

void sort(int tab[], int taille){

  int i;
  int var=0;

  for(i=0; i<taille-1; i++){
    
    if(tab[i]>tab[i+1]){
      
      var=tab[i];
      tab[i]=tab[i+1];
      tab[i+1]=var;
      
    }
    
  }
  
  for(i=0; i<taille-1; i++){
    if(tab[i]>tab[i+1]){
      sort(tab, taille);
      return;
    }
  }
  return;
}

void main(){
  int i;
  int tab[11]={3,4,2,8,5,4,5,6,10,3,5};
  sort(tab,11);
  
  for(i=0; i<11; i++){
    printf("i: %d\n", tab[i]);
  }
  

}
