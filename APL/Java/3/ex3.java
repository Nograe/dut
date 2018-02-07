// Composants graphiques
import javax.swing.*;
import java.awt.*;

public class ex3 {
  public static void main(String[] args) {
    // un objet pour servir de fenetre
    JFrame fenetre = new JFrame();
    // on configure la fenetre
    fenetre.setSize(500, 200);
    fenetre.setLocation(500, 300);
    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JTextField champ = new JTextField("Je suis en bas");
    Color c1 = new Color(0, 255, 0);
    Color c2 = new Color(50, 50, 50);
    champ.setForeground(c1);
    champ.setBackground(c2);
    JTextArea zone = new JTextArea();
    Color c3 = new Color(0, 255, 0);
    Color c4 = new Color(0, 0, 0);
    zone.setForeground(c3);
    zone.setBackground(c4);

    fenetre.add(champ, BorderLayout.SOUTH);
    fenetre.add(zone, BorderLayout.CENTER);

    fenetre.setVisible(true);
  }
}
