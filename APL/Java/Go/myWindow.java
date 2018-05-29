import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import java.util.*;
import java.awt.event.*;

public class myWindow extends JFrame implements ComponentListener {
   private Panneau contentPane = new Panneau();
   public Goban goban;
   public static Infos infos;
   private Label title;
   private Button start;

   public static Dimension MenuWindow = new Dimension(800, 600);
   public static Dimension GobanWindow = new Dimension(650, 500);

   public myWindow() {
      addComponentListener(this);
      setIconImage(Toolkit.getDefaultToolkit().getImage(getClass().getResource("img/icon.png")));
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setVisible(true);

      setContentPane(contentPane);
   }

   public void displayMenu() {
      setTitle("Go - Menu");
      setSize((int)MenuWindow.getWidth(), (int)MenuWindow.getHeight());
      setLocationRelativeTo(null);
      setMinimumSize(new Dimension(300, 200));
      contentPane.removeAll();
      contentPane.setLayout(new GridBagLayout());
      contentPane.setBackground(new Color(20, 120, 130));

      title = new Label("Jeu de Go", getWidth()/8, Color.WHITE);
      start = new Button("Jouer", getWidth()/17, new Color(20, 100, 120));

      GridBagConstraints gbc = new GridBagConstraints();
      gbc.gridx = gbc.gridy = 0; gbc.insets = new Insets(0, 0, 20, 0);
      contentPane.add(title, gbc);
      gbc.gridy = 1;
      start.setSize(getWidth()/4, getHeight()/8);
      contentPane.add(start, gbc);
      contentPane.validate();
   }

   public void chooseSize() { //Choisir taille goban
      setTitle("Go - Menu");
      setSize((int)MenuWindow.getWidth(), (int)MenuWindow.getHeight());
      setLocationRelativeTo(null);
      setMinimumSize(new Dimension(300, 200));
      contentPane.removeAll();
      contentPane.setLayout(new GridBagLayout());
      contentPane.setBackground(new Color(10, 90, 90));

      Label size = new Label("Taille du goban ?", getWidth()/14, Color.WHITE);
      Button size9 = new Button("9", 30, new Color(36, 120, 122));
      Button size13 = new Button("13", 30, new Color(36, 120, 122));
      Button size19 = new Button("19", 30, new Color(36, 120, 122));
      Panneau buttonContainer = new Panneau();
      buttonContainer.setLayout(new GridBagLayout());
      buttonContainer.setOpaque(false);
      GridBagConstraints gbc = new GridBagConstraints();
      gbc.insets = new Insets(0, 10, 0, 10);
      buttonContainer.add(size9, gbc);
      buttonContainer.add(size13, gbc);
      buttonContainer.add(size19, gbc);

      gbc = new GridBagConstraints();
      gbc.gridx = gbc.gridy = 0; gbc.insets = new Insets(0, 0, 20, 0);
      contentPane.add(size, gbc);
      gbc.gridy = 1;
      contentPane.add(buttonContainer, gbc);
      contentPane.validate();
   }

   public void displayGame(int GOBAN_SIZE) {
      setTitle("Go - Jouer");
      setSize((int)GobanWindow.getWidth(), (int)GobanWindow.getHeight());
      setMinimumSize(new Dimension(600, 500));
      setLocationRelativeTo(null);
      contentPane.removeAll();
      // contentPane.setBackground(new Color(20, 100, 90));
      contentPane.setLayout(new BorderLayout());

      goban = new Goban((int)GobanWindow.getWidth()/2, GOBAN_SIZE);
      infos = new Infos();

      JSplitPane sp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT);
      sp.setResizeWeight(0.5);
      sp.setDividerSize(5);
      sp.setBorder(null);
      sp.add(goban);
      sp.add(infos);
      contentPane.add(sp);
   }

   public void componentResized(ComponentEvent e) {
      if(title == null || start == null) return;
      title.setFontSize(getWidth()/8);
      start.setFontSize(getWidth()/17);
      start.setSize(getWidth()/4, getHeight()/8);
   }
   public void componentMoved(ComponentEvent e) {
   }
   public void componentHidden(ComponentEvent e) {
   }
   public void componentShown(ComponentEvent e) {
   }
}
