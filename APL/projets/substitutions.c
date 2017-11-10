#include <stdio.h>
#include <stdlib.h>
int strlength(char* str);
char **identify(char *str, char delim, int *nb, int *result);
void insert(char **chain, char *subst, int total, int elements);
void identify_rule(char *rule, char *replace, char *subst);


int strlength(char* str) {

    int i=0;

    while(str[i]!='\0') {
        i++;
    }

    return i;
}

char **identify(char *str, char delim, int *nb, int *reste) {

    int taille=strlength(str),i,j=0,elements=*nb,total=0;
    int var=0;	//Taille de chaque élément(string)

    for(i=0; i<taille; i++) {
        if(str[i]==delim)
            elements++;
    }

    elements++;
    *nb=elements;

    //Création d'autant de cases(string) que d'éléments
    char **result = malloc(sizeof(char) * elements);

    while(elements!=0) {
        //Délimitation de la taille de chaque élément
        while(str[j]!=delim && j!=taille) {
//printf("'%c' ? '%c'\n",str[j],delim);
            var++;
            j++;
        }
//printf("Found! Taille:%d\n",var);

        //Allocation pour chaque string
        result[*nb-elements] = malloc(var+1 * sizeof(char));
        result[*nb-elements][var]='\0';

        //Remplissage de chaque case(string)

        for(i=0; i<var; i++) {
//printf("Element %d : str[%d]=%c\n",elements,total+i,str[total+i]);
            result[*nb-elements][i]=str[total+i];
        }

        elements--;
        j++;
        total+=var+1;
        var=0;
//printf("Elements restants: %d\n",elements);
    }

    *reste=total-*nb;

    return (char **)result;
}

void insert(char **origin,char *subst,int reste,int elements) {

    int i=0,j=0,var=0,z;
    int taille_subst = strlength(subst);
    int taille_complete = (elements * taille_subst)+reste;

    char *result = malloc( sizeof(char) * taille_complete+1 );
    result[taille_complete]='\0';

    if(strlength(origin[0])==0) {
        for(i=0; i<taille_subst; i++)
            result[i]=subst[i];
        var++;
    }

    while(var<=elements) {
        for(j=i,z=0; z<strlength(origin[var]); j++,z++) {
            result[j]=origin[var][z];
            //printf("result[%d]:%c   origin[%d][%d]:%c \n",j,result[j],var,z,origin[var][z]);
        }

        var++;
        if(var>elements)
            break;

        for(i=j,z=0; z<taille_subst; i++,z++){
            result[i]=subst[z];
			//printf("result[%d]:%c   subst[%d]:%c \n",i,result[i],z,subst[z]);
        }
    }
	printf("%s\n",result);
}

void identify_rule(char *rule, char *replace, char *subst){

    int i=0;

    //Identification règles
    while(rule[i]=='[' || rule[i]==' ')
        i++;

    replace[0]=rule[i];

    i++;
    while(rule[i]!='-')
        i++;

    i=i+2;
    while(rule[i]==' ')
        i++;

    int j=0;
    while(rule[i]!=' ' && rule[i]!=']'){
        subst[j]=rule[i];
        i++; j++;
    }
    subst[j]='\0';

}

int main(int argc, char *argv[]) {

    /*char rule[100];
    scanf("%[^\n]",rule);
    char origin[100];
    scanf("%s[^\n]",origin);
    int repet;
    scanf("%d",&repet);*/
    if(argv[3][0] == '0'){
        printf("%s\n",argv[2]);
        return 0;
    }

    int elements=0,reste=0;

    char replacetab[1];
    char subst[100];
    identify_rule(argv[1],replacetab,subst);
    char replace=replacetab[0];

    char **result = identify(argv[2],replace,&elements,&reste);
    insert(result, subst, reste, elements-1);

    return 0;
}
