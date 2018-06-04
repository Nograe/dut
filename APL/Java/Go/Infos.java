import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Infos extends JPanel implements ComponentListener {
   public Countdown p1Timer;
   public Countdown p2Timer;
   private int time = 100;
   public static JLabel scoreBlack;
   public static JLabel scoreWhite;

   public Infos() {
      addComponentListener(this);
      setBackground(new Color(60, 125, 100));
      setLayout(new GridBagLayout());
      scoreBlack = new JLabel("0");
      scoreWhite = new JLabel("0");
      displayInfos();
   }

   public void displayInfos() {
      p1Timer = new Countdown(time);
      p2Timer = new Countdown(time);
      p2Timer.setForeground(Color.BLACK);
      Button quit = new Button("Quitter", 20, getBackground().darker().darker());
      ImageIcon undoIcon = new ImageIcon(new ImageIcon("img/undo.png").getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT));
      Button undo = new Button(undoIcon, 20, getBackground().darker().darker());
      ImageIcon redoIcon = new ImageIcon(new ImageIcon("img/redo.png").getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT));
      Button redo = new Button(redoIcon, 20, getBackground().darker().darker());
      undo.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            Go.getGoban().undoCoup();
         }
      });
      redo.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            Go.getGoban().redoCoup();
         }
      });

      GridBagConstraints gbc = new GridBagConstraints();
      gbc.insets = new Insets(15, 0, 15, 0);
      gbc.gridy = 0; gbc.gridx = 1;
      add(quit, gbc);

      if(Goban.timer != TimerType.NONE) {
         gbc.gridx = 0;
         gbc.gridy = 1;
         add(p1Timer, gbc);
         add(new JLabel(new ImageIcon(new ImageIcon("img/icon.png").getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT))), gbc);
         gbc.gridx = 2;
         add(p2Timer, gbc);
         add(new JLabel(new ImageIcon(new ImageIcon("img/white.png").getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT))), gbc);
      }

      gbc.gridy++; gbc.gridx = 0;
      add(scoreBlack, gbc);
      gbc.gridx = 2;
      add(scoreWhite, gbc);

      gbc.gridx = 0; gbc.weighty = 1;
      gbc.anchor = GridBagConstraints.LAST_LINE_START;
      add(undo, gbc);
      gbc.gridx = 2;
      gbc.anchor = GridBagConstraints.LAST_LINE_END;
      add(redo, gbc);
   }

   public static void setScoreBlack(int score) {
      scoreBlack.setText(Integer.toString(Integer.parseInt(scoreBlack.getText())+score));
   }
   public static void setScoreWhite(int score) {
      scoreWhite.setText(Integer.toString(Integer.parseInt(scoreWhite.getText())+score));
   }

   @Override
   public void setSize(int width, int height) {
      setMinimumSize(new Dimension(width, height));
      setPreferredSize(new Dimension(width, height));
      setMaximumSize(new Dimension(width, height));
   }

   public void componentResized(ComponentEvent e) {
   }
   public void componentMoved(ComponentEvent e) {
   }
   public void componentHidden(ComponentEvent e) {
   }
   public void componentShown(ComponentEvent e) {
   }
}
