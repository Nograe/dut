#include <stdio.h>

int test(int n1, int n2){
  int n11,n12,n13,n14,n21,n22,n23,n24;
  n11=n1/1000; n21=n2/1000;
  n12=n1%1000/100; n22=n2%1000/100;
  n13=n1%100/10; n23=n2%100/10;
  n14=n1%10; n24=n2%10;

  if(compa(n11,n21) || compa(n11,n22) || compa(n11,n23) || compa(n11,n24) || compa(n12,n21) || compa(n12,n22) || compa(n12,n23) || compa(n12,n24) || compa(n13,n21) || compa(n13,n22) || compa(n13,n23) || compa(n13,n24) || compa(n14,n21) || compa(n14,n22) || compa(n14,n23) || compa(n14,n24) ){
    return 1;
  }
  return 0;
}

int compa(int ent1, int ent2){
  if(ent1==ent2){
    return 1;
  } else {
    return 0;
  }
}

int main() {
  test(8467,5016);
	return 0;
}
