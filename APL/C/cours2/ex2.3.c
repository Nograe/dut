#include <stdio.h>
int main(int argc, char* argv[]) {
	
	int ent;
	scanf("%d",&ent);
	double reel;
	scanf("%lf", &reel);
	int verif=ent==(int)reel;
	printf("%d\n", verif);

	return 0;
}
