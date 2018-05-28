import java.util.*;
import java.awt.*;
import javax.swing.*;

public class Panneau extends JPanel {
   public void setSize(int width, int height) {
      setMinimumSize(new Dimension(width, height));
      setPreferredSize(new Dimension(width, height));
      setMaximumSize(new Dimension(width, height));
   }
}

class Button extends JButton {
   public Button(String text) {
      super(text);
   }
   public void setSize(int width, int height) {
      setMinimumSize(new Dimension(width, height));
      setPreferredSize(new Dimension(width, height));
      setMaximumSize(new Dimension(width, height));
   }
   public void setText(Font font, Color color) {
      setFont(font);
      setForeground(color);
      setBorderPainted(false);
      setFocusPainted(false);
   }
}
