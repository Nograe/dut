import java.util.*;

public class Titre {
  String nom;
  Artiste artiste;
  Album album;

  public Titre (String nom, Artiste artiste, Album album) {
    this.nom = nom;
    this.artiste = artiste;
    this.album = album;
  }
  public String getNom() {
    return this.nom;
  }
  public Artiste getArtiste() {
    return this.artiste;
  }
  public Album getAlbum() {
    return this.album;
  }
  public void setNom(String nom) {
    this.nom = nom;
  }
  public void setArtiste(Artiste artiste) {
    this.artiste = artiste;
  }
  public void setAlbum(Album album) {
    this.album = album;
  }
}
