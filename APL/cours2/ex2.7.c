#include <stdio.h>
int main(int argc, char* argv[]) {
	
	int n1;
	int n2;
	scanf("%d %d", &n1, &n2);
	int verif= n1!=0 && n2!=0 || n1==0 && n2==0;
	printf("%d\n", verif);

	return 0;
}
