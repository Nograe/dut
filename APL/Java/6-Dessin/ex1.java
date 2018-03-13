import java.awt.*;
import java.util.*;
import javax.swing.*;

class Fenetre extends JFrame {

   public Fenetre (int width, int height) {
      setSize(width, height);
      setLocation(width+width/2, height);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setLocationRelativeTo(null);
      setVisible(true);
   }
}

class Dessin extends JComponent {

   @Override
   public void paintComponent(Graphics origin) {
      Graphics rect = origin.create();

      rect.setColor(Color.blue);
      rect.fillRect(100, 100, 50, 50);

      rect.setColor(Color.green);
      rect.drawOval(200, 100, 50, 50);

      rect.setFont(new Font("Sans", Font.BOLD, 24));
      rect.setColor(Color.magenta);
      rect.drawString(">o<", 150, 25);

      Image circles = Toolkit.getDefaultToolkit().getImage("circles.png");
      rect.drawImage(circles, 10, 20, this);
   }
}

public class ex1 {
   public static void main(String[] args) {

      Fenetre F = new Fenetre(300, 200);

      Dessin rect = new Dessin();

      F.setLayout(new BoxLayout(F.getContentPane(), BoxLayout.X_AXIS));
      F.add(rect);
   }
}
