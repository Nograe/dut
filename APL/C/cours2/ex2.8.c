#include <stdio.h>
int main(int argc, char* argv[]) {
	int n;
	scanf("%d", &n);
	int verif = n%400==0 || n%4==0 && n%100!=0;
	printf("%d\n", verif);

	return 0;
}
