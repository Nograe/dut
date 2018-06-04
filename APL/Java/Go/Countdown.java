import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class Countdown extends JLabel {
   private int interval;
   private Timer timer;

   public Countdown(int time) {
      super(Integer.toString(time));
      setFont(new Font("Roboto", Font.PLAIN, 25));
      setForeground(Color.WHITE);
      interval = time*1000;
      int delay = 1000; //milliseconds
      ActionListener taskPerformer = new ActionListener() {
         public void actionPerformed(ActionEvent evt) {
            if(interval <= 0) {
               setForeground(new Color(200, 20, 20));
               return;
            }
            interval-=delay;
            setText(Integer.toString(interval/1000));
         }
      };
      timer = new Timer(delay, taskPerformer);
   }

   public void start() {
      timer.start();
   }
   public void stop() {
      timer.stop();
   }
}

enum TimerType {
   NONE, ABSOLUTE, BYO
}
