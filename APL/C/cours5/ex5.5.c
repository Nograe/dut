#include <stdio.h>

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
	printf("%d\n",division(a,b));
}
