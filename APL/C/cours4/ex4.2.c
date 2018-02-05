#include <stdio.h>

int max2(int ent1, int ent2){
  int max=0;
  if(ent1==ent2){
    return ent1;
  }
  if(ent1>ent2){
    return ent1;
  }else{
    return ent2;
  }
  return;
}

int max4(int ent1, int ent2, int ent3, int ent4){
  if(ent1==ent2==ent3==ent4){
    return;
  }
  int maxi=max2(ent1, ent2);
  int maxi2=max2(ent3, ent4);
  return max2(maxi, maxi2);
}

int main(int argc, char* argv[]) {
  int ent1,ent2,ent3,ent4;
  scanf("%d %d %d %d", &ent1, &ent2, &ent3, &ent4);

  max4(ent1,ent2,ent3,ent4);
	return 0;
}
