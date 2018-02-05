#include <stdio.h>
int main(int argc, char* argv[]) {
	
	int ent;
	int ent2;
	int ent3;
	scanf("%d %d %d",&ent,&ent2,&ent3);
	if(ent>ent2 && ent>ent3){
	  printf("%d\n",ent);
	} else if(ent2>ent && ent2>ent3){
	  printf("%d\n",ent2);
	} else {
	  printf("%d\n",ent3);
	}

	return 0;
}
