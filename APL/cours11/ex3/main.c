#include "main.h"
#include <stdio.h>

int main () {

  int choix;

  printf("Choisissez votre exercice: ");
  scanf("%d",&choix);

  switch(choix){
  case 1:
    ex1();
    break;
  case 2:
    ex2();
    break;
  case 3:
    ex3();
    break;
  case 4:
    ex4();
    break;
  case 5:
    ex5();
    break;
  case 6:
    ex6();
    break;
  }
  return 0;
}
