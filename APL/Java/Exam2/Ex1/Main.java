import java.util.*;

public class Main {
   public static void main(String[] args) {
      Env env = new Env();

      Scanner sc = new Scanner(System.in);
      String line = sc.nextLine();
      String cmd = env.getCommand(line);
      while(!cmd.equals("exit")) {

         if(cmd.equals("set")) env.set(line);
         else if(cmd.equals("unset")) env.unset(line);
         else if(cmd.equals("display")) env.display(line);
         else if(cmd.equals("listall")) env.listall();
         else break;

         line = sc.nextLine();
         cmd = env.getCommand(line);
      }
   }
}
