#include <stdio.h>
#include <stdlib.h>
int strlength(char* str);
void copy(char *origin, char *copy);
int new_size(char *origin, char idrule[][256]);
void identify_rule(char *rule,char idrule[][256]);
void replace(char *origin, char idrule[][256], char *result);


int strlength(char* str) {

    int i=0;

    while(str[i]!='\0') {
        i++;
    }

    return i;
}

void copy(char *origin, char *copy) {

    int i,taille = strlength(origin);
    //printf("Original: %s | Copy: %s\n",origin,copy);

    for(i = 0 ; i <= taille ; i++) {

        copy[i] = origin[i];
        //printf("%d| origin: '%c' -> copy: '%c'\n",i,origin[i],copy[i]);

    }

}

int new_size(char *origin, char idrule[][256]) {

    int size = strlength(origin)+1;

    int i=0,ascii=0;

    while(origin[i] != '\0') {
        ascii = (int)origin[i];

        if(idrule[0][ascii] != '\0')
            size += idrule[0][ascii]-1;

        i++;
    }

    return (size*sizeof(char));
}

void identify_rule(char *rule,char idrule[][256]) {

    int i=0,j=0,c=0,ascii=0;;

    while(rule[i]!=']') {
        j=0;
        i++;

        while(rule[i]==' ' || rule[i] == ',')
            i++;

        if(rule[i]==']')
            break;

        ///Caractère à remplacer
        ascii = (int)rule[i];
        //printf("idrule[%d][0]: %c\n",c,idrule[c][0]);

        i++;
        while(rule[i] != '-')
            i++;

        i=i+2;
        while(rule[i] == ' ')
            i++;

        while(rule[i] != ' ' && rule[i] != ']' && rule[i] != ',') {
            idrule[ascii][j] = rule[i];
            //printf("idrule[%d][%d]: %c\n",ascii,j,idrule[ascii][j]);
            i++;
            j++;
        }
        idrule[ascii][j] = '\0';
        idrule[0][ascii] = j;
        //printf("Taille du replace: %d\n",idrule[c][1]);
    }
}

void replace(char *origin, char idrule[][256], char *result) {

    int i=0,c=0,j=0,ascii=0;

    while(origin[i] != '\0') {
        ascii = (int)origin[i];

        if(idrule[ascii][0] == '\0') {
            result[c] = origin[i];
            //printf("NO RULE | result[%d]: %c\n",c,result[c]);
            c++;
        } else {
            j = 0;
            while(idrule[ascii][j] != '\0') {
                result[c] = idrule[ascii][j];
                //printf("idrule[%d][%d]: %c -> result[%d]: %c\n",ascii,j,idrule[ascii][j],c,result[c]);
                j++;
                c++;
            }
        }
        i++;
    }
}

int main(int argc, char *argv[]) {

    char *rule_origin=argv[1];
    char *origin=argv[2];
    int repet=argv[3][0]-'0';
    if(argv[3][1] == '0' && argv[3][0] == '1') {
        repet = 10;
    }
    //printf("%d\n",repet);

    if(repet == 0) {
        printf("%s",origin);
        return 0;
    }

    ///Contient chaque règle, le idchar: [r][0] et la taille: [r][1], taille totale: [0][0]
    char idrule[256][256] = {{'0'}};
    identify_rule(rule_origin,idrule);

    /*int j;
    for(j = 0 ; j < 256 ; j++) {
        if(idrule[j][0] != '\0')
            printf("%d | %s | %d \n", j, idrule[j], idrule[0][j]);
    }*/

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
        ///Provisoire
        if(i == repet && i != 1) {
            break;
        }

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
