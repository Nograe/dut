import java.util.*;

class Fraction {
   private int num;
   private int denom;

   public Fraction () {
      num = 1;
      denom = 1;
   }
   public Fraction (int ent1, int ent2) {
      num = ent1;
      denom = ent2;
      simplify();
   }
   public Fraction (Fraction F) {
      num = F.num;
      denom = F.denom;
      simplify();
   }
   public int getNum () {
      return num;
   }
   public int getDenom () {
      return denom;
   }
   public void set (int ent) {
      num = Math.max(1, ent);
   }
   public void set (int ent1, int ent2) {
      num = Math.max(1, ent1);
      denom = Math.max(1, ent2);
   }
   public void setDenom (int ent) {
      denom = Math.max(1, ent);
   }
   public void print () {
      if(denom == 1)
      System.out.println(num);
      else
      System.out.println(num+"/"+denom);
   }
   public static int pgcd(int a, int b) {
      if (b==0) return a;
      return pgcd(b,a%b);
   }
   public void simplify () {
      int var = pgcd(num, denom);
      num /= var;
      denom /= var;
   }
   public boolean equals(Fraction F) {
      if(num == F.num && denom == F.denom)
      return true;
      return false;
   }
}

public class ex1 {
   public static void main (String[] args) {
      Fraction frac = new Fraction(3243543, 246);
      Fraction frac2 = new Fraction(1081182, 82);
      System.out.println(frac.equals(frac2));
   }
}
