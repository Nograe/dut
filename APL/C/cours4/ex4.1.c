#include <stdio.h>

int max2(int ent1, int ent2){
  if(ent1==ent2){
    return;
  }
  if(ent1>ent2){
    return ent1;
  }else{
    return ent2;
  }
	return;
}

int main(int argc, char* argv[]) {
  int ent1,ent2;
  max2(ent1,ent2);
	return 0;
}
