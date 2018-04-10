import java.awt.*;
import javax.swing.*;
import java.util.*;

public class Couleur extends JPanel {
  private int nb;

  public Couleur(int nb) {
    this.setSize(new Dimension(800, 600));
    this.setPreferredSize(new Dimension(800, 600));
    this.nb = nb;
  }

  @Override
  public void paintComponent (Graphics g) {
    super.paintComponent(g);
    g.setColor(new Color(255, 50, 50));
    Random rand = new Random();
    int posx, posy, width;
    for (int i = 0; i < nb; i++) {
      width = rand.nextInt(40)+10;
      posx = rand.nextInt(800-100)+width*2;
      posy = rand.nextInt(600-100)+width*2;
      System.out.println(posx+" | "+posy);
      // g.drawLine(0, posy, 800, posy);
      // g.drawLine(posx, 0, posx, 600);
      g.fillOval(posx, posy, width, width);
    }
  }
}
