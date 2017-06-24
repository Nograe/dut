#include <stdio.h>
int main(int argc, char* argv[]) {
	
  int a;
  int b;
  scanf("%d %d",&a,&b);
  if(a==0 && b==0){
    printf("Tout x est solution\n");
  } else if(b==0){
    printf("0\n");
  } else if(a==0){
    printf("Pas de solution\n");
  } else {
    double var=-b/(double)a;
    printf("%lf\n",var);
  }

  return 0;
}
