import java.util.*;

class Matrix {
   int tab[][];

   Matrix (int N, int M) {
      tab = new int[N][M];
      Random rand = new Random();

      for (int i = 0; i < N; i++) {
         for (int j = 0; j < M; j++)
            tab[i][j] = rand.nextInt(100);
      }
   }

   void print () {
      for (int i = 0; i < this.tab.length; i++)
         System.out.println(Arrays.toString(this.tab[i]));
   }

   void copy (int origin[], int dim) {
      for (int i = 0; i < this.tab[0].length; i++)
         this.tab[dim][i] = origin[i];
   }

   void addition (int add[][]) {
      for (int i = 0; i < this.tab.length; i++) {
         for (int j = 0; j < this.tab[0].length; j++) {
            this.tab[i][j] += add[i][j];
         }
      }
   }
}

public class ex7 {

   public static void main (String[] args) {
      Matrix matrice;
      matrice = new Matrix(2, 4);

      matrice.print();

      int[] copytab = {1, 5, 54, -10};

      System.out.println("After copy: ");
      matrice.copy(copytab, 1);
      matrice.print();

      Matrix add;
      add = new Matrix(2, 4);
      System.out.println("Add tab: ");
      add.print();
      matrice.addition(add.tab);
      System.out.println("After addition: ");
      matrice.print();
   }
}