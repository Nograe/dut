#include <stdio.h>
#include <stdlib.h>

int startswith(char* str1, char* str2){
  
  int i=0,j=0;

  while(str2[i]!='\0')
    i++;

  
  for(j=0; j<i; j++){
   
    if(str1[j] != str2[j])
      return 0;
  }

  return 1;

}

void main(){
  char *str1="abcd",*str2="abc";

  if(startswith(str1,str2))
    printf("identiques");
  else
    printf("différents");
}
