import java.time.LocalDate;

public interface Observateur {
   void evenementProduitVendu(Magasin m, int codeProduit, LocalDate aujourdhui);
   String toString(boolean type);
}

interface Observable {
   void ajouterObservateur(Observateur o);
   void supprimerObservateur(Observateur o);
}
