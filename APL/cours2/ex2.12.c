 #include <stdio.h>
int main(int argc, char* argv[]) {
	char c;
	char c1;
	scanf("%c %c", &c, &c1);
	int verif = c>='0' && c<='9' && c1>'9'|| c1>='0' && c1<='9' && c>'9';
	printf("%d\n", verif);

	return 0;
}
