// Composants graphiques
import javax.swing.*;
import java.awt.*;

public class ex1 {
  public static void main(String[] args) {
    // un objet pour servir de fenetre
    JFrame fenetre = new JFrame();
    // on configure la fenetre
    fenetre.setSize(500, 200);
    fenetre.setLocation(0, 0);
    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    // un composant pour afficher du texte
    JLabel text = new JLabel("Sirocco");
    // on configure l'text
    text.setHorizontalAlignment(JLabel.RIGHT);
    text.setVerticalAlignment(JLabel.BOTTOM);
    // on ajoute le composant dans la fenetre, au milieu
    fenetre.add(text, BorderLayout.CENTER);
    // et on montre le resultat
    fenetre.setVisible(true);
  }
}
