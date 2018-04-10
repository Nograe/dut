import java.util.*;

public class Playliste {
  LinkedList<Titre> listeTitre;

  public Playliste () {
    this.listeTitre = new LinkedList<Titre>();
  }
  public LinkedList<Titre> getListe () {
    return this.listeTitre;
  }

  public void triAlpha() {
    if(listeTitre == null || listeTitre.isEmpty() || listeTitre.size() <= 1) {
      return;
    }

    LinkedList<Titre> clone = listeTitre;
    Titre t1;
    Titre t2;
    for (int i = 0; i < clone.size()-1; i++) {
      t1 = clone.get(i);
      t2 = clone.get(i+1);
      System.out.println("Compare: "+t1.getNom()+" | "+t2.getNom());
      if (t1.getNom().compareTo(t2.getNom()) > 0) {
        listeTitre.remove(t2);
        listeTitre.add(0, t2);
        System.out.println("Change");
      }
    }

    //Verification
    for (int i = 0; i < clone.size()-1; i++) {
      t1 = clone.get(i);
      t2 = clone.get(i+1);
      if (t1.getNom().compareTo(t2.getNom()) > 0) {
        triAlpha();
        return;
      }
    }
  }
  public void triArtiste() {
    if(listeTitre == null || listeTitre.isEmpty() || listeTitre.size() <= 1) {
      return;
    }

    LinkedList<Titre> clone = listeTitre;
    Titre t1;
    Titre t2;
    for (int i = 0; i < clone.size()-1; i++) {
      t1 = clone.get(i);
      t2 = clone.get(i+1);
      System.out.println("Compare: "+t1.getArtiste().getNom()+" | "+t2.getArtiste().getNom());
      if (t1.getArtiste().getNom().compareTo(t2.getArtiste().getNom()) == 0) {
      //TRI noms
      }
      if (t1.getArtiste().getNom().compareTo(t2.getArtiste().getNom()) > 0) {
        listeTitre.remove(t2);
        listeTitre.add(0, t2);
        System.out.println("Change");
      }
    }

    //Verification
    for (int i = 0; i < clone.size()-1; i++) {
      t1 = clone.get(i);
      t2 = clone.get(i+1);
      if (t1.getArtiste().getNom().compareTo(t2.getArtiste().getNom()) > 0) {
        triArtiste();
        return;
      }
    }
  }

  public static void main(String[] args) {
    // System.out.println("test");
    Playliste P = new Playliste();
    Artiste artiste1 = new Artiste("ABC");
    Album album1 = new Album("A1", artiste1);
    P.getListe().add(new Titre("Luis",artiste1, album1));

    Artiste artiste2 = new Artiste("ABC");
    Album album2 = new Album("A2", artiste2);
    P.getListe().add(new Titre("Test",artiste2, album2));

    Artiste artiste3 = new Artiste("ABC");
    Album album3 = new Album("A3", artiste3);
    P.getListe().add(new Titre("ABC",artiste3, album3));

    Artiste artiste4 = new Artiste("ABC");
    Album album4 = new Album("LOL", artiste3);
    P.getListe().add(new Titre("LOL",artiste4, album4));

    P.triArtiste();
    System.out.println(P.getListe().get(0).getArtiste().getNom());
    System.out.println(P.getListe().get(1).getArtiste().getNom());
    System.out.println(P.getListe().get(2).getArtiste().getNom());
    System.out.println(P.getListe().get(3).getArtiste().getNom());
  }
}
