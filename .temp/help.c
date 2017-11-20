///Ouvrir fichier
#include <stdio.h>
int main(int argc, char *argv[]) {
    FILE* fichier = NULL;
    fichier = fopen("temp.txt", "r+");
    if (fichier == NULL)
        return 1;
    /* 	  Code    */
    fclose(fichier);
    return 0;
}

///Ecrire dans fichier
fputc(char, fichier); //Ecrit caractère
fputs(char*, fichier); //Ecrit chaîne
fprintf(fichier, "... %X ...",typeX); //Custom


///Lire dans fichier
fgetc(fichier); //Scan les char à la suite
fgets(*chaine, X char, fichier); //Lit X char ; max: '\n', stocké dans "chaine"
fscanf(fichier, "... %X ... %Y",typeX, typeY); //Custom
///EOF = Fin fichier
while(char_lu != EOF)
/* Code */
