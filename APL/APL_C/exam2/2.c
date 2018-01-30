#include <stdio.h>
#include <stdlib.h>

int match (char *str, char** tab, int size) {
  
  int i;
  for(i = 0; i < size; i++) {
    if(verif(str, tab[i]))
      return 1;
  }

  return 0;
}

int verif (char *s1, char *s2) {

  if (*s1 == '\0' && *s2 == '\0')
    return 1;
  if (*s1 == '\0' && *s2 == '*')
    return verif(s1, s2 + 1);
  if (*s1 == *s2)
    return verif(s1 + 1, s2 + 1);
  if (*s2 == '*') {
    if(!verif(s1, s2 + 1))
      return verif(s1 + 1, s2);
    return verif(s1, s2 + 1);
  }
  return 0;
}

void main (int argc, int *argv[]) {

  char *tab[3];
  tab[0] = "test";
  tab[1] = "lol";
  tab[2] = "exam";

  char *str = "test"; 
  printf("%d\n", match(str, tab, 3));
}
