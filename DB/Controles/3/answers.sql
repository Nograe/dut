1. insert into Client values(12,'Jean Dupont', 'Versailles');

2. update Client set nom='Jeanne Dupont' where idClient=12;

3. alter table Chocolat add Prix INTEGER default 5;

4. select distinct idChocolatier from Chocolatier natural join Chocolat where Chocolatier.nom = 'Larnicol';
	PUIS
   update Chocolat set prix=prix+prix/2 where idChocolatier=3;

5. select COUNT(idChocolat) from Chocolat where pourcentageCacao > 40;

6. select SUM(quantite)/10 from Commande natural join Chocolat where pourcentageCacao > 40;

7. create view ChocolatNoir(idChocolat, nomChocolat, pourcentageCacao) as (select idChocolat, nomChocolat, pourcentageCacao from Chocolat where pourcentageCacao > 40);

8.
9.
10.

11. select distinct idChocolatier,nom,AVG(Prix) from Chocolatier natural join Chocolat group by(idChocolat);

12. select * from Chocolat where nomChocolat like '%truffe%';
