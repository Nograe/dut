import java.util.Comparator;

public class Node implements Comparable<Node> {
   private byte character;
   private int count;
   Node filsGauche;
   Node filsDroit;

   public Node(byte character, int count) {
      this.character = character;
      this.count = count;
   }
   public Node(byte character, int count, Node filsGauche, Node filsDroit) {
      this(character, count);
      this.filsGauche = filsGauche;
      this.filsDroit = filsDroit;
   }
   public byte getChar() {
      return character;
   }
   public int getCount() {
      return count;
   }

   @Override
   public String toString() {
      if(character == -1) {
         return "char: "+character+" count: "+count + "  filsGauche: " + filsGauche.toString() + "  filsDroit: " + filsDroit.toString();
      }
      return "char: "+(char)character+" count: "+count;
   }

   @Override
   public int compareTo(Node other) {
       if (this.count < other.count) return -1;
       else if (this.count > other.count) return 1;
       return 0;
   }
}
