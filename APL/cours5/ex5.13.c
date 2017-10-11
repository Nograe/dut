#include <stdio.h>

void croix(int n, int var, int var2, int line) {
    //printf("N:%d 	var:%d 		var2:%d 	line:%d\n",n,var,var2,line);
    int i,j;

    if(line==n) {
        var2=var;
    }
    if(line==n+1) {
        var=1;
    }

    if(line==2*n+1) {
        return;
    }

    if(line>n) {
        for(j=0; j<var2; j++) {
            printf(" ");
        }
        printf("*");
    }

    for(i=0; i<var; i++) {
        printf(" ");
    }

    printf("*");
    if(line>=n) {
        printf("\n");
    }

    if(line>=n) {
        croix(n,var+2,var2-1,line+1);
        return;
    } else {
        for(j=0; j<var2; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    croix(n,var+1,var2-2,line+1);
    return;
}

void main() {
    int n;
    scanf("%d",&n);
    croix(n,0,(2*n-1),0);
}

