#include <stdio.h>

int taille(int nb){
  
  int leng = 0;
  
  if(nb == 0)
    return 1;

  while(nb > 0){
    nb/=10;
    leng++;
  }

  return leng;

}

int get(int nb, int pos){

  int i;
  int mult = 1;

  for( i = 1 ; i < taille(nb)-pos ; i++)
    mult*=10;

  return nb/mult%10;

}

int miroir(int nb){
  
  int i;
  int exclude;
  int tnb = taille(nb);

  if(tnb%2 == 0)
    exclude = tnb/2;
  else
    exclude = (tnb/2)+1;

  if(tnb == 1)
    return 1;

  tnb--;

  for(i = 0 ; i < tnb ; i++ ){
    if( get(nb,i) != get(nb,tnb-i) && i != exclude){
      //printf("Pos: %d et %d | Compare: %d et %d\n",i,tnb-i,get(nb,i),get(nb,tnb-i));
      return 0;
    }
  }

  return 1;

}

void main(){

  //printf("taille: %d\n",taille(3521));

  /*int i;
  for( i = 0 ; i < 5 ; i ++)
    printf("Positon %d: %d\n",i,get(95438,i));
  */

  //printf("miroir: %d\n",miroir(28482));

}
