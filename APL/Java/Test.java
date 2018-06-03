import java.util.*;

public class Test {
   static ArrayList<int[][]> list = new ArrayList<int[][]>();

   public static void main(String[] args) {
      Lister L = new Lister();
   }

   public static void add(int[][] array) {
      list.add(array);
      printArray();
   }

   public static void printArray() {
      for (int i = 0; i < list.size(); i++) {
         System.out.println("Element: " + i);
         printDim(list.get(i));
      }
      System.out.println("--------------------------------");
   }

   public static void printDim(int[][] array) {
      for (int x = 0; x < array.length; x++) {
         for (int y = 0; y < array[0].length; y++) {
            System.out.print(array[y][x]+" ");
         }
         System.out.println();
      }
      System.out.println("-----------");
   }
}

class Lister {
   Lister() {
      int[][] array1 = new int[5][5];
      array1[0][4] = 1;
      Test.add(array1);
      int[][] array2 = array1.clone();
      for (int i = 0; i < array2.length; i++) {
         array2[i] = array1[i].clone();
      }
      array2[1][2] = 1;
      Test.add(array2);
   }
}
