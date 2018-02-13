//Mise en page
import javax.swing.*;
import java.awt.*;

public class ex3 {
   public static void main(String[] args) {

      JFrame fenetre = new JFrame();

      fenetre.setSize(400, 200);
      fenetre.setLocation(500, 200);
      fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      JLabel question = new JLabel("Aimez-vous les chats ?");
      question.setHorizontalAlignment(JLabel.CENTER);
      question.setVerticalAlignment(JLabel.BOTTOM);
      question.setPreferredSize(new Dimension(400, 100));

      JPanel panneau = new JPanel();
      JButton bouton = new JButton("Oui");
      panneau.add(bouton);
      JButton bouton2 = new JButton("Non");
      panneau.add(bouton2);
      JButton bouton3 = new JButton("NSPP");
      panneau.add(bouton3);
      fenetre.add(question, BorderLayout.NORTH);
      fenetre.add(panneau, BorderLayout.CENTER);

      fenetre.setVisible(true);
   }
}
