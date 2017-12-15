EXERCICE 2

2. select distinct idChocolatier, nom from Chocolat natural join Chocolatier where biologique = 1 order by nom;
+---------------+-----------------------+
| idChocolatier | nom                   |
+---------------+-----------------------+
|             6 | Jacques Genin         |
|             7 | La Maison du chocolat |
|             3 | Larnicol              |
|             5 | Patrick Roger         |
+---------------+-----------------------+

3. Le produit cartésien renvoie toutes les combinaisons des tuples de Chocolatier et Chocolat.
La jointure (naturelle) permet de combiner les tuples de Chocolat et Chocolatier, basée sur le champ commun qui est 'idChocolatier', elle n'affiche pas toutes les combinaisons possibles.

4. Cette jointure est pertinente, en effet on peut retrouver grâce à elle le nom du client qui a commandé, ainsi que sa ville. Ce qui pourrait faciliter la livraison.

EXERCICE 3

1. create table Livreur (
   idLivreur INTEGER PRIMARY KEY,
   Nom VARCHAR(25) NOT NULL,
   idCommande INTEGER NOT NULL,
   FOREIGN KEY (idCommande) REFERENCES Commande (idCommande)
   );
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| idLivreur  | int(11)     | NO   | PRI | NULL    |       |
| Nom        | varchar(25) | NO   |     | NULL    |       |
| idCommande | int(11)     | NO   | MUL | NULL    |       |
+------------+-------------+------+-----+---------+-------+

2. show tables;
+-------------------+
| Tables_in_chocoDB |
+-------------------+
| Chocolat          |
| Chocolatier       |
| Client            |
| Commande          |
| Livreur           |
+-------------------+

EXERCICE 4

1. alter table Chocolat add Perempt DATE default '2018-01-01';
+------------------+-------------+------+-----+------------+----------------+
| Field            | Type        | Null | Key | Default    | Extra          |
+------------------+-------------+------+-----+------------+----------------+
| idChocolat       | int(11)     | NO   | PRI | NULL       | auto_increment |
| nomChocolat      | varchar(25) | NO   |     | NULL       |                |
| pourcentageCacao | int(11)     | NO   |     | NULL       |                |
| origineFeve      | varchar(25) | NO   |     | NULL       |                |
| biologique       | tinyint(1)  | NO   |     | NULL       |                |
| idChocolatier    | int(11)     | NO   | MUL | NULL       |                |
| Prix             | int(11)     | YES  |     | 5          |                |
| Perempt          | date        | YES  |     | 2018-01-01 |                |
+------------------+-------------+------+-----+------------+----------------+

2. update Chocolat set Prix=Prix+Prix/10 where idChocolatier = 3;
+------------+-----------------+------------------+-------------+------------+---------------+------+------------+
| idChocolat | nomChocolat     | pourcentageCacao | origineFeve | biologique | idChocolatier | Prix | Perempt    |
+------------+-----------------+------------------+-------------+------------+---------------+------+------------+
|          1 | gianduja1       |               35 | Equateur    |          0 |             3 |    6 | 2018-01-01 |
|          2 | gianduja2       |               38 | Ghana       |          0 |             3 |    6 | 2018-01-01 |
|          3 | giandujabio     |               38 | Ghana       |          1 |             3 |    6 | 2018-01-01 |
|          4 | palet-noir      |               75 | Cameroun    |          0 |             3 |    6 | 2018-01-01 |
|          5 | palet-lait      |               35 | Cameroun    |          0 |             3 |    6 | 2018-01-01 |
|          6 | buchette-lait   |               30 | Perou       |          0 |             1 |    5 | 2018-01-01 |
|          7 | palet           |               70 | Venezuela   |          0 |             1 |    5 | 2018-01-01 |
|          8 | trèfle          |               70 | Equateur    |          0 |             1 |    5 | 2018-01-01 |
|          9 | orangette       |               70 | Mexique     |          0 |             1 |    5 | 2018-01-01 |
|         10 | mini rocher     |               56 | Bresil      |          0 |             1 |    5 | 2018-01-01 |
|         11 | rocher-praline  |               56 | Indonesie   |          0 |             2 |    5 | 2018-01-01 |
|         12 | carre-noir      |               76 | Mexique     |          0 |             2 |    5 | 2018-01-01 |
|         13 | carre-lait      |               27 | Mexique     |          0 |             2 |    5 | 2018-01-01 |
|         14 | rocher-praline  |               56 | Indonesie   |          0 |             2 |    5 | 2018-01-01 |
|         15 | carre-noir      |               76 | Mexique     |          0 |             2 |    5 | 2018-01-01 |
|         16 | truffe-lait     |               35 | Perou       |          0 |             4 |    5 | 2018-01-01 |
|         17 | truffe-praline  |               32 | Perou       |          0 |             4 |    5 | 2018-01-01 |
|         18 | truffe-noir     |               75 | Perou       |          0 |             4 |    5 | 2018-01-01 |
|         19 | truffe-noir     |               78 | Cameroun    |          0 |             5 |    5 | 2018-01-01 |
|         20 | truffe-noir-bio |               79 | Cameroun    |          1 |             5 |    5 | 2018-01-01 |
|         21 | truffe-lait     |               37 | Cameroun    |          0 |             5 |    5 | 2018-01-01 |
|         22 | truffe-lait-bio |               38 | Cameroun    |          0 |             5 |    5 | 2018-01-01 |
|         23 | palet-blanc     |               10 | Nigeria     |          0 |             6 |    5 | 2018-01-01 |
|         24 | palet-lait      |               32 | Nigeria     |          0 |             6 |    5 | 2018-01-01 |
|         25 | palet-noir      |               77 | Nigeria     |          0 |             6 |    5 | 2018-01-01 |
|         26 | palet-noir-bio  |               79 | Nigeria     |          1 |             6 |    5 | 2018-01-01 |
|         27 | truffe-tradi    |               72 | Perou       |          1 |             7 |    5 | 2018-01-01 |
|         28 | truffe-fruitee  |               36 | Cote Ivoire |          1 |             7 |    5 | 2018-01-01 |
|         29 | ganache-noire   |               83 | Cote Ivoire |          0 |             7 |    5 | 2018-01-01 |
|         30 | ganache-lait    |               33 | Cote Ivoire |          0 |             7 |    5 | 2018-01-01 |
|         31 | pepite          |               85 | Perou       |          0 |             8 |    5 | 2018-01-01 |
|         32 | palette-blanche |               13 | Ghana       |          0 |             8 |    5 | 2018-01-01 |
|         33 | palette-lait    |               29 | Ghana       |          0 |             8 |    5 | 2018-01-01 |
|         34 | palette-noir    |               67 | Ghana       |          0 |             8 |    5 | 2018-01-01 |
+------------+-----------------+------------------+-------------+------------+---------------+------+------------+

3. create view infoTruffe(idChocolat, nomChocolat, pourcentageCacao, origineFeve, biologique, idChocolatier, Prix, Perempt) as (select idChocolat, nomChocolat, pourcentageCacao, origineFeve, biologique, idChocolatier, Prix, Perempt from Chocolat where nomChocolat like '%truffe%') with check option;
+------------+-----------------+------------------+-------------+------------+---------------+------+------------+
| idChocolat | nomChocolat     | pourcentageCacao | origineFeve | biologique | idChocolatier | Prix | Perempt    |
+------------+-----------------+------------------+-------------+------------+---------------+------+------------+
|         16 | truffe-lait     |               35 | Perou       |          0 |             4 |    5 | 2018-01-01 |
|         17 | truffe-praline  |               32 | Perou       |          0 |             4 |    5 | 2018-01-01 |
|         18 | truffe-noir     |               75 | Perou       |          0 |             4 |    5 | 2018-01-01 |
|         19 | truffe-noir     |               78 | Cameroun    |          0 |             5 |    5 | 2018-01-01 |
|         20 | truffe-noir-bio |               79 | Cameroun    |          1 |             5 |    5 | 2018-01-01 |
|         21 | truffe-lait     |               37 | Cameroun    |          0 |             5 |    5 | 2018-01-01 |
|         22 | truffe-lait-bio |               38 | Cameroun    |          0 |             5 |    5 | 2018-01-01 |
|         27 | truffe-tradi    |               72 | Perou       |          1 |             7 |    5 | 2018-01-01 |
|         28 | truffe-fruitee  |               36 | Cote Ivoire |          1 |             7 |    5 | 2018-01-01 |
+------------+-----------------+------------------+-------------+------------+---------------+------+------------+

4. insert into infoTruffe values(70, 'Ferrero', 45, 'Italie', 0, 4, 5, '2018-01-01');
ERROR 1369 (HY000): CHECK OPTION failed 'chocoDB.infoTruffe'

Cela n'a pas fonctionné car la vue a été créée avec check option, et cette insertion ne la respecte pas car 'Ferrero' ne contient pas 'truffe'.
Sans le check option, l'insertion aurait réussie.

5. drop view infoTruffe;

6. create view infoTruffe(idChocolat, nomChocolat, pourcentageCacao, origineFeve, biologique, idChocolatier, Prix, Perempt, quantite) as (select idChocolat, nomChocolat, pourcentageCacao, origineFeve, biologique, idChocolatier, Prix, Perempt, quantite from Chocolat natural join Commande where nomChocolat like '%truffe%') with check option;
+------------+----------------+------------------+-------------+------------+---------------+------+------------+----------+
| idChocolat | nomChocolat    | pourcentageCacao | origineFeve | biologique | idChocolatier | Prix | Perempt    | quantite |
+------------+----------------+------------------+-------------+------------+---------------+------+------------+----------+
|         28 | truffe-fruitee |               36 | Cote Ivoire |          1 |             7 |    5 | 2018-01-01 |        2 |
|         16 | truffe-lait    |               35 | Perou       |          0 |             4 |    5 | 2018-01-01 |        7 |
+------------+----------------+------------------+-------------+------------+---------------+------+------------+----------+

7. insert into infoTruffe values(70, 'truffeFerrero', 45, 'Italie', 0, 4, 5, '2018-01-01', 0);
ERROR 1394 (HY000): Can not insert into join view 'chocoDB.infoTruffe' without fields list

L'insertion n'a pas réussie car la table Commande ne contient pas le tuple pour 'truffeFerrero'.

Si on insère d'abord dans Chocolat, puis dans Commande, l'insertion aurait réussie.

8. select idChocolatier, nom, AVG(pourcentageCacao) from Chocolatier natural join Chocolat group by (idChocolatier);
+---------------+-----------------------+-----------------------+
| idChocolatier | nom                   | AVG(pourcentageCacao) |
+---------------+-----------------------+-----------------------+
|             1 | Jeff De Bruges        |               59.2000 |
|             2 | De Neuville           |               58.2000 |
|             3 | Larnicol              |               44.2000 |
|             4 | Jean-Paul Hevin       |               47.3333 |
|             5 | Patrick Roger         |               58.0000 |
|             6 | Jacques Genin         |               49.5000 |
|             7 | La Maison du chocolat |               56.0000 |
|             8 | Michel Cluizel        |               48.5000 |
+---------------+-----------------------+-----------------------+
