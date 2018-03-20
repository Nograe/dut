import java.util.*;
import java.time.LocalDate;

public class Usine implements Observateur {
   private String nom;
   private String ville;

   Usine (String nom, String ville) {
      this.nom = nom;
      this.ville = ville;
   }

   @Override
   public String toString () {
      return String.format("Nom de l'usine: %s \nLocalisation: %s", nom, ville);
   }
   @Override
   public String toString (boolean type) {
      return String.format("\n\t%s: \n\tLocalisation: %s", nom, ville);
   }

   public void setNom (String nom) {
      this.nom = nom;
   }
   public void setVille (String nom) {
      this.ville = ville;
   }
   public String getNom () {
      return nom;
   }
   public String getVille () {
      return ville;
   }

   public void evenementProduitVendu(Magasin m, int codeProduit, LocalDate aujourdhui) {
      Iterator<Produit> iterator = m.getListe().iterator();
      Produit P;

      if(!iterator.hasNext()) {
         for(int i = 0; i < 10; i++) {
            P = produire(codeProduit, aujourdhui);
            m.ajouterProduit(P);
         }
         return;
      }

      do {
         P = iterator.next();
         if (codeProduit == CodeProduit.CHOUCROUTE && P instanceof Choucroute && P.getDateLimite().isAfter(aujourdhui)) {
            return;
         }
         if (codeProduit == CodeProduit.LASAGNES && P instanceof Lasagne && P.getDateLimite().isAfter(aujourdhui)) {
            return;
         }
         if(codeProduit == CodeProduit.POELEE && P instanceof Poelee && P.getDateLimite().isAfter(aujourdhui)) {
            return;
         }
      } while (iterator.hasNext());

      if (codeProduit == CodeProduit.CHOUCROUTE) System.out.println("\tProduction de 10 Choucroute à: " + nom);
      if (codeProduit == CodeProduit.LASAGNES) System.out.println("\tProduction de 10 Lasagne à: " + nom);
      if(codeProduit == CodeProduit.POELEE) System.out.println("\tProduction de 10 Poelee à: " + nom);
      for(int i = 0; i < 10; i++) {
         P = produire(codeProduit, aujourdhui);
         m.ajouterProduit(P);
      }
   }

   public Produit produire (int codeProduit, LocalDate aujourdhui) {
      Produit P;

      if(codeProduit == CodeProduit.CHOUCROUTE)
      P = new Choucroute(aujourdhui, this);
      else if(codeProduit == CodeProduit.LASAGNES)
      P = new Lasagne(aujourdhui, this);
      else
      P = new Poelee(aujourdhui, this);

      return P;
   }
}
