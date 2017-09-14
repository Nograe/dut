#include <stdio.h>
int main(int argc, char* argv[]) {
	char n;
	char n2;
	char n3;
	scanf("%c %c %c", &n, &n2, &n3);
	int verif = (n==n2 && n!=n3) || (n==n3 && n!=n2) || (n2==n3 && n2!=n);
	printf("%d\n", verif);

	return 0;
}
