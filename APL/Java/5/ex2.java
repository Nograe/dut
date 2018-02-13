//Héritage

import java.util.*;
import java.awt.*;
import javax.swing.*;

class Nuance extends JPanel {
    public Nuance () {
	JTextField panneau = new JTextField();

	return;
    }
}

public class ex2 {
    public static void main(String[] args) {

	JFrame fenetre = new JFrame();

	fenetre.setSize(500, 200);
	fenetre.setLocation(500, 300);
	fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	fenetre.setLayout(new BoxLayout(fenetre, X_AXIS));

	Nuance N = new Nuance(args[0], args[1], args[2]);

	fenetre.add(N, Box.CENTER);

	fenetre.setVisible(true);
    }
}