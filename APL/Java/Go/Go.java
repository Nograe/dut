public class Go {
   public static myWindow mainWindow = new myWindow();

   public static myWindow getWindow() {
      return mainWindow;
   }
   public static Goban getGoban() {
      return mainWindow.goban;
   }

   public static void main(String[] args) {
      mainWindow.displayMenu();
   }
}
