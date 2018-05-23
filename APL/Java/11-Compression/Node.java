import java.util.Comparator;
import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.*;

public class Node implements Comparable<Node> {
   private byte character;
   private int count;
   Node filsGauche;
   Node filsDroit;

   public Node(byte character, int count) {
      this.character = character;
      this.count = count;
   }
   public Node(byte character, int count, Node filsGauche, Node filsDroit) {
      this(character, count);
      this.filsGauche = filsGauche;
      this.filsDroit = filsDroit;
   }
   public byte getChar() {
      return character;
   }
   public int getCount() {
      return count;
   }

   @Override
   public String toString() {
      if(character == -1) {
         return "char: "+character+" count: "+count + "  filsGauche: " + filsGauche.toString() + "  filsDroit: " + filsDroit.toString();
      }
      return "char: "+(char)character+" count: "+count;
   }

   @Override
   public int compareTo(Node other) {
       if (this.count < other.count) return -1;
       else if (this.count > other.count) return 1;
       return 0;
   }



   public int sizeValueConsole() {
		return (new Integer(count)).toString().length();
	}

	public int countPlaceGraphique(FontMetrics fm, int off_node, int off) {
		int nb = fm.stringWidth((new Integer(count)).toString()) + off_node;

		if (filsGauche != null)
			nb += off + filsGauche.countPlaceGraphique(fm, off_node, off);
		if (filsDroit != null)
			nb += off + filsDroit.countPlaceGraphique(fm, off_node, off);

		return nb;
	}

	public int countOffsetLeftGraphique(FontMetrics fm, int off_node, int off) {
		int nb = fm.stringWidth((new Integer(count)).toString()) + off_node + off;

		if (filsGauche != null)
			nb += filsGauche.countPlaceGraphique(fm, off_node, off) + off;

		return nb;
	}

	public int countOffsetRightGraphique(FontMetrics fm, int off_node, int off) {
		int nb = fm.stringWidth((new Integer(count)).toString()) + off_node + off;

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

		return nb + 1;
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
		LinkedList<Node2DisplayConsole> list = new LinkedList<Node2DisplayConsole>();

		list.add(new Node2DisplayConsole(this, this.countOffsetLeftConsole(), 0, 0, true));
		int cur_offset = 0;
		int lastposy = 0;
		while (!list.isEmpty()) {
			Node2DisplayConsole n = list.poll();
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
            if(n.node.character == 0) System.out.print(n.node.count);
				else System.out.print((char)n.node.character);

				if (n.node.filsGauche != null) {
					int nbbranche = n.node.filsGauche.countOffsetRightConsole()+Math.max(n.node.filsGauche.sizeValueConsole()/2, 1);
					list.add(new Node2DisplayConsole(n.node.filsGauche, n.posx - 1, n.posy+1, nbbranche, true));
				}

				if (n.node.filsDroit != null) {
					int nbbranche = n.node.filsDroit.countOffsetLeftConsole()+Math.max(n.node.filsDroit.sizeValueConsole()/2, 1);
					list.add(new Node2DisplayConsole(n.node.filsDroit, n.posx + n.sizeValueConsole(), n.posy+1, nbbranche, false));
				}
			} else {
				if (n.left) {
					System.out.print("/");
					list.add(new Node2DisplayConsole(n.node, n.posx - 1, n.posy+1, n.nbbranche - 1, n.left));
				} else {
					System.out.print("\\");
					list.add(new Node2DisplayConsole(n.node, n.posx + 1, n.posy+1, n.nbbranche - 1, n.left));
				}
			}
			cur_offset += n.sizeValueConsole();
		}
      System.out.println();
	}
}
