#include <stdio.h>

void main(){
	int N, ent, i;
	int var=0; int var2=0;
	scanf("%d", &N);
	for(i=0; i<N; i++){
	scanf("%d",&ent);
	var=ent*ent;
	var2+=var;
	}
	printf("%d\n", var2);
}
