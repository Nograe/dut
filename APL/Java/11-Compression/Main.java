import java.io.*;
import java.util.*;

public class Main {
   public static void main(String [] argument) {
      String fileName;
      if(argument.length == 0) {
         fileName = "test.txt";
      } else {
         fileName = argument[0];
      }
      Huffman.encodage(fileName, "hashmap_"+fileName);
   }
}
