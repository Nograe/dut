//Mise en page
import javax.swing.*;
import java.awt.*;

public class ex1 {
   public static void main(String[] args) {

      JFrame fenetre = new JFrame();

      fenetre.setSize(300, 300);
      fenetre.setLocation(500, 200);
      fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      GridLayout grille = new GridLayout(4, 1);
      fenetre.setLayout(grille);

      JRadioButton gryf = new JRadioButton("Gryffondor");
      JRadioButton serd = new JRadioButton("Serdaigle");
      JRadioButton serp = new JRadioButton("Serpentard");
      JRadioButton pouf = new JRadioButton("Poufsouffle");

      ButtonGroup group = new ButtonGroup();
      group.add(gryf);
      group.add(serd);
      group.add(serp);
      group.add(pouf);

      fenetre.add(gryf);
      fenetre.add(serd);
      fenetre.add(serp);
      fenetre.add(pouf);

      fenetre.setVisible(true);
   }
}
