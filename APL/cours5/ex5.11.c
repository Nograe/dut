#include <stdio.h>

int miroir(int ent){
	int var, varnew;
	int new=0;
	while(ent>0){
		var=ent%10;
		ent=ent/10;
		new=new*10+var;
	}
	return new;
}

void main(){
	int ent;
	scanf("%d",&ent);
	printf("%d\n",miroir(ent));
}
