//Héritage

import java.util.*;
import java.awt.*;
import javax.swing.*;

class Gris extends Color {
    public Gris () {
	super(50, 50, 50);
    }
    public Gris (int v) {
	super(v, v, v);
    }
}

public class ex1 {
    public static void main(String[] args) {

	JFrame fenetre = new JFrame();

	fenetre.setSize(500, 200);
	fenetre.setLocation(500, 300);
	fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	JLabel panneau = new JLabel("Je suis gris");
	//panneau.setForeground(c1);
	panneau.setBackground(new Gris(100));
	panneau.setOpaque(true);

	fenetre.add(panneau, BorderLayout.CENTER);

	fenetre.setVisible(true);
    }
}