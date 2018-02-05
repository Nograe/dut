#include <stdio.h>
int main(int argc, char* argv[]) {
	
  int lp1;
  int cp1;
  char p;
  int lp2;
  int cp2;
  scanf("%d %d  %c %d %d",&lp1,&cp1,&p,&lp2,&cp2);

  if(p=='R'){
    if(lp1-lp2==1 && cp1==cp2 || lp1-lp2==-1 && cp1==cp2 || cp1-cp2==1 && lp1==lp2 || cp1-cp2==-1 && lp1==lp2 || lp2==lp1+1 && cp2==lp1+1 || lp2==lp1+1 && cp2==lp1-1 || lp2==lp1-1 && cp2==lp1+1 || lp2==lp1-1 && cp2==lp1-1){
      printf("Echec\n");
    } else {
      printf("Pas Echec\n");
    }
  }

  if(p=='D'){
    if(lp1==lp2 || cp1==cp2 || cp1-cp2==lp1-lp2 || cp1-cp2==-(lp1-lp2)){
      printf("Echec\n");
    } else {
      printf("Pas Echec\n");
    }
  }

  if(p=='T'){
    if(lp1==lp2 || cp1==cp2){
      printf("Echec\n");
    } else {
      printf("Pas Echec\n");
    }  
  }

  if(p=='C'){
  if(lp2+2==lp1 && cp2+1==cp1 || lp2+2==lp1 && cp2-1==cp1 || lp2-2==lp1 && cp2+1==cp1 || lp2-2==lp1 && cp2-1==cp1 || cp2+2==cp1 && lp2+1==lp1 || cp2+2==cp1 && lp2-1==lp1 || cp2-2==cp1 && lp2+1==lp1 || cp2-2==cp1 && lp2-1==lp1){
      printf("Echec\n");
    } else {
      printf("Pas Echec\n");
    } 
    }

  if(p=='F'){
    if(cp1-cp2==lp1-lp2 || cp1-cp2==-(lp1-lp2)){
      printf("Echec\n");
    } else {
      printf("Pas Echec\n");
    } 
    }

  return 0;
}
