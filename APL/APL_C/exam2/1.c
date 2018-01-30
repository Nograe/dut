#include <stdio.h>
#include <stdlib.h>

int premier (int nb) {

  if(nb <= 1)
    return 0;

  return test(nb, nb-1);
}

int test (int nb, int div) {

  if(div <= 1)
    return 1;

  if(nb % div == 0)
    return 0;

  return test(nb, div-1);
}

void main (int argc, int *argv[]) {
   
  int i;
  for(i = 0; i < 20; i++) {
    printf("%d: %d\n", i, premier(i));
  }
}
