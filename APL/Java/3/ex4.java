// Composants graphiques
import javax.swing.*;
import java.awt.*;

public class ex4 {
  public static void main(String[] args) {

    JFrame fenetre = new JFrame();

    fenetre.setSize(300, 300);
    fenetre.setLocation(500, 200);
    fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JRadioButton gryf = new JRadioButton("Gryffondor");
    JRadioButton serd = new JRadioButton("Serdaigle");
    JRadioButton serp = new JRadioButton("Serpentard");
    ButtonGroup group = new ButtonGroup();

    group.add(gryf);
    group.add(serd);
    group.add(serp);

    gryf.setHorizontalAlignment(JLabel.CENTER);
    serd.setHorizontalAlignment(JLabel.CENTER);
    serp.setHorizontalAlignment(JLabel.CENTER);

    fenetre.add(gryf, BorderLayout.NORTH);
    fenetre.add(serd, BorderLayout.CENTER);
    fenetre.add(serp, BorderLayout.SOUTH);

    fenetre.setVisible(true);
  }
}
