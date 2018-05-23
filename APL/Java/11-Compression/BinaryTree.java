import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;

class Node2DisplayGraphique {
	int posx;
	int posy;
	int val;

	Node2DisplayGraphique filsGauche;
	Node2DisplayGraphique filsDroit;

	Node2DisplayGraphique(int val, int posx, int posy, Node2DisplayGraphique fg, Node2DisplayGraphique fd) {
		this.val = val;
		this.posx = posx;
		this.posy = posy;

		this.filsGauche = fg;
		this.filsDroit = fd;
	}
}


class Node2DisplayConsole {
	int posx;
	int posy;
	boolean left;
	int nbbranche;

	Node node;

	Node2DisplayConsole(Node node, int posx, int posy, int nbbranche, boolean left) {
		this.node = node;
		this.posx = posx;
		this.posy = posy;
		this.nbbranche = nbbranche;
		this.left = left;
	}

	int sizeValueConsole() {
		if (nbbranche == 0)
			return node.sizeValueConsole();
		else
			return 1;
	}
}

class TreePanel extends JPanel {
	static int STARTY = 50;
	static int STARTX = 50;
	static int OFF_NODE = 5;

	static int OFFX = 10;
	static int OFFY = 80;

	Node2DisplayGraphique treed;
	Font font = new Font("Helvetica",Font.PLAIN,12);
	FontMetrics fm;

	public TreePanel(Node2 tree) {
		super();

		setFont(font);
		fm = getFontMetrics(font);

		treed = getDisplayInfo(tree);
	}


	public void drawTreeRec(Graphics g, Node2DisplayGraphique n)	{
		if (n == null)
			return;

		if (n.filsGauche != null)
			g.drawLine(n.posx, n.posy, n.filsGauche.posx, n.filsGauche.posy);

		if (n.filsDroit != null)
			g.drawLine(n.posx, n.posy, n.filsDroit.posx, n.filsDroit.posy);


		drawNode2(g, n.posx, n.posy, (new Integer(n.val)).toString());

		drawTreeRec(g, n.filsGauche);
		drawTreeRec(g, n.filsDroit);
	}

	public void drawTree(Graphics g)	{
		drawTreeRec(g, treed);
	}

	public void drawNode2(Graphics g, int x, int y, String text) {
		int width = fm.stringWidth(text);
		int height = fm.getHeight();
		int size = width+OFF_NODE;

		g.setColor(Color.yellow);
		g.fillOval(x - size / 2, y - size / 2, size, size);

		g.setColor(this.getForeground());
		g.drawString(text, x - width / 2, y + (height/3));
	}

	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);

		g.setColor(this.getForeground());

		drawTree(g);
	}

	Node2DisplayGraphique getDisplayInfo(Node2 tree) {
		return getDisplayInfoRec(tree, STARTX, STARTY, false);
	}


	Node2DisplayGraphique getDisplayInfoRec(Node2 tree, int posx, int posy, boolean left) {
		if (left) {
			posx -= tree.countOffsetRightGraphique(fm, OFF_NODE, OFFX);
		} else {
			posx += tree.countOffsetLeftGraphique(fm, OFF_NODE, OFFX);
		}

		Node2DisplayGraphique fg = null;
		Node2DisplayGraphique fd = null;
		if (tree.filsGauche != null)
			fg = getDisplayInfoRec(tree.filsGauche, posx, posy + OFFY, true);
		if (tree.filsDroit != null)
			fd = getDisplayInfoRec(tree.filsDroit, posx, posy + OFFY, false);

		System.out.println("Val : " + tree.val + " posx : " + posx);

		return new Node2DisplayGraphique(tree.val, posx, posy, fg, fd);
	}
}

public class BinaryTree {
	// public static void BinaryTreeStart() {
	// 	//Node2 n = new Node2(1, new Node2(20), new Node2(3));
	// 	//Node2 n = new Node2(1, new Node2(2, new Node2(4), new Node2(5)), new Node2(3, new Node2(6), new Node2(70)));
	// 	//Node2 n = new Node2(1, null, new Node2(3, new Node2(2), new Node2(7)));
	//
	// 	Node2 n = new Node2(101,
	// 			 new Node2(22, new Node2(40, new Node2(8321), new Node2(922224)), new Node2(5, new Node2(224), new Node2(3, new Node2(22), new Node2(43, new Node2(22), new Node2(43))))),
	// 			 new Node2(321209, new Node2(6109, new Node2(82367, new Node2(20), new Node2(13)), new Node2(9097)), new Node2(709)));
	//
	// 	JFrame f = new JFrame();
	// 	f.setSize(800, 800);
	// 	f.setLocation(100, 100);
	// 	f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	//
	// 	f.add(new TreePanel(n), BorderLayout.CENTER);
	//
	// 	f.setVisible(true);
	//
	// 	n.afficher();
	// }
}
