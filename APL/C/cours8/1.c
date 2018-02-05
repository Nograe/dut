#include <stdio.h>
#include <stdlib.h>

int strlength(char* str)
{

  int i=0;

  while(str[i]!='\0'){
    i++;
  }

  return i;
}

void main(){

  char *chain="test";
  printf("%d",strlength(chain));

}
