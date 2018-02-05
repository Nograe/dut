class Compteur{
    int x;
    Compteur(int n){
	x=n;
    }
    Compteur incremente(){
	x++;
	return this;
    }
    int value(){
	return x;
    }
}
public class ex6 {
    public static void main(String[] argv){
	Compteur c1, c2, c3;
	c1 = new Compteur(0);
	c1.incremente();
	c2 = new Compteur(1);
	c3 = c1;
	if (c1 == c3){
	    System.out.println("c1 et c3 sont egaux");
	} else {
	    System.out.println("c1 et c3 ne sont pas egaux");
	}
	if (c1.value() == c2.value()){
	    System.out.println("c1 et c2 ont meme valeur");
	} else {
	    System.out.println("c1 et c2 n'ont pas la meme valeur");
	}
	if (c1 == c2) {
	    System.out.println("c1 et c2 sont egaux");
	} else {
	    System.out.println("c1 et c2 ne sont pas egaux");
	}
	if (c1.value() == c1.incremente().value()){
	    System.out.println("c1 et c1 incremente ont meme valeur");
	} else {
	    System.out.println("c1 et c1 incremente n'ont pas la meme valeur");
	}
	if (c1 == c1.incremente()){
	    System.out.println("c1 et c1 incremente sont egaux");
	} else {
	    System.out.println("c1 et c1 incremente ne sont pas egaux");
	}
    }
}
