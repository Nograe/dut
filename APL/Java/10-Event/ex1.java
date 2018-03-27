import java.awt.*;
import javax.swing.*;

public class ex1 {
   public static void main(String[] args) {
      
      JFrame fenetre = new JFrame();

      fenetre.setSize(500, 200);
      fenetre.setLocation(500, 300);
      fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      JPanel MainPanel = new JPanel();
      MainPanel.setBackground(Color.GREEN);
      MainPanel.setSize(new Dimension(500, 60));

      JPanel ControlPanel = new JPanel();
      ControlPanel.setBackground(Color.RED);
      ControlPanel.setSize(new Dimension(500, 80));

      JPanel InformationPanel = new JPanel();
      InformationPanel.setBackground(Color.YELLOW);
      MainPanel.setSize(new Dimension(500, 60));
      
      ControlPanel.add(new JButton());
      ControlPanel.add(new JButton());
      ControlPanel.add(new JButton());
      ControlPanel.add(new JButton());

      fenetre.add(MainPanel, BorderLayout.CENTER);
      fenetre.add(ControlPanel, BorderLayout.SOUTH);
      fenetre.add(InformationPanel, BorderLayout.NORTH);

      fenetre.setVisible(true);
   }
}
