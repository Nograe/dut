import java.util.*;

public class Chain {
   public ArrayList<Stone> stones;

   public Chain() {
      stones = new ArrayList<>();
   }

   public int getLiberties() {
      ArrayList<int[][]> liberties = new ArrayList<int[][]>();
      int total = 0;
      for (Stone stone : stones) {
         total += stone.liberties;
      }
      return liberties.size;
   }

   public void addStone(Stone stone) {
      stone.chain = this;
      stones.add(stone);
   }

   public void join(Chain chain) {
      for (Stone stone : chain.stones) {
         addStone(stone);
      }
   }

   public void printChain() {
      for (int y = 0; y < Goban.SIZE; y++) {
         for (int x = 0; x < Goban.SIZE; x++) {
            if(stones.contains(Go.getGoban().grid.stones[x][y])) System.out.print("["+x+"]"+"["+y+"],");
         }
      }
      System.out.println("");
      System.out.println("-----");
   }
}
