#include <stdio.h>
#include <stdlib.h>

int sumsquare(int n){
  if(n == 1)
    return 1;

  if(n == 0)
    return 0;

  return ((n*n)+sumsquare(n-1));
}

void main(){
  printf("%d\n",sumsquare(5));
}
