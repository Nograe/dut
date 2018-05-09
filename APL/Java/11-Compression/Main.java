import java.io.*;

public class Main {
   public static void main(String [] argument) {
      Huffman H = new Huffman();
      H.compterOcc(new File("test.txt"));
   }
}
