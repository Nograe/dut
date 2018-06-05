public class Main {
   public static void main(String[] args) {
      TableHash<String, Double> hashmap = new TableHash<String, Double>();
      hashmap.associer("PI", 3.14);
      hashmap.associer("PI", 3.1456);
      hashmap.associer("NBR_OR", 12.1);
      hashmap.associer("NBR_OR", 2.1);
      hashmap.associer("RACINE_2", 1.41);
      System.out.println(hashmap.value("PI"));
      System.out.println(hashmap.value("NBR_OR"));
      System.out.println(hashmap.value("RACINE_2"));
   }
}

// class Key {
//    String key;
//
//    @Override
//    public int hashCode() {
//       return key.hashCode();
//    }
//    @Override
//    public boolean equals(Object o) {
//       if(o instanceof Key) {
//          Key K = (Key) o;
//          if(K.key == this.key) {
//             return true;
//          }
//          else {
//             return false;
//          }
//       }
//       else {
//          return false;
//       }
//    }
// }
// class Value {
//    double value;
// }
