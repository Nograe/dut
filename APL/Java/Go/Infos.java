import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Infos extends JPanel implements ComponentListener {
   Panneau hist = new Panneau();

   public Infos() {
      addComponentListener(this);
      setBackground(new Color(60, 125, 100));
      setLayout(new GridBagLayout());
      displayInfos();
   }

   public void displayInfos() {
      Button quit = new Button("Quitter", 20, getBackground().darker().darker());
      Button retour = new Button("Annuler", 20, getBackground().darker().darker());
      Button reset = new Button("Revenir", 20, getBackground().darker().darker());
      GridBagConstraints gbc = new GridBagConstraints();

      gbc.insets = new Insets(15, 5, 15, 5);
      gbc.gridy = 0;
      add(quit, gbc);
      gbc.gridy++;
      hist.setBackground(new Color(50, 100, 80));
      hist.setSize(100, (int)Go.mainWindow.GobanWindow.getHeight()-200);
      add(hist, gbc);
      gbc.gridy++;
      add(retour, gbc);
      add(reset, gbc);
   }

   public void componentResized(ComponentEvent e) {
      hist.setSize(getWidth()-80, getHeight()-150);
   }
   public void componentMoved(ComponentEvent e) {
   }
   public void componentHidden(ComponentEvent e) {
   }
   public void componentShown(ComponentEvent e) {
   }
}
