import java.util.Comparator;

public class Node implements Comparable<Node> {
   private byte character;
   private int count;
   Node filsGauche;
   Node filsDroit;

   @Override
   public int compareTo(Node other) {
       if (this.count < other.count) return -1;
       else if (this.count > other.count) return 1;
       return 0;
   }
}
