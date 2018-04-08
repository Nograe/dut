import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.net.URL;
import javax.sound.sampled.*;
import java.io.*;

public class MainPanel extends JPanel implements MouseMotionListener, MouseListener {
   private int width;
   private int height;
   private int[][] obstacles;
   private Case[][] cases;
   private int RectWidth;
   private int RectHeight;
   private Coord contour = null;
   private Coord start = null;
   private Coord arrivee = null;
   private ArrayList<Coord> path = null;
   boolean visited[][];
   PriorityQueue<Case> openList;
   HashMap<Coord, Coord> mapPath = null;
   Clip clip = null;

   MainPanel (int width, int height, int tX, int tY) {
      this.width = width;
      this.height = height;
      this.setSize(new Dimension(width, height));
      this.setPreferredSize(new Dimension(width, height));

      this.obstacles = new int[tY][tX];
      this.setLayout(new GridLayout(obstacles.length, obstacles[0].length));
      this.path = new ArrayList<Coord>();
   }

   @Override
   public void paintComponent (Graphics g) {
      super.paintComponent(g);
      int posX = 0;
      int posY = 0;
      this.RectWidth = this.getWidth()/obstacles[0].length;
      this.RectHeight = this.getHeight()/obstacles.length;
      for(int i = 0; i < obstacles.length; i++) {
         for(int j = 0; j < obstacles[i].length; j++) {
            if(obstacles[i][j] == 1) {
               // Image obstacle = Toolkit.getDefaultToolkit().getImage("risitas.png");
               URL url = this.getClass().getResource("obstacle.gif");
               Image obstacle = new ImageIcon(url).getImage();
               g.drawImage(obstacle, posX+RectWidth/8, posY+RectHeight/8, (int)(RectWidth*0.8), (int)(RectHeight*0.8), null, this);
            }
            posX += RectWidth;
         }
         posX = 0;
         posY += RectHeight;
      }

      if(contour != null && Main.window.placeObstacle.isSelected()) {
         g.setColor(new Color(50, 150, 50));
         g.drawRoundRect(contour.getX()*RectWidth, contour.getY()*RectHeight, RectWidth, RectHeight, 20, 20);
      }
      if(start != null) {
         // Image start = Toolkit.getDefaultToolkit().getImage("start.png");
         URL url = this.getClass().getResource("start.gif");
         Image startImg = new ImageIcon(url).getImage();
         g.drawImage(startImg, start.getX()*RectWidth+RectWidth/8, start.getY()*RectHeight, (int)(RectWidth*0.8), (int)(RectHeight*0.8), null, this);
      }
      else if(contour != null && Main.window.selectDepart.isSelected()) {
         // Image start = Toolkit.getDefaultToolkit().getImage("start.png");
         URL url = this.getClass().getResource("start.gif");
         Image startImg = new ImageIcon(url).getImage();
         g.drawImage(startImg, contour.getX()*RectWidth+RectWidth/8, contour.getY()*RectHeight, (int)(RectWidth*0.8), (int)(RectHeight*0.8), null, this);
      }

      if(start != null && arrivee != null && mapPath != null && Main.window.selectDepart.isSelected()) {
         Coord key = arrivee;
         Coord value = mapPath.get(key);
         g.setColor(new Color(50, 150, 50));
         g.fillOval(key.getX()*RectWidth+RectWidth/4, key.getY()*RectHeight+RectHeight/4, RectWidth/2, RectHeight/2);
         if(value == null) {
            // System.out.println("ERREUR DE DESSIN");
            return;
         }
         while (value.getX() != start.getX() || value.getY() != start.getY()) {
            g.fillOval(value.getX()*RectWidth+RectWidth/4, value.getY()*RectHeight+RectHeight/4, RectWidth/2, RectHeight/2);
            value = mapPath.get(key);
            key = value;
            if(value == null || start == null) {
               System.out.println("Erreur d'éxecution");
               return;
            }
         }
      }
   }

   public void mouseDragged (MouseEvent e) {
      if(e.getX()/RectWidth >= obstacles[0].length || e.getY()/RectHeight >= obstacles.length) return;
      if(e.getX() >= getWidth() || e.getX() < 0 || e.getY() >= getHeight() || e.getY() < 0) return;
      updateContour(e);
      if(contour.getX() >= obstacles[0].length || contour.getY() >= obstacles.length) return;

      if(!Main.window.placeObstacle.isSelected() || SwingUtilities.isMiddleMouseButton(e)) return;
      int posX = e.getX() / RectWidth;
      int posY = e.getY() / RectHeight;

      if(SwingUtilities.isLeftMouseButton(e) && start == null) {
         obstacles[posY][posX] = 1;
      }
      else if(SwingUtilities.isLeftMouseButton(e) && !start.equals(new Coord(posX, posY))) {
         obstacles[posY][posX] = 1;
      }
      else if(SwingUtilities.isRightMouseButton(e)) {
         obstacles[posY][posX] = 0;
      }
      repaint();
   }

   public void mouseClicked (MouseEvent e) {
      if(e.getX()/RectWidth >= obstacles[0].length || e.getY()/RectHeight >= obstacles.length) return;
      if(e.getX() >= getWidth() || e.getX() < 0 || e.getY() >= getHeight() || e.getY() < 0) return;
      updateContour(e);
      if(contour.getX() >= obstacles[0].length || contour.getY() >= obstacles.length) return;

      // On gère le cas où l'utilisateur veut placer/retirer un seul obstacle
      if(Main.window.placeObstacle.isSelected()) mouseDragged(e);

      if(Main.window.selectDepart.isSelected() && SwingUtilities.isRightMouseButton(e)) {
         start = null;
         repaint();
         return;
      }
      if(!Main.window.selectDepart.isSelected() || SwingUtilities.isMiddleMouseButton(e) || obstacles[e.getY() / RectHeight][e.getX() / RectWidth] == 1) return;
      if(start != null) {
         mapPath = null;
      }
      start = new Coord(e.getX() / RectWidth, e.getY() / RectHeight);
      repaint();
   }

   public void mouseMoved (MouseEvent e) {
      if(e.getX()/RectWidth >= obstacles[0].length || e.getY()/RectHeight >= obstacles.length) return;
      if(e.getX() >= getWidth() || e.getX() < 0 || e.getY() >= getHeight() || e.getY() < 0) return;
      updateContour(e);
      if(contour.getX() >= obstacles[0].length || contour.getY() >= obstacles.length) return;

      // Application de l'algorithme
      arrivee = new Coord(e.getX()/RectWidth, e.getY()/RectHeight);
      if(start != null && Main.window.selectDepart.isSelected() && !start.equals(arrivee)) {
         mapPath = calculRoute(start, arrivee);
         if(mapPath == null) {
            // System.out.println("Il n'existe aucun chemin.");
            return;
         }
         repaint();
      }
      else {
         mapPath = null;
      }
   }

   public HashMap<Coord,Coord> calculRoute(Coord depart, Coord arrivee) {
      if(obstacles[arrivee.getY()][arrivee.getX()] == 1) {
         return null;
      }

      int countCases = 0;
      cases = new Case[obstacles[0].length][obstacles.length];
      for (int x = 0; x < obstacles.length; x++) {
         for (int y = 0; y < obstacles[0].length; y++) {
            if(obstacles[x][y] == 0) {
               cases[y][x] = new Case(y, x);
               countCases++;
            }
         }
      }
      // System.out.println(arrivee.getX() + " | " + arrivee.getY());
      cases[depart.getX()][depart.getY()].update(0, depart, arrivee);

      /*------------------------------------ ALGO A* -----------------------------------------------*/
      visited = new boolean[cases.length][cases[0].length];
      openList = new PriorityQueue<Case>(countCases, (Case A, Case B) -> {
         if (A.getEstimation() < B.getEstimation()) {
            return -1;
         }
         if (A.getEstimation() > B.getEstimation()) {
            return 1;
         }
         return 0;
      });
      mapPath = new HashMap<Coord, Coord>();
      openList.add(cases[depart.getX()][depart.getY()]);
      while(openList.size() != 0) {
         Case C = openList.poll();
         if(C.getX() == arrivee.getX() && C.getY() == arrivee.getY()) {
            return mapPath;
         }
         else {
            visited[C.getX()][C.getY()] = true;
            adjacent(C, C.getX(), C.getY()-1);
            adjacent(C, C.getX()+1, C.getY());
            adjacent(C, C.getX(), C.getY()+1);
            adjacent(C, C.getX()-1, C.getY());
         }
      }
      return null;
   }

   public void adjacent(Case origin, int x, int y) {
      if(x < 0 || y < 0 || x >= cases.length || y >= cases[0].length || obstacles[y][x] == 1 || visited[x][y] == true) {
         return;
      }
      if(!openList.contains(cases[x][y])) {
         cases[x][y].update(origin.getCout()+1, new Coord(x, y), origin.getCoord());
         openList.add(cases[x][y]);
         mapPath.put(cases[x][y].getCoord(), origin.getCoord());
      }
      if(openList.contains(cases[x][y]) && origin.getCout()+1 < cases[x][y].getCout()) {
         cases[x][y].update(origin.getCout()+1, new Coord(x, y), origin.getCoord());
         mapPath.put(cases[x][y].getCoord(), origin.getCoord());
      }
   }

   public void updateContour (MouseEvent e) {
      if(e.getX()/RectWidth >= obstacles[0].length || e.getY()/RectHeight >= obstacles.length) return;
      contour = new Coord(e.getX() / RectWidth, e.getY() / RectHeight);
      repaint();
   }

   public void printCases() {
      for (int x = 0; x < cases.length; x++) {
         for (int y = 0; y < cases[0].length; y++) {
            if(cases[x][y] != null) {
               System.out.println(cases[x][y].toString());
            }
         }
      }
      System.out.println("-----------------------------------------------------------------");
   }

   public void setRandom() {
      arrivee = null;
      repaint();
      for(int[] row: obstacles) {
         Arrays.fill(row, 0);
      }
      for(int i = 0; i < obstacles.length; i++) {
         for (int j = 0; j < obstacles[0].length; j++) {
            if(Math.random()*100 > 70 && (start == null || (start.getX() != j || start.getY() != i))) {
               obstacles[i][j] = 1;
            }
         }
      }
      repaint();
   }

   public void playSound () {
      if(clip != null && clip.isRunning()) {
         System.out.println("Sound playing");
         clip.stop();
         clip.start();
         return;
      }
      try {
         DataLine.Info daInfo = new DataLine.Info(Clip.class, null);
         try {
            URL sounURL = this.getClass().getResource("sound.wav");

            AudioInputStream inputStream = AudioSystem.getAudioInputStream(sounURL);
            DataLine.Info info = new DataLine.Info(Clip.class, inputStream.getFormat());
            clip = (Clip) AudioSystem.getLine(info);
            clip.open(inputStream);
            clip.start();
         } catch (LineUnavailableException e) {
            e.printStackTrace();
         } catch (UnsupportedAudioFileException ex) {
            ex.printStackTrace();
         } catch (IOException ex) {
            ex.printStackTrace();
         }
      } catch (Exception e) {
         System.out.println("error catched");
      }
   }

   public void mouseEntered(MouseEvent e) {
   }
   public void mouseExited(MouseEvent e) {
   }
   public void mousePressed(MouseEvent e) {
   }
   public void mouseReleased(MouseEvent e) {
   }
}
