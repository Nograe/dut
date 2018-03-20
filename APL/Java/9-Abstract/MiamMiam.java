import java.time.LocalDate;

public class MiamMiam {
   public static void main(String[] args) {
      Magasin m1 = new Magasin("Magasin-1", "Paris");
      Usine u1 = new Usine("Usine-1", "Lille");
      Usine u3 = new Usine("Usine-3", "Amsterdam");
      SiegeMiamMiam Siege = new SiegeMiamMiam();
      Siege.ajouterUsine(u1);
      Siege.ajouterUsine(u3);
      Siege.ajouterMagasin(m1);
      System.out.println(Siege.toString());

      Produit P = u1.produire(1, LocalDate.of(2010, 4, 22));
      P.afficher();

      m1.ajouterObservateur(u1);
      m1.ajouterObservateur(u3);
      m1.supprimerObservateur(u1);
      m1.ajouterObservateur(new Usine("Usine-10", "Berlin"));
      m1.ajouterProduit(P);
      m1.ajouterProduit(new Choucroute(LocalDate.of(2002, 4, 2), new Usine("Usine-2", "Madrid")));
      m1.ajouterProduit(new Choucroute(LocalDate.of(2017, 4, 4), u1));
      m1.ajouterProduit(new Lasagne(LocalDate.of(2012, 4, 7), u3));
      m1.ajouterProduit(new Lasagne(LocalDate.of(2015, 4, 9), u3));
      m1.ajouterProduit(new Poelee(LocalDate.of(2009, 4, 20), u3));
      m1.ajouterProduit(new Poelee(LocalDate.of(2018, 4, 28), u3));
      m1.ajouterProduit(new Poelee(LocalDate.of(2016, 4, 29), new Usine("Usine-2", "Madrid")));
      m1.afficher();

      m1.vendre(CodeProduit.POELEE, 1, LocalDate.now());
      m1.vendre(CodeProduit.LASAGNES, 10, LocalDate.now());
      m1.afficher();
      m1.vendre(CodeProduit.LASAGNES, 9, LocalDate.now());
      m1.afficher();

      Siege.detruire(CodeProduit.CHOUCROUTE, LocalDate.now());
      m1.ajouterProduit(new Lasagne(LocalDate.of(2000, 1, 10), u3));
      m1.afficher();

      Siege.detruire(CodeProduit.LASAGNES, LocalDate.now());
   }
}
