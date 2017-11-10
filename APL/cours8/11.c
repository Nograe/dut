#include <stdio.h>
#include <stdlib.h>

int strlength(char* str) {

    int i=0;

    while(str[i]!='\0') {
        i++;
    }

    return i;
}

char **split(char *str, char delim, int *nb) {

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
        var++;
        result[*nb-elements] = malloc(var * sizeof(char));
        var--;
        result[*nb-elements][var]='\0';

        //Remplissage de chaque case(string)
        for(i=0;i<var;i++){
//printf("Element %d : str[%d]=%c\n",elements,total+i,str[total+i]);
            result[*nb-elements][i]=str[total+i];
        }

        elements--;
        j++;
        total+=var+1;
        var=0;
//printf("Elements restants: %d\n",elements);
    }

    return (char **)result;
}

void main() {
    int nb=0,i=0;
    char *chain="Je suis trop tres bcp cool";

    char **result = split(chain,' ',&nb);

	for(i=0;i<nb;i++)
		printf("%s\n",result[i]);

}
