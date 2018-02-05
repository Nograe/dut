#include <stdio.h>
#include <stdlib.h>

int strequals(char* str1, char* str2){

  int i=0,j=0,var=0;
  
  while(str1[i]!='\0')
    i++;

  while(str2[j]!='\0')
    j++;

  if(i>j || j>i)
    return 0;

  for(j=0 ; j<i ; j++){
    if(str1[j]!=str2[j])
      return 0;
  }
  
  return 1;

}

void main(){

  char *str1="test",*str2="test2";

  if(strequals(str1,str2))
    printf("identiques");
  else
    printf("différents");
}
