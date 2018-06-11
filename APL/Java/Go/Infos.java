import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Infos extends JPanel implements ComponentListener {
   public Countdown p1Timer;
   public Countdown p2Timer;
   public static Label scoreBlack;
   public static Label scoreWhite;

   private Button redo;
   private Button undo;

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
      undo = new Button(undoIcon, 20, getBackground().darker().darker());
      ImageIcon redoIcon = new ImageIcon(new ImageIcon("img/redo.png").getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT));
      redo = new Button(redoIcon, 20, getBackground().darker().darker());
      skip.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            Goban.SKIPS++;
            if(Goban.SKIPS == 2) {
               Go.getGoban().finish();
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
         gbc.gridwidth = 3;
         gbc.gridx = 0;
         gbc.gridy = 1;
         add(p1Timer, gbc);
         add(new JLabel(new ImageIcon(new ImageIcon("img/black.png").getImage().getScaledInstance(90, 90, Image.SCALE_DEFAULT))), gbc);
         gbc.gridy = 2;
         add(p2Timer, gbc);
         add(new JLabel(new ImageIcon(new ImageIcon("img/white.png").getImage().getScaledInstance(90, 90, Image.SCALE_DEFAULT))), gbc);
      }

      gbc.gridy++; gbc.gridx = 0; gbc.gridwidth = 3;
      add(new Label("Score:", 30, Color.WHITE), gbc);
      gbc.gridy++; gbc.gridx = 0; gbc.gridwidth = 1;
      add(scoreBlack, gbc);
      add(new JLabel(new ImageIcon(new ImageIcon("img/black.png").getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT))), gbc);
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

   public static void setScore() {
      Stone stones[][] = Go.getGoban().getStones();
      int scoreB = 0, scoreW = 0;
      for (Stone[] row : stones) {
         for (Stone stone : row) {
            if(stone == null) continue;
            if(stone.color == State.BLACK || stone.color == State.BLACK_T) scoreB++;
            if(stone.color == State.WHITE || stone.color == State.WHITE_T) scoreW++;
         }
      }
      setScore(State.BLACK, scoreB);
      setScore(State.WHITE, scoreW);
   }
   public static void setScore(int score) {
      if(Goban.player == State.BLACK) {
         scoreBlack.setText(Integer.toString(score));
      } else {
         scoreWhite.setText(Double.toString(7.5 + score));
      }
   }
   public static void setScore(State color, int score) {
      if(color == State.BLACK) {
         scoreBlack.setText(Integer.toString(score));
      } else {
         scoreWhite.setText(Double.toString(7.5 + score));
      }
   }

   public void finish() {
      removeAll();

      Button quit = new Button("Quitter", 20, getBackground().darker().darker());
      GridBagConstraints gbc = new GridBagConstraints();
      gbc.insets = new Insets(15, 0, 15, 0);
      gbc.gridy = gbc.gridx = 0; gbc.gridwidth = 3;
      add(quit, gbc);

      gbc.gridy++;
      add(new Label("Retirez les groupes morts", 18, Color.WHITE), gbc);

      Button captureB = new Button("Capturer", 20, new Color(200, 200, 200), new Color(20, 20, 20));
      Button captureW = new Button("Capturer", 20, new Color(20, 20, 20), new Color(200, 200, 200));
      captureB.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            Goban.player = State.BLACK;
            Goban.gameState = (Goban.gameState == GameState.CAPTURE) ? GameState.END : GameState.CAPTURE;
            GobanGrid.hoverStone = null;
            Goban.grid.repaint();
         }
      });
      captureW.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            Goban.player = State.WHITE;
            Goban.gameState = (Goban.gameState == GameState.CAPTURE) ? GameState.END : GameState.CAPTURE;
            GobanGrid.hoverStone = null;
            Goban.grid.repaint();
         }
      });
      gbc.gridy++; gbc.gridwidth = 1;
      add(captureB, gbc);
      gbc.gridx = 2;
      add(captureW, gbc);
      Button suivant = new Button("Suivant", 20, new Color(50, 120, 180));
      suivant.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            territories();
         }
      });
      gbc.gridx = 0; gbc.gridy++;
      add(undo, gbc);
      gbc.gridx = 2;
      add(redo, gbc);
      gbc.gridx = 0; gbc.gridy++; gbc.gridwidth = 3;
      add(suivant, gbc);

      Goban.grid.repaint();
      repaint();
      revalidate();
   }
   public void territories() {
      Stone[][] backupStones = Goban.deepCopy(Goban.getStones());
      Stone[][] stones = Goban.getStones();
      for (int y = 0; y < stones[0].length; y++) {
         for (int x = 0; x < stones.length; x++) {
            if(Go.getGoban().grid.deadStones[x][y]) stones[x][y] = null;
         }
      }
      for (int y = 0; y < stones[0].length; y++) {
         for (int x = 0; x < stones.length; x++) {
            if(stones[x][y] != null) continue;
            stones[x][y] = new Stone(State.EMPTY, x, y);
            stones[x][y].calculateTerritory();
         }
      }

      removeAll();
      GobanGrid.hoverStone = null;
      Goban.gameState = GameState.TERRITORY;
      Button retour = new Button("Retour", 20, getBackground().darker().darker());
      retour.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            Goban.setStones(backupStones);
            Goban.gameState = GameState.END;
            finish();
         }
      });
      GridBagConstraints gbc = new GridBagConstraints();
      gbc.insets = new Insets(15, 0, 15, 0);
      gbc.gridy = gbc.gridx = 0; gbc.gridwidth = 3;
      add(retour, gbc);

      Button suivant = new Button("Suivant", 20, new Color(50, 120, 180));
      suivant.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            Go.mainWindow.displayWinner();
         }
      });
      gbc.gridx = 0; gbc.gridy++;
      add(suivant, gbc);
      setScore();

      Goban.grid.repaint();
      repaint();
      revalidate();
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

enum GameState {
   START, END, CAPTURE, TERRITORY
}
