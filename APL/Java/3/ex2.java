// Composants graphiques
import javax.swing.*;
import java.awt.*;

public class ex2 {
  public static void main(String[] args) {
    // un objet pour servir de fenetre
    JFrame fenetre = new JFrame();
    // on configure la fenetre
    fenetre.setSize(300, 300);
    fenetre.setLocation(500, 200);
    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    // un composant pour afficher du texte
    JButton B1 = new JButton("Bouton 1 TESTTESTTESTTESTTEsTESTETSTETSTETSTE");
    JButton B2 = new JButton("Bouton 2");
    JButton B3 = new JButton("Bouton 3");
    JButton B4 = new JButton("Bouton 4");
    JButton B5 = new JButton("Bouton 5");
    // on configure le texte
    B1.setHorizontalAlignment(JLabel.CENTER);
    B2.setHorizontalAlignment(JLabel.CENTER);
    B3.setHorizontalAlignment(JLabel.CENTER);
    B4.setHorizontalAlignment(JLabel.CENTER);
    B5.setHorizontalAlignment(JLabel.CENTER);
    // on ajoute le composant dans la fenetre, au milieu
    fenetre.add(B1, BorderLayout.NORTH);
    fenetre.add(B2, BorderLayout.SOUTH);
    fenetre.add(B3, BorderLayout.WEST);
    fenetre.add(B4, BorderLayout.EAST);
    fenetre.add(B5, BorderLayout.CENTER);
    // et on montre le resultat
    fenetre.setVisible(true);
  }
}
