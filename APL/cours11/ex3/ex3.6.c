#include <stdio.h>
int ex6() {
	
  int entier;
  scanf("%d",&entier);
  int ent=entier/100;
  int ent2=entier%100/10;
  int ent3=entier%100%10;

  if(ent>ent2 && ent>ent3){
    printf("%d\n",ent);
  } else if(ent2>ent && ent2>ent3){
    printf("%d\n",ent2);
  } else {
    printf("%d\n",ent3);
  }

  return 0;
}
