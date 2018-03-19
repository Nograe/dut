import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;

class NodeDisplay {
   int posx;
   int posy;
   int val;

   public static int espaceX = 50;
   public static int espaceY = 50;

   NodeDisplay filsGauche;
   NodeDisplay filsDroit;

   public NodeDisplay() {
   }

   public int countPlaceGraphique(FontMetrics F, String dir) {
      if(dir == "gauche" && filsGauche != null) {
         // System.out.println("Offset gauche");
         return (filsGauche.countPlaceGraphique(F) + espaceX + F.stringWidth(Integer.toString(val)));
      }
      if(dir == "droit" && filsDroit != null) {
         // System.out.println("    PlaceGraphiqueFilsDroit: " + filsDroit.countPlaceGraphique(F) + " + " + espaceX + " + " + F.stringWidth(Integer.toString(val)));
         return (filsDroit.countPlaceGraphique(F) + espaceX + F.stringWidth(Integer.toString(val)));
      }
      return F.stringWidth(Integer.toString(val)) + espaceX/2;
   }

   public int countPlaceGraphique(FontMetrics F) {
      if(filsGauche != null && filsDroit != null) {
         // System.out.println("        Val:" + val + " PlaceGraphiqueFilGauche: " + filsGauche.countPlaceGraphique(F) + " PlaceGraphiqueFilsDroit: " + filsDroit.countPlaceGraphique(F));
         return (filsGauche.countPlaceGraphique(F) + filsDroit.countPlaceGraphique(F) + espaceX + F.stringWidth(Integer.toString(val)));
      }
      if(filsGauche != null && filsDroit == null) {
         return (filsGauche.countPlaceGraphique(F) + espaceX + F.stringWidth(Integer.toString(val)));
      }
      if(filsGauche == null && filsDroit != null) {
         return (filsDroit.countPlaceGraphique(F) + espaceX + F.stringWidth(Integer.toString(val)));
      }
      // System.out.println("           /!\\       " + Integer.toString(val) + " : " + F.stringWidth(Integer.toString(val)));
      return F.stringWidth(Integer.toString(val));
   }
}
