#include <stdio.h>
#include <stdlib.h>

void syracus(int a_n){

  if(a_n == 1){
    printf("%d\n",1);
    return;
  }

  if(a_n%2 == 0){
    printf("%d\n",a_n);
    syracus(a_n/2);
    return;
  } else {
    printf("%d\n",a_n);
    syracus(3*a_n+1);
    return;
  }
}

void main(){
  syracus(7);
}
