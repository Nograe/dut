#include <stdio.h>

void main(){
	int N, ent, i;
	int var=0;
	scanf("%d", &N);
	for(i=0; i<N; i++){
	scanf("%d",&ent);
	var+=ent;
	}
	printf("%d\n", var);
}
