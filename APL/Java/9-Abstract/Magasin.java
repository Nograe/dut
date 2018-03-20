import java.time.LocalDate;
import java.util.*;
import java.time.format.DateTimeFormatter;

public class Magasin implements Observable {
   private String nom;
   private String ville;
   LinkedList<Produit> liste;
   LinkedList<Observateur> listeObs;

   Magasin (String nom, String ville) {
      this.nom = nom;
      this.ville = ville;
      liste = new LinkedList<Produit>();
      listeObs = new LinkedList<Observateur>();
   }

   @Override
   public String toString () {
      String produits = "";
      String observateurs = "";

      for(int i = 0; i < liste.size(); i++) {
         produits = produits.concat("\n\t" + liste.get(i).getClass().getName() + ':');
         produits = produits.concat(liste.get(i).toString(true));
         if(liste.size() - i > 1)
         produits = produits.concat("\n");
      }
      for(int i = 0; i < listeObs.size(); i++) {
         observateurs = observateurs.concat(listeObs.get(i).toString(true));
         if(listeObs.size() - i > 1)
         observateurs = observateurs.concat("\n");
      }

      return String.format("Localisation: %s \nProduits disponibles: %d %s \nObservateurs: %s", ville, liste.size(), produits, observateurs);
   }
   public void afficher () {
      System.out.println("------------------ " + "\033[0;34m" + getNom() + "\033[0m" + " ------------------\n" + toString() + "\n---------------------------------------------\n");
   }

   public void setNom (String nom) {
      this.nom = nom;
   }
   public void setVille (String ville) {
      this.ville = ville;
   }
   public String getNom () {
      return nom;
   }
   public String getVille () {
      return ville;
   }
   public LinkedList<Produit> getListe () {
      return liste;
   }
   public LinkedList<Observateur> getListeObs () {
      return listeObs;
   }

   public void ajouterObservateur (Observateur O) {
      listeObs.add(O);
   }

   public void supprimerObservateur (Observateur O) {
      listeObs.remove(O);
   }

   public void ajouterProduit (Produit P) {
      if(liste.size() == 0) {
         liste.add(P);
         return;
      }

      if(P.getDateLimite().isAfter(liste.getLast().getDateLimite())) {
         liste.addLast(P);
         return;
      }

      Iterator<Produit> iterator = liste.iterator();
      int pos = -1;
      Produit tmp;

      do {
         pos++;
         tmp = iterator.next();
      } while(P.getDateLimite().isAfter(tmp.getDateLimite()) && iterator.hasNext());
      liste.add(pos, P);
   }

   public float vendreProduit (int codeProduit, int quantite, LocalDate aujourdhui) {
      Iterator<Produit> iterator = liste.iterator();
      if (!iterator.hasNext())
      return 0;

      int i = 0, loop = 0, end = liste.size();
      float total = 0;
      while(i != quantite) {
         Produit P = iterator.next();
         if (codeProduit == CodeProduit.CHOUCROUTE && P instanceof Choucroute && P.getDateLimite().isAfter(aujourdhui)) {
            iterator.remove();
            total += P.getPrixVente();
            i++;
         }
         if (codeProduit == CodeProduit.LASAGNES && P instanceof Lasagne && P.getDateLimite().isAfter(aujourdhui)) {
            iterator.remove();
            total += P.getPrixVente();
            i++;
         }
         if(codeProduit == CodeProduit.POELEE && P instanceof Poelee && P.getDateLimite().isAfter(aujourdhui)) {
            iterator.remove();
            total += P.getPrixVente();
            i++;
         }
         loop++;
         if(loop >= end) {
            break;
         }
      }

      if (codeProduit == CodeProduit.CHOUCROUTE) System.out.println("Vente de: " + i + " Choucroute");
      if (codeProduit == CodeProduit.LASAGNES) System.out.println("Vente de: " + i + " Lasagne");
      if(codeProduit == CodeProduit.POELEE) System.out.println("Vente de: " + i + " Poelee");

      for(i = 0; i < listeObs.size(); i++) {
         listeObs.get(i).evenementProduitVendu(this, codeProduit, aujourdhui);
      }

      return total;
   }
   public void vendre (int codeProduit, int quantite, LocalDate aujourdhui) {
      System.out.println("\tArgent obtenu: " + vendreProduit(codeProduit, quantite, aujourdhui));
   }

   public float detruireProduit(int codeProduit, LocalDate aujourdhui) {
      Iterator<Produit> iterator = liste.iterator();
      if (!iterator.hasNext())
      return 0;

      int i = 0;
      float total = 0;
      do {
         Produit P = iterator.next();
         if (codeProduit == CodeProduit.CHOUCROUTE && P instanceof Choucroute && P.getDateLimite().isBefore(aujourdhui)) {
            iterator.remove();
            total += P.getPrixVente();
            i++;
         }
         if (codeProduit == CodeProduit.LASAGNES && P instanceof Lasagne && P.getDateLimite().isBefore(aujourdhui)) {
            iterator.remove();
            total += P.getPrixVente();
            i++;
         }
         if(codeProduit == CodeProduit.POELEE && P instanceof Poelee && P.getDateLimite().isBefore(aujourdhui)) {
            iterator.remove();
            total += P.getPrixVente();
            i++;
         }
      } while(iterator.hasNext());

      if (codeProduit == CodeProduit.CHOUCROUTE) System.out.print("Destruction de: " + i + " Choucroute");
      if (codeProduit == CodeProduit.LASAGNES) System.out.print("Destruction de: " + i + " Lasagne");
      if(codeProduit == CodeProduit.POELEE) System.out.print("Destruction de: " + i + " Poelee");

      for(i = 0; i < listeObs.size(); i++) {
         listeObs.get(i).evenementProduitVendu(this, codeProduit, aujourdhui);
      }

      return total;
   }
}
