import java.util.*;

class De {
    private int faces;
    private int alea;
    static int def_faces = 6;
    Random rand = new Random();    

    public De () {
	faces = def_faces;
    }
    public De (int faces) {
	this.faces = faces;
    }
    public De (De D) {
	faces = D.faces;
    }
    public int get () {
	return faces;
    }
    public void set (int ent) {
	faces = Math.max(1, ent);
    }
    public int lancer () {
	alea = rand.nextInt(faces)+1;
	return alea;
    }
    public void print () {
	System.out.println(alea);
    }
}

public class ex2 {
    public static void main (String[] args) {
	De D = new De();

	int[] f = new int[D.get()];
	for(int i = 0; i < 1000; i++)
	    f[D.lancer()-1]++;
	for(int i = 0; i < D.get(); i++) 
	    System.out.println("Faces "+(i+1)+": "+f[i]);
    }
}