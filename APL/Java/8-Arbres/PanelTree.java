import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;

class PanelTree extends JPanel {
   Font font;
   FontMetrics fm;
   NodeDisplay tree;
   static int WIDTH = 1500;
   static int HEIGHT = 0;

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
      g.setColor(new Color(255, 80, 80));
      paint(g, tree);
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
      g.fillOval(x-width/2, y-height, width+width/2, height+height/2);
      g.setColor(Color.BLACK);
      g.drawString(text, x-width/4, y);
      g.setColor(new Color(50, 150, 200));
   }

   NodeDisplay getCopy(NodeDisplay N, Node tree) {
      if(tree.filsGauche != null) {
         // N.filsGauche = new NodeDisplay();
         // System.out.println("Valeur: " + N.filsGauche.val);
         // N.filsGauche.val = tree.filsGauche.val;
         N.filsGauche.posx = N.posx - N.filsGauche.countPlaceGraphique(fm, "droit"); //Parent - offset droit
         N.filsGauche.posy = N.posy + NodeDisplay.espaceY;
         // if(N.filsGauche.val == 40)
         // System.out.println("Posx: " + N.filsGauche.posx + " Posy: " + N.filsGauche.posy + " PlaceGraphique: " + N.filsGauche.countPlaceGraphique(fm, "droit"));
         N.filsGauche = getCopy(N.filsGauche, tree.filsGauche);
      }
      if(tree.filsDroit != null) {
         // N.filsDroit = new NodeDisplay();
         // N.filsDroit.val = tree.filsDroit.val;
         N.filsDroit.posx = N.posx + N.filsDroit.countPlaceGraphique(fm, "gauche"); //Parent + offset gauche
         N.filsDroit.posy = N.posy + NodeDisplay.espaceY;
         // System.out.println("Posx: " + N.filsDroit.posx + " Posy: " + N.filsDroit.posy + " Valeur: " + N.filsDroit.val + " PlaceGraphique: " + N.filsDroit.countPlaceGraphique(fm, "gauche"));
         N.filsDroit = getCopy(N.filsDroit, tree.filsDroit);
      }
      // System.out.println("");
      if(N.posy > HEIGHT)
      HEIGHT = N.posy;
      return N;
   }

   NodeDisplay getDisplayInfo(Node tree) {
      //Position de la racine
      NodeDisplay N = new NodeDisplay();
      N.posx = WIDTH/2;
      N.posy = NodeDisplay.espaceY;
      N.val = tree.val;
      // System.out.println("Posx: " + N.posx + " Posy: " + N.posy + " Valeur: " + N.val);

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
         n.filsGauche.val = tree.filsGauche.val;
         init(n.filsGauche, tree.filsGauche);
      }
      if(tree.filsDroit != null) {
         // System.out.println("Ajout branche droit");
         n.filsDroit = new NodeDisplay();
         n.filsDroit.val = tree.filsDroit.val;
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
