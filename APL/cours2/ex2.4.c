#include <stdio.h>
int main(int argc, char* argv[]) {
	
	int ent;
	scanf("%d", &ent);
	int verif = ent==7 || ent==43 || ent==34 || ent==70 || ent%7==0 || ent==07 || ent/10==7 || ent%10==7 || ent==52 || ent==16 || ent==25 || ent==16;
	printf("%d\n", verif);

	return 0;
}
