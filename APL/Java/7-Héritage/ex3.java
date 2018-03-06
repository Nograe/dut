import java.lang.*;
import java.util.*;

class Volaille {
    private int prix;
    private int poids_abattage;
    int poids;
    
    Volaille (int pr, int pa, int pp) {
	setPrix(pr);
	setPoids(pa);
	poids = pp;
    }
    void setPoids (int arg) {
	poids_abattage = arg;
    }
    void setPrix (int arg) {
	prix = arg;
    }

    int getPrix () {
	return prix;
    }
    int getPoidsAbattage () {
	return poids_abattage;
    }
    int getPoids () {
	return poids;
    }
}

class Poulet extends Volaille {
    static int prixPoulet = 5;
    static int poidsPoulet = 3; 
    Poulet () {
	super(prixPoulet, poidsPoulet, 1);
    }
    Poulet (int arg) {
	super(prixPoulet, poidsPoulet, arg);
    }
}

class Canard extends Volaille {
    static int prixCanard = 20;
    static int poidsCanard = 5; 
    Canard () {
	super(prixCanard, poidsCanard, 1);
    }
    Canard (int arg) {
	super(prixCanard, poidsCanard, arg);
    }
}

class Elevage {
    ArrayList<Volaille> liste = new ArrayList<Volaille>();
    void ajouter (Volaille V) {
	liste.add(V);
    }
    void afficher () {
	for(int i = 0; i < liste.size(); i++)
	    System.out.println(liste.get(i));
    }
    void a_abattre () {
	for(int i = 0; i < liste.size(); i++) {
	    if(liste.get(i).getPoids() > liste.get(i).getPoidsAbattage()) {
		System.out.println(liste.get(i));
	    }
	}
    }
    int evaluer () {
	int total = 0;
	for(int i = 0; i < liste.size(); i++) {
	    if(liste.get(i).getPoids() > liste.get(i).getPoidsAbattage()) {
		total += liste.get(i).getPrix();
	    }
	}
	return total;
    }
    void abattre () {
	 System.out.println("Argent obtenu: " + evaluer());
	for(int i = 0; i < liste.size(); i++) {
	    if(liste.get(i).getPoids() > liste.get(i).getPoidsAbattage()) {
		liste.remove(i);
	    }
	}
    }
}

class ex3 {
    public static void main(String[] args){
	Elevage E = new Elevage();
	E.ajouter(new Poulet(5));
	E.ajouter(new Canard(1));
	E.ajouter(new Canard(12));
	E.afficher();
	// System.out.println(E.evaluer());
	E.abattre();
	E.afficher();
    }
}
