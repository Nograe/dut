#include <stdio.h>
int main(int argc, char* argv[]) {
	
  char P1;
  int n;
  scanf("%c %d",&P1,&n);

  int m = n%3;
  int victoirejoueur = P1=='P' && m=='2' || P1=='F' && m=='0' || P1=='C' && m==1;
  int victoireordi = P1=='C' && m=='0' || P1=='C' && m=='1' || P1=='F' && m==2;
  
  printf("%d\n",victoirejoueur);
  printf("%d\n",victoireordi);
  
  return 0;
}
