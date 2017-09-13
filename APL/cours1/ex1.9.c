#include <stdio.h>

int main(int argc, char* argv[]) {
  
  int note1;
  int note2;
  int note3;
  scanf("%d", &note1);
  scanf("%d", &note2);
  scanf("%d", &note3);
  double moyenne = ((double)note1+(double)note2+(double)note3)/3;
  printf("result : %lf\n", moyenne);

    return 0;
}
