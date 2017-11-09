#include <stdio.h>
#include <stdlib.h>

int contains(char *str1, char *str2){

  int i=0,j=0,x,z,var;
  char c;

  if(str1==0 || str2==0)
    return 1;

  while(str2[i]!='\0')
    i++;

  while(str1[j]!='\0')
    j++;

  if(i==0 || j==0 || i>j)
    return ;
  
  for(x<j; x<j ;x++){
    var=startswith(str1+x,str2);
      if(var)
	return 1;
      else
	var=0;
  }


    return 0;
     
  
}

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
  char *str1="4XBU85L5P",*str2="";

  printf("%d",contains(str1,str2));
}
