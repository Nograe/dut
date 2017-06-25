#include <stdio.h>

void fct(int *p1, int *p2, int *p3){
  
  int var;

  var=*p1;
  *p1=*p2;
  *p2=*p3;
  *p3=var;
  
}

void main(){

}
