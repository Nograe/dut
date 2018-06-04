public class Stone {
   public Chain chain;
   public State color;
   public int x;
   public int y;

   public Stone(State color, int x, int y) {
      this.chain = null;
      this.color = color;
      this.x = x;
      this.y = y;
   }

   @Override
   public String toString() {
      if(this.color == State.BLACK) {
         return "\033[40m" + " " + "\033[0m";
      }
      return "\033[47m" + " " + "\033[0m";
   }
}

enum State {
    BLACK, WHITE
}
