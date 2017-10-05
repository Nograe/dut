#include <stdio.h>

void etoiles(int n, int var){
	if(var==n){ return; }
	int i;
	for(i=0; i<var; i++){
	printf(" ");
	}
	printf("*\n");
	etoiles(n,var+1);
}

void main(){
	int N;
	scanf("%d",&N);
	while(N<0)
	scanf("%d",&N);
	etoiles(N,0);
}
