
    sizeof(type / variable) : renvoie taille en octets
        
        ex: sizeof(int) = 4
    
    malloc(X octets) : alloue X octets dans la mémoire
                       retourne un pointeur vers 1er octet
                       
        ex: scanf("%d",&taille);
            int *tab;
            tab = malloc(sizeof(int) * taille);
            
    free(pointeur) : libère mémoire allouée à/aux adresse(s) pointées
        
        ex: free(tab)
        
    realloc(pointeur, X octets) : efface et ré-alloue à l'adresse X octets
    
        ex: realloc(tab, sizeof(int) * taille + 1);