1. select Region,COUNT(Region) as NombreVins from Vin group by Region;
+-----------+---------------+
| Region    | NombreVins    |
+-----------+---------------+
| Bordeaux  |             5 |
| Bourgogne |             4 |
| Champagne |             2 |
| Loire     |             5 |
+-----------+---------------+

2. select Nom,NumVitic,COUNT(Cru) as NombreCrus from Viticulteur natural join Vin group by NumVitic;
+-----------------------+----------+------------+
| Nom                   | NumVitic | NombreCrus |
+-----------------------+----------+------------+
| Moulin                |        1 |          1 |
| Morin                 |        3 |          1 |
| Vallee                |        4 |          3 |
| Coulis Dutheil        |        5 |          1 |
| Parent                |       10 |          2 |
| Barancourt            |       15 |          2 |
| Jadot                 |       16 |          1 |
| Medeville             |       18 |          2 |
| Lynch-Bages           |       21 |          1 |
| Chateau Monbrison     |       22 |          1 |
| Chateau Moulin A Vent |       23 |          1 |
+-----------------------+----------+------------+

3. select Nom,NumBuveur,AVG(Qtte) as MoyenneCommande from Buveur natural join Commande where Ville="Paris" group by NumBuveur;
+---------+-----------+-----------------+
| Nom     | NumBuveur | MoyenneCommande |
+---------+-----------+-----------------+
| Maury   |      1200 |          7.5000 |
| Gautier |      1400 |         12.0000 |
| Dupond  |      1600 |          6.0000 |
+---------+-----------+-----------------+

4. select Nom,Count(NumBuveur) as NombreCommandes from Buveur natural join Commande group by NumBuveur;
+---------+-----------------+
| Nom     | NombreCommandes |
+---------+-----------------+
| Combet  |               2 |
| Maury   |               2 |
| Jamet   |               1 |
| Gautier |               1 |
| Fradet  |               2 |
| Dupond  |               2 |
+---------+-----------------+

5. select Nom,SUM(Qtte) as SommeQuantite from buveur natural join Commande group by NumBuveur having AVG(Qtte)>=12;
+---------+---------------+
| Nom     | SommeQuantite |
+---------+---------------+
| Gautier |            12 |
| Fradet  |            42 |
+---------+---------------+

6. select Nom,NumVitic from Viticulteur natural join Vin group by NumVitic having COUNT(distinct Cru)>=2;
+------------+----------+
| Nom        | NumVitic |
+------------+----------+
| Vallee     |        4 |
| Parent     |       10 |
| Barancourt |       15 |
| Medeville  |       18 |
+------------+----------+

7. select NumVin,Cru,COUNT(NumVin) as NombreCommandes from Vin natural join Commande group by (NumVin) having COUNT(NumVin)>=2;
+--------+------------+-----------------+
| NumVin | Cru        | NombreCommandes |
+--------+------------+-----------------+
|     88 | Chambertin |               2 |
|    140 | Pommard    |               4 |
+--------+------------+-----------------+

8. select Commande.NumCom from Commande,Livraison where Commande.NumCom=Livraison.NumCom group by NumCom having SUM(distinct Commande.Qtte)-SUM(Livraison.Qtte) > 0;
+--------+
| NumCom |
+--------+
|      3 |
+--------+
