import java.util.*;

public class Artiste {
  String nom;
  LinkedList<Album> listeAlbum;

  public Artiste (String nom) {
    this.nom = nom;
    this.listeAlbum = new LinkedList<Album>();
  }
  public String getNom() {
    return this.nom;
  }
  public LinkedList<Album> getListe () {
    return this.listeAlbum;
  }
  public void setNom(String nom) {
    this.nom = nom;
  }
}
