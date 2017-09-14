#include <stdio.h>
int main(int argc, char* argv[]) {
	int ent;
	int ent2;
	scanf("%d %d", &ent, &ent2);
	int verif = ent/100==ent2 || ent%100==ent2 || ent/10%10==ent2 || ent%10==ent2;
	printf("%d\n", verif);

	return 0;
}
