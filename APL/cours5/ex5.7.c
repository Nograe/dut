#include <stdio.h>
int fibonacci(int n){
	int i;	
	int vm2 = 0;
	int vm1 = 1;

	for(i=0; i<n; i++){
		int v = vm1 + vm2;
		vm2 = vm1;
		vm1 = v;		
	}
	
	return vm2;
}

void main(){
	int i;
	for (i = 0; i < 10; ++i)
		printf("%d\n", fibonacci(i));
}
