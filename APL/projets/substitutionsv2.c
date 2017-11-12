#include <stdio.h>
#include <stdlib.h>
int strlength(char* str);
void identify_rule(char *rule,char idrule[][100]);
void replace(char *origin, char idrule[][100], char *result);


int strlength(char* str) {

    int i=0;

    while(str[i]!='\0') {
        i++;
    }

    return i;
}

void copy(char *origin, char *copy){

    int i;
    //printf("Original: %s | Copy: %s\n",origin,copy);

    for(i = 0 ; i <= strlength(origin) ; i++){

        copy[i] = origin[i];
        //printf("%d| origin: '%c' -> copy: '%c'\n",i,origin[i],copy[i]);

    }

}

int new_size(char *origin, char idrule[][100]) {

    int size = strlength(origin)+1;

    int i=0,j;

    while(origin[i] != '\0') {

        ///Parcours de chaque règle pour trouver un idchar dans origin, stocké dans idrule[r][0]
        for(j = 1 ; j <= (int)idrule[0][0] ; j++) {
            if(idrule[j][0] == origin[i]) {
                size = size + idrule[j][1];
                size--;
                //printf("Found: %c | size = %d\n",idrule[j][0],size);
            }
        }
        i++;
    }

    return (size*sizeof(char));
}

void identify_rule(char *rule,char idrule[][100]) {

    int i=0,j,c=0;

    while(rule[i]!=']') {
        j=2;
        c++;
        i++;

        while(rule[i]==' ' || rule[i] == ',')
            i++;

        if(rule[i]==']')
            break;

        ///Caractère à remplacer
        idrule[c][0] = rule[i];
        //printf("idrule[%d][0]: %c\n",c,idrule[c][0]);

        i++;
        while(rule[i] != '-')
            i++;

        i=i+2;
        while(rule[i] == ' ')
            i++;

        while(rule[i] != ' ' && rule[i] != ']' && rule[i] != ',') {
            idrule[c][j]=rule[i];
            //printf("\tidrule[%d][%d]: %c\n",c,j,idrule[c][j]);
            i++;
            j++;
        }
        idrule[c][1]=j-2;
        //printf("Taille du replace: %d\n",idrule[c][1]);
    }
    idrule[0][0]=c;
    //printf("Nombre regles: %d\n",idrule[0][0]);
}

void replace(char *origin, char idrule[][100], char *result) {

    int i=0,c=0,j,k;

    while(origin[i] != '\0') {

        result[c] = origin[i];
        //printf("result[%d]: %c\n",c,result[c]);
        ///Parcours de chaque règle pour trouver un idchar dans origin, stocké dans idrule[r][0]
        for(j = 1 ; j <= (int)idrule[0][0] ; j++) {

            if(idrule[j][0] == origin[i]) {

                for(k = 2 ; k <= idrule[j][1]+1 ; k++){
                    result[c] = idrule[j][k];
                    //printf("\tidrule[%d][%d]: %c -> result[%d]: %c\n",j,k,idrule[j][k],c,result[c]);
                    c++;
                }
                c--;
            }
        }
        i++;
        c++;
    }
}

int main(int argc, char *argv[]) {

    char *rule_origin=argv[1];
    char *origin=argv[2];
    int repet=argv[3][0]-'0';
    if(argv[3][1] == '0' && argv[3][0] == '1'){
        repet = 10;
    }
    //printf("%d\n",repet);

    if(repet == 0){
        printf("%s",origin);
        return 0;
    }

    ///Contient chaque règle, le idchar: [r][0] et la taille: [r][1], taille totale: [0][0]
    char idrule[100][100] = {{'0'}};
    identify_rule(rule_origin,idrule);

    int i;
    char *result;
    int size;

    for(i = 1 ; i <= repet ; i++) {

        if(i != 1)
            free(result);

        size = new_size(origin, idrule);
        //printf("\nNew size: %d\n",size);
        result = malloc(size);

        replace(origin, idrule, result);

        result[size-1] = '\0';

        if(i != 1)
            free(origin);

        origin = malloc(size);
        copy(result, origin);

    }
    printf("%s\n",result);

    free(result);
    free(origin);

    return 0;
}
