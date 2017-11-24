1. 
a) create view CommandeBuveur(NumCom,DateCom,Nom) as select NumCom,DateCom,Nom from Commande natural join Buveur;
b) delete from CommandeBuveur where NumCom=8; /*Impossible: NumCom utilisé dans d'autres tables*/
c) update CommandeBuveur set DateCom='1990-04-22' where NumCom=12;
d) update CommandeBuveur set Nom='Risitas' where NumCom=2;
e) insert into CommandeBuveur(NumCom,DateCom,Nom) values(14,'1990-05-10','Collin'); /*On ne peut modifier qu'une table à la fois*/

2. create view Vin2(NumVin,Cru,Region) as select NumVin,Cru,Region from Vin;
a) update Vin2 set Cru='Bourgueuil' where NumVin=85;
b) delete from Vin2 where NumVin=190; /*NumVin présent dans d'autres tables*/ 
c) insert into Vin2(NumVin,Cru,Region) values(10,'Chinon','Loire'); /*La table d'origine n'a pas de valeurs par défaut*/

3.
a) create view BuveurParis(NumBuveur,Nom,Prenom) as select NumBuveur,Nom,Prenom from Buveur where Ville='Paris' with check option;
      insert into BuveurParis(NumBuveur,Nom,Prenom) values(2400,'Old el','Paso'); /*Le buveur n'est pas de Paris: tuple non inséré*/
b) create view GrosseCommande(NumCom) as (select NumCom from Commande where Qtte>10) with check option;
      insert into GrosseCommande(NumCom) values(5);/*On ne peut pas insérer de champ ne       respectant pas le where à la création*/

4. create view NombreCommande(NombreCom,NumBuveur,Nom) as select COUNT(NumBuveur),NumBuveur,Nom from Buveur natural join Commande group by NumBuveur;
