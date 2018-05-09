import java.io.*;

public class Huffman {
   public static SortedLinkedList<Node> compterOcc(File file) {
      try {
         //Phase d'´ecriture
         String toWrite = "Les exceptions c'est très bien";
         FileOutputStream fileW = new FileOutputStream(file);
         fileW.write(toWrite.getBytes()); //Ecrire un tableau de caractères (un tableau de bytes)
         fileW.write('\n'); //Ecrire un seul caractère (un seul byte)
         fileW.close();
         //Phase de lecture
         byte[] toRead = new byte[toWrite.length()];
         FileInputStream fileR = new FileInputStream(file);
         fileR.read(toRead);
         fileR.close();
         System.out.println(new String(toRead));
      } catch (IOException e) {
         //Si la lecture ou l'écriture se passent mal, on écrit le message de l'exception.
         System.out.println(e.getMessage());
         System.out.println("Erreur de lecture.");
      }
      SortedLinkedList listNode = new SortedLinkedList();
      for (int i = 0; i < ; ) {

      }
      return null;
   }
}
