#include <stdio.h>

void main(){
  int ent1,ent2,ent3;

  scanf("%d",&ent1);
  scanf("%d",&ent2);
  scanf("%d",&ent3);

  if(ent1%7 == 0 && ent2%7 == 0 && ent3%7 == 0){
    printf("1\n");
    return;
  }

  if(ent1%2 == 0){
    if(ent2%2 == 0 && ent3%2 !=0)
      printf("1\n");
    if(ent3%2 == 0 && ent2%2 !=0)
      printf("1\n");
    return;
  }
 if(ent2%2 == 0){
    if(ent1%2 == 0 && ent3%2 !=0)
      printf("1\n");
    if(ent3%2 == 0 && ent1%2 !=0)
      printf("1\n");
    return;
  }

 printf("0\n");
 
}
