import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import java.util.*;

public class myWindow extends JFrame {
   private Panneau contentPane = new Panneau();
   private Goban goban;
   private Panneau infos;

   public myWindow() {
      setIconImage(Toolkit.getDefaultToolkit().getImage(getClass().getResource("img/icon.png")));
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setVisible(true);

      setContentPane(contentPane);
   }

   public void displayMenu(int width, int height) {
      setTitle("Go - Menu");
      setSize(width, height);
      setLocationRelativeTo(null);
      setMinimumSize(new Dimension(300, 200));
      contentPane.setLayout(new GridBagLayout());
      contentPane.setBackground(new Color(20, 120, 130));

      JLabel title = new JLabel("Jeu de Go", JLabel.CENTER);
      title.setFont(new Font("Roboto", Font.PLAIN, 60));
      title.setForeground(Color.white);
      Button start = new Button("Jouer");

      start.addMouseListener(new java.awt.event.MouseAdapter() {
         public void mouseEntered(java.awt.event.MouseEvent evt) {
            start.setBackground(new Color(20, 110, 130));
         }

         public void mouseExited(java.awt.event.MouseEvent evt) {
            start.setBackground(new Color(20, 100, 120));
         }
      });

      start.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            Go.mainWindow.displayGame(800, 600);
         }
      });

      GridBagConstraints gbc = new GridBagConstraints();

      gbc.gridx = gbc.gridy = 0;
      gbc.insets = new Insets(0, 0, 20, 0);
      contentPane.add(title, gbc);

      gbc.gridy = 1;
      start.setSize(100, 30);
      start.setBackground(new Color(20, 100, 120));
      start.setText(new Font("Roboto", Font.PLAIN, 20), Color.white);
      start.setBorderPainted(false);
      start.setFocusPainted(false);
      contentPane.add(start, gbc);

      contentPane.validate();
   }

   public void displayGame(int width, int height) {
      setTitle("Go - Jouer");
      setSize(width, height);
      setMinimumSize(new Dimension(500, 500));
      setLocationRelativeTo(null);
      contentPane.removeAll();
      // contentPane.setBackground(new Color(20, 100, 90));
      contentPane.setLayout(new BorderLayout());

      goban = new Goban(width*0.7);
      infos = new Panneau();
      infos.setBackground(new Color(60, 125, 100));

      JSplitPane sp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT);
      sp.setResizeWeight(0.7);
      // sp.setEnabled(true);
      sp.setDividerSize(5);
      sp.setBorder(null);

      sp.add(goban);
      sp.add(infos);
      contentPane.add(sp);
      // goban.drawGrid();
   }
}
