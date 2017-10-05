#include <stdio.h>

int commun(int ent, int ent2){
	int var, var2;
	int new=0;
	int verif;
	while(ent2>0){
	var2=ent2%10;
	ent2=ent2%10;
	while(ent>0){
		var=ent%10;
		ent=ent/10;
		if(var==var2){ return 1; }
	}
	}
	return 0;
}

void main(){
	int ent, ent2;
	scanf("%d %d",&ent, &ent2);
	printf("%d\n",commun(ent, ent2));
}
