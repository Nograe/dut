#include <stdio.h>

void main(){
	char carac;
	printf("Veuillez rentrer un caractère alphanumérique.\n");
	scanf("%c",&carac);
	while( !(carac>='0' && carac<='9') && !(carac>='a' && carac<='z') && !(carac>='A' && carac<='Z') ){
		printf("Veuillez rentrer un caractère alphanumérique.\n");
		scanf(" %c",&carac);
	}
	return;
}
