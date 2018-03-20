import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.LinkedList;
import java.lang.Math;

public abstract class Produit {
   private float poids;
   private float coutFabrication;
   private float prixVente;
   private LocalDate dateLimite;
   private Usine origine;

   Produit (float pds, float cF, float pV, LocalDate dL, Usine provenance) {
      poids = Math.max(0f, pds);
      coutFabrication = Math.max(0f, cF);
      prixVente = Math.max(0, pV);
      dateLimite = dL;

      origine = new Usine(provenance.getNom(), provenance.getVille());
   }

   @Override
   public String toString () {
      return String.format("Poids: %f \nCoût de fabrication: %f \nPrix de vente: %f \nDate limite: %s \nOrigine: \n\t %s \n\t Localisation: %s", poids, coutFabrication, prixVente, dateLimite.format(DateTimeFormatter.ofPattern("dd/MM/yyyy")), origine.getNom(), origine.getVille());
   }
   public String toString(boolean type) {
      String color = "";
      if(dateLimite.isBefore(LocalDate.now())) color = color.concat("\033[1;31m");
      else color = color.concat("\033[0;32m");
      return String.format("\n\tPoids: %f \n\tCoût de fabrication: %f \n\tPrix de vente: %f \n\tDate limite: " + color + "%s" + "\033[0m" + " \n\tOrigine: \n\t\t %s \n\t\t Localisation: %s", poids, coutFabrication, prixVente, dateLimite.format(DateTimeFormatter.ofPattern("dd/MM/yyyy")), origine.getNom(), origine.getVille());
   }
   public void afficher () {
      System.out.println("------------------ " + "\033[0;32m" + getClass().getName() + "\033[0m" + " ------------------\n" + toString(true) + "\n---------------------------------------------\n");
   }

   public float getPoids () {
      return poids;
   }
   public float getCoutFabrication () {
      return coutFabrication;
   }
   public float getPrixVente () {
      return prixVente;
   }
   public LocalDate getDateLimite () {
      // return dateLimite;
      if(this instanceof Poelee) return dateLimite.plusMonths((long)Math.pow(origine.getNom().length(), 2));
      else if(this instanceof Lasagne && dateLimite.getMonthValue() == 1 && dateLimite.getDayOfMonth() == 10) return dateLimite.plusYears(69);
      else if(this instanceof Lasagne && dateLimite.getMonthValue() == 6) return dateLimite.plusMonths(9);
      else return dateLimite;
   }
   public void setPrixVente (float pV) {
      prixVente = Math.max(0f, pV);
   }
}

class Choucroute extends Produit {
   Choucroute (LocalDate dL, Usine provenance) {
      super(0.240f, 1.8f, 3.4f, dL.plusYears(5), provenance);
   }
}

class Lasagne extends Produit {
   Lasagne (LocalDate dL, Usine provenance) {
      super(0.280f, 0.3f, 3.2f, dL.plusYears(3), provenance);
   }
}

class Poelee extends Produit {
   Poelee (LocalDate dL, Usine provenance) {
      super(0.150f, 2f, 3.9f, dL.plusYears(3), provenance);
   }
}
