#include <stdio.h>
#include <stdlib.h>

void tri(char** tab, int size) {
  
  if(size <= 1)
    return;

  char *tmp = NULL;
  int i = 0, j, strlen, go = 0, change = 0;

  while(i != size-1) {
    strlen = length(tab[i], tab[i+1]);
    go = 0;

    for(j = 0; j < strlen; j++) {

      if(tab[i][j] < tab[i+1][j]) {
	//printf("%s | %s : %c < %c\n", tab[i], tab[i+1],tab[i][j], tab[i+1][j]);
	go = 1;
      }

      if(tab[i][j] > tab[i+1][j] && go != 1) {
	//printf("%s | %s : %c > %c\n", tab[i], tab[i+1],tab[i][j], tab[i+1][j]);

	tmp = tab[i];
	tab[i] = tab[i+1];
	tab[i+1] = tmp;

	change = 1;
	go = 1;
      }

    }
    i++;
  }

  if(change)
    return tri(tab, size);
}

int length (char *str1, char *str2) {
  
  int l1 = 0, l2 = 0;

  while(*str1 != '\0') {
    str1++;
    l1++;
  }
  while(*str2 != '\0') {
    str2++;
    l2++;
  }
  
  if(l1 > l2)
    return l2;
  else
    return l1;
}

void main (int argc, int *argv[]) {

  int size = 5;
  char *tab[10];
  tab[0] = "hola";
  tab[1] = "salut";
  tab[2] = "hello";
  tab[3] = "salami";
  tab[4] = "hella";

  /*int i;
  for(i = 0; i < size; i++)
    printf("%s\n", tab[i]);

  tri(tab, size);

  for(i = 0; i < size; i++)
  printf("%s\n", tab[i]);*/
}
