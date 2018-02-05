#include <stdio.h>

int xor(int a, int b){
  if(a==b){
    return 0;
  }
  if(a && !b){
    return 1;
  }
  if(!a && b){
    return 1;
  }
}

int main(int argc, char* argv[]) {
  int a,b;
  xor(scanf("%d",&a),scanf("%d",&b));
	return 0;
}
