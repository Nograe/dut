#include <stdio.h>
int main(int argc, char* argv[]) {
	
  int ent;
  scanf("%d",&ent);
  if(ent%5==0 && ent%7==0){
    printf("FizzBuzz\n");
  } else if(ent%5==0){
    printf("Fizz\n");
  } else if(ent%7==0){
    printf("Buzz\n");
  } 
 

  return 0;
}
