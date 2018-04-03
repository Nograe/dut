import java.util.Comparator;

public class Case {
   private Coord C;
   private int cout;
   private int estimation;

   public Case(int x, int y) {
      C = new Coord(x, y);
      cout = 999;
      estimation = 999;
   }
   public void setCout(int cout) {
      this.cout = cout;
   }
   public void setEstimation(int estimation) {
      this.estimation = estimation;
   }
   public void update(int cout, Coord A, Coord B) {
      this.cout = cout;
      this.estimation = cout + Heuristique(A, B);
   }
   public Coord getCoord() {
      return this.C;
   }
   public int getX() {
      return C.getX();
   }
   public int getY() {
      return C.getY();
   }
   public int getCout() {
      return cout;
   }
   public int getEstimation() {
      return estimation;
   }

   public static int Heuristique(Coord C, Coord G) {
      int diffX = C.getX() - G.getX();
      if(C.getX() < G.getX()) diffX = G.getX() - C.getX();
      int diffY = C.getY() - G.getY();
      if(C.getY() < G.getY()) diffY = G.getY() - C.getY();
      // System.out.println("diffX: "+diffX+" | diffY: "+diffY);
      return diffX + diffY;
   }

   @Override
   public String toString() {
      return "   posX: "+C.getX()+"\n   posY: "+C.getY()+"\n   cout: "+this.cout+"\n   estimation: "+this.estimation;
   }
}

class Coord {
   private int posX;
   private int posY;

   public Coord () {
      posX = -1;
      posY = -1;
   }
   public Coord(int posX, int posY) {
      this.posX = posX;
      this.posY = posY;
   }

   public void setX(int posX) {
      this.posX = posX;
   }
   public void setY(int posY) {
      this.posY = posY;
   }
   public int getX() {
      return posX;
   }
   public int getY() {
      return posY;
   }

   @Override
   public int hashCode() {
      return posX*1000+posY;
   }
   @Override
   public boolean equals(Object o) {
      if(o instanceof Coord) {
         Coord C = (Coord) o;
         if(C.getX() == this.posX && C.getY() == this.posY) {
            return true;
         }
         else {
            return false;
         }
      }
      else {
         return false;
      }
   }
}
