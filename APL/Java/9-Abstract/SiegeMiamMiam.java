import java.util.*;
import java.time.LocalDate;

public class SiegeMiamMiam {
   LinkedList<Magasin> listeM;
   LinkedList<Usine> listeU;

   SiegeMiamMiam () {
      listeM = new LinkedList<Magasin>();
      listeU = new LinkedList<Usine>();
   }

   @Override
   public String toString () {
      String magasins = "";
      String usines = "";

      for(int i = 0; i < listeM.size(); i++) {
         magasins = magasins.concat(listeM.get(i).toString() + '\n');
      }
      for(int i = 0; i < listeU.size(); i++) {
         usines = usines.concat(listeU.get(i).toString() + '\n');
      }

      return String.format("Liste des magasins: \n%s \nListe des usines: \n%s", magasins, usines);
   }

   public void ajouterMagasin (Magasin M) {
      listeM.add(M);
   }
   public void ajouterUsine (Usine U) {
      listeU.add(U);
   }

   public float detruireProduit(int codeProduit, LocalDate aujourdhui) {
      float total = 0;
      for(int i = 0; i < listeM.size(); i++) {
         total += listeM.get(i).detruireProduit(codeProduit, aujourdhui);
      }
      return total;
   }
   public void detruire(int codeProduit, LocalDate aujourdhui) {
      System.out.println("\n\tManque à gagner: " + detruireProduit(codeProduit, aujourdhui));
   }
}
