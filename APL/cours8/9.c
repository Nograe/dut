#include <stdio.h>
#include <stdlib.h>

int strlength(char* str) {

    int i=0;

    while(str[i]!='\0') {
        i++;
    }

    return i;
}

char *strcat(char *str1, char *str2) {

    int long1=strlength(str1),long2=strlength(str2);
    char *chain = malloc(sizeof(char) * (long1+long2+1));
    int i,j,z=0;

    for(i = 0;i < long1;i++)
    	chain[i]=str1[i];
    for(j = i;j < long1+long2;j++){
    	chain[j]=str2[z];
    	z++;
    }

    chain[long1+long2]='\0';

    return chain;

}

void main() {
    printf("%s",strcat("tur","WCYO"));
}
