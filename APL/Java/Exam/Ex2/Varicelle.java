import java.awt.*;
import javax.swing.*;
import java.util.*;

public class Varicelle extends JFrame {
  private JPanel pan;
  private Couleur C;

  public Varicelle (int nb) {
    this.setTitle("EX2");
    this.setSize(800, 600);
    this.setLocationRelativeTo(null);
    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    this.setVisible(true);

    this.pan = new JPanel();
    this.setContentPane(pan);
    this.setVisible(true);
    this.setLayout(new BoxLayout(this.pan, BoxLayout.PAGE_AXIS));

    this.C = new Couleur(nb);
    this.add(C);
  }

  public static void main(String[] args) {
    if(args.length != 0) {
      Varicelle var = new Varicelle(Integer.parseInt(args[0]));
    }
  }
}
