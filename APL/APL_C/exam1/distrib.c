#include <stdio.h>

void verif(int prix,int argent){
  
  int i;

  //Problème de conversion pour 114 

  //printf("Argent: %d, Prix: %d\n",argent,prix);

  if(argent == prix)
    return;
  
  if(argent < prix){
    printf("Il manque: %lf euros.\n",(prix-argent) / 100.0);
    return;
  }
  
  printf("La machine rend:\n");
  
  i=0;
  while(argent-200 >= prix){
    argent -= 200;
    i++;
  }
  printf("2 euros : %d\n",i);
  
  i=0;
  while(argent-100 >= prix){
    argent -= 100;
    i++;
  }
  printf("1 euro : %d\n",i);
  
  i=0;
  while(argent-50 >= prix){
    argent -= 50;
    i++;
  }
  printf("50 centimes : %d\n",i);
  
  i=0;
  while(argent-20 >= prix){
    argent -= 20;
    i++;
  }
  printf("20 centimes : %d\n",i);
  
  i=0;
  while(argent-10 >= prix){
    argent -= 10;
    i++;
  }
  printf("10 centimes : %d\n",i);
  
  i=0;
  while(argent-5 >= prix){
    argent -= 5;
    i++;
  }
  printf("5 centimes : %d\n",i);
  
  i=0;
  while(argent-2 >= prix){
    argent -= 2;
    i++;
  }
  printf("2 centimes : %d\n",i);

  i=0;
  while(argent-1 >= prix){
    argent -= 1;
    i++;
  }
  printf("1 centime : %d\n",i);
  
}

void main(){
  
  double r;
  char c;

  scanf("%lf", &r);
  scanf(" %c", &c);

  if(c == 'c'){
    verif(115,(int)(r*100));
    return;
  }
  
  if(c == 'd'){
    verif(187,r*100);
    return;
  }

  if(c == 'g'){
    verif(221,r*100);
    return;
  }

}
