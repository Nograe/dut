1.
Alter Table Chocolat Add Prix integer default 5;
+------------+-----------------+------------------+-------------+------------+---------------+------+
| idChocolat | nomChocolat     | pourcentageCacao | origineFeve | biologique | idChocolatier | Prix |
+------------+-----------------+------------------+-------------+------------+---------------+------+
|          1 | gianduja1       |               35 | Equateur    |          0 |             3 |    5 |
|          2 | gianduja2       |               38 | Ghana       |          0 |             3 |    5 |
|          3 | giandujabio     |               38 | Ghana       |          1 |             3 |    5 |
|          4 | palet-noir      |               75 | Cameroun    |          0 |             3 |    5 |
|          5 | palet-lait      |               35 | Cameroun    |          0 |             3 |    5 |
|          6 | buchette-lait   |               30 | Perou       |          0 |             1 |    5 |
|          7 | palet           |               70 | Venezuela   |          0 |             1 |    5 |
|          8 | trèfle          |               70 | Equateur    |          0 |             1 |    5 |
|          9 | orangette       |               70 | Mexique     |          0 |             1 |    5 |
|         10 | mini rocher     |               56 | Bresil      |          0 |             1 |    5 |
|         11 | rocher-praline  |               56 | Indonesie   |          0 |             2 |    5 |
|         12 | carre-noir      |               76 | Mexique     |          0 |             2 |    5 |
|         13 | carre-lait      |               27 | Mexique     |          0 |             2 |    5 |
|         14 | rocher-praline  |               56 | Indonesie   |          0 |             2 |    5 |
|         15 | carre-noir      |               76 | Mexique     |          0 |             2 |    5 |
|         16 | truffe-lait     |               35 | Perou       |          0 |             4 |    5 |
|         17 | truffe-praline  |               32 | Perou       |          0 |             4 |    5 |
|         18 | truffe-noir     |               75 | Perou       |          0 |             4 |    5 |
|         19 | truffe-noir     |               78 | Cameroun    |          0 |             5 |    5 |
|         20 | truffe-noir-bio |               79 | Cameroun    |          1 |             5 |    5 |
|         21 | truffe-lait     |               37 | Cameroun    |          0 |             5 |    5 |
|         22 | truffe-lait-bio |               38 | Cameroun    |          0 |             5 |    5 |
|         23 | palet-blanc     |               10 | Nigeria     |          0 |             6 |    5 |
|         24 | palet-lait      |               32 | Nigeria     |          0 |             6 |    5 |
|         25 | palet-noir      |               77 | Nigeria     |          0 |             6 |    5 |
|         26 | palet-noir-bio  |               79 | Nigeria     |          1 |             6 |    5 |
|         27 | truffe-tradi    |               72 | Perou       |          1 |             7 |    5 |
|         28 | truffe-fruitee  |               36 | Cote Ivoire |          1 |             7 |    5 |
|         29 | ganache-noire   |               83 | Cote Ivoire |          0 |             7 |    5 |
|         30 | ganache-lait    |               33 | Cote Ivoire |          0 |             7 |    5 |
|         31 | pepite          |               85 | Perou       |          0 |             8 |    5 |
|         32 | palette-blanche |               13 | Ghana       |          0 |             8 |    5 |
|         33 | palette-lait    |               29 | Ghana       |          0 |             8 |    5 |
|         34 | palette-noir    |               67 | Ghana       |          0 |             8 |    5 |
+------------+-----------------+------------------+-------------+------------+---------------+------+

2.
select idChocolat, nomChocolat, sum(Commande.quantite)
from Chocolat natural join Commande
group by idChocolat;

+------------+-----------------+------------------------+
| idChocolat | nomChocolat     | sum(Commande.quantite) |
+------------+-----------------+------------------------+
|          1 | gianduja1       |                      3 |
|          2 | gianduja2       |                      2 |
|          3 | giandujabio     |                      1 |
|          4 | palet-noir      |                      3 |
|          5 | palet-lait      |                      6 |
|          9 | orangette       |                      1 |
|         12 | carre-noir      |                      9 |
|         14 | rocher-praline  |                      1 |
|         16 | truffe-lait     |                      7 |
|         28 | truffe-fruitee  |                      2 |
|         32 | palette-blanche |                      1 |
+------------+-----------------+------------------------+

3.
Create view ChocoNoir(idChocolat, nomChocolat, pourcentageCacao)
As select idChocolat, nomChocolat, pourcentageCacao
From Chocolat
Where pourcentageCacao>40
With Check Option;

+------------+-----------------+------------------+
| idChocolat | nomChocolat     | pourcentageCacao |
+------------+-----------------+------------------+
|          4 | palet-noir      |               75 |
|          7 | palet           |               70 |
|          8 | trèfle          |               70 |
|          9 | orangette       |               70 |
|         10 | mini rocher     |               56 |
|         11 | rocher-praline  |               56 |
|         12 | carre-noir      |               76 |
|         14 | rocher-praline  |               56 |
|         15 | carre-noir      |               76 |
|         18 | truffe-noir     |               75 |
|         19 | truffe-noir     |               78 |
|         20 | truffe-noir-bio |               79 |
|         25 | palet-noir      |               77 |
|         26 | palet-noir-bio  |               79 |
|         27 | truffe-tradi    |               72 |
|         29 | ganache-noire   |               83 |
|         31 | pepite          |               85 |
|         34 | palette-noir    |               67 |
+------------+-----------------+------------------+

4.
Insert into ChocoNoir(idChocolat, nomChocolat, pourcentageCacao)
values (35, 'TruffeBlanchNoel', 12);

/*Erreur de Check Option : L'insertion ne respect pas le where (pourcentageCacao>40) à la création de la vue controlée par le check option.*/







