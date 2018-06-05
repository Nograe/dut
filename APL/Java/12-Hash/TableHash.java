import java.util.*;

public class TableHash<C, V> {
   class Pair {
      C key;
      V value;
      Pair(C key, V value) {
         this.key = key;
         this.value = value;
      }
   }
   private LinkedList<Pair>[] tab = null;
   private int capacite = 2;
   private int nbElements = 0;
   private float loadFactor = 3.f/4.f;

   @SuppressWarnings("unchecked")
   public TableHash() {
      tab = (LinkedList<Pair>[]) new LinkedList<?>[capacite];
   }

   public void associer(C key, V value) {
      if(nbElements >= loadFactor*capacite) reHash();
      int index = Math.abs(key.hashCode()) % capacite;
      Pair pair = new Pair(key, value);
      if(tab[index] == null) {
         tab[index] = new LinkedList<Pair>();
      }
      for (Pair p : tab[index]) {
         if(p.key.equals(pair.key)) {
            p.value = pair.value;
            nbElements++;
            return;
         }
      }
      tab[index].add(pair);
      nbElements++;
   }

   @SuppressWarnings("unchecked")
   private void reHash() {
      capacite *= 2;
      nbElements = 0;
      LinkedList<Pair>[] oldTab = tab;
      tab = (LinkedList<Pair>[]) new LinkedList<?>[capacite];
      for(LinkedList<Pair> list : oldTab) {
         if(list == null) continue;
         for(Pair pair : list) {
            associer(pair.key, pair.value);
         }
      }
   }

   public void supprimer(C key) {
      int index = Math.abs(key.hashCode()) % capacite;
      for (Pair p : tab[index]) {
         if(p.key.equals(key)) {
            tab[index].remove(p);
         }
      }
   }

   public V value(C key) {
      int index = Math.abs(key.hashCode()) % capacite;
      for (Pair p : tab[index]) {
         if(p.key.equals(key)) {
            return p.value;
         }
      }
      return null;
   }
}
