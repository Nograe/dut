#include <stdio.h>
int main(int argc, char* argv[]) {

	char color;
	int d1, d2, serie, batt, port;
	scanf("%c %d %d %d %d %d", &color, &d1, &d2, &serie, &batt, &port);

	int C= color!='r' && color!='n' && color!='d' && d1!=1 && d2!=1 || color=='r' && color!='n' && color!='d' && d1==1 && d2!=1 || color!='r' && color!='n' && color!='d' && d1==1 && d2!=1 || color=='b' && d1==1 && d2!=1 || color=='b' && d1!=1 && d2!=1;

	int S= color=='r' && color!='n' && color!='d' && d1!=1 && d2!=1 || color!='r' && color=='n' && color!='d' && d1!=1 && d2!=1 || color!='r' && color!='n' && color=='d' && d1!=1 && d2!=1 || color!='r' && color!='n' && color=='b' && d1!=1 && d2==1;
	int verifS= S && serie%2==0;

	int D= color!='r' && color!='n' && color=='d' && d1==1 && d2==1 || color!='r' && color=='n' && color!='d' && d1==1 && d2!=1 || color!='r' && color!='n' && color!='d' && d1!=1 && d2==1 || color=='d' && d1!=1 && d2==1;

	int P= color!='r' && color!='n' && color=='d' && d1==1 && d2!=1 || color!='r' && color=='n' && color!='d' && d1!=1 && d2==1 || color!='r' && color=='n' && color!='d' && d1==1 && d2==1;
	int verifP= P && port==1;

	int B= color=='r' && color!='n' && color!='d' && d1==1 && d2==1 || color=='r' && color!='n' && color!='d' && d1!=1 && d2==1 || color!='r' && color!='n' && color!='d' && d1==1 && d2==1 || color=='b' && d1==1 && d2==1;
	int verifB= B && batt>=2;


	int verif= C || verifS || verifP || verifB;
	printf("%d\n", verif);

	return 0;
}
