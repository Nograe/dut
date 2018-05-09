import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import java.util.*;

public class Fenetre extends JFrame {
   public static JPanel pan;
   Panneau ControlPanel;
   MainPanel Main;
   public static JRadioButton placeObstacle;
   public static JRadioButton selectDepart;
   public static JButton random;

   public Fenetre (int tX, int tY) {
      this.setTitle("A*");
      this.setSize(800, 500);
      this.setLocationRelativeTo(null);
      this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      this.setVisible(true);

      this.pan = new JPanel();
      this.setContentPane(pan);
      this.setVisible(true);
      this.setLayout(new BoxLayout(this.pan, BoxLayout.PAGE_AXIS));

      this.Main = new MainPanel(800, 450, tX, tY);
      this.add(Main);
      this.Main.addMouseMotionListener(this.Main);
      this.Main.addMouseListener(this.Main);

      this.ControlPanel = new Panneau(800, 50);
      this.ControlPanel.setMaximumSize(new Dimension(Integer.MAX_VALUE, 100));
      this.add(ControlPanel);

      this.placeObstacle = new JRadioButton("Placer/Enlever des obstacles");
      this.selectDepart = new JRadioButton("Appliquer l'algorithme");
      this.random = new JButton("Placer des obstacles aleatoirement");
      this.placeObstacle.setBackground(new Color(20, 120, 100));
      this.selectDepart.setBackground(new Color(20, 120, 100));
      this.random.setBackground(new Color(20, 90, 75));
      this.random.setForeground(new Color(170, 220, 200));
      this.placeObstacle.setFocusPainted(false);
      this.selectDepart.setFocusPainted(false);
      this.random.setBorderPainted(false);
      this.random.setFocusPainted(false);
      this.ControlPanel.add(placeObstacle);
      this.ControlPanel.add(selectDepart);
      this.ControlPanel.add(random);
      ButtonGroup Group = new ButtonGroup();
      Group.add(placeObstacle);
      Group.add(selectDepart);

      random.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            Main.setRandom();
         }
      });
   }
}

class Panneau extends JPanel {
   private int width;
   private int height;

   Panneau (int width, int height) {
      this.width = width;
      this.height = height;
      this.setSize(new Dimension(width, height));
      this.setPreferredSize(new Dimension(width, height));
   }
}
