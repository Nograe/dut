#include <stdio.h>
int main(int argc, char* argv[]) {
	
  char l1;
  char l2;
  char l3;
  char l4;
  char l5;
  char l6;
  int var=0;
  scanf("%c%c%c%c%c%c",&l1,&l2,&l3,&l4,&l5,&l6);

  if(l1=='o'){
    var=var+1;
  } if(l2=='i'){
    var=var+1;
  } if(l3=='s'){
    var=var+1;
  } if(l4=='e'){
    var=var+1;
  } if(l5=='a'){
    var=var+1;
  } if(l6=='u'){
    var=var+1;
  }

  printf("%d\n",var);

  return 0;
}
