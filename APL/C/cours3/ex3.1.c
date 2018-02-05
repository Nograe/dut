#include <stdio.h>
int main(int argc, char* argv[]) {
	
	double ent;
	double ent2;
	scanf("%lf %lf",&ent,&ent2);
	if(ent*ent2>=0){
	  printf("+\n");
	} else {
	  printf("-\n");
	}

	return 0;
}
