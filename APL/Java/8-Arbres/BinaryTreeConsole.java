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

class NodeDisplay {
    int posx;
    int posy;
    int val;

    static int Y = 20;
    
    NodeDisplay filsGauche;
    NodeDisplay filsDroit;
    public NodeDisplay() {
    }
    public int countPlaceGraphique(FontMetrics F, int espacement) {
	if(filsGauche != null && filsDroit != null)
	    return filsGauche.countPlaceGraphique(F, espacement) + filsDroit.countPlaceGraphique(F, espacement) + espacement*2 + F.stringWidth(Integer.toString(val));
	if(filsGauche != null && filsDroit == null)
	    return filsGauche.countPlaceGraphique(F, espacement) + espacement + F.stringWidth(Integer.toString(val));
	if(filsGauche == null && filsDroit != null)
	    return filsDroit.countPlaceGraphique(F, espacement) + espacement + F.stringWidth(Integer.toString(val));

	return F.stringWidth(Integer.toString(val));
    }
}

class PanelTree extends JPanel {
    Font font;
    FontMetrics fm;
    public PanelTree() {
	super();
	font = new Font("Helvetica", Font.PLAIN, 12);
	setFont(font);
	fm = getFontMetrics(font);
    }
    @Override
    public void paintComponent(Graphics g) {
	drawNode(g, 100, 100, "122");
    }
    public void drawNode(Graphics g, int x, int y, String text) {
	int width = fm.stringWidth("text");
	int height = fm.getMaxDescent() + fm.getMaxAscent();
	g.drawOval(x-width/4, y-height-height/2, width+width/2, width+width/2);
	g.drawString(text, x, y);
    }
    NodeDisplay getCopy(NodeDisplay N, Node tree) {
	System.out.print(" Valeur: " + tree.val);
	N.val = tree.val;
	if(tree.filsGauche != null) {
	    N.filsGauche = getCopy(N.filsGauche, tree.filsGauche);
	    N.filsGauche.posx = N.posx - N.filsGauche.countPlaceGraphique(fm, 10);
	    N.filsGauche.posy = N.posy+20;
	}
	if(tree.filsDroit != null) {
	    N.filsDroit = getCopy(N.filsDroit, tree.filsDroit);
	    N.filsDroit.posx = N.posx - N.filsDroit.countPlaceGraphique(fm, 10);
	    N.filsDroit.posy = N.posy+20;
	}
	// if(tree.filsGauche != null && tree.filsDroit != null) {
	//     N.posx = ;
	//     N.posy = NodeDisplay.Y;
	// }
	if(tree.filsGauche == null && tree.filsDroit == null) {
	    N.posx = 0;
	    N.posy = NodeDisplay.Y;
	}
	System.out.println("Posx: " + N.posx + " Posy: " + N.posy);
	return N;
    }
    NodeDisplay getDisplayInfo(Node tree) {
	NodeDisplay N = new NodeDisplay();
	N.posx = 500/2;
	N.posy = NodeDisplay.Y; System.out.println("Posx: " + N.posx + " Posy: " + N.posy);
	return getCopy(N, tree);
    }
}

public class BinaryTreeConsole {	
    public static void main(String[] args) {
	//Node n = new Node(1, null, new Node(20));
	//Node n = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3, new Node(6), new Node(70)));
	//Node n = new Node(1, null, new Node(3, new Node(2), new Node(7)));
		
	/*Node n = new Node(101, 
	  new Node(22, new Node(40, new Node(8321), new Node(922224)), new Node(5, new Node(224), new Node(3, new Node(22), new Node(43, new Node(22), new Node(43))))), 
	  new Node(321209, new Node(6109, new Node(82367, new Node(20), new Node(13)), new Node(9097)), new Node(709)));
	*/	
	
	
	//Node n = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3, new Node(6), new Node(70)));
	
	Node n=new Node(14894,
			new Node (265,
				  new Node (4111, 
					    new Node (1444),
					    new Node (5232)),
				  new Node (3112,
					    new Node (8112,
						      new Node (755),
						      new Node (96)),
					    new Node(6456))),
			new Node(844,
				 new Node (12),
				 new Node (1756)));
	
	/*Node n = new Node(101, 
	  new Node(22, new Node(40, new Node(8321), new Node(922224)), new Node(5, new Node(224), new Node(3, new Node(22), new Node(43, new Node(22), new Node(43))))), 
	  new Node(321209, new Node(6109, new Node(82367, new Node(20), new Node(13)), new Node(9097)), new Node(709)));	*/
	

	JFrame fenetre = new JFrame();

	fenetre.setSize(500, 500);
	fenetre.setLocation(100, 100);
	fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	PanelTree tree = new PanelTree();
	
	fenetre.add(tree, BorderLayout.CENTER);
	fenetre.setVisible(true);
	//n.afficher();

	NodeDisplay N = new NodeDisplay();
	N.val = 5;
	N.filsDroit = new NodeDisplay();
	N.filsDroit.val = 10;
	N.filsGauche = new NodeDisplay();
	N.filsGauche.val = 2;
	N.filsGauche.filsGauche = new NodeDisplay();
	N.filsGauche.filsGauche.val = 15;
	System.out.println(N.countPlaceGraphique(tree.fm, 20));
    }
}