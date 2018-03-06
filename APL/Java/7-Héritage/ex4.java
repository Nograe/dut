import java.lang.*;
import java.util.*;

class Vehicule {
   private String marque;
   private String modele;
   private String couleur;

   Vehicule (String arg1, String arg2, String arg3) {
      marque = arg1;
      modele = arg2;
      couleur = arg3;
   }

   String getMarque() {
      return marque;
   }
   String getModele() {
      return modele;
   }
   String getCouleur() {
      return couleur;
   }
}

class Auto extends Vehicule {
   Auto(String arg1, String arg2, String arg3) {
      super(arg1, arg2, arg3);
   }

   @Override
   public boolean equals (Object O) {
      if(O instanceof Auto)
      return true;
      else
      return false;
   }

   String getType () {
      return "Auto";
   }
}

class Moto extends Vehicule {
   Moto(String arg1, String arg2, String arg3) {
      super(arg1, arg2, arg3);
   }

   @Override
   public boolean equals (Object O) {
      if(O instanceof Moto)
      return true;
      else
      return false;
   }

   String getType () {
      return "Moto";
   }
}

class Camion extends Vehicule {
   Camion(String arg1, String arg2, String arg3) {
      super(arg1, arg2, arg3);
   }

   @Override
   public boolean equals (Object O) {
      if(O instanceof Camion)
      return true;
      else
      return false;
   }

   String getType () {
      return "Camion";
   }
}

class Collection {
   ArrayList<Vehicule> liste = new ArrayList<Vehicule>();

   void ajouter (Vehicule V) {
      liste.add(V);
   }

   void afficher () {
      System.out.println("Liste: ");
      for(int i = 0; i < liste.size(); i++) {
         System.out.print(liste.get(i).getMarque() + " ");
         System.out.print(liste.get(i).getModele() + " ");
         System.out.println(liste.get(i).getCouleur());
      }
   }

   void searchMarque (String mar) {
      System.out.println("Recherche: ");
      for(int i = 0; i < liste.size(); i++) {
         if(liste.get(i).getMarque() == mar) {
            System.out.print(liste.get(i).getMarque() + " ");
            System.out.print(liste.get(i).getModele() + " ");
            System.out.println(liste.get(i).getCouleur());
         }
      }
   }

   void searchModele (String mod) {
      System.out.println("Recherche: ");
      for(int i = 0; i < liste.size(); i++) {
         if(liste.get(i).getModele() == mod) {
            System.out.print(liste.get(i).getMarque() + " ");
            System.out.print(liste.get(i).getModele() + " ");
            System.out.println(liste.get(i).getCouleur());
         }
      }
   }

   void delete (String mar, String mod, String cou) {
      for(int i = 0; i < liste.size(); i++) {
         if(liste.get(i).getMarque() == mar && liste.get(i).getModele() == mod && liste.get(i).getCouleur() == cou) {
            System.out.print("Supprimé: ");
            System.out.print(liste.get(i).getMarque() + " ");
            System.out.print(liste.get(i).getModele() + " ");
            System.out.println(liste.get(i).getCouleur());
            liste.remove(i);
         }
      }
   }

   void delete (String type, String mar, String mod, String cou) {
      for(int i = 0; i < liste.size(); i++) {
         if(liste.get(i).getClass().getName() == type && liste.get(i).getMarque() == mar && liste.get(i).getModele() == mod && liste.get(i).getCouleur() == cou) {
            System.out.print("Supprimé: ");
            System.out.print(type + " ");
            System.out.print(liste.get(i).getMarque() + " ");
            System.out.print(liste.get(i).getModele() + " ");
            System.out.println(liste.get(i).getCouleur());
            liste.remove(i);
         }
      }
   }
}

class ex4 {
   public static void main(String[] args){
      Collection C = new Collection();
      C.ajouter(new Auto("Renault", "Clio", "bleue"));
      C.ajouter(new Auto("Peugeot", "207", "gris"));
      C.ajouter(new Moto("Yamaha", "TMax", "noir"));
      C.afficher();
      //C.searchMarque("Renault");
      C.delete("Peugeot", "207", "gris");
      C.afficher();

      Moto M = new Moto("Yamaha", "TMax", "rouge");
      Moto M2 = new Moto("KTM", "RC", "vert");
      System.out.println(M.equals(M2));

      C.delete("Auto", "Renault", "Clio", "bleue");
      C.afficher();
   }
}
