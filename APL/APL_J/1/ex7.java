import java.util.*;

class Matrix {
    int tab[][];

    Matrix (int N, int M) {
	tab = new int[N][M];
	Random rand = new Random(); 
	 
	for(int i = 0; i < N; i++) {
	    for(int j = 0; j < M; j++)
		tab[i][j] = rand.nextInt(100);
	}
    }

    void copy (int origin[], int dim) {
	for(int i = 0; i < origin.length; i++)
	    tab[dim][i] = origin[i];
    }
    
    void addition (int mat[]) {
	
    }
}

public class ex7 {

    public static void main (String[] args) {
	Matrix matrice;
	matrice = new Matrix(2, 4);

	//System.out.println("0: "+matrice.tab[0][0]);
    }
}