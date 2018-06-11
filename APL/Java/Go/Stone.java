public class Stone {
   public State color;
   public int x;
   public int y;

   public Stone(State color, int x, int y) {
      this.color = color;
      this.x = x;
      this.y = y;
   }

   public int getLiberties() {
      return getLiberties(new boolean[Goban.SIZE][Goban.SIZE]);
   }
   public int getLiberties(boolean[][] visited) {
      Stone[][] stones = Goban.getStones();
      int boolcurrent, bool1, bool2, bool3, bool4;
      boolcurrent = bool1 = bool2 = bool3 = bool4 = 0;
      if (x > 0) {
         if(stones[x-1][y] != null && !visited[x-1][y] && stones[x-1][y].color == color) {
            visited[x-1][y] = true;
            bool1 = stones[x-1][y].getLiberties(visited);
         } else if(stones[x-1][y] == null) {
            boolcurrent++;
         }
      }
      if (x+1 < Goban.SIZE) {
         if(stones[x+1][y] != null && !visited[x+1][y] && stones[x+1][y].color == color) {
            visited[x+1][y] = true;
            bool2 = stones[x+1][y].getLiberties(visited);
         } else if(stones[x+1][y] == null) {
            boolcurrent++;
         }
      }
      if (y > 0) {
         if(stones[x][y-1] != null && !visited[x][y-1] && stones[x][y-1].color == color) {
            visited[x][y-1] = true;
            bool3 = stones[x][y-1].getLiberties(visited);
         } else if(stones[x][y-1] == null) {
            boolcurrent++;
         }
      }
      if (y+1 < Goban.SIZE) {
         if(stones[x][y+1] != null && !visited[x][y+1] && stones[x][y+1].color == color) {
            visited[x][y+1] = true;
            bool4 = stones[x][y+1].getLiberties(visited);
         } else if(stones[x][y+1] == null) {
            boolcurrent++;
         }
      }
      return (boolcurrent + bool1 + bool2 + bool3 + bool4);
   }

   public void removeGroup() {
      Goban.getStones()[x][y] = null;
      Stone[][] stones = Goban.getStones();
      if (x > 0 && stones[x-1][y] != null && stones[x-1][y].color == color) {
         stones[x-1][y].removeGroup();
      }
      if (x+1 < Goban.SIZE && stones[x+1][y] != null && stones[x+1][y].color == color) {
         stones[x+1][y].removeGroup();
      }
      if (y > 0 && stones[x][y-1] != null && stones[x][y-1].color == color) {
         stones[x][y-1].removeGroup();
      }
      if (y+1 < Goban.SIZE && stones[x][y+1] != null && stones[x][y+1].color == color) {
         stones[x][y+1].removeGroup();
      }
   }
   public void removeGroup(boolean dead) {
      Goban.grid.deadStones[x][y] = dead;
      Stone[][] stones = Goban.getStones();
      if (x > 0 && stones[x-1][y] != null && stones[x-1][y].color == color && Goban.grid.deadStones[x-1][y] != dead) {
         stones[x-1][y].removeGroup(dead);
      }
      if (x+1 < Goban.SIZE && stones[x+1][y] != null && stones[x+1][y].color == color && Goban.grid.deadStones[x+1][y] != dead) {
         stones[x+1][y].removeGroup(dead);
      }
      if (y > 0 && stones[x][y-1] != null && stones[x][y-1].color == color && Goban.grid.deadStones[x][y-1] != dead) {
         stones[x][y-1].removeGroup(dead);
      }
      if (y+1 < Goban.SIZE && stones[x][y+1] != null && stones[x][y+1].color == color && Goban.grid.deadStones[x][y+1] != dead) {
         stones[x][y+1].removeGroup(dead);
      }
   }

   public State calculateTerritory() {
      setToEmpty();
      GobanGrid.printStones(Goban.getStones());

      if(calculateTerritory(State.BLACK, new boolean[Goban.SIZE][Goban.SIZE])) {
         System.out.println("Group is: "+State.BLACK);
         return State.BLACK;
      }
      if(calculateTerritory(State.WHITE, new boolean[Goban.SIZE][Goban.SIZE])) {
         System.out.println("Group is: "+State.WHITE);
         return State.WHITE;
      }
      return null;
   }
   public boolean calculateTerritory(State color, boolean[][] visited) {
      Stone[][] stones = Goban.getStones();
      visited[x][y] = true;
      boolean bool1 = false, bool2 = false, bool3 = false, bool4 = false;
      if (x > 0 && stones[x-1][y] != null && !visited[x-1][y]) {
         if(stones[x-1][y].color == State.EMPTY) return stones[x-1][y].calculateTerritory(color, visited);
         if(stones[x-1][y].color != color) return false;
         else bool1 = true;
      }
      if (x+1 < Goban.SIZE && stones[x+1][y] != null && !visited[x+1][y]) {
         if(stones[x+1][y].color == State.EMPTY) return stones[x+1][y].calculateTerritory(color, visited);
         if(stones[x+1][y].color != color) return false;
         else bool2 = true;
      }
      if (y > 0 && stones[x][y-1] != null && !visited[x][y-1]) {
         if(stones[x][y-1].color == State.EMPTY) return stones[x][y-1].calculateTerritory(color, visited);
         if(stones[x][y-1].color != color) return false;
         else bool3 = true;
      }
      if (y+1 < Goban.SIZE && stones[x][y+1] != null && !visited[x][y+1]) {
         if(stones[x][y+1].color == State.EMPTY) return stones[x][y+1].calculateTerritory(color, visited);
         if(stones[x][y+1].color != color) return false;
         else bool4 = true;
      }
      return bool1 && bool2 && bool3 && bool4;
   }
   public void setToEmpty() {
      Stone[][] stones = Goban.getStones();
      if (x > 0 && stones[x-1][y] == null) {
         stones[x-1][y] = new Stone(State.EMPTY, x-1, y);
         stones[x-1][y].setToEmpty();
      }
      if (x+1 < Goban.SIZE && stones[x+1][y] == null) {
         stones[x+1][y] = new Stone(State.EMPTY, x+1, y);
         stones[x+1][y].setToEmpty();
      }
      if (y > 0 && stones[x][y-1] == null) {
         stones[x][y-1] = new Stone(State.EMPTY, x, y-1);
         stones[x][y-1].setToEmpty();
      }
      if (y+1 < Goban.SIZE && stones[x][y+1] == null) {
         stones[x][y+1] = new Stone(State.EMPTY, x, y+1);
         stones[x][y+1].setToEmpty();
      }
   }

   @Override
   public String toString() {
      if(color == State.BLACK)
      return "\033[40m" + " " + "\033[0m";
      if(color == State.WHITE)
      return "\033[47m" + " " + "\033[0m";
      else
      return "\033[45m" + " " +  "\033[0m";
   }
}

enum State {
   BLACK, WHITE, EMPTY
}
