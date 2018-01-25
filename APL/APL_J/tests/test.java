import java.util.Arrays;

public class test {
   public static void main(String[] args) {
      /*for(int i = 0; i < args.length; i++)
      System.out.println("Bonjour "+args[i]);*/

      /*int sum = 0;
      for(int i = 0; i < args.length; i++)
       sum += Integer.parseInt(args[i]);
        System.out.println("Somme: "+sum);*/

      int[] tab = new int[args.length];
      for (int i = 0; i < args.length; i++)
         tab[i] = Integer.parseInt(args[i]);
      Arrays.sort(tab);
      for (int i = 0; i < args.length; i++)
         System.out.print(tab[i] + " ");
   }
}