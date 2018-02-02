import java.util.*;

public class ex5 {
    public static void main (String[] args) {
	int tab1[] = {1, 2, 3};
	int tab2[] = tab1;
	
	tab2[0] = 3;

	System.out.println(Arrays.toString(tab2));
    }
}