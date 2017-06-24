#include <stdio.h>
int main(int argc, char* argv[]) {
	char catout;
	int vcarte1;
	char ccarte1;
	int vcarte2;
	char ccarte2;
	scanf("%c %d %c %d %c", &catout, &vcarte1, &ccarte1, &vcarte2, &ccarte2);

	int verif1 = ccarte1==catout && ccarte2!=catout; //carte 1 supérieure

	int verif21 = ccarte1==catout && ccarte2==catout && vcarte1!=vcarte2; //classement atout
	int verif22;
	int verif2 = verif21 && verif22;


	int verif41 = ccarte1!=catout && ccarte2!=catout && vcarte1!=vcarte2; //classement non-atout
	int verif42 = vcarte1>vcarte2 && vcarte2!=10 && vcarte1!=10 || vcarte2==10 && vcarte1==14 || vcarte1==10 && vcarte2<=13;
	int verif4 = verif41 && verif42;

	int verif3 = ccarte1!=catout && ccarte2==catout && !verif1 && !verif2 && !verif4; //carte 2 supérieure
	
	int cheat = ccarte1==catout && ccarte2==catout && vcarte1>vcarte2;

	int verif = verif1 || verif4 || cheat;
	printf("%d\n", verif);

	return 0;
}
