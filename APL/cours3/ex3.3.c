#include <stdio.h>
int main(int argc, char* argv[]) {
	
	int ent;
	scanf("%d",&ent);
	int modulo=ent%3;
	if(modulo==1){
	  printf("%d\n",ent-1);
	} else if(modulo==2){
	  printf("%d\n",ent+1);
	} else {
	  printf("%d\n",ent);
	}
	return 0;
}
