#include <stdio.h>

int main(int argc, char* argv[]) {
  
  int d1,d2,d3,a1,a2,a3;
  scanf("%d %d %d %d %d %d",&d1,&d2,&d3,&a1,&a2,&a3);

  int x1,y1,z1,x2,y2,z2;
//Tri dés
  if(d1>=d2 && d2>=d3){
    x1=d1; y1=d2; z1=d3;
  } if(d1>=d3 && d3>=d2){
    x1=d1; y1=d3; z1=d2;
  } if(d2>=d3 && d3>=d1){
    x1=d2; y1=d3; z1=d1;
  } if(d2>=d1 && d1>=d3){
    x1=d2; y1=d1; z1=d3;
  } if(d3>=d2 && d2>=d1){
    x1=d3; y1=d2; z1=d1;
  } if(d3>=d1 && d1>=d2) {
    x1=d3; y1=d1; z1=d2;
  }

  if(a1>=a3 && a3>=a2){
    x2=a1; y2=a3; z2=a2;
  } if(a1>=a2 && a2>=a3){
    x2=a1; y2=a2; z2=a3;
  } if(a2>=a1 && a1>=a3){
    x2=a2; y2=a1; z2=a3;
  } if(a2>=a3 && a3>=a1){
    x2=a2; y2=a3; z2=a1;
  } if(a3>=a2 && a2>=a1){
    x2=a3; y2=a2; z2=a1;
  } if(a3>=a1 && a1>=a2) {
    x2=a3; y2=a1; z2=a2;
  }
  
//Attribution combos spéciaux
  int cj1=0; int cj2=0;
  if(x1==y1+1 && y1==z1+1){
    cj1=1;
  } if(z1==1 && y1==1 && x1>1){
    cj1=2;
  } if(x1==y1 && x1==z1){
    cj1=3;
  } if(x1==4 && y1==2 && z1==1){
    cj1=4;
  }

  if(x2==y2+1 && y2==z2+1){
    cj2=1;
  } if(z2==1 && y2==1 && x2>1){
    cj2=2;
  } if(x2==y2 && x2==z2){
    cj2=3;
  } if(x2==4 && y2==2 && z2==1){
    cj2=4;
  }
//Comparaisons
  //Combo spéciaux (1)
  if(cj1>cj2){
    printf("Player1 wins\n");
  } if(cj2>cj1){
    printf("Player2 wins\n");
  }
  //Combo suites et fiches (2-3)
  if(cj1==cj2 && cj1>0 && cj1<3){
    if(x1>x2){
      printf("Player1 wins\n");
    } if(x2>x1){
      printf("Player2 wins\n");
    }
  }
  //Combo triplets (4)
  if(cj1==cj2 && cj1==3){
    if(x1>x2){
      printf("Player1 wins\n");
    } else if(x2>x1){
      printf("Player2 wins\n");
    }
  }

  //Combo quelconque (5)
  if(cj1==cj2 && cj1==0){
    if(x1>x2){
      printf("Player1 wins\n");
      return 0;
    } if(x1==x2 && y1>y2){
      printf("Player1 wins\n");
      return 0;
    } if(x1==x2 && y1==y2 && z1>z2){
      printf("Player1 wins\n");
      return 0;
    } else{
      printf("Player2 wins");
      return 0;
    }
  }

  //Draw
  if(x1==x2 && y1==y2 && z1==z2){
    printf("Draw\n");
  }
  return 0;
}
