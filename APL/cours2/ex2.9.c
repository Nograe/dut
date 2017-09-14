#include <stdio.h>
int main(int argc, char* argv[]) {
	int n;
	int n2;
	int n3;
	scanf("%d %d %d", &n, &n2, &n3);
	int verif = n>=8 && n2>=8 && n3>=8 && (n+n2+n3)/3>=10;
	printf("%d\n", verif);

	return 0;
}
