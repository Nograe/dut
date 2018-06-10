public class Stone {
   public State color;
   public int x;
   public int y;

   public Stone(State color, int x, int y) {
      this.color = color;
      this.x = x;
      this.y = y;
   }

   public boolean isFree() {
      return isFree(new boolean[Goban.SIZE][Goban.SIZE]);
   }
   public boolean isFree(boolean[][] visited) {
      boolean boolcurrent, bool1, bool2, bool3, bool4;
      boolcurrent = bool1 = bool2 = bool3 = bool4 = false;
      if (x > 0) {
         if(Goban.getStones()[x-1][y] != null && !visited[x-1][y] && Goban.getStones()[x-1][y].color == color) {
            visited[x-1][y] = true;
            bool1 = Goban.getStones()[x-1][y].isFree(visited);
         } else if(Goban.getStones()[x-1][y] == null) {
            boolcurrent = true;
         }
      }
      if (x+1 < Goban.SIZE) {
         if(Goban.getStones()[x+1][y] != null && !visited[x+1][y] && Goban.getStones()[x+1][y].color == color) {
            visited[x+1][y] = true;
            bool2 = Goban.getStones()[x+1][y].isFree(visited);
         } else if(Goban.getStones()[x+1][y] == null) {
            boolcurrent = true;
         }
      }
      if (y > 0) {
         if(Goban.getStones()[x][y-1] != null && !visited[x][y-1] && Goban.getStones()[x][y-1].color == color) {
            visited[x][y-1] = true;
            bool3 = Goban.getStones()[x][y-1].isFree(visited);
         } else if(Goban.getStones()[x][y-1] == null) {
            boolcurrent = true;
         }
      }
      if (y+1 < Goban.SIZE) {
         if(Goban.getStones()[x][y+1] != null && !visited[x][y+1] && Goban.getStones()[x][y+1].color == color) {
            visited[x][y+1] = true;
            bool4 = Goban.getStones()[x][y+1].isFree(visited);
         } else if(Goban.getStones()[x][y+1] == null) {
            boolcurrent = true;
         }
      }
      return (boolcurrent || bool1 || bool2 || bool3 || bool4);
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
