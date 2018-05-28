import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Goban extends JPanel implements ComponentListener {
   public static int GOBAN_SIZE = 10;
   private GobanGrid grid;
   private int gridPadding = 150;

   public Goban(double gridSize) {
      addComponentListener(this);
      setBackground(new Color(60, 100, 125));
      setMinimumSize(new Dimension(400, 0));
      setLayout(new GridBagLayout());

      grid = new GobanGrid((int)gridSize - gridPadding);
      GridBagConstraints gbc = new GridBagConstraints();
      gbc.gridx = gbc.gridy = 0;
      // gbc.insets = new Insets(0, 0, 20, 0);
      add(grid, gbc);
   }

   @Override
   public void paintComponent(Graphics g) {
      super.paintComponent(g);
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
   private int[][] stones; //1: noir  |  2: blanc

   public GobanGrid(int gridSize) {
      addMouseListener(this);
      setBackground(new Color(155, 105, 50));
      setSize(gridSize, gridSize);
      stones = new int[Goban.GOBAN_SIZE+1][Goban.GOBAN_SIZE+1];
      stones[0][0] = 1;
      stones[4][5] = 2;
   }

   public void setSize(int width, int height) {
      int gridSize = width;
      if(width > height) gridSize = height;
      // gridSize = (int)(gridSize/Goban.GOBAN_SIZE)*Goban.GOBAN_SIZE+1;
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
      int padding = gridSize/Goban.GOBAN_SIZE/2;
      gridSize -= padding*2;
      int cellSize = gridSize/Goban.GOBAN_SIZE;
      gridSize = (int)(gridSize/Goban.GOBAN_SIZE)*Goban.GOBAN_SIZE;

      for (int x = 0; x <= Goban.GOBAN_SIZE; x++) {
         g.drawLine(x*cellSize+padding, padding, x*cellSize+padding, gridSize+padding);
      }
      for (int y = 0; y <= Goban.GOBAN_SIZE; y++) {
         g.drawLine(padding, y*cellSize+padding, gridSize+padding, y*cellSize+padding);
         drawLineStones(g, y, cellSize, padding);
      }
   }

   public void drawLineStones(Graphics g, int Y, int cellSize, int padding) {
      double width = cellSize*0.8;
      for (int i = 0; i <= Goban.GOBAN_SIZE; i++) {
         if(stones[i][Y] == 1) g.setColor(new Color(30, 30, 30));
         else if(stones[i][Y] == 2) g.setColor(new Color(200, 200, 200));
         else {
            continue;
         }
         g.fillOval(i*cellSize+(int)width/5, (Y*cellSize+padding)-cellSize/2+(int)width/7, (int)width, (int)width);
      }
      g.setColor(new Color(0, 0, 0));
   }

   public void mouseClicked(MouseEvent e) {
      int cellSize = getWidth()/Goban.GOBAN_SIZE;
      int padding = cellSize/2;
      int gridSize = getWidth() - padding*2;

      System.out.println(e.getX()*(getWidth()/gridSize)/Goban.GOBAN_SIZE+ "  " +e.getY()*(getHeight()/gridSize)/Goban.GOBAN_SIZE);
   }

   public void mousePressed(MouseEvent e) {
   }
   public void mouseReleased(MouseEvent e) {
   }
   public void mouseEntered(MouseEvent e) {
   }
   public void mouseExited(MouseEvent e) {
   }
}
