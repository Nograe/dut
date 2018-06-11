import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class Countdown extends JLabel {
   public static int TIME;
   private int interval;
   private Timer timer;
   private int BYO_PERIODS;
   private int BYO_TIME = 5;

   public Countdown() {
      super(Integer.toString(TIME));
      BYO_PERIODS = 3;
      TIME = myWindow.timer.getValue()*60;

      setFont(new Font("Roboto", Font.PLAIN, 25));
      setForeground(Color.WHITE);
      interval = TIME*1000;
      int delay = 1000; //milliseconds
      setText(interval/1000/60 + ":00");
      ActionListener taskPerformer = new ActionListener() {
         public void actionPerformed(ActionEvent evt) {
            if(Goban.END) {
               timer.stop();
               return;
            }
            if(interval <= 0 && Goban.timer != TimerType.NONE) {
               if(Goban.timer == TimerType.BYO && BYO_PERIODS > 0) {
                  interval = BYO_TIME*1000;
                  BYO_PERIODS--;
                  setForeground(new Color(230, 90, 90));
               }
               else {
                  setForeground(new Color(200, 20, 20));
                  if(Goban.player == State.BLACK) {
                     Infos.scoreBlack.setText("-1");
                  } else {
                     Infos.scoreWhite.setText("-1");
                  }
                  Go.mainWindow.displayWinner();
                  return;
               }
            }
            interval-=delay;
            setText(interval/1000/60 + ":" + interval/1000%60);
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
