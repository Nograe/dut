#include <stdio.h>
int main(int argc, char* argv[]) {
	
	int ent;
	scanf("%d",&ent);
	int verif= ent>99 && ent<=999;
	printf("%d\n", verif);

	return 0;
}
