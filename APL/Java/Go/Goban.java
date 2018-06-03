import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Goban extends JPanel implements ComponentListener {
   public static int GOBAN_SIZE;
   private Infos infos;
   private GobanGrid grid;
   private boolean player = true;
   private static ArrayList<int[][]> listeCoups = new ArrayList<int[][]>();
   private int listIndex = 1;

   public Goban(int GOBAN_SIZE) {
      addComponentListener(this);
      // setBackground(new Color(60, 100, 125));
      setBackground(new Color(155, 105, 50));
      this.GOBAN_SIZE = GOBAN_SIZE;

      setLayout(new BoxLayout(this, BoxLayout.LINE_AXIS));
      grid = new GobanGrid();
      infos = new Infos();
      add(grid);
      add(infos);
      infos.p1Timer.start();
      listeCoups.add(new int[Goban.GOBAN_SIZE+1][Goban.GOBAN_SIZE+1]);
   }

   @Override
   public void paintComponent(Graphics g) {
      super.paintComponent(g);
   }

   public void nextPlayer() {
      player = !player;
      if(player) {
         infos.p1Timer.start();
         infos.p2Timer.stop();
      } else {
         infos.p1Timer.stop();
         infos.p2Timer.start();
      }
   }
   public boolean getPlayer() {
      return player;
   }

   public void addCoup() {
      listeCoups.add(deepCopy(grid.stones));

      for (; listIndex > 1; listIndex--) {
         System.out.println("delete all");
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

   public int[][] deepCopy(int[][] A) {
      int[][] array = A.clone();
      for (int i = 0; i < array.length; i++) {
         array[i] = A[i].clone();
      }
      return array;
   }

   public void reSize() {
      int width = getWidth(), height = getHeight();
      int gridSize = (width < height) ? width : height;
      if(width - gridSize < 200) {
         gridSize -= 200;
      }
      gridSize = (int)(gridSize/GOBAN_SIZE)*(GOBAN_SIZE);
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
   public int[][] stones; // 1: noir 2: blanc

   public GobanGrid() {
      addMouseListener(this);
      setBackground(new Color(155, 105, 50));
      stones = new int[Goban.GOBAN_SIZE+1][Goban.GOBAN_SIZE+1];
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
      int cellSize = gridSize/(Goban.GOBAN_SIZE);
      int padding = cellSize;
      gridSize -= padding;
      padding /= 2;

      g.setColor(new Color(30, 30, 30));
      if(Goban.GOBAN_SIZE == 9 || Goban.GOBAN_SIZE == 13) {
         setHoshi(g, (int)Goban.GOBAN_SIZE/4, (int)Goban.GOBAN_SIZE/4, cellSize, padding);
         setHoshi(g, (int)Goban.GOBAN_SIZE/4, Goban.GOBAN_SIZE-(int)Goban.GOBAN_SIZE/4-1, cellSize, padding);
         setHoshi(g, Goban.GOBAN_SIZE-(int)Goban.GOBAN_SIZE/4-1, (int)Goban.GOBAN_SIZE/4, cellSize, padding);
         setHoshi(g, Goban.GOBAN_SIZE-(int)Goban.GOBAN_SIZE/4-1, Goban.GOBAN_SIZE-(int)Goban.GOBAN_SIZE/4-1, cellSize, padding);
         setHoshi(g, (int)Goban.GOBAN_SIZE/2, (int)Goban.GOBAN_SIZE/2, cellSize, padding);
      }
      if(Goban.GOBAN_SIZE == 19) {
         setHoshi(g, 3, 3, cellSize, padding); setHoshi(g, 9, 3, cellSize, padding); setHoshi(g, 15, 3, cellSize, padding);
         setHoshi(g, 3, 9, cellSize, padding); setHoshi(g, 9, 9, cellSize, padding); setHoshi(g, 15, 9, cellSize, padding);
         setHoshi(g, 3, 15, cellSize, padding); setHoshi(g, 9, 15, cellSize, padding); setHoshi(g, 15, 15, cellSize, padding);
      }

      for (int x = 0; x < stones.length; x++) {
         for (int y = 0; y < stones[0].length; y++) {
            if(stones[x][y] == 0) continue;
            checkStone(x, y);
         }
      }

      for (int x = 0; x < Goban.GOBAN_SIZE; x++) {
         g.drawLine(x*cellSize+padding, padding, x*cellSize+padding, gridSize+padding);
      }
      for (int y = 0; y < Goban.GOBAN_SIZE; y++) {
         g.drawLine(padding, y*cellSize+padding, gridSize+padding, y*cellSize+padding);
         drawLineStones(g, y, cellSize, padding);
      }
   }

   public void drawLineStones(Graphics g, int y, int cellSize, int padding) {
      double width = cellSize*0.9;
      for (int x = 0; x < Goban.GOBAN_SIZE; x++) {
         if(stones[x][y] == 0) continue;
         if(stones[x][y] == 1) g.setColor(new Color(30, 30, 30));
         if(stones[x][y] == 2) g.setColor(new Color(200, 200, 200));
         g.fillOval(x*cellSize+(int)width/14, y*cellSize+(int)width/14, (int)width, (int)width);
      }
      g.setColor(new Color(0, 0, 0));
   }

   public void checkStone(int x, int y) {
      int freedoms = 4;
      boolean isBlack = false;
      if(stones[x][y] == 1) isBlack = true;
      if(x-1 >= 0) {
         if (isTaken(x-1, y, isBlack)) {
            freedoms--;
         }
      } else freedoms--;
      if(y-1 >= 0) {
         if (isTaken(x, y-1, isBlack)) {
            freedoms--;
         }
      } else freedoms--;
      if(x+1 < Goban.GOBAN_SIZE) {
         if (isTaken(x+1, y, isBlack)) {
            freedoms--;
         }
      } else freedoms--;
      if(y+1 < Goban.GOBAN_SIZE) {
         if (isTaken(x, y+1, isBlack)) {
            freedoms--;
         }
      } else freedoms--;
      if(freedoms == 0) {
         stones[x][y] = 0;
      }
   }
   public boolean isTaken(int x, int y, boolean isBlack) {
      if(isBlack) {
         if(stones[x][y] == 2) {
            return true;
         }
         return false;
      }
      else {
         if(stones[x][y] == 1) {
            return true;
         }
         return false;
      }
   }

   public void addStone(MouseEvent e) {
      int gridSize = getWidth();
      int cellSize = gridSize/(Goban.GOBAN_SIZE);
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
      int cellValue = stones[(int)cell.getX()][(int)cell.getY()];
      if (!isTaken((int)cell.getX(), (int)cell.getY(), Go.getGoban().getPlayer())) {
         stones[(int)cell.getX()][(int)cell.getY()] = (Go.getGoban().getPlayer()) ? 1 : 2;
         Go.getGoban().addCoup();
         Go.getGoban().nextPlayer();
      }
      repaint();
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

   public void printStones(int [][] array) {
      for (int y = 0; y < Goban.GOBAN_SIZE; y++) {
         for (int x = 0; x < Goban.GOBAN_SIZE; x++) {
            System.out.print(array[x][y]+" ");
         }
         System.out.println();
      }
      for (int x = 0; x < Goban.GOBAN_SIZE; x++) {
         System.out.print("--");
      }
      System.out.println();
   }
}
