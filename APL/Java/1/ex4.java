import java.util.*;

public class ex4 {
    public static void swap(int a, int b) {
	int var = b;
	b = a;
	a = var;
    }
    public static void swaptab(int[] a, int[] b) {
	int var = b[0];
	b[0] = a[0];
	a[0] = var;
    }
    public static void main (String[] args) {
	int a = 5;
	int b = 10;
	swap(a, b);
	System.out.println("a: "+a+" b: "+b);

	int atab[] = new int[1];
	int btab[] = new int[1];
	atab[0] = a;
	btab[0] = b;
	swaptab(atab, btab);
	System.out.println("a: "+atab[0]+" b: "+btab[0]);
    }
}