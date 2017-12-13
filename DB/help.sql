COMMANDES:
SHOW TABLES : Affiche les tables
DELETE FROM Table WHERE Champ=? : Supprime Champ de Table
TRUNCATE table : Supprime tous les champs table
DESCRIBE table : Affiche champs de Table
UPDATE table SET champ='?' WHERE clé=?
INSERT INTO table VALUES(A,B,C,D) : Insère dans table les valeurs A,B,C,D
ALTER TABLE table ADD champ type <DEFAULT value>

OPERATIONS:

select SUM(Qtte),COUNT(Qtte),Qtte from Commande group by Qtte;
//Regroupe les quantités identiques, les additionne(2),affiche le nombre de qtte identiques(3) et affiche la quantité

OPERATION( ALL | DISTINCT | * | Champ )

GROUP BY Element : Effectue opération selon élément spécifié  

COUNT : Nombre lignes | SUM : Somme de valeurs | AVG : Moyenne

HAVING : Condition avec agrégats | ex: HAVING COUNT(Qtte) >= 8

LEFT (OUTER) JOIN : Liste tout éléments de la table de gauche et du join
