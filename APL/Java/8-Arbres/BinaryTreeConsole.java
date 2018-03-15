import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;

class NodeDisplayConsole {
    int posx;
    int posy;
    boolean left;
    int nbbranche;

    Node node;

    NodeDisplayConsole(Node node, int posx, int posy, int nbbranche, boolean left) {
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

class Node{
    int val;

    Node filsGauche;
    Node filsDroit;

    public Node(int val) {
	this.val = val;
	this.filsDroit = null;
	this.filsGauche = null;
    }

    public Node(int val, Node fg, Node fd) {
	this.val = val;
	this.filsGauche = fg;
	this.filsDroit = fd;
    }

    public int sizeValueConsole() {
	return (new Integer(val)).toString().length();
    }

    public int countPlaceConsole() {
	int nb = sizeValueConsole();
	if (filsGauche != null)
	    nb += 1 + filsGauche.countPlaceConsole();
	if (filsDroit != null)
	    nb += 1 + filsDroit.countPlaceConsole();

	return nb;
    }

    public int countOffsetLeftConsole() {
	int nb = 0;
	if (filsGauche != null) {
	    nb += 1 + filsGauche.countPlaceConsole();
	}

	return nb;
    }

    public int countOffsetRightConsole() {
	int nb = 0;
	if (filsDroit != null) {
	    nb += 1 + filsDroit.countPlaceConsole();
	}

	return nb;
    }

    public void afficher() {
	LinkedList<NodeDisplayConsole> list = new LinkedList<NodeDisplayConsole>();

	list.add(new NodeDisplayConsole(this, this.countOffsetLeftConsole(), 0, 0, true));
	int cur_offset = 0;
	int lastposy = 0;
	while (!list.isEmpty()) {
	    NodeDisplayConsole n = list.poll();
	    if (n.posy != lastposy) {
		System.out.println("");
		cur_offset = 0;
		lastposy = n.posy;
	    }
	    if (n.left)
		n.posx = n.posx - (n.sizeValueConsole()-1)/2;
	    else
		n.posx = n.posx - n.sizeValueConsole()/2;

	    int tmp = cur_offset;
	    for (int i = 0; i < n.posx - tmp; ++i) {
		System.out.print(" ");
		cur_offset++;
	    }

	    if (n.nbbranche == 0) {
		System.out.print(n.node.val);
		if (n.node.filsGauche != null) {
		    int nbbranche = n.node.filsGauche.countOffsetRightConsole()+Math.max(n.node.filsGauche.sizeValueConsole()/2, 1);
		    list.add(new NodeDisplayConsole(n.node.filsGauche, n.posx - 1, n.posy+1, nbbranche, true));
		}

		if (n.node.filsDroit != null) {
		    int nbbranche = n.node.filsDroit.countOffsetLeftConsole()+Math.max(n.node.filsDroit.sizeValueConsole()/2, 1);
		    list.add(new NodeDisplayConsole(n.node.filsDroit, n.posx + n.sizeValueConsole(), n.posy+1, nbbranche, false));
		}
	    } else {
		if (n.left) {
		    System.out.print("/");
		    list.add(new NodeDisplayConsole(n.node, n.posx - 1, n.posy+1, n.nbbranche - 1, n.left));
		} else {
		    System.out.print("\\");
		    list.add(new NodeDisplayConsole(n.node, n.posx + 1, n.posy+1, n.nbbranche - 1, n.left));
		}
	    }
	    cur_offset += n.sizeValueConsole();
	}
	System.out.println("");
    }
}

public class BinaryTreeConsole {
    public static void main(String[] args) {
	//Node n = new Node(1, null, new Node(20));
	// Node n = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3, new Node(6), new Node(70)));
	//Node n = new Node(1, null, new Node(3, new Node(2), new Node(7)));

	// Node n = new Node(101,
	//   new Node(22, new Node(40, new Node(8321), new Node(2224)), new Node(5, new Node(24454), new Node(3, new Node(22), new Node(43, new Node(22), new Node(333))))),
	//   new Node(321209, new Node(6109, new Node(82367, new Node(20), new Node(13)), new Node(9097)), new Node(709)));



	// Node n = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3, new Node(6), new Node(70)));

	Node n=new Node(1,
			new Node (21,
				  new Node (311,
					    new Node (4111),
					    new Node (4112)),
				  new Node (312,
					    new Node (4121,
						      new Node (51211),
						      new Node (51212)),
					    new Node(4122))),
			new Node(22,
				 new Node (321),
				 new Node (322)));

     //n.afficher();

	PanelTree graphicTree = new PanelTree(n);
	// System.out.println(graphicTree.getOffsetGauche() + " | " + graphicTree.getOffsetDroit());

   	JFrame fenetre = new JFrame();

   	//fenetre.setSize(graphicTree.getOffsetGauche()+graphicTree.getOffsetDroit(), 500);
	fenetre.setSize(PanelTree.WIDTH, PanelTree.HEIGHT+NodeDisplay.espaceY*2);
	fenetre.setLocation(100, 100);
   	fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


   	fenetre.add(graphicTree, BorderLayout.CENTER);
	graphicTree.repaint();
   	fenetre.setVisible(true);
    }
}
