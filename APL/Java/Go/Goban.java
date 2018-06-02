import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Goban extends JPanel implements ComponentListener {
   public static int GOBAN_SIZE;
   private Infos infos;
   private GobanGrid grid;
   private boolean player = true;
   private LinkedList<Point> listeCoups = new LinkedList<Point>();
   private int listIndex = 0;

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

   public void addCoup(Point p) {
      listeCoups.add(p);
      for (; listIndex > 0; listIndex--) {
         listeCoups.remove(listeCoups.size()-listIndex-1);
      }
      listIndex = 0;
   }
   public void undoCoup() {
      if(listIndex >= listeCoups.size()) return;
      Point p = listeCoups.get(listeCoups.size()-listIndex-1);
      // if(grid.stones[(int)p.getX()][(int)p.getY()] < 0) grid.stones[(int)p.getX()][(int)p.getY()] *= -1;
      if(grid.stones[(int)p.getX()][(int)p.getY()] == 5 || grid.stones[(int)p.getX()][(int)p.getY()] == 9) grid.stones[(int)p.getX()][(int)p.getY()]++;
      else grid.stones[(int)p.getX()][(int)p.getY()] *= 4;
      grid.repaint();
      listIndex++;
      nextPlayer();
      // System.out.println("undo: "+grid.stones[(int)p.getX()][(int)p.getY()]);
   }
   public void redoCoup() {
      if(listIndex > listeCoups.size() || listIndex == 0) return;
      Point p = listeCoups.get(listeCoups.size()-listIndex);
      // System.out.println("Redo old: "+grid.stones[(int)p.getX()][(int)p.getY()]);
      if(grid.stones[(int)p.getX()][(int)p.getY()] == 6 || grid.stones[(int)p.getX()][(int)p.getY()] == 10) grid.stones[(int)p.getX()][(int)p.getY()]--;
      else grid.stones[(int)p.getX()][(int)p.getY()] /= 4;
      // System.out.println("Redo new: "+grid.stones[(int)p.getX()][(int)p.getY()]);
      grid.repaint();
      listIndex--;
      nextPlayer();
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
   public int[][] stones; /* 1: noir 2: blanc 3: hoshi || 4: ancien noir 8: ancien blanc || 5: noir/hoshi 9: blanc/hoshi
   6: ancien noir/hoshi 10: ancien blanc/hoshi || -1: noir capturé -2: blanc capturé || -5: noir/hoshi capturé -9: blanc/hoshi capturé */

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

      if(Goban.GOBAN_SIZE == 9 || Goban.GOBAN_SIZE == 13) {
         setHoshi((int)Goban.GOBAN_SIZE/4, (int)Goban.GOBAN_SIZE/4);
         setHoshi((int)Goban.GOBAN_SIZE/4, Goban.GOBAN_SIZE-(int)Goban.GOBAN_SIZE/4-1);
         setHoshi(Goban.GOBAN_SIZE-(int)Goban.GOBAN_SIZE/4-1, (int)Goban.GOBAN_SIZE/4);
         setHoshi(Goban.GOBAN_SIZE-(int)Goban.GOBAN_SIZE/4-1, Goban.GOBAN_SIZE-(int)Goban.GOBAN_SIZE/4-1);
         setHoshi((int)Goban.GOBAN_SIZE/2, (int)Goban.GOBAN_SIZE/2);
      }
      if(Goban.GOBAN_SIZE == 19) {
         setHoshi(3, 3); setHoshi(9, 3); setHoshi(15, 3);
         setHoshi(3, 9); setHoshi(9, 9); setHoshi(15, 9);
         setHoshi(3, 15); setHoshi(9, 15); setHoshi(15, 15);
      }

      for (int x = 0; x < stones.length; x++) {
         for (int y = 0; y < stones[0].length; y++) {
            if(stones[x][y] != 1 && stones[x][y] != 2 && stones[x][y] != 5 && stones[x][y] != 9 && stones[x][y] != -1 && stones[x][y] != -2 && stones[x][y] != -5 && stones[x][y] != -9) continue;
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

   public void drawLineStones(Graphics g, int Y, int cellSize, int padding) {
      double width = cellSize*0.9;
      for (int i = 0; i < Goban.GOBAN_SIZE; i++) {
         if(stones[i][Y] <= 0 || stones[i][Y] == 4 || stones[i][Y] == 8) continue;
         if(stones[i][Y] == 1 || stones[i][Y] == 5) g.setColor(new Color(30, 30, 30));
         if(stones[i][Y] == 2 || stones[i][Y] == 9) g.setColor(new Color(200, 200, 200));
         if(stones[i][Y] == 3 || stones[i][Y] == 6 || stones[i][Y] == 10) {
            g.setColor(new Color(30, 30, 30));
            g.fillOval(i*cellSize+padding-3, Y*cellSize+padding-3, 6, 6);
            continue;
         }
         g.fillOval(i*cellSize+(int)width/14, Y*cellSize+(int)width/14, (int)width, (int)width);
      }
      g.setColor(new Color(0, 0, 0));
   }

   public void checkStone(int x, int y) {
      int freedoms = 4;
      boolean isBlack = false;
      if(stones[x][y] == 1 || stones[x][y] == 5 || stones[x][y] == -1 || stones[x][y] == -5) isBlack = true;
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
         stones[x][y] *= -1;
      }
   }
   public boolean isTaken(int x, int y, boolean isBlack) {
      if(isBlack) {
         if(stones[x][y] == 2 || stones[x][y] == 9) {
            return true;
         }
         return false;
      }
      else {
         if(stones[x][y] == 1 || stones[x][y] == 5) {
            return true;
         }
         return false;
      }
   }

   public void mouseClicked(MouseEvent e) {
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
         if(cellValue == 3 || cellValue == 6 || cellValue == 10) { //Si il y a un hoshi
            stones[(int)cell.getX()][(int)cell.getY()] = (Go.getGoban().getPlayer()) ? 5 : 9;
         } else {
            stones[(int)cell.getX()][(int)cell.getY()] = (Go.getGoban().getPlayer()) ? 1 : 2;
         }
         Go.getGoban().addCoup(cell);
         Go.getGoban().nextPlayer();
      }
      repaint();
   }

   public double distance(int x1, int y1, int x2, int y2) {
      return Math.sqrt(Math.pow((x1-x2), 2) + Math.pow((y1-y2), 2));
   }

   public void setHoshi(int x, int y) {
      if(stones[x][y] == 1 || stones[x][y] == 2 || stones[x][y] == 5 || stones[x][y] == 9 || stones[x][y] == 6 || stones[x][y] == 10) return;
      stones[x][y] = 3;
   }

   public void mousePressed(MouseEvent e) {
      mouseClicked(e);
   }
   public void mouseReleased(MouseEvent e) {
   }
   public void mouseEntered(MouseEvent e) {
   }
   public void mouseExited(MouseEvent e) {
   }
}
