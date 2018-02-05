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

int megaxor(int a,int b, int c, int d){
  return xor(xor(a,b),xor(c,d));
}

int main(int argc, char* argv[]) {
	return 0;
}
