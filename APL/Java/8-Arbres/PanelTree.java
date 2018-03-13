import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;

class PanelTree extends JPanel {
   Font font;
   FontMetrics fm;
   NodeDisplay tree;

   public PanelTree(Node N) {
      super();
      font = new Font("Helvetica", Font.PLAIN, 12);
      setFont(font);
      fm = getFontMetrics(font);

      tree = getDisplayInfo(N);
   }

   @Override
   public void paintComponent(Graphics g) {
      // On peint la racine
      NodeDisplay tmp = tree;
      g.setColor(new Color(239, 124, 209));
      paint(g, tmp);
   }

   public void paint(Graphics g, NodeDisplay node) {
      drawNode(g, node.posx, node.posy, Integer.toString(node.val));

      if(node.filsGauche != null) {
         g.drawLine(node.posx, node.posy, node.filsGauche.posx, node.filsGauche.posy);
         paint(g, node.filsGauche);
      }
      if(node.filsDroit != null) {
         g.drawLine(node.posx, node.posy, node.filsDroit.posx, node.filsDroit.posy);
         paint(g, node.filsDroit);
      }
   }

   public void drawNode(Graphics g, int x, int y, String text) {
      int width = fm.stringWidth(text);
      int height = fm.getMaxDescent() + fm.getMaxAscent();
      g.fillOval(x-width/4, y-height, width+width/2, height+height/2);
      g.setColor(Color.BLACK);
      g.drawString(text, x, y);
      g.setColor(new Color(52, 102, 163));
   }

   NodeDisplay getCopy(NodeDisplay N, Node tree) {
      if(tree.filsGauche != null) {
         // N.filsGauche = new NodeDisplay();
         N.filsGauche.val = tree.filsGauche.val;
         N.filsGauche.posx = N.posx - N.filsGauche.countPlaceGraphique(fm, "droit"); //Parent - offset droit
         N.filsGauche.posy = N.posy + NodeDisplay.espaceY;
         System.out.println("Posx: " + N.filsGauche.posx + " Posy: " + N.filsGauche.posy + " Valeur: " + N.filsGauche.val);
         N.filsGauche = getCopy(N.filsGauche, tree.filsGauche);
      }
      if(tree.filsDroit != null) {
         // N.filsDroit = new NodeDisplay();
         N.filsDroit.val = tree.filsDroit.val;
         N.filsDroit.posx = N.posx + N.filsDroit.countPlaceGraphique(fm, "gauche"); //Parent + offset gauche
         N.filsDroit.posy = N.posy + NodeDisplay.espaceY;
         System.out.println("Posx: " + N.filsDroit.posx + " Posy: " + N.filsDroit.posy + " Valeur: " + N.filsDroit.val);
         N.filsDroit = getCopy(N.filsDroit, tree.filsDroit);
      }
      System.out.println("");
      return N;
   }

   NodeDisplay getDisplayInfo(Node tree) {
      //Position de la racine
      NodeDisplay N = new NodeDisplay();
      N.posx = 1500/2;
      N.posy = NodeDisplay.espaceY;
      N.val = tree.val;
      System.out.println("Posx: " + N.posx + " Posy: " + N.posy + " Valeur: " + N.val);

      init(N, tree);
      return getCopy(N, tree);
   }

   void init(NodeDisplay n, Node tree) {
      // if(tree.filsGauche != null && tree.filsDroit != null) {
      //    n.filsGauche = new NodeDisplay();
      //    n.filsDroit = new NodeDisplay();
      //    n = init(n.filsGauche, tree.filsGauche);
      //    n = init(n.filsDroit, tree.filsDroit);
      // }
      if(tree.filsGauche != null) {
         // System.out.println("Ajout branche gauche");
         n.filsGauche = new NodeDisplay();
         init(n.filsGauche, tree.filsGauche);
      }
      if(tree.filsDroit != null) {
         // System.out.println("Ajout branche droit");
         n.filsDroit = new NodeDisplay();
         init(n.filsDroit, tree.filsDroit);
      }
      // return n;
   }

   int getOffsetGauche() {
      return tree.filsGauche.countPlaceGraphique(fm);
   }
   int getOffsetDroit() {
      return tree.filsDroit.countPlaceGraphique(fm);
   }
}
