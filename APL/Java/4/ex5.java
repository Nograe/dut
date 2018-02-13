//Mise en page
import javax.swing.*;
import java.awt.*;

public class ex5 {
   public static void main(String[] args) {

      JFrame fenetre = new JFrame();

      fenetre.setSize(400, 430);
      fenetre.setLocation(500, 200);
      fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      fenetre.setLayout(null);

      JButton bouton = new JButton("1");
      bouton.setSize(300, 100);
      bouton.setLocation(0, 0);
      fenetre.add(bouton);
      JButton bouton2 = new JButton("2");
      bouton2.setSize(100, 300);
      bouton2.setLocation(300, 0);
      fenetre.add(bouton2);
      JButton bouton3 = new JButton("3");
      bouton3.setSize(300, 100);
      bouton3.setLocation(100, 300);
      fenetre.add(bouton3);
      JButton bouton4 = new JButton("4");
      bouton4.setSize(100, 300);
      bouton4.setLocation(0, 100);
      fenetre.add(bouton4);
      JButton bouton5 = new JButton("5");
      bouton5.setSize(200, 200);
      bouton5.setLocation(100, 100);
      fenetre.add(bouton5);

      fenetre.setVisible(true);
   }
}
