import java.util.*;

class Noeud {
  char clef;
  ArrayList<Noeud> fils;
  Noeud(char clef) {
    fils = new ArrayList<Noeud>();
    this.clef = clef;
  }

  // public ArrayList<Noeud> getFils() {
  //   return fils;
  // }

  public boolean containsClef(char clef) {
    for (int i = 0; i < fils.size(); i++) {
      if(fils.get(i).clef == clef) {
        return true;
      }
    }
    return false;
  }

  public Noeud getNode(char clef) {
    for (int i = 0; i < fils.size(); i++) {
      if(fils.get(i).clef == clef) {
        return fils.get(i);
      }
    }
    return null;
  }
}

public class ArbrePrefix {
  private Noeud racine;
  public ArbrePrefix() {
    racine = new Noeud(' ');
  }
  // Renvoie true si et seulement si le mot fait partie de l'arbre.
  public boolean recherche(String mot) {
    return recherche(mot+'F', racine);
  }
  public boolean recherche(String mot, Noeud current) {
    if (mot.length() <= 0 || mot == null || current == null) {
      return false;
    }
    char c = mot.charAt(0);
    if (current.containsClef('F') && c == 'F' && mot.length() == 1) {
      return true;
    }
    if (current.containsClef(c)) {
      System.out.println("La clef '"+c+"' est contenue dans '"+current.clef+"'");
      return recherche(mot.substring(1, mot.length()), current.getNode(c));
    }
    else {
      System.out.println("La clef '"+c+"' n'est pas contenue dans '"+current.clef+"'");
      return false;
    }
  }

  // Doit supprimer le mot. Renvoie true si un mot a ete supprime et false sinon.
  public boolean supprimer(String mot) {
    return supprimer(mot+'F', racine);
  }
  private boolean supprimer(String mot, Noeud current) {
    // if (supprimer(mot, current)) {
    //   return true;
    // }
    if (mot.length() <= 0 || mot == null || current == null) {
      return false;
    }
    char c = mot.charAt(0);
    // System.out.println("Mot a supprimer: "+mot+" sur le node '"+current.clef+"'");
    // System.out.println(current.getNode(c).fils.size());
    if (current.containsClef('F') && c == 'F') {
      return true;
    }
    // System.out.println(current.containsClef('r'));
    if (current.containsClef(c) && current.fils.size() == 1) {
      System.out.println("Le node: '"+current.clef+"' ne contient qu'un node: "+c);
      if (supprimer(mot.substring(1, mot.length()), current.getNode(c))) {
        current.fils.remove(current.getNode(c));
        System.out.println("\t\tCe node n'est rattache a aucun nodes");
        return true;
      }
    }
    System.out.println("\tCe node est rattache a d'autres nodes");
    return supprimer(mot.substring(1, mot.length()), current.getNode(c));
  }

  // Doit ajouter le mot.
  public void ajouter(String mot) {
    ajouter(mot+'F', racine);
  }
  private void ajouter(String mot, Noeud current) {
    if (mot.length() <= 0 || mot == null || current == null) {
      return;
    }
    char c = mot.charAt(0);
    System.out.println("Mot a ajouter: "+mot);
    if (current.containsClef(c) && c != 'F') {
      System.out.println("Il existe deja un node avec le char: "+c+" sur le node "+current.clef);
      ajouter(mot.substring(1, mot.length()), current.getNode(c));
      return;
      // current.getNode(c).fils.add(new Noeud(c));
    }
    else {
      System.out.println("Il n'existe pas de node avec le char: "+c+" sur le node "+current.clef);
      current.fils.add(new Noeud(c));
    }
    ajouter(mot.substring(1, mot.length()), current.getNode(c));
    return;
  }

  public static void main(String[] args) {
    ArbrePrefix tree = new ArbrePrefix();
    tree.ajouter("java");
    System.out.println();
    tree.ajouter("jar");
    System.out.println();
    // System.out.println(tree.recherche("jar"));
    // System.out.println();
    System.out.println(tree.supprimer("java"));
    System.out.println();
    System.out.println(tree.recherche("jar"));


    // System.out.println(tree.racine.getNode('j').getNode('a').fils.size());
  }
}
