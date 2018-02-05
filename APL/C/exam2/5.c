#include <stdio.h>
#include <stdlib.h>

int check(int tab[], int length);

void display (int *tab) {

   printf("{");
   int i;
   for (i = 0; i < 9; i++)
      printf("%d,", tab[i]);
   printf("}\n");
}

int validLigne (int tab[9][9], int line, int nb) {

   return check(tab[line], 9);
}

int validColonne (int tab[9][9], int colonne, int nb) {
   int i;
   int tmp[9];

   for (i = 0; i < 9; i++)
      tmp[i] = tab[i][colonne];

   return check(tmp, 9);
}

int validBloc (int tab[9][9], int debi, int debj) {

   int i, j, var = 0;
   int tmp[9];

   for (i = debi; i < debi + 3; i++) {
      for (j = debj; j < debj + 3; j++) {
         tmp[var] = tab[i][j];
         var++;
      }
   }

   return check(tmp, 9);
}

int check(int tab[], int length) {
   //display(tab);

   int i, j;
   for (i = 1; i <= length; ++i) {
      int nb = 0;
      for (j = 0; j < length; ++j) {
         if (tab[j] == i)
            nb++;
      }
      if(nb != 1)
         return 0;
   }

   return 1;
}

int valide (int sudoku[9][9]) {

   int i, j;

   //verif lignes
   for (i = 0; i < 9; i++) {
      if (!validLigne(sudoku, i, j)) {
         //printf("error line %d\n", i);
         return 0;
      }
   }

   //verif colonne
   for (i = 0; i < 9; i++) {
      if (!validColonne(sudoku, i, j)) {
         //printf("error colonne\n");
         return 0;
      }
   }

   //verif bloc
   for (i = 0; i < 9; i+=3) {
      for (j = 0; j < 9; j+=3) {
         if (!validBloc(sudoku, i, j)) {
            //printf("error block\n");
            return 0;
         }
      }
   }

   return 1;
}

void main (int argc, int *argv[]) {

  int sudoku[9][9];

  int i, j;
  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      scanf(" %d", &sudoku[i][j]);
    }
  }

   printf("%d\n", valide(sudoku));
}
