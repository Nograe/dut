SQL89
1 select <distinct> Buveur.NumBuveur,Nom,Ville from Buveur,Commande where Buveur.NumBuveur=Commande.NumBuveur;
2 select distinct Viticulteur.NumVitic,Nom,Ville from Viticulteur,Vin where Viticulteur.NumVitic=Vin.NumVitic and Vin.Region='Loire' and Vin.Millesime='1983';
3 select distinct Buveur.NumBuveur,Buveur.Nom from Buveur,Commande,Vin where Buveur.NumBuveur=Commande.NumBuveur and Commande.NumVin=Vin.NumVin and Vin.Cru='Pommard';
4 select distinct Viticulteur.Prenom from Buveur,Commande,Viticulteur,Vin where Vin.NumVitic=Viticulteur.NumVitic and Commande.NumVin=Vin.NumVin and Commande.NumBuveur=1600;
5 select distinct Viticulteur.Prenom from Buveur,Commande,Viticulteur,Vin where Vin.NumVitic=Viticulteur.NumVitic and Commande.NumVin=Vin.NumVin and Commande.NumBuveur=Buveur.NumBuveur and Buveur.Nom='Dupond';
6 select distinct Viticulteur.NumVitic,Viticulteur.Prenom,Viticulteur.Ville from Viticulteur,Commande,Vin,Buveur and Viticulteur.NumVitic=Vin.NumVitic and Commande.NumVin=Vin.NumVin and Commande.NumBuveur=Buveur.NumBuveur and Buveur.Ville=Viticulteur.Ville;
7. select * from Buveur where Ville in (select Ville from Buveur where NumBuveur=1400) and Buveur.NumBuveur!=1400;
//Afficher Buveur1 et Buveur2 avec Buveur2 qui habite dans la même ville que Buveur1=1400
select distinct B1.Ville, B1.NumBuveur, B2.Ville, B2.NumBuveur from Buveur as B1, Buveur as B2 where B1.NumBuveur=1400 and B1.Ville=B2.Ville;
//Enlever la table Buveur1 <sans Buveur1=1400>
7.1 select B2.Ville, B2.NumBuveur from Buveur as B1, Buveur as B2 where B1.NumBuveur=1400 and B1.Ville=B2.Ville <>;
7.1.1 
7.2 select * from Buveur where Ville=any (select Ville from Buveur where NumBuveur=1400) <and NumBuveur!=1400>;

SQL92
1 select <distinct> Buveur.NumBuveur,Nom,Ville from Buveur natural join Commande;
2 select distinct Viticulteur.NumVitic,Nom,Ville from Viticulteur natural join Vin where Region='Loire' and Millesime=1983;
3 select distinct Buveur.NumBuveur,Buveur.Nom from Buveur natural join Commande natural join Vin where Cru='Pommard';
4 select distinct Viticulteur.Prenom from Viticulteur join Vin using (NumVitic) join Commande using (NumVin) join Buveur using (NumBuveur) where Buveur.NumBuveur=1600;
5 select distinct Viticulteur.Prenom from Viticulteur join Vin using (NumVitic) join Commande using (NumVin) join Buveur using (NumBuveur) where Buveur.Nom='Dupond';
6 select distinct Viticulteur.NumVitic,Viticulteur.Prenom,Viticulteur.Ville from Viticulteur join Vin using (NumVitic) join Commande using (NumVin) join Buveur using (NumBuveur) where Buveur.Ville=Viticulteur.Ville; 


ALL: Cherche à remplir toutes les 2 conditions dans la sous-requête (Ne sélectionne pas Paris dans ('Paris' ou 'Versailles')

ANY: Fonctionne comme un OR, sélectionne l'élément même s'il ne vérifie qu'1 seule condition de la sous-requête (Sélectionne Paris dans ('Paris' ou 'Versailles')

T1 natural join T2: Produit cartésien entre T1 et T2, en utilisant comme clé étrangère le même nom de clé
T1 join T2 using (NomClé): Produit cartésien entre T1 et T2, en utilisant la clé spécifiée entre parenthèses.

EXISTS : (select NomP,Prix from Produit as P where exists(select from Livraison where Livraison.NomP=P.NomP))