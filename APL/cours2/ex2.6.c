#include <stdio.h>
int main(int argc, char* argv[]) {
	
	int ent;
	int ent2;
	int ent3;
	scanf("%d %d %d", &ent, &ent2, &ent3);
	int verif= ent>ent2 && ent>ent3 || ent2>ent && ent2>ent3 || ent3>ent && ent3>ent2;
	printf("%d\n", verif);

	return 0;
}
