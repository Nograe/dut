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

class Sablier extends JComponent {

   @Override
   public void paintComponent(Graphics origin) {
      Graphics rect = origin.create();

      rect.setColor(Color.blue);
      rect.fillRect(100, 100, 50, 50);
   }
}

public class ex2 {
   public static void main(String[] args) {

      Fenetre F = new Fenetre(300, 300);

      JPanel[] container = new JPanel[];
      Sablier S = new Sablier();

      F.setLayout(new BoxLayout(F.getContentPane(), BoxLayout.X_AXIS));

      for(int i = 0; i < 25; i++) {
         container[i] = new Sablier();
         F.add(S[i]);
      }
   }
}
