import java.util.*;

class SalleAttente {
   LinkedList<String> patients = new LinkedList<String>();

   public void faireEntrer(String nom) {
      patients.addLast(nom);
   }
   public void faireSortir() {
      if (patients.peekFirst() == null) {
         System.out.println("La salle d'attente est vide.");
         return;
      }
      System.out.println("On appelle : " + patients.pollFirst());
   }
   public void afficherSalle() {
      if (patients.size() == 0) {
         System.out.println("La salle d'attente est vide.");
         return;
      }
      System.out.println("Liste des patients :");
      for (int i = 0; i < patients.size(); i++)
         System.out.println(patients.get(i));
   }
}

public class ex4 {
   public static void main(String[] args) {
      SalleAttente docteur = new SalleAttente();
      int rep;
      String nom;
      boolean fini = false;
      Scanner clavier = new Scanner(System.in);

      while (!fini) {
         System.out.print("Entrez une commande : " + "\n" + "1)Faire Entrer 2)FaireSortir 3) Afficher 4)Quitter ");
         rep = clavier.nextInt();
         switch (rep) {
         case 1 :
            clavier.nextLine();
            System.out.print("Entrez un nom : ");
            nom = clavier.nextLine();
            docteur.faireEntrer(nom);
            break;
         case 2 :
            docteur.faireSortir();
            break;
         case 3 :
            docteur.afficherSalle();
            break;
         case 4:
            System.out.println("bye");
            fini = true;
            break;
         default : System.out.println("commande inconnue");
         }
      }
   }
}