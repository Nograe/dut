#include <stdio.h>

double mult(double a, int n){
	int i;
	double var=a;
	if(n<0){
		for(i=1; i<-n; i++){
			a+=var;
		}
	return -a;	
	}
	for(i=1; i<n; i++){
		a+=var;
	}
	return a;
}

void main(){
	double a;
	int n;
	scanf("%lf %d",&a,&n);
	printf("%lf\n",mult(a,n));
}

