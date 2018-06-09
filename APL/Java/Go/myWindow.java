import java.awt.*;
import javax.swing.*;
import java.util.*;
import javax.swing.event.*;
import java.awt.event.*;

public class myWindow extends JFrame implements ComponentListener, ChangeListener {
   private Panneau contentPane = new Panneau();
   public Goban goban;
   private Label title;
   private Button start;

   public static Dimension MenuWindow = new Dimension(800, 600);
   public static Dimension GobanWindow = new Dimension(650, 500);

   public static JSlider range;
   private Label output;

   public myWindow() {
      addComponentListener(this);
      setIconImage(Toolkit.getDefaultToolkit().getImage(getClass().getResource("img/icon.png")));
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setVisible(true);

      setContentPane(contentPane);
   }

   public void displayMenu() {
      setTitle("Go");
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
      contentPane.removeAll();
      contentPane.repaint();
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
   public void chooseTimer(int SIZE) { //Choisir type horloge
      contentPane.removeAll();
      contentPane.repaint();
      contentPane.setLayout(new GridBagLayout());

      Label size = new Label("Type d'horloge ?", getWidth()/14, Color.WHITE);
      Button none = new Button("Aucune", 30, new Color(36, 120, 122));
      Button absolute = new Button("Absolue", 30, new Color(36, 120, 122));
      Button byo = new Button("Byo-Yomi", 30, new Color(36, 120, 122));
      Panneau buttonContainer = new Panneau();
      buttonContainer.setLayout(new GridBagLayout());
      buttonContainer.setOpaque(false);
      GridBagConstraints gbc = new GridBagConstraints();
      gbc.insets = new Insets(0, 10, 0, 10);
      buttonContainer.add(none, gbc);
      buttonContainer.add(absolute, gbc);
      buttonContainer.add(byo, gbc);

      none.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            displayGame(SIZE, TimerType.NONE);
         }
      });
      absolute.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            displayGame(SIZE, TimerType.ABSOLUTE);
         }
      });
      byo.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            displayGame(SIZE, TimerType.BYO);
         }
      });

      gbc = new GridBagConstraints();
      gbc.gridx = gbc.gridy = 0; gbc.insets = new Insets(0, 0, 20, 0);
      contentPane.add(size, gbc);
      gbc.gridy = 1;
      contentPane.add(buttonContainer, gbc);

      gbc.gridy++; gbc.gridx--; gbc.insets = new Insets(20, 0, 0, 0);
      if(SIZE == 9 || SIZE == 13) {
         range = new JSlider(0, 5, 0);
      } else {
         range = new JSlider(0, 9, 0);
      }
      range.setOpaque(false);
      range.addChangeListener(this);
      contentPane.add(range, gbc);
      gbc.gridy++;
      output = new Label("Handicap: 0", 30, Color.WHITE);
      contentPane.add(output, gbc);

      contentPane.validate();
   }

   public void displayGame(int size, TimerType timer) {
      contentPane.setLayout(new BorderLayout());
      contentPane.removeAll();
      goban = new Goban(size, timer);
      contentPane.add(goban);
      contentPane.validate();
   }

   public void displayWinner() {
      goban.END = true;
      setScores();
      contentPane.removeAll();
      contentPane.repaint();
      contentPane.setLayout(new GridBagLayout());


      Label scoreB = new Label(Infos.scoreBlack.getText(), getWidth()/17, Color.WHITE);
      Label scoreW = new Label(Infos.scoreWhite.getText(), getWidth()/17, Color.WHITE);

      GridBagConstraints gbc = new GridBagConstraints();
      gbc.gridwidth = 4;
      gbc.gridx = gbc.gridy = 0;
      gbc.insets = new Insets(0, 0, 20, 0);
      contentPane.add(new Label("Score: ", getWidth()/12, Color.WHITE), gbc);

      gbc.insets = new Insets(0, 0, 0, getWidth()/16);
      gbc.gridy = gbc.gridx = gbc.gridwidth = 1;
      contentPane.add(scoreB, gbc);
      gbc.insets = new Insets(0, getWidth()/16, 0, 0);
      gbc.gridx = 2;
      contentPane.add(scoreW, gbc);

      gbc.insets = new Insets(0, 8, 0, 8);
      gbc.gridx = 0;
      contentPane.add(new JLabel(new ImageIcon(new ImageIcon("img/icon.png").getImage().getScaledInstance(getWidth()/16, getWidth()/16, Image.SCALE_DEFAULT))), gbc);
      gbc.gridx = 3;
      contentPane.add(new JLabel(new ImageIcon(new ImageIcon("img/white.png").getImage().getScaledInstance(getWidth()/16, getWidth()/16, Image.SCALE_DEFAULT))), gbc);

      gbc.gridwidth = 4;
      gbc.gridx = 0; gbc.gridy = 2;
      gbc.insets = new Insets(30, 0, 0, 0);
      double scoreBlack = Double.parseDouble(scoreB.getText());
      double scoreWhite = Double.parseDouble(scoreW.getText());
      if(scoreBlack > scoreWhite) {
         if(scoreWhite == -1) scoreW.setText("Temps \u00e9coul\u00e9");
         scoreB.setForeground(new Color(20, 200, 50));
         scoreW.setForeground(new Color(200, 20, 50));
         contentPane.add(new Label("Joueur 1 gagne !", getWidth()/18, Color.WHITE), gbc);
      } else if(scoreBlack < scoreWhite) {
         if(scoreBlack == -1) scoreB.setText("Temps \u00e9coul\u00e9");
         scoreB.setForeground(new Color(200, 20, 50));
         scoreW.setForeground(new Color(20, 200, 50));
         contentPane.add(new Label("Joueur 2 gagne !", getWidth()/18, Color.WHITE), gbc);
      } else {
         scoreB.setForeground(new Color(20, 110, 170));
         scoreW.setForeground(new Color(20, 110, 170));
         contentPane.add(new Label("\u00c9galit\u00e9 !", getWidth()/18, Color.WHITE), gbc);
      }

      Button play = new Button("Jouer", 20, Color.WHITE, new Color(50, 100, 120));
      gbc.gridwidth = 2;
      gbc.gridx = 1; gbc.gridy = 3;
      contentPane.add(play,gbc);

      contentPane.validate();
   }

   public void setScores() {
      
   }

   public void componentResized(ComponentEvent e) {
      if(title == null || start == null) return;
      title.setFontSize(getWidth()/8);
      start.setFontSize(getWidth()/17);
      start.setSize(getWidth()/3, getHeight()/8);
   }
   public void componentMoved(ComponentEvent e) {
   }
   public void componentHidden(ComponentEvent e) {
   }
   public void componentShown(ComponentEvent e) {
   }

   public void stateChanged(ChangeEvent e) {
      output.setText("Handicap: " + range.getValue());
   }
}
