#include <stdio.h>

int main(void) {
  char min, maj;
  char *p = NULL;
  for(min = 'a', maj = 'A'; maj <= 'Z'; min++, maj++) {
      if (p == &min)
	p = &maj;
      else
	p = &min;
    printf("%c", *p);
  }
  printf("\n");
  return 0;
}
