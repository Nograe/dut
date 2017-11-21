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
fputc(char, fichier); //Ecrit caract�re
fputs(char*, fichier); //Ecrit cha�ne
fprintf(fichier, "... %X ...",typeX); //Custom


///Lire dans fichier
fgetc(fichier); //Scan les char � la suite
fgets(*chaine, X char, fichier); //Lit X char ; max: '\n', stock� dans "chaine"
fscanf(fichier, "... %X ... %Y",typeX, typeY); //Custom
///EOF = Fin fichier
while(char_lu != EOF)
/* Code */

///Position
ftell(fichier); //Renvoie la position
fseek(fichier, long deplacement, int depart)
	SEEK_CUR; SEEK_END; SEEK_SET;
rewind(fichier) //Retourne au d�but

///Renommer/Supprimer
rename(char* ancienNom, char* nouveauNom);
remove(char* nomFichier);
