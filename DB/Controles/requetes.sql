1.select * from Client;
+----------+---------------------+---------------+
| idClient | nom                 | ville         |
+----------+---------------------+---------------+
|        1 | Bob Marley          | Kingston      |
|        2 | Harrison Stafford   | San Francisco |
|        3 | Billy Gibbons       | Houston       |
|        4 | Dusty Hill          | Houston       |
|        5 | Janis Joplin        | San Francisco |
|        6 | Michael Jackson     | Los Angeles   |
|        7 | Nina Simone         | Mount Vernon  |
|        8 | Brahim Zaibat       | Paris         |
|        9 | Benjamin Millepied  | Paris         |
|       10 | Maurice Béjart      | Marseille     |
|       11 | Charles Beaudelaire | Paris         |
+----------+---------------------+---------------+

2.select distinct Client.idClient from Client,Commande where Client.idClient=Commande.idClient;
+----------+
| idClient |
+----------+
|        1 |
|        2 |
|        3 |
|        4 |
|        6 |
|        7 |
|        8 |
|        9 |
|       10 |
|       11 |
+----------+

3. select idChocolat,nomChocolat,Chocolatier.nom from Chocolat,Chocolatier where Chocolat.idChocolatier=Chocolatier.idChocolatier and biologique=1;
+------------+-------------+-----------------------+
| idChocolat | nomChocolat | nom                   |
+------------+-------------+-----------------------+
|          3 |           0 | Larnicol              |	//-> nomChocolat était un int à la création au lieu d'un Varchar, donc affiche 0
|         20 |           0 | Patrick Roger         |
|         26 |           0 | Jacques Genin         |
|         27 |           0 | La Maison du chocolat |
|         28 |           0 | La Maison du chocolat |
+------------+-------------+-----------------------+

4. select distinct Chocolatier.idChocolatier,Chocolatier.nom from Chocolat,Chocolatier where Chocolat.idChocolatier=Chocolatier.idChocolatier and Chocolat.biologique=1;
select distinct Chocolatier.idChocolatier,Chocolatier.nom from Chocolat natural join Chocolatier where biologique=1;


+---------------+-----------------------+
| idChocolatier | nom                   |
+---------------+-----------------------+
|             3 | Larnicol              |
|             5 | Patrick Roger         |
|             6 | Jacques Genin         |
|             7 | La Maison du chocolat |
+---------------+-----------------------+

5. select nom from Chocolatier where nom like '%de%';
+----------------+
| nom            |
+----------------+
| Jeff De Bruges |
| De Neuville    |
+----------------+
