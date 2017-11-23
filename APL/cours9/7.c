#include <stdio.h>
#include <stdlib.h>

int isint(char *str){
  if(str[0] == '\0')
    return 0;
  if(*str >= '0' && *str <= '9'){
    if(*(str+1) == '\0')
      return 1;
    return isint(str+1);
  }
  return 0;
}

void main(){
  printf("%d",isint("1234"));
}
