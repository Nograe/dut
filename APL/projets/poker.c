#include<stdio.h>
int combi(int p1, int p2, int p3, int p4, int p5, char t1, char t2, char t3, char t4, char t5, int option);

// Tri des 2 mains puis redirection vers attribution des points
int tri(int p1, int p2, int p3, int p4, int p5, char t1, char t2, char t3, char t4, char t5){

  int var=0;
  if(p1<p2){
    var=p1; p1=p2; p2=var;
  } if(p2<p3){
    var=p2; p2=p3; p3=var;
  } if(p3<p4){
    var=p3; p3=p4; p4=var;
  } if(p4<p5){
    var=p4; p4=p5; p5=var;
  }
  if(p1<p2 || p2<p3 || p3<p4 || p4<p5){
    tri(p1,p2,p3,p4,p5,t1,t2,t3,t4,t5);
    return;
  }
  //printf("Tri: %d %d %d %d %d\n",p1,p2,p3,p4,p5);
  //printf("%d\n",combi(p1,p2,p3,p4,p5,t1,t2,t3,t4,t5,0));
  return combi(p1,p2,p3,p4,p5,t1,t2,t3,t4,t5,0);
}

int combi(int p1, int p2, int p3, int p4, int p5, char t1, char t2, char t3, char t4, char t5, int option){
  //Carré, full et brelan

  if(p1==p2 && p1==p3 && p1==p4 || p2==p3 && p2==p4 && p2==p5){
    if(option==1 && p1==p2){return p2;}
    if(option==1 && p4==p5){return p4;}
    return 8;
  }
  if(p1==p2 && p1==p3){
    if(p4==p5){ return 7; }
    return 4;
  }
  if(p3==p4 && p3==p5){
    if(p1==p2){ return 7; }
    if(option==1){ return p3;}
    return 4;
  }
  if(p2==p3 && p2==p4){ return 4; }
  //Paire et double paire
  if(p1==p2){
    if(p4==p5 || p3==p4){ if(option==1){return p1;} return 3; }
    if(option==1){ return p1; }
    return 2;
  }
  if(p2==p3){
    if(p4==p5){ if(option==1){return p2;} return 3; }
    if(option==1){ return p2; }
    return 2;
  }
  if(p4==p5){
    if(option==1){ return p4; }
    return 2;
  }
  if(p3==p4){
  if(option==1){return p3;}
  return 2;
  }
  //Suite et quinte flush
  if(p1-p2==1 && p2-p3==1 && p3-p4==1 && p4-p5==1 || p5==1 && p1==13 && p2==12 && p3==11 && p4==10 || p1==14 && p2==5 && p3==4 && p4==3 && p5==2){
    if(t1==t2 && t1==t3 && t1==t4 && t1==t5){ return 9;}
    return 5;
  }
  //Couleur
  if(t1==t2 && t1==t3 && t1==t4 && t1==t5){ return 6;}

  //Autre
  return 0;
}

int trisimple(int v1, int v2, int v3, int v4, int v5, int vv1, int vv2, int vv3, int vv4, int vv5, int option){
  int var=0;
  if(v1<v2){
    var=v1; v1=v2; v2=var;
  } if(v2<v3){
    var=v2; v2=v3; v3=var;
  } if(v3<v4){
    var=v3; v3=v4; v4=var;
  } if(v4<v5){
    var=v4; v4=v5; v5=var;
  }
  if(v1<v2 || v2<v3 || v3<v4 || v4<v5){
    trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,option);
    return;
  }

  int var2=0;
  if(vv1<vv2){
    var2=vv1; vv1=vv2; vv2=var2;
  } if(vv2<vv3){
    var2=vv2; vv2=vv3; vv3=var2;
  } if(vv3<vv4){
    var2=vv3; vv3=vv4; vv4=var2;
  } if(vv4<vv5){
    var2=vv4; vv4=vv5; vv5=var2;
  }
  if(vv1<vv2 || vv2<vv3 || vv3<vv4 || vv4<vv5){
    trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,option);
    return;
  }

  if(v1==vv1 && v2==vv2 && v3==vv3 && v4==vv4 && v5==vv5){return 2;}

  //On retourne combi avec option=1 pour avoir valeur des cartes concernées par le combo
  if(option==1){
  return combi(v1,v2,v3,v4,v5,'A','B','C','D','E',1);
  }
  if(option==2){
  return combi(vv1,vv2,vv3,vv4,vv5,'A','B','C','D','E',1);
  }

  if(max(v1,vv1)==1){
    return 1;
  } else if(max(v1,vv1)==0){
    return 0;
  } else if(max(v1,vv1)==2){
    if(max(v2,vv2)==1){
      return 1;
    } else if(max(v2,vv2)==0){
      return 0;
    } else if(max(v2,vv2)==2){
      if(max(v3,vv3)==1){
	return 1;
      } else if(max(v3,vv3)==0){
	return 0;
      } else if(max(v3,vv3)==2){
	if(max(v4,vv4)==1){
	  return 1;
	} else if(max(v4,vv4)==0){
	  return 0;
	} else if(max(v4,vv4)==2){
	  if(max(v5,vv5)==1){
	    return 1;
	  } else if(max(v5,vv5)==0){
	    return 0;
	  } else if(max(v5,vv5)==2){
	    return 2;
	  }
	}
      }
    }
  }
}

int max(int x, int y){
  if(x>y){
    return 1;
  } else if(y>x){
    return 0;
  } else {
    return 2;
  }
}

void samecombi(int j1, int j2, int v1, int v2, int v3, int v4, int v5, int vv1, int vv2, int vv3, int vv4, int vv5){

  if(j1==2){
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==1){ printf("Player1 wins\n"); return;}
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==0){ printf("Player2 wins\n"); return;}
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==2){ samecombi(0,0,v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5); return; }
  }

  if(j1==3){
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==1){ printf("Player1 wins\n"); return;}
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==0){ printf("Player2 wins\n"); return;}
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==2){ samecombi(0,0,v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5); return; }
  }

  if(j1==4){
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==1){ printf("Player1 wins\n"); return;}
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==0){ printf("Player2 wins\n"); return;}
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==2){ samecombi(0,0,v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5); return; }
  }

  if(j1==8){
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==1){ printf("Player1 wins\n"); return;}
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==0){ printf("Player2 wins\n"); return;}
  if(max(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,1),trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,2))==2){ samecombi(0,0,v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5); return; }
  }

  if(j1==0 || j1==5 || j1==6 || j1==7 || j1==9){
    if(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,0)==1){
      printf("Player1 wins\n");
      return;
    }
    if(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,0)==0){
      printf("Player2 wins\n");
      return;
    }
    if(trisimple(v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5,0)==2){
      printf("Draw\n");
      return;
    }
  }
}

void main(){
  int v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5;
  char c1,c2,c3,c4,c5,cc1,cc2,cc3,cc4,cc5;
  scanf("%d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c",&v1,&c1,&v2,&c2,&v3,&c3,&v4,&c4,&v5,&c5,&vv1,&cc1,&vv2,&cc2,&vv3,&cc3,&vv4,&cc4,&vv5,&cc5);

  if(v1==1){v1=14;} if(v2==1){v2=14;} if(v3==1){v3=14;} if(v4==1){v4=14;} if(v5==1){v5=14;} if(vv1==1){vv1=14;} if(vv2==1){vv2=14;} if(vv3==1){vv3=14;} if(vv4==1){vv4=14;} if(vv5==1){vv5=14;}

  int combij1=tri(v1,v2,v3,v4,v5,c1,c2,c3,c4,c5);
  int combij2=tri(vv1,vv2,vv3,vv4,vv5,cc1,cc2,cc3,cc4,cc5);

  if(combij1>combij2){
    printf("Player1 wins\n"); return;
  } else if(combij1<combij2){
    printf("Player2 wins\n"); return;
  }
  if(combij1==combij2){
    samecombi(combij1, combij2,v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5) ;
    return;
  }
}
