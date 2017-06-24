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
    return ent1;
  }
  int maxi=max2(ent1, ent2);
  int maxi2=max2(ent3, ent4);
  return max2(maxi, maxi2);
}

int max8(int ent1, int ent2, int ent3, int ent4, int ent5, int ent6, int ent7, int ent8){
  int maxi=max4(ent1, ent2, ent3, ent4);
  int maxi2=max4(ent5, ent6, ent7, ent8);
  return max2(maxi,maxi2);
}

int main(int argc, char* argv[]) {
  int ent1,ent2,ent3,ent4,ent5,ent6,ent7,ent8;
  scanf("%d %d %d %d %d %d %d %d", &ent1, &ent2, &ent3, &ent4,&ent5,&ent6,&ent7,&ent8);
  max8(ent1,ent2,ent3,ent4,ent5,ent6,ent7,ent8);
	return 0;
}
