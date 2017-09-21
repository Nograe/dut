#include <stdio.h>

int main(int argc, char* argv[]) {
	
  int ent;
  int ent2;
  int ent3;
  scanf("%d %d %d",&ent,&ent2,&ent3);

  if(ent<=ent2 && ent2<=ent3){
    printf("%d %d %d\n",ent,ent2,ent3);
  } else if(ent<=ent3 && ent3<=ent2){
    printf("%d %d %d\n",ent,ent3,ent2);
  } else if(ent2<=ent && ent<=ent3){
    printf("%d %d %d\n",ent2,ent,ent3);
  } else if(ent2<=ent3 && ent3<=ent){
    printf("%d %d %d\n",ent2,ent3,ent);
  } else if(ent3<=ent2 && ent2<=ent){
    printf("%d %d %d\n",ent3,ent2,ent);
  } else {
    printf("%d %d %d\n",ent3,ent,ent2);
  }
  
  return 0;
}
