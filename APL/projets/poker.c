#include<stdio.h>
int combi(int p1, int p2, int p3, int p4, int p5, char t1, char t2, char t3, char t4, char t5);

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
    if(p1<p2 || p2<p3 || p3<p4){
    tri(p1,p2,p3,p4,p5,t1,t2,t3,t4,t5);
    }
    return combi(p1,p2,p3,p4,p5,t1,t2,t3,t4,t5);
}

int combi(int p1, int p2, int p3, int p4, int p5, char t1, char t2, char t3, char t4, char t5){
    //Carré, full et brelan
    if(p1==p2==p3==p4 || p2==p3==p4==p5){
        return 8;
    }
    if(p1==p2==p3){
        if(p4==p5){ return 7; }
        return 4;
    }
    if(p3==p4==p5){
        if(p1==p2){ return 7; }
        return 4;
    }
    if(p2==p3==p4){ return 4; }
    //Paire
    if(p1==p2){
        if(p4==p5){ return 3; }
        return 2;
    }
    if(p4==p5){
        if(p1==p2){ return 3; }
        return 2;
    }
    if(p2==p3 || p3==p4){ return 2; }
    //Suite et quinte flush
    if(p1-p2==1 && p2-p3==1 && p3-p4==1 && p4-p5==1 || p5==1 && p1==13 && p2==12 && p3==11 && p4==10){
        if(t1==t2 && t1==t3 && t1==t4 && t1==t5){ return 9;}
        return 5;
    }
    //Couleur
    if(t1==t2 && t1==t3 && t1==t4 && t1==t5){ return 9;}
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
    if(j1==0 || j1==5 || j1==6 || j1==9){
        if(max(v1,vv1)==1){
            printf("Player1 wins\n");
            return;
        }
        if(max(v1,vv1)==0){
            printf("Player2 wins\n");
            return;
        }
        if(max(v1,vv1)==2){
            max(v2,vv2);
            return;
        }
    }

}

void main(){
    int v1,v2,v3,v4,v5,vv1,vv2,vv3,vv4,vv5;
    char c1,c2,c3,c4,c5,cc1,cc2,cc3,cc4,cc5;
    scanf("%d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c",&v1,&v2,&v3,&v4,&v5,&vv1,&vv2,&vv3,&vv4,&vv5,&c1,&c2,&c3,&c4,&c5,&cc1,&cc2,&cc3,&cc4,&cc5);

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
