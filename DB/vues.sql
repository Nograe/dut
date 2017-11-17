VUE : Table virtuelle, basée sur une requête SELECT
Les VUES ne contiennent pas de données, contrairement aux table

Syntaxe: CREATE VIEW nom_vue(Champ1,Champ2,Champ3)
	 AS (SELECT Attribut1,Attribut2,Attribut3
	 FROM Table WHERE *)

Ex:	 create view BonClient(Num,Nom,Ville,Achats)
     	 as select NumBuveur,Nom,Ville,COUNT(NumBuveur)
	 from Buveur natural join Commande group by(NumBuveur)
	 