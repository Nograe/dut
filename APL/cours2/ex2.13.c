#include <stdio.h>
int main(int argc, char* argv[]) {
	char catout;
	int vcarte1;
	char ccarte1;
	int vcarte2;
	char ccarte2;
	scanf("%c %d %c %d %c", &catout, &vcarte1, &ccarte1, &vcarte2, &ccarte2);
	int verif1 = ccarte1==catout && ccarte2!=catout; //carte 1 supérieure
	int verif2 = ccarte1==catout && ccarte2==catout && (vcarte1>vcarte2 && vcarte2!=11 && vcarte2!=9 && vcarte2!=10 || vcarte1==11 && (vcarte2==9 || vcarte2==10) || vcarte1==9 && (vcarte2!=11 || vcarte2==10) || vcarte1==10 && vcarte2!=11 && vcarte2!=9); //classement atout
	int verif3 = ccarte1!=catout && ccarte2==catout; //carte 2 supérieure
	int verif4 = ccarte1!=catout && ccarte2!=catout && (vcarte1>vcarte2 && vcarte2!=10 && vcarte2!=14 || vcarte1==14 && vcarte2==10 || vcarte1==10 && vcarte2!=14); //classement non-atout
	int verif5 = verif1 || verif2 || !verif3 || verif4;
	printf("%d\n", verif4);

	return 0;
}
