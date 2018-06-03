import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Goban extends JPanel implements ComponentListener {
   public static int SIZE;
   private Infos infos;
   public GobanGrid grid;
   public State player = State.BLACK;
   private static ArrayList<Stone[][]> listeCoups = new ArrayList<Stone[][]>();
   private static ArrayList<Chain> listChain = new ArrayList<Chain>();
   private int listIndex = 1;

   public Goban(int SIZE) {
      addComponentListener(this);
      // setBackground(new Color(60, 100, 125));
      setBackground(new Color(155, 105, 50));
      this.SIZE = SIZE;

      setLayout(new BoxLayout(this, BoxLayout.LINE_AXIS));
      grid = new GobanGrid();
      infos = new Infos();
      add(grid);
      add(infos);
      infos.p1Timer.start();
      listeCoups.add(new Stone[Goban.SIZE+1][Goban.SIZE+1]);
   }

   @Override
   public void paintComponent(Graphics g) {
      super.paintComponent(g);
   }

   public void nextPlayer() {
      if(player == State.BLACK) {
         player = State.WHITE;
         infos.p1Timer.stop();
         infos.p2Timer.start();
      } else {
         player = State.BLACK;
         infos.p1Timer.start();
         infos.p2Timer.stop();
      }
   }

   public void addCoup() {
      listeCoups.add(deepCopy(grid.stones));

      for (; listIndex > 1; listIndex--) {
         listeCoups.remove(listeCoups.size()-listIndex);
      }
      listIndex = 1;
      // printArray();
      // System.out.println("Current: "+(listeCoups.size()-1)+" Index: "+listIndex);
   }
   public void undoCoup() {
      if(listIndex >= listeCoups.size()) return;
      grid.stones = deepCopy(listeCoups.get(listeCoups.size()-listIndex-1));
      grid.repaint();
      // System.out.println("Get: "+(listeCoups.size()-listIndex-1));
      // grid.printStones(grid.stones);
      listIndex++;
      nextPlayer();
   }
   public void redoCoup() {
      if(listIndex > listeCoups.size() || listIndex == 1) return;
      grid.stones = deepCopy(listeCoups.get(listeCoups.size()-listIndex+1));
      grid.repaint();
      // System.out.println("Get: "+(listeCoups.size()-listIndex+1));
      // grid.printStones(grid.stones);
      listIndex--;
      nextPlayer();
      // grid.printStones(newStones);
   }

   public void printArray() {
      System.out.println("------------------------------");
      for (int i = 0; i < listeCoups.size(); i++) {
         grid.printStones(listeCoups.get(i));
      }
      System.out.println("------------------------------");
   }

   public Stone[][] deepCopy(Stone[][] A) {
      Stone[][] array = A.clone();
      for (int i = 0; i < array.length; i++) {
         array[i] = A[i].clone();
      }
      return array;
   }

   public void addChain(Chain chain) {
      listChain.add(chain);
   }

   public void reSize() {
      int width = getWidth(), height = getHeight();
      int gridSize = (width < height) ? width : height;
      if(width - gridSize < 200) {
         gridSize -= 200;
      }
      gridSize = (int)(gridSize/SIZE)*(SIZE);
      grid.setSize(gridSize);
      infos.setSize(width-gridSize, height);
      revalidate();
   }
   public void componentResized(ComponentEvent e) {
      reSize();
   }
   public void componentMoved(ComponentEvent e) {
   }
   public void componentHidden(ComponentEvent e) {
   }
   public void componentShown(ComponentEvent e) {
   }
}


class GobanGrid extends JPanel implements MouseListener {
   public Stone[][] stones; // 1: noir 2: blanc

   public GobanGrid() {
      addMouseListener(this);
      setBackground(new Color(155, 105, 50));
      stones = new Stone[Goban.SIZE+1][Goban.SIZE+1];
   }

   public void setSize(int gridSize) {
      setMinimumSize(new Dimension(gridSize, gridSize));
      setPreferredSize(new Dimension(gridSize, gridSize));
      setMaximumSize(new Dimension(gridSize, gridSize));
   }

   @Override
   public void paintComponent(Graphics g) {
      super.paintComponent(g);
      drawGrid(g);
   }

   public void drawGrid(Graphics g) {
      int gridSize = getWidth();
      int cellSize = gridSize/(Goban.SIZE);
      int padding = cellSize;
      gridSize -= padding;
      padding /= 2;

      g.setColor(new Color(30, 30, 30));
      if(Goban.SIZE == 9 || Goban.SIZE == 13) {
         setHoshi(g, (int)Goban.SIZE/4, (int)Goban.SIZE/4, cellSize, padding);
         setHoshi(g, (int)Goban.SIZE/4, Goban.SIZE-(int)Goban.SIZE/4-1, cellSize, padding);
         setHoshi(g, Goban.SIZE-(int)Goban.SIZE/4-1, (int)Goban.SIZE/4, cellSize, padding);
         setHoshi(g, Goban.SIZE-(int)Goban.SIZE/4-1, Goban.SIZE-(int)Goban.SIZE/4-1, cellSize, padding);
         setHoshi(g, (int)Goban.SIZE/2, (int)Goban.SIZE/2, cellSize, padding);
      }
      if(Goban.SIZE == 19) {
         setHoshi(g, 3, 3, cellSize, padding); setHoshi(g, 9, 3, cellSize, padding); setHoshi(g, 15, 3, cellSize, padding);
         setHoshi(g, 3, 9, cellSize, padding); setHoshi(g, 9, 9, cellSize, padding); setHoshi(g, 15, 9, cellSize, padding);
         setHoshi(g, 3, 15, cellSize, padding); setHoshi(g, 9, 15, cellSize, padding); setHoshi(g, 15, 15, cellSize, padding);
      }

      for (int x = 0; x < Goban.SIZE; x++) {
         g.drawLine(x*cellSize+padding, padding, x*cellSize+padding, gridSize+padding);
      }
      for (int y = 0; y < Goban.SIZE; y++) {
         g.drawLine(padding, y*cellSize+padding, gridSize+padding, y*cellSize+padding);
         drawLineStones(g, y, cellSize, padding);
      }
   }

   public void drawLineStones(Graphics g, int y, int cellSize, int padding) {
      double width = cellSize*0.9;
      for (int x = 0; x < Goban.SIZE; x++) {
         if(stones[x][y] == null) continue;
         if(stones[x][y].color == State.BLACK) g.setColor(new Color(30, 30, 30));
         if(stones[x][y].color == State.WHITE) g.setColor(new Color(200, 200, 200));
         g.fillOval(x*cellSize+(int)width/14, y*cellSize+(int)width/14, (int)width, (int)width);
      }
      g.setColor(new Color(0, 0, 0));
   }

   public boolean checkStone(Stone stone) {
      if(stone.chain == null) return false;
      // System.out.println("stone has "+stone.chain.getLiberties()+" liberties");
      Chain chain = stone.chain;
      if (chain.getLiberties() <= 0) {
         for (Stone s : chain.stones) {
            stones[s.x][s.y] = null;
            s = null;
         }
         chain.stones.clear();
         return true;
      }
      return false;
   }

   public void addStone(MouseEvent e) {
      int gridSize = getWidth();
      int cellSize = gridSize/(Goban.SIZE);
      int padding = cellSize;
      gridSize -= padding;
      padding /= 2;
      int posX = (e.getX()-padding)/cellSize;
      int posY = (e.getY()-padding)/cellSize;

      double dist = distance(e.getX(), e.getY(), (posX*cellSize)+padding, (posY*cellSize)+padding);
      Point cell = new Point(posX, posY);
      if(distance(e.getX(), e.getY(), (posX*cellSize)+padding+cellSize, (posY*cellSize)+padding) < dist) {
         dist = distance(e.getX(), e.getY(), (posX*cellSize)+padding+cellSize, (posY*cellSize)+padding);
         cell = new Point(posX+1, posY);
      }
      if(distance(e.getX(), e.getY(), (posX*cellSize)+padding, (posY*cellSize)+padding+cellSize) < dist){
         dist = distance(e.getX(), e.getY(), (posX*cellSize)+padding, (posY*cellSize)+padding+cellSize);
         cell = new Point(posX, posY+1);
      }
      if(distance(e.getX(), e.getY(), (posX*cellSize)+padding+cellSize, (posY*cellSize)+padding+cellSize) < dist){
         dist = distance(e.getX(), e.getY(), (posX*cellSize)+padding+cellSize, (posY*cellSize)+padding+cellSize);
         cell = new Point(posX+1, posY+1);
      }
      if (stones[(int)cell.getX()][(int)cell.getY()] == null) {
         if(addStone((int)cell.getX(), (int)cell.getY())) {
            Go.getGoban().addCoup();
            Go.getGoban().nextPlayer();
         }
      }
      repaint();
   }

   public boolean addStone(int x, int y) {
      stones[x][y] = new Stone(Go.getGoban().player, x, y);
      Stone[] neighbors = new Stone[4];
      if (x > 0) {
         neighbors[0] = stones[x - 1][y];
      } else stones[x][y].liberties--;
      if (x+1 < Goban.SIZE) {
         neighbors[1] = stones[x + 1][y];
      } else stones[x][y].liberties--;
      if (y > 0) {
         neighbors[2] = stones[x][y - 1];
      } else stones[x][y].liberties--;
      if (y+1 < Goban.SIZE) {
         neighbors[3] = stones[x][y + 1];
      } else stones[x][y].liberties--;
      for (Stone neighbor : neighbors) {
         if(neighbor != null && neighbor.color != stones[x][y].color) {
            stones[x][y].liberties--;
         }
      }
      if(stones[x][y].liberties == 0) {
         stones[x][y] = null;
         return false;
      }

      Chain finalChain = new Chain();
      for (Stone neighbor : neighbors) {
         if (neighbor == null) {
            continue;
         }
         stones[x][y].liberties--;
         neighbor.liberties--;
         if (neighbor.color != stones[x][y].color) {
            checkStone(neighbor);
            continue;
         }
         if (neighbor.chain != null) {
            finalChain.join(neighbor.chain);
         }
      }
      finalChain.addStone(stones[x][y]);
      // printStones(stones);
      // stones[x][y].chain.printChain();
      return true;
   }

   public double distance(int x1, int y1, int x2, int y2) {
      return Math.sqrt(Math.pow((x1-x2), 2) + Math.pow((y1-y2), 2));
   }

   public void setHoshi(Graphics g, int x, int y, int cellSize, int padding) {
      g.fillOval(x*cellSize+padding-3, y*cellSize+padding-3, 6, 6);
   }

   public void mouseClicked(MouseEvent e) {
   }
   public void mousePressed(MouseEvent e) {
      addStone(e);
   }
   public void mouseReleased(MouseEvent e) {
   }
   public void mouseEntered(MouseEvent e) {
   }
   public void mouseExited(MouseEvent e) {
   }

   public void printStones(Stone[][] array) {
      for (int y = 0; y < Goban.SIZE; y++) {
         for (int x = 0; x < Goban.SIZE; x++) {
            if(array[x][y] == null) System.out.print(" ");
            else System.out.print(array[x][y]);
         }
         System.out.println();
      }
      for (int x = 0; x < Goban.SIZE; x++) {
         System.out.print("-");
      }
      System.out.println();
   }
}
