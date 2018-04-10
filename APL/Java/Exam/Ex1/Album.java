import java.util.*;

public class Album {
  String nom;
  Artiste artiste;
  LinkedList<Titre> listeTitre;

  public Album (String nom, Artiste artiste) {
    this.nom = nom;
    this.artiste = artiste;
    this.listeTitre = new LinkedList<Titre>();
  }
  public String getNom() {
    return this.nom;
  }
  public Artiste getArtiste() {
    return this.artiste;
  }
  public LinkedList<Titre> getListe () {
    return this.listeTitre;
  }
  public void setNom(String nom) {
    this.nom = nom;
  }
  public void setArtiste(Artiste artiste) {
    this.artiste = artiste;
  }
}
