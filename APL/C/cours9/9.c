#include <stdio.h>
#include <stdlib.h>

//Pos[m-1][X,Y]: position ligne/colonne
int dames(int m, int n, int pos[][2]){
  
  int i;

  if(pos[m-1][1] == n)
    return 0;

  //Diago / Ligne (Y)
  for(i = 0 ; i < n ; i++){
    if(i != m && (pos[i][1] == pos[m][1] || pos[i][0]-pos[m][0] == pos[i][1]-pos[m][1]))
      return 0;
  }
  return dames(m+1,n,pos);

}

int abs(){
  
}

void main(){
  
  int n = 4;

  int pos[4][2]={{0,0},{1,0},{2,0},{3,0}};
  
  dames(0,n,pos);
}
