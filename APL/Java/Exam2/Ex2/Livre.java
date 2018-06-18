public class Livre {
   private String titre;
   private String auteur;
   private float prix;

   public Livre(String titre, String auteur, float prix) {
      this.titre = titre;
      this.auteur = auteur;
      this.prix = prix;
   }
   public String getTitre() {
      return titre;
   }
   public String getAuteur() {
      return auteur;
   }
   public float getPrix() {
      return prix;
   }

   @Override
   public String toString() {
      return titre;
   }
}
