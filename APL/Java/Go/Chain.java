import java.util.*;
import java.awt.Point;

public class Chain {
   public ArrayList<Stone> stones;
   int liberties;

   public Chain() {
      stones = new ArrayList<>();
      liberties = 0;
   }

   public int getLiberties() {
      ArrayList<Point> liberties = new ArrayList<Point>();
      for (Stone stone : stones) {
         int x = stone.x, y = stone.y;
         if(Goban.grid.stones[x][y] == null) {
            System.out.println("Pierre a disparue");
         }
         if (x > 0 && Goban.grid.stones[x-1][y] == null && !liberties.contains(new Point(x-1, y))) {
            liberties.add(new Point(x-1, y));
         }
         if (x+1 < Goban.SIZE && Goban.grid.stones[x+1][y] == null && !liberties.contains(new Point(x+1, y))) {
            liberties.add(new Point(x+1, y));
         }
         if (y > 0 && Goban.grid.stones[x][y-1] == null && !liberties.contains(new Point(x, y-1))) {
            liberties.add(new Point(x, y-1));
         }
         if (y+1 < Goban.SIZE && Goban.grid.stones[x][y+1] == null && !liberties.contains(new Point(x, y+1))) {
            liberties.add(new Point(x, y+1));
         }
      }
      this.liberties = liberties.size();
      return this.liberties;
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
