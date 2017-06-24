SQL89
1.select <distinct> Buveur.NumBuveur,Nom,Ville from Buveur,Commande where Buveur.NumBuveur=Commande.NumBuveur;
1.1.select <distinct> Buveur.NumBuveur,Nom,Ville from Buveur natural join Commande;
2.
2.1.

SQL92