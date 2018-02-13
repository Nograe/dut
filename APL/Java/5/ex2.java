//Héritage

import java.awt.*;
import java.util.*;
import javax.swing.*;

class Nuance extends JPanel {

   JLabel desc;
   JPanel couleur;

   public Nuance (int r, int g, int b) {
      this.setPreferredSize(new Dimension(100, 100));
      this.setMaximumSize(new Dimension(500, 500));
      this.setMinimumSize(new Dimension(100, 100));

      setLayout(new BorderLayout());
      this.desc = new JLabel('(' + Integer.toString(r) + ',' + Integer.toString(g) + ',' + Integer.toString(b) + ')');
      this.desc.setHorizontalAlignment(JLabel.CENTER);
      this.desc.setBackground(Color.black);
      this.desc.setForeground(Color.white);
      this.desc.setOpaque(true);
      add(desc, BorderLayout.NORTH);

      this.couleur = new JPanel();
      this.couleur.setBackground(new Color(r, g, b));
      add(couleur, BorderLayout.CENTER);
   }
}

public class ex2 {
   public static void main(String[] args) {

      JFrame fenetre = new JFrame();

      fenetre.setTitle("Nuancier");
      fenetre.setLocation(500, 300);
      fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      fenetre.setLayout(new FlowLayout(FlowLayout.CENTER));

      Nuance N1 = new Nuance(Integer.parseInt(args[0].substring(1, 3), 16), Integer.parseInt(args[0].substring(3, 5), 16), Integer.parseInt(args[0].substring(5, 7), 16));
      Nuance N2 = new Nuance(Integer.parseInt(args[1].substring(1, 3), 16), Integer.parseInt(args[1].substring(3, 5), 16), Integer.parseInt(args[1].substring(5, 7), 16));
      Nuance N3 = new Nuance(Integer.parseInt(args[2].substring(1, 3), 16), Integer.parseInt(args[2].substring(3, 5), 16), Integer.parseInt(args[2].substring(5, 7), 16));

      fenetre.add(N1);
      fenetre.add(N2);
      fenetre.add(N3);

      fenetre.pack();
      fenetre.setVisible(true);
   }
}
