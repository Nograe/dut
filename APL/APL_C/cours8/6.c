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

char* removeLast(char* str,int n){

  int i=0,j=0,new_size=0;
  char *vide=malloc(sizeof(char) * 1);
  vide[0]='\0';
  
  new_size=strlength(str)-n;

  char *chain=malloc((new_size+1) * sizeof(char));
  
  if(n>strlength(str))
    return vide;

  for(j=0 ; j<new_size ; j++){
    chain[j]=str[j];
  }
  chain[new_size]='\0';
  return chain;
  
}

void main(){
  char *test=removeLast("GwlM0aUc",3);
  int i;

  for(i=0; i<strlength(test)+1; i++)
    printf("%d ",(int)test[i]);
}
