import java.util.*;

public class ex2 {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int tab[] = new int[5];
		tab[0] = sc.nextInt();
		tab[1] = sc.nextInt();
		tab[2] = sc.nextInt();
		tab[3] = sc.nextInt();
		tab[4] = sc.nextInt();

		int grand = tab[0];
		for (int i = 1; i < tab.length; i++) {
			if (tab[i] > grand) {
				grand = tab[i];
			}
		}

		System.out.println(Arrays.toString(tab));
		System.out.println("Plus grand entier: " + grand);
	}
}