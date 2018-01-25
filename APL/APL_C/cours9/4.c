#include <stdio.h>
#include <stdlib.h>

int megaPower(int x, int y){

  if(y == 0)
    return 1;

  return power(x,megaPower(x,y-1));

}

int power(int x, int y){
  if(y == 1)
    return x;

  return x*power(x,y-1);
}

void main(){
  printf("%d\n",megaPower(2,4));
}
