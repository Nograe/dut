import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Main {
   static Fenetre window;

   public static void main(String[] args) {
      if(args.length != 0)
      window = new Fenetre(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
      else
      window = new Fenetre(10, 10);

      window.Main.setBackground(new Color(20, 100, 120));
      window.ControlPanel.setBackground(new Color(20, 120, 100));
      // window.repaint(); //debug
      // window.Main.repaint();
      // window.ControlPanel.repaint();
   }
}
