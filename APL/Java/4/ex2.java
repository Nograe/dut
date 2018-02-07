//Mise en page
import javax.swing.*;
import java.awt.*;

public class ex2 {
   public static void main(String[] args) {
      int taille = Integer.parseInt(args[0]);

      JFrame fenetre = new JFrame();

      fenetre.setSize(500, 500);
      fenetre.setLocation(500, 200);
      fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      Color c1 = new Color(50, 170, 255);
      Color c2 = new Color(200, 200, 200);

      GridLayout grille = new GridLayout(taille, taille);
      fenetre.setLayout(grille);

      JLabel[] cases = new JLabel[taille*taille];

      for(int i = 0; i < taille*taille; i++) {
         cases[i] = new JLabel();
         cases[i].setOpaque(true);
         if(i%2 == 0) {
            cases[i].setBackground(c1);
            fenetre.add(cases[i]);
         }
         else {
            cases[i].setBackground(c2);
            fenetre.add(cases[i]);
         }
      }

      fenetre.setVisible(true);
   }
}
