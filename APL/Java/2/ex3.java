import java.util.*;

class SalleAttente {
   String[] patients;
   int in, out;
   int count;

   public SalleAttente (int nbr) {
      patients = new String[nbr];
   }
   public boolean faireEntrer (String nom) {
      if(in == out-1 || count == patients.length) {
         in = 0;
         return false;
      }
      if(in == patients.length)
      in = 0;
      patients[in] = nom;
      in++;
      count++;
      return true;
   }
   public String faireSortir () {
      out++;
      String temp = patients[out-1];
      patients[out-1] = null;
      if(out == patients.length)
      out = 0;
      count--;
      return temp;
   }
   public void afficherSalle () {
      System.out.println("Liste des patients: ");
      for(int i = 0; i < patients.length; i++) {
         if(patients[i] != null)
         System.out.println(patients[i]);
      }
   }
}

public class ex3 {
   public static void main(String[] args) {
      SalleAttente docteur = new SalleAttente(4);
      int rep;
      String nom;
      boolean fini = false;
      Scanner clavier = new Scanner(System.in);

      while (!fini) {
         System.out.print("Entrez une commande 1)Faire Entrer 2)FaireSortir 3)Afficher 4)Quitter ");
         rep = clavier.nextInt();
         switch(rep){
            case 1 :
            if(docteur.in == docteur.out-1 || docteur.count == docteur.patients.length) {
               System.out.println("La salle est pleine !");
               break;
            }
            clavier.nextLine();
            System.out.print("Entrez un nom : ");
            nom = clavier.nextLine();
            docteur.faireEntrer(nom);
            break;
            case 2 :
            if(docteur.in == docteur.out) {
               System.out.println("La salle est vide !");
               break;
            }
            System.out.println("on appelle " + docteur.faireSortir());
            break;
            case 3 :
            docteur.afficherSalle();
            break;
            case 4:
            System.out.println("ok bye bye");
            fini = true;
            break;
            default : System.out.println("commande inconnue");
         }
      }
   }
}
