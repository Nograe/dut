import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Infos extends JPanel implements ComponentListener {
   public Countdown p1Timer;
   public Countdown p2Timer;
   public static Label scoreBlack;
   public static Label scoreWhite;

   public Infos() {
      addComponentListener(this);
      setBackground(new Color(60, 125, 100));
      setLayout(new GridBagLayout());
      scoreBlack = new Label(Integer.toString(myWindow.range.getValue()), 20, Color.WHITE);
      scoreWhite = new Label("7.5", 20, Color.BLACK);
      displayInfos();
   }

   public void displayInfos() {
      Button skip = new Button("Passer", 20, getBackground().darker().darker());
      Button quit = new Button("Quitter", 20, getBackground().darker().darker());
      ImageIcon undoIcon = new ImageIcon(new ImageIcon("img/undo.png").getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT));
      Button undo = new Button(undoIcon, 20, getBackground().darker().darker());
      ImageIcon redoIcon = new ImageIcon(new ImageIcon("img/redo.png").getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT));
      Button redo = new Button(redoIcon, 20, getBackground().darker().darker());
      skip.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            Goban.SKIPS++;
            if(Goban.SKIPS == 2) {
               Go.mainWindow.displayWinner();
               return;
            }
            Go.getGoban().nextPlayer();
         }
      });
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
         p1Timer = new Countdown();
         p2Timer = new Countdown();
         p2Timer.setForeground(Color.BLACK);
         gbc.gridx = 0;
         gbc.gridy = 1;
         add(p1Timer, gbc);
         add(new JLabel(new ImageIcon(new ImageIcon("img/icon.png").getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT))), gbc);
         gbc.gridx = 2;
         add(p2Timer, gbc);
         add(new JLabel(new ImageIcon(new ImageIcon("img/white.png").getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT))), gbc);
      }

      gbc.gridy++; gbc.gridx = 0; gbc.gridwidth = 3;
      add(new Label("Score:", 30, Color.WHITE), gbc);
      gbc.gridy++; gbc.gridx = 0; gbc.gridwidth = 1;
      add(scoreBlack, gbc);
      add(new JLabel(new ImageIcon(new ImageIcon("img/icon.png").getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT))), gbc);
      gbc.gridx = 2;
      add(scoreWhite, gbc);
      add(new JLabel(new ImageIcon(new ImageIcon("img/white.png").getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT))), gbc);

      gbc.gridx = 0; gbc.weighty = 1;
      gbc.gridy++;
      // gbc.anchor = GridBagConstraints.LAST_LINE_START;
      add(undo, gbc);
      gbc.gridx++;
      add(skip, gbc);
      gbc.gridx++;
      // gbc.anchor = GridBagConstraints.LAST_LINE_END;
      add(redo, gbc);
   }

   public static void setScore(int score) {
      if(Goban.player == State.BLACK) {
         scoreBlack.setText(Integer.toString(Integer.parseInt(scoreBlack.getText())+score));
      } else {
         scoreWhite.setText(Double.toString(Double.parseDouble(scoreWhite.getText())+score));
      }
   }
   public static void setScore(State color, int score) {
      if(color == State.BLACK) {
         scoreBlack.setText(Integer.toString(Integer.parseInt(scoreBlack.getText())+score));
      } else {
         scoreWhite.setText(Double.toString(Double.parseDouble(scoreWhite.getText())+score));
      }
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
