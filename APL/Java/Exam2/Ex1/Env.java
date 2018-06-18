import java.util.*;

public class Env {
   private static HashMap<String, String> env;

   public Env() {
      env = new HashMap<String, String>();
   }

   public String getCommand(String line) {
      if(line == null) return "erreur";

      String cmd = null;
      if(line.charAt(0) == 's') return "set";
      if(line.charAt(0) == 'u') return "unset";
      if(line.charAt(0) == 'd') return "display";
      if(line.charAt(0) == 'l') return "listall";
      return "exit";
   }

   public String getVar(String line) { //split....
      int cmdlength = getCommand(line).length()+1;
      line = line.substring(cmdlength, line.length());
      char i = line.charAt(0);
      int count = 0;
      do {
         count++;
         i = line.charAt(count);
      } while (i != '=');
      return line.substring(0, count);
   }

   public void set(String line) {
      String var = getVar(line);
      int length = getCommand(line).length()+getVar(line).length()+2;
      String value = line.substring(length, line.length());
      env.put(var, value);
   }
   public void unset(String line) {
      int cmdlength = getCommand(line).length()+1;
      String var = line.substring(cmdlength, line.length());
      env.remove(var);
   }
   public void display(String line) {
      int cmdlength = getCommand(line).length()+1;
      String var = line.substring(cmdlength, line.length());
      if(env.get(var) == null) System.out.println("no value");
      else System.out.println(env.get(var));
   }
   public void listall() {
      for(Map.Entry<String, String> entry : env.entrySet()) {
         String key = entry.getKey();
         String value = entry.getValue();
         System.out.println(key+"="+value);
      }
   }
}
