import java.io.*;
import java.util.*;
import java.nio.file.Files;

public class Huffman {
   public static SortedLinkedList<Node> compterOcc(File file) {
      try {
         byte[] toRead = Files.readAllBytes(file.toPath());
         // FileInputStream fileR = new FileInputStream(file);
         // fileR.read(toRead);
         // fileR.close();
         // for (int i = 0; i < toRead.length; i++) {
         //    System.out.print((char)toRead[i]);
         // }
         HashMap<Byte,Integer> map = new HashMap<Byte,Integer>();
         for (int i = 0; i < toRead.length; i++) {
            if(map.get(toRead[i]) != null) {
               map.put(toRead[i], map.get(toRead[i])+1);
            } else {
               map.put(toRead[i], 1);
            }
         }

         SortedLinkedList<Node> listNode = new SortedLinkedList<Node>();
         for (Byte name: map.keySet()) {
            listNode.sortedAdd(new Node(name, map.get(name)));
         }
         return listNode;

      } catch (IOException e) {
         System.out.println(e.getMessage());
         System.out.println("Erreur de lecture.");
         return null;
      }
   }

   public static Node creerArbre(File file) {
      SortedLinkedList<Node> listNode = compterOcc(file);
      // displayList(listNode);

      while(listNode.size() >= 2) {
         Node n1 = listNode.pollFirst();
         Node n2 = listNode.pollFirst();
         // if(n1.getChar() == -1 && n2.getChar() == -1) {
         //    break;
         // }
         Node newNode = new Node((byte)-1, n1.getCount()+n2.getCount(), n1, n2);
         System.out.println(newNode.toString());
         listNode.sortedAdd(newNode);
      }

      return null;
   }

   public static void displayList(SortedLinkedList<Node> listNode) {
      System.out.println(Arrays.toString(listNode.toArray()));
   }
}
