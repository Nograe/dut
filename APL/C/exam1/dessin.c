#include <stdio.h>

void main(){

  int taille,i,j,var=0;
  
  scanf("%d",&taille);

  int total = taille*2;

  for( i = 0 ; i < taille; i++)
    printf(" ");

  for( i = 0 ; i < taille; i++)
    printf("*");

  printf("\n");


  for(j = taille; j > 0 ; j--) {

    for(i = 1; i < j ; i++) {
      printf(" ");
    }
    
    printf("*");
    
    for(i = j ; i < taille*2+var ; i++) {
      printf(" ");
      
    }
    var++;
    printf("*\n");
    
  }
  var--;
  
  for(j = 2 ; j <= taille ; j++) {
    
    for(i = 1; i < j ; i++)
      printf(" ");
    
    printf("*");
    
    for(i = 2; i < taille+var*2 ; i++)
      printf(" ");
    
    var--;
    printf("*\n");
  }


  for( i = 0 ; i < taille; i++)
    printf(" ");

  for( i = 0 ; i < taille; i++)
    printf("*");

  printf("\n");

}
