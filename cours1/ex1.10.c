#include <stdio.h>

int main(int argc, char* argv[]) {
  
  int n;
  int m;
  scanf("%d", &n);
  scanf("%d", &m);
  printf("%d = %d * %d + %d\n", n, n/m, m, n%m);

    return 0;
}
