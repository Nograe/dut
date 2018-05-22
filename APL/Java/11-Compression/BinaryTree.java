import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;

class NodeDisplayGraphique {
	int posx;
	int posy;
	int val;
	
	NodeDisplayGraphique filsGauche;
	NodeDisplayGraphique filsDroit;
	
	NodeDisplayGraphique(int val, int posx, int posy, NodeDisplayGraphique fg, NodeDisplayGraphique fd) {
		this.val = val;
		this.posx = posx;
		this.posy = posy;
		
		this.filsGauche = fg;
		this.filsDroit = fd;		
	}
}


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
	
	public int countPlaceGraphique(FontMetrics fm, int off_node, int off) {
		int nb = fm.stringWidth((new Integer(val)).toString()) + off_node;
		
		if (filsGauche != null)
			nb += off + filsGauche.countPlaceGraphique(fm, off_node, off);
		if (filsDroit != null)
			nb += off + filsDroit.countPlaceGraphique(fm, off_node, off);
		
		return nb;		
	}
		
	public int countOffsetLeftGraphique(FontMetrics fm, int off_node, int off) {
		int nb = fm.stringWidth((new Integer(val)).toString()) + off_node + off;

		if (filsGauche != null)
			nb += filsGauche.countPlaceGraphique(fm, off_node, off) + off;
				
		return nb;
	}
	
	public int countOffsetRightGraphique(FontMetrics fm, int off_node, int off) {
		int nb = fm.stringWidth((new Integer(val)).toString()) + off_node + off;
		
		if (filsDroit != null)
			nb += filsDroit.countPlaceGraphique(fm, off_node, off) + off;
				
		return nb;		
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
	}
}

class TreePanel extends JPanel {
	static int STARTY = 50;
	static int STARTX = 50;	
	static int OFF_NODE = 5;
	
	static int OFFX = 10;
	static int OFFY = 80;
	
	NodeDisplayGraphique treed;
	Font font = new Font("Helvetica",Font.PLAIN,12);
	FontMetrics fm;
	
	public TreePanel(Node tree) {
		super();
		
		setFont(font);
		fm = getFontMetrics(font);
		
		treed = getDisplayInfo(tree);
	}

	
	public void drawTreeRec(Graphics g, NodeDisplayGraphique n)	{
		if (n == null)
			return;
		
		if (n.filsGauche != null)
			g.drawLine(n.posx, n.posy, n.filsGauche.posx, n.filsGauche.posy);
		
		if (n.filsDroit != null)
			g.drawLine(n.posx, n.posy, n.filsDroit.posx, n.filsDroit.posy);
		
		
		drawNode(g, n.posx, n.posy, (new Integer(n.val)).toString());
		
		drawTreeRec(g, n.filsGauche);
		drawTreeRec(g, n.filsDroit);		
	}
	
	public void drawTree(Graphics g)	{
		drawTreeRec(g, treed);
	}
	
	public void drawNode(Graphics g, int x, int y, String text) {
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
	
	NodeDisplayGraphique getDisplayInfo(Node tree) {
		return getDisplayInfoRec(tree, STARTX, STARTY, false);
	}

	
	NodeDisplayGraphique getDisplayInfoRec(Node tree, int posx, int posy, boolean left) {		
		if (left) {		
			posx -= tree.countOffsetRightGraphique(fm, OFF_NODE, OFFX);
		} else {
			posx += tree.countOffsetLeftGraphique(fm, OFF_NODE, OFFX);			
		}
		
		NodeDisplayGraphique fg = null;
		NodeDisplayGraphique fd = null;
		if (tree.filsGauche != null)
			fg = getDisplayInfoRec(tree.filsGauche, posx, posy + OFFY, true);
		if (tree.filsDroit != null)
			fd = getDisplayInfoRec(tree.filsDroit, posx, posy + OFFY, false);
		
		System.out.println("Val : " + tree.val + " posx : " + posx);
		
		return new NodeDisplayGraphique(tree.val, posx, posy, fg, fd);		
	}
}

public class BinaryTree {	
	public static void main(String[] args) {
		//Node n = new Node(1, new Node(20), new Node(3));
		//Node n = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3, new Node(6), new Node(70)));
		//Node n = new Node(1, null, new Node(3, new Node(2), new Node(7)));
				
		Node n = new Node(101, 
				 new Node(22, new Node(40, new Node(8321), new Node(922224)), new Node(5, new Node(224), new Node(3, new Node(22), new Node(43, new Node(22), new Node(43))))), 
				 new Node(321209, new Node(6109, new Node(82367, new Node(20), new Node(13)), new Node(9097)), new Node(709)));

		JFrame f = new JFrame();
		f.setSize(800, 800);
		f.setLocation(100, 100);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		f.add(new TreePanel(n), BorderLayout.CENTER);
		

		f.setVisible(true);		

				 
		n.afficher();
	}
}