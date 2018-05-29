import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Goban extends JPanel implements ComponentListener {
   public static int GOBAN_SIZE;
   private GobanGrid grid;
   private int gridPadding = 150;
   private boolean player = true;
   private LinkedList<Point> listeCoups = new LinkedList<Point>();
   private int listIndex = 0;

   public Goban(int gridSize, int GOBAN_SIZE) {
      addComponentListener(this);
      setBackground(new Color(60, 100, 125));
      setMinimumSize(new Dimension(400, 0));
      setLayout(new GridBagLayout());
      this.GOBAN_SIZE = GOBAN_SIZE;

      grid = new GobanGrid(400);
      add(grid);
   }

   @Override
   public void paintComponent(Graphics g) {
      super.paintComponent(g);
   }

   public void nextPlayer() {
      player = !player;
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
   public void cancelCoup() {
      if(listIndex >= listeCoups.size()) return;
      Point p = listeCoups.get(listeCoups.size()-listIndex-1);
      grid.stones[(int)p.getX()][(int)p.getY()] *= 4;
      grid.repaint();
      listIndex++;
   }
   public void resetCoup() {
      if(listIndex > listeCoups.size() || listIndex == 0) return;
      Point p = listeCoups.get(listeCoups.size()-listIndex);
      grid.stones[(int)p.getX()][(int)p.getY()] /= 4;
      grid.repaint();
      listIndex--;
   }

   public void componentResized(ComponentEvent e) {
      grid.setSize(getWidth()-gridPadding, getHeight()-gridPadding);
   }
   public void componentMoved(ComponentEvent e) {
      grid.setSize(getWidth()-gridPadding, getHeight()-gridPadding);
   }
   public void componentHidden(ComponentEvent e) {
      grid.setSize(getWidth()-gridPadding, getHeight()-gridPadding);
   }
   public void componentShown(ComponentEvent e) {
      grid.setSize(getWidth()-gridPadding, getHeight()-gridPadding);
   }
}


class GobanGrid extends JPanel implements MouseListener {
   public int[][] stones; //1: noir  2: blanc  3: hoshi  ||  4: ancien noir  8: ancien blanc

   public GobanGrid(int gridSize) {
      addMouseListener(this);
      setBackground(new Color(155, 105, 50));
      setSize(gridSize, gridSize);
      stones = new int[Goban.GOBAN_SIZE+1][Goban.GOBAN_SIZE+1];
   }

   public void setSize(int width, int height) {
      int gridSize = (width < height) ? width : height;
      gridSize = (int)(gridSize/Goban.GOBAN_SIZE)*(Goban.GOBAN_SIZE);
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
         if(stones[i][Y] <= 0 || stones[i][Y] > 3) continue;
         if(stones[i][Y] == 1) g.setColor(new Color(30, 30, 30));
         if(stones[i][Y] == 2) g.setColor(new Color(200, 200, 200));
         if(stones[i][Y] == 3) {
            g.setColor(new Color(30, 30, 30));
            g.fillOval(i*cellSize+padding-3, Y*cellSize+padding-3, 6, 6);
            continue;
         }
         g.fillOval(i*cellSize+(int)width/14, Y*cellSize+(int)width/14, (int)width, (int)width);
      }
      g.setColor(new Color(0, 0, 0));
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
      if (stones[(int)cell.getX()][(int)cell.getY()] != 1 && stones[(int)cell.getX()][(int)cell.getY()] != 2) {
         stones[(int)cell.getX()][(int)cell.getY()] = (Go.getGoban().getPlayer()) ? 1 : 2;
         Go.getGoban().nextPlayer();
         Go.getGoban().addCoup(cell);
      }
      repaint();
   }

   public double distance(int x1, int y1, int x2, int y2) {
      return Math.sqrt(Math.pow((x1-x2), 2) + Math.pow((y1-y2), 2));
   }

   public void setHoshi(int x, int y) {
      if(stones[x][y] == 1 || stones[x][y] == 2) return;
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
