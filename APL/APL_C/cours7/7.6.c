#include <stdio.h>

int* fct(){
  srand(time(NULL));

  int ent=rand();

  return &ent;
}

void main(){

  printf("%d\n", *fct());

}
