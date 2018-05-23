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
         Node newNode = new Node((byte)0, n1.getCount()+n2.getCount(), n1, n2);
         listNode.sortedAdd(newNode);
         // System.out.println(newNode.toString());
      }
      listNode.peek().afficher();
      return listNode.peek();
   }

   public static void displayList(SortedLinkedList<Node> listNode) {
      System.out.println(Arrays.toString(listNode.toArray()));
   }

   public static HashMap<Byte,boolean[]> getCodage(Node tree, HashMap<Byte,boolean[]> map, ArrayList<Boolean> array) {
      if(map == null) {
         map = new HashMap<Byte, boolean[]>();
      }
      if(array == null) {
         array = new ArrayList<Boolean>();
      }

      if(tree.getChar() != 0) { //Traitement node courant
         boolean[] boolArray = new boolean[array.size()];
         for(int i = 0; i < array.size(); i++) {
            boolArray[i] = array.get(i);
         }
         map.put(tree.getChar(), boolArray);
      }

      if(tree.filsGauche != null) { //Traitement fils gauche
         array.add(false);
         map = getCodage(tree.filsGauche, map, array);
         array.remove(array.size()-1);
      }
      if(tree.filsDroit != null) { //Traitement fils droit
         array.add(true);
         map = getCodage(tree.filsDroit, map, array);
         array.remove(array.size()-1);
      }

      return map;
   }

   public static void saveInFile(HashMap<Byte,boolean[]> map, String file) {
      try {
         FileOutputStream newFile = new FileOutputStream(new File(file));
         newFile.write((byte)map.size());
         for (Byte key : map.keySet()) {
            newFile.write(key);
            for (int i = 0; i < map.get(key).length; i++) {
               if(map.get(key)[i] == true) newFile.write(1);
               else newFile.write(0);
            }
            newFile.write(' ');
         }
         newFile.close();
      } catch (IOException e) {
         System.out.println(e.getMessage());
      }
   }

   public static void encodage(String fileName, String fileNameOut) {
      Node mainNode = Huffman.creerArbre(new File(fileName));
      HashMap<Byte, boolean[]> map = getCodage(mainNode, null, null);

      for (byte name: map.keySet()){
         String value = Arrays.toString(map.get(name));
         System.out.println((char)name + " " + value);
      }

      saveInFile(map, fileNameOut);
   }
}
