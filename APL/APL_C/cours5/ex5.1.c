#include <stdio.h>

double puissance(double a, int n){
	int i,j;
	double var=a;
	if(n==0){
	return 1;}
	if(n>0){
		for(i=1; i<n; i++){
			a=a*var;
		}
	return a;
	}
	if(n<0){
		for(i=1; i<(-n); i++){
			a=a*var;
		}
	return 1/a;	
	}
}

void main(){
	double a;
	int n;
	scanf("%lf %d",&a,&n);
	printf("%lf\n",puissance(a,n));
}

