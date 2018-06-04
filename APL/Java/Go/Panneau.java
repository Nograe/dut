import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Panneau extends JPanel {
   public void setSize(int width, int height) {
      setMinimumSize(new Dimension(width, height));
      setPreferredSize(new Dimension(width, height));
      setMaximumSize(new Dimension(width, height));
   }
}

class Button extends JButton implements ActionListener {
   private Color backgroundColor;

   public Button(Icon icon, int iconSize, Color backgroundColor) {
      super(icon);
      constructor(backgroundColor);
   }
   public Button(String text, int fontSize, Color backgroundColor) {
      super(text);
      setFont(new Font("Roboto", Font.PLAIN, fontSize), Color.WHITE);
      constructor(backgroundColor);
   }
   public void constructor(Color backgroundColor) {
      setContentAreaFilled(false);
      addActionListener(this);
      setBorderPainted(false);
      setFocusPainted(false);
      setBackground(backgroundColor);
      this.backgroundColor = backgroundColor;
   }
   public Button(String text, int fontSize, Color fontColor, Color backgroundColor) {
      this(text, fontSize, backgroundColor);
      setForeground(fontColor);
   }

   public void setSize(int width, int height) {
      setMinimumSize(new Dimension(width, height));
      setPreferredSize(new Dimension(width, height));
      setMaximumSize(new Dimension(width, height));
   }
   public void setFont(Font font, Color color) {
      setFont(font);
      setForeground(color);
   }
   public void setFontSize(int fontSize) {
      setFont(getFont().deriveFont((float)fontSize));
   }

   @Override
   protected void paintComponent(Graphics g) {
      if (getModel().isPressed()) {
         g.setColor(getBackground().darker());
      } else if (getModel().isRollover()) {
         g.setColor(getBackground().brighter());
      } else {
         g.setColor(backgroundColor);
      }
      g.fillRect(0, 0, getWidth(), getHeight());
      super.paintComponent(g);
   }

   public void actionPerformed(ActionEvent e) {
      if(e.getActionCommand() == "Jouer") {
         Go.mainWindow.chooseSize();
      }
      if(e.getActionCommand() == "9" || e.getActionCommand() == "13" || e.getActionCommand() == "19") {
         Go.mainWindow.chooseTimer(Integer.parseInt(e.getActionCommand()));
      }
      if(e.getActionCommand() == "Quitter") {
         Go.mainWindow.displayMenu();
      }
   }
}

class Label extends JLabel {
   public Label(String text, int fontSize, Color textColor) {
      super(text);
      setFont(new Font("Roboto", Font.PLAIN, fontSize));
      setForeground(textColor);
   }
   public void setFontSize(int fontSize) {
      setFont(this.getFont().deriveFont((float)fontSize));
   }
}
