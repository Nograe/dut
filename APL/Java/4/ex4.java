//Mise en page
import javax.swing.*;
import java.awt.*;

public class ex4 {
   public static void main(String[] args) {

      JFrame fenetre = new JFrame();

      fenetre.setSize(300, 200);
      fenetre.setLocation(500, 200);
      fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      JLabel l1 = new JLabel("MYSTRAL");
      l1.setHorizontalAlignment(JLabel.LEFT);
      l1.setVerticalAlignment(JLabel.TOP);
      l1.setPreferredSize(new Dimension(50, 100));
      fenetre.add(l1, BorderLayout.NORTH);

      JLabel l2 = new JLabel("TRAMONTANE");
      l2.setHorizontalAlignment(JLabel.CENTER);
      l2.setVerticalAlignment(JLabel.TOP);
      l2.setPreferredSize(new Dimension(50, 100));
      fenetre.add(l2, BorderLayout.NORTH);

      JLabel l3 = new JLabel("GREC");
      l3.setHorizontalAlignment(JLabel.RIGHT);
      l3.setVerticalAlignment(JLabel.TOP);
      l3.setPreferredSize(new Dimension(50, 100));
      fenetre.add(l3, BorderLayout.NORTH);

      JLabel l4 = new JLabel("LEVANT");
      l4.setHorizontalAlignment(JLabel.RIGHT);
      l4.setVerticalAlignment(JLabel.CENTER);
      // l4.setPreferredSize(new Dimension(400, 100));
      fenetre.add(l4, BorderLayout.CENTER);

      JLabel l5 = new JLabel("PONANT");
      l5.setHorizontalAlignment(JLabel.LEFT);
      l5.setVerticalAlignment(JLabel.CENTER);
      // l5.setPreferredSize(new Dimension(400, 100));
      fenetre.add(l5, BorderLayout.CENTER);

      fenetre.setVisible(true);
   }
}
