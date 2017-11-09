#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* Fichier = NULL;
    Fichier = fopen("test.txt", "r");

    if (Fichier != NULL)
    {
        printf ("Fichier ouvert, pointeur: %p",Fichier);
    }
    else
    {
        printf ("Erreur.");
    }

	return 0;

}
