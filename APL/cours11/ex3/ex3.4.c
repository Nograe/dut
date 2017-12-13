#include <stdio.h>
int ex4() {
	
	double ent;
	scanf("%lf",&ent);
	if(ent<8){
	  printf("Recalé\n");
	} else if(ent<10) {
	  printf("Rattrapage\n");
	} else if(ent<12) {
	  printf("Mention passable\n");
	} else if(ent<14) {
	  printf("Mention assez bien\n");
	} else if(ent<16) {
	  printf("Mention bien\n");
	} else {
	  printf("Mention très bien\n");
	}

	return 0;
}
