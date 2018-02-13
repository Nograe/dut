//Mise en page
import javax.swing.*;
import java.awt.*;

public class ex4 {
    public static void main(String[] args) {

	JFrame fenetre = new JFrame();

	fenetre.setSize(400, 400);
	fenetre.setLocation(500, 200);
	fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	GridLayout grille = new GridLayout(3, 3);
	fenetre.setLayout(grille);

	JLabel l1 = new JLabel("MYSTRAL");
	l1.setHorizontalAlignment(JLabel.LEFT);
	l1.setVerticalAlignment(JLabel.TOP);
	//l1.setPreferredSize(new Dimension(50, 50));
	fenetre.add(l1);

	JLabel l2 = new JLabel("TRAMONTANE");
	l2.setHorizontalAlignment(JLabel.CENTER);
	l2.setVerticalAlignment(JLabel.TOP);
	//l2.setPreferredSize(new Dimension(50, 50));
	fenetre.add(l2);

	JLabel l3 = new JLabel("GREC");
	l3.setHorizontalAlignment(JLabel.RIGHT);
	l3.setVerticalAlignment(JLabel.TOP);
	//l3.setPreferredSize(new Dimension(50, 50));
	fenetre.add(l3);

	JLabel l4 = new JLabel("PONANT");
	l4.setHorizontalAlignment(JLabel.LEFT);
	l4.setVerticalAlignment(JLabel.CENTER);
	//l4.setPreferredSize(new Dimension(50, 50));
	fenetre.add(l4);

	JLabel l5 = new JLabel("");
	l5.setHorizontalAlignment(JLabel.CENTER);
	l5.setVerticalAlignment(JLabel.CENTER);
	//l5.setPreferredSize(new Dimension(50, 50));
	fenetre.add(l5);

	JLabel l6 = new JLabel("LEVANT");
	l6.setHorizontalAlignment(JLabel.RIGHT);
	l6.setVerticalAlignment(JLabel.CENTER);
	//l2.setPreferredSize(new Dimension(50, 50));
	fenetre.add(l6);

	JLabel l7 = new JLabel("LIBECCIO");
	l7.setHorizontalAlignment(JLabel.LEFT);
	l7.setVerticalAlignment(JLabel.BOTTOM);
	//l3.setPreferredSize(new Dimension(50, 50));
	fenetre.add(l7);

	JLabel l8 = new JLabel("MARIN");
	l8.setHorizontalAlignment(JLabel.CENTER);
	l8.setVerticalAlignment(JLabel.BOTTOM);
	//l4.setPreferredSize(new Dimension(50, 50));
	fenetre.add(l8);

	JLabel l9 = new JLabel("SIROCCO");
	l9.setHorizontalAlignment(JLabel.RIGHT);
	l9.setVerticalAlignment(JLabel.BOTTOM);
	//l5.setPreferredSize(new Dimension(50, 50));
	fenetre.add(l9);

	fenetre.setVisible(true);
    }
}
