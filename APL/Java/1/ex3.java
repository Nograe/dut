import java.util.*;

public class ex3 {
    public static void main (String[] args) {
	Scanner sc = new Scanner(System.in);
	String chain = sc.nextLine();
	String first = chain;
	String last = chain;

	while (!chain.equals("Fin")) {
	    chain = sc.nextLine();
	    if(chain.compareTo(first) < 0 && !chain.equals("Fin"))
		first = chain;
	    if(chain.compareTo(last) > 0 && !chain.equals("Fin"))
		last = chain;
	}

	System.out.println("Premier mot: " + first + "\n"  +"Dernier mot: " + last);
    }
}