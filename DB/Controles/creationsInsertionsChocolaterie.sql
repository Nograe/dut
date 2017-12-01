
CREATE TABLE Chocolatier ( 
	idChocolatier INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,
	nom VARCHAR(25) NOT NULL,
	ville VARCHAR(25) NOT NULL
	 );

CREATE TABLE Chocolat ( 
	idChocolat INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,
	nomChocolat VARCHAR(25) NOT NULL,
	pourcentageCacao INTEGER NOT NULL,
	origineFeve VARCHAR(25) NOT NULL,
	biologique BOOLEAN NOT NULL,
	idChocolatier INTEGER NOT NULL,
	FOREIGN KEY (idChocolatier) REFERENCES Chocolatier (idChocolatier)
	);

CREATE TABLE Client (
       idClient INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,	
       nom VARCHAR(25) NOT NULL,
       ville VARCHAR(25) NOT NULL
);

CREATE TABLE Commande (
       idCommande INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,	
       idChocolat INTEGER NOT NULL,
       idClient INTEGER NOT NULL,
       quantite INTEGER NOT NULL,
       dateCommande DATE NOT NULL,
       FOREIGN KEY (idChocolat) REFERENCES Chocolat (idChocolat),
       FOREIGN KEY (idClient) REFERENCES Client (idClient)
);

----- Chocolatiers ----

INSERT INTO Chocolatier (nom , ville ) 
       VALUES ('Jeff De Bruges' ,'Bruges' );
       
INSERT INTO Chocolatier (nom , ville ) 
       VALUES ('De Neuville' ,'Neuville St-Rémy' );

INSERT INTO Chocolatier (nom , ville ) 
       VALUES ('Larnicol' ,'Melgven' );

INSERT INTO Chocolatier (nom , ville ) 
       VALUES ('Jean-Paul Hevin' ,'Paris' );
       
INSERT INTO Chocolatier (nom , ville ) 
       VALUES ('Patrick Roger' ,'Paris' );

INSERT INTO Chocolatier (nom , ville ) 
       VALUES ('Jacques Genin' ,'Paris' );

INSERT INTO Chocolatier (nom , ville ) 
       VALUES ('La Maison du chocolat' ,'Bruges' );

INSERT INTO Chocolatier (nom , ville ) 
       VALUES ('Michel Cluizel' ,'Damville' );


------ Chocolats ------

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('gianduja1' , 35, 'Equateur', 0, 3);
       
       INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('gianduja2' , 38, 'Ghana', 0, 3);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('giandujabio' , 38, 'Ghana', 1, 3);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palet-noir' , 75, 'Cameroun', 0, 3);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palet-lait' , 35, 'Cameroun', 0, 3);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('buchette-lait' , 30, 'Perou', 0, 1);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palet' , 70, 'Venezuela', 0, 1);
       
INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('trèfle' , 70, 'Equateur', 0, 1);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('orangette' , 70, 'Mexique', 0, 1);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('mini rocher' , 56, 'Bresil', 0, 1);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('rocher-praline' , 56, 'Indonesie', 0, 2);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('carre-noir' , 76, 'Mexique', 0, 2);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('carre-lait' , 27, 'Mexique', 0, 2);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('rocher-praline' , 56, 'Indonesie', 0, 2);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('carre-noir' , 76, 'Mexique', 0, 2);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('truffe-lait' , 35, 'Perou', 0, 4);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('truffe-praline' , 32, 'Perou', 0, 4);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('truffe-noir' , 75, 'Perou', 0, 4);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('truffe-noir' , 78, 'Cameroun', 0, 5);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('truffe-noir-bio' , 79, 'Cameroun', 1, 5);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('truffe-lait' , 37, 'Cameroun', 0, 5);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('truffe-lait-bio' , 38, 'Cameroun', 0, 5);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palet-blanc' , 10, 'Nigeria', 0, 6);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palet-lait' , 32, 'Nigeria', 0, 6);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palet-noir' , 77, 'Nigeria', 0, 6);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palet-noir-bio' , 79, 'Nigeria', 1, 6);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('truffe-tradi' , 72, 'Perou', 1, 7);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('truffe-fruitee' , 36, 'Cote Ivoire', 1, 7);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('ganache-noire' , 83, 'Cote Ivoire', 0, 7);
       
INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('ganache-lait' , 33, 'Cote Ivoire', 0, 7);

 INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('pepite' , 85, 'Perou', 0, 8);

 INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palette-blanche' , 13, 'Ghana', 0, 8);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palette-lait' , 29, 'Ghana', 0, 8);

INSERT INTO Chocolat (nomChocolat , pourcentageCacao, origineFeve, biologique, idChocolatier) 
       VALUES ('palette-noir' , 67, 'Ghana', 0, 8);

------ Clients ------

INSERT INTO Client (nom , ville ) 
       VALUES ('Bob Marley', 'Kingston');

INSERT INTO Client (nom , ville ) 
       VALUES ('Harrison Stafford', 'San Francisco');

INSERT INTO Client (nom , ville ) 
       VALUES ('Billy Gibbons', 'Houston');

INSERT INTO Client (nom , ville ) 
       VALUES ('Dusty Hill', 'Houston');

INSERT INTO Client (nom , ville ) 
       VALUES ('Janis Joplin', 'San Francisco');

INSERT INTO Client (nom , ville ) 
       VALUES ('Michael Jackson', 'Los Angeles');

INSERT INTO Client (nom , ville ) 
       VALUES ('Nina Simone', 'Mount Vernon');

INSERT INTO Client (nom , ville ) 
       VALUES ('Brahim Zaibat', 'Paris');

INSERT INTO Client (nom , ville ) 
       VALUES ('Benjamin Millepied', 'Paris');

INSERT INTO Client (nom , ville ) 
       VALUES ('Maurice Béjart', 'Marseille');

INSERT INTO Client (nom , ville ) 
       VALUES ('Charles Beaudelaire', 'Paris');

----- Commandes ----

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (1,1,3,STR_TO_DATE('20-12-1987', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (2,1,2,STR_TO_DATE('25-12-1997', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (3,2,1,STR_TO_DATE('25-11-2012', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (4,3,3,STR_TO_DATE('13-04-2016', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (5,4,5,STR_TO_DATE('03-07-2015', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (5,6,1,STR_TO_DATE('02-01-2017', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (9,7,1,STR_TO_DATE('02-05-2014', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (12,8,2,STR_TO_DATE('02-05-2014', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (14,9,1,STR_TO_DATE('21-06-2016', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (32,9,1,STR_TO_DATE('21-06-2016', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (28,10,2,STR_TO_DATE('08-01-2017', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (16,11,7,STR_TO_DATE('12-01-2017', '%d-%m-%Y'));

INSERT INTO Commande (idChocolat, idClient, quantite, dateCommande) 
       VALUES (12,9,7,STR_TO_DATE('12-01-2017', '%d-%m-%Y'));
