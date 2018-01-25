#include <stdio.h>

double plus(double a, int n){
	a+=n;
	return a;
}

void main(){
	double a;
	int n;
	scanf("%lf %d",&a,&n);
	printf("%lf",plus(a,n));
}
