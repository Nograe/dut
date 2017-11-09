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

int strtoint(char *str, int *error){

  int length=strlength(str);
  int convert=0,i=0;
  int var;
  *error=0;
  var=str[i]-'0';
  
   if(var<0 || var>9){
    *error=1;
    return 0;
  }

  for(i=0;i<length;i++){
    var=str[i]-'0';
    if(var<0 || var>9){
      *error=0;
      return convert;
    }
      convert=convert*10+var;
  }
  
  return convert;
}

void main(){
  int error;
  printf("%d ; %d\n",strtoint("469684d589",&error),error);
}
