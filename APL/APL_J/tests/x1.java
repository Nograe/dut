import java.util.Arrays;

public class x1 {
   public static void main(String[] args) {
      /*for(int i = 0; i < args.length; i++)
      System.out.println("Bonjour "+args[i]);*/

      /*int sum = 0;
      for(int i = 0; i < args.length; i++)
       sum += Integer.parseInt(args[i]);
        System.out.println("Somme: "+sum);*/

      /*int[] tab = new int[args.length];
      for (int i = 0; i < args.length; i++)
         tab[i] = Integer.parseInt(args[i]);
      Arrays.sort(tab);
      for (int i = 0; i < args.length; i++)
         System.out.print(tab[i] + " ");*/

      int len = Integer.parseInt(args[0]);
      for (int i = 0; i <= len; i++) {
         for (int j = 0; j < len; j++) {
            System.out.print("+");
            System.out.print("-");
         }
         System.out.println("+");
         if (i != len) {
            for (int j = 0; j < len; j++) {
               System.out.print("| ");
            }
            System.out.println("|");
         }
      }
   }
}
