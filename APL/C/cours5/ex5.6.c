#include <stdio.h>
int division(int a, int b);
int mult(int a, int n){
	int i;
	int var=a;
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

int modulo(int a, int b){
	//printf("a: %d b: %d division a et b: %d multiplication a/b et b: %d  modulo a et b: %d\n",a,b,division(a,b),mult(division(a,b),b),a%b);

	return a-mult(division(a,b),b);
}

int division(int a, int b){
	int compteur=0;
	int flag=0;
	
	if(a<0){
	a=-a;
	flag++;
	}

	if(b<0){
	b=-b;
	flag--;
	}

	while(a>0){
		a-=b;
		compteur++;
	}

	if(!(a==0)){
		compteur--;
	}
	if(flag!=0){
		return -compteur;
	}
	return compteur;
}

void main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",modulo(a,b));
}
