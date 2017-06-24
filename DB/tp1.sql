CREATE TABLE Buveur(
       NumBuveur INTEGER PRIMARY KEY,
       Nom VARCHAR(25) NOT NULL,
       Prenom VARCHAR(25) NOT NULL,
       Ville VARCHAR(30)
       );
CREATE TABLE Viticulteur(
       NumVitic INTEGER PRIMARY KEY,
       Nom VARCHAR(25) NOT NULL,
       Prenom VARCHAR(25),
       Ville VARCHAR(30) NOT NULL
       );
CREATE TABLE Vin(
       NumVin INTEGER PRIMARY KEY,
       Cru VARCHAR(15) NOT NULL,
       Millesime INTEGER NOT NULL,
       Region VARCHAR(15) NOT NULL,
       NumVitic INTEGER NOT NULL,
       FOREIGN KEY (NumVitic) REFERENCES Viticulteur (NumVitic)
       );
CREATE TABLE Commande(
       NumCom INTEGER PRIMARY KEY NOT NULL,
       NumBuveur INTEGER NOT NULL,
       NumVin INTEGER NOT NULL,
       Qtte INTEGER NOT NULL,
       DateCom DATE NOT NULL,
       FOREIGN KEY (NumVin) REFERENCES Vin (NumVin),
       FOREIGN KEY (NumBuveur) REFERENCES Buveur (NumBuveur)
       );
CREATE TABLE Livraison(
       NumCom INTEGER NOT NULL,
       Qtte INTEGER NOT NULL,
       DateLiv DATE NOT NULL,
       PRIMARY KEY (NumCom, DateLiv),
       FOREIGN KEY (NumCom) REFERENCES Commande (NumCom)
       );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville ) 
       VALUES (1400 ,'Gautier' ,'Robert' ,'Paris' );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville ) 
       VALUES (1500 ,'Fradet' ,'Philippe' ,'Macon'  );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville ) 
       VALUES (1300 ,'Jamet' ,'Florence' ,'Versailles'  );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville ) 
       VALUES (1100 ,'Combet' ,'Aline' ,'Dijon'  );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville ) 
       VALUES (1600 ,'Dupond' ,'Alain' ,'Paris'  );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville )     
       VALUES (1700 ,'Combes' ,'Edouard' ,'Paris'  );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville ) 
       VALUES (1350 ,'Gravinel' ,'Sophie' ,'Nice'  );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville ) 
       VALUES (1450 ,'Pascal' ,'Yves' ,'Macon'  );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville ) 
       VALUES (1750 ,'Durieux' ,'Blaise' ,'Chinon'  );

INSERT INTO Buveur (NumBuveur ,Nom ,Prenom , Ville ) 
       VALUES (1200 ,'Maury' ,'Francois' ,'Paris'  );





INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (1 ,'Moulin' ,'Jean' ,'Macon'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (3 ,'Morin' ,'Jules' ,'Benais'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (5 ,'Coulis Dutheil' ,NULL ,'Chinon'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (4 ,'Vallee' ,'Claude' ,'Saint Nicolas'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (10 ,'Parent' ,'Pierre' ,'Pommard'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville )     
    VALUES (15 ,'Barancourt' ,NULL ,'Tours sur Marne'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (16 ,'Jadot' ,'Louis' ,'Beaune'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (18 ,'Medeville' ,'Charles' ,'Preignac'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (21 ,'Lynch-Bages' ,NULL ,'Pauillac'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (22 ,'Chateau Monbrison' , NULL ,'Margaux'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville ) 
    VALUES (23 ,'Chateau Moulin A Vent' ,NULL ,'Castelnau de Medoc'  );

INSERT INTO Viticulteur (NumVitic ,Nom ,Prenom, Ville )     
    VALUES (20,'Tissot' ,'Jacques' ,'Arbois'  );



INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (160 ,'Bourgueil' ,1984 ,'Loire' ,3  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (88 ,'Chambertin' ,1980 ,'Bourgogne' ,1  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (170 ,'Bouzy' ,1984 ,'Champagne' ,15  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (175 ,'Meursault' ,1980 ,'Bourgogne' ,16  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (80 ,'Sauternes' ,1982 ,'Bordeaux' ,18  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (84 ,'Pauillac' ,1982 ,'Bordeaux' ,21  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (90 ,'Margaux' ,1978 ,'Bordeaux' ,22  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (98 ,'Moulis' ,1981 ,'Bordeaux' ,23  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (86 ,'Chinon' ,1978 ,'Loire' ,4  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (85 ,'Chinon' ,1983 ,'Loire' ,5  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (120 ,'Chinon' ,1985 ,'Loire' ,4  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (190 ,'Saint Emilion' ,1981 ,'Bordeaux' ,18  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (128 ,'Bourgueil' ,1985 ,'Loire' ,4  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (140 ,'Pommard' ,1976 ,'Bourgogne' ,10  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (150 ,'Monthelie' ,1978 ,'Bourgogne' ,10  );

INSERT INTO Vin (NumVin , Cru ,Millesime ,Region ,  NumVitic ) 
    VALUES (100 ,'Champagne Brut' ,1988 ,'Champagne' ,15  );




INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (8 ,1400 ,140 ,12 ,STR_TO_DATE('10-01-1988', '%d-%m-%Y') );

INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (3 ,1500 ,88 ,24 ,STR_TO_DATE('10-09-1987', '%d-%m-%Y') );

INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (2 ,1500 ,100 ,18 ,STR_TO_DATE('20-11-1987', '%d-%m-%Y') );

INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (4 ,1600 ,175 ,6 ,STR_TO_DATE('12-02-1987', '%d-%m-%Y') );

INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (5 ,1300 ,140 ,3 ,STR_TO_DATE('18-03-1987', '%d-%m-%Y') );

INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (1 ,1600 ,90 ,6 ,STR_TO_DATE('10-06-1987', '%d-%m-%Y') );

INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (6 ,1100 ,140 ,8 ,STR_TO_DATE('24-12-1987', '%d-%m-%Y') );

INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (7 ,1200 ,88 ,3 ,STR_TO_DATE('24-12-1987', '%d-%m-%Y') );

INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (11 ,1200 ,140 ,12 ,STR_TO_DATE('12-12-1989', '%d-%m-%Y') );

INSERT INTO Commande (NumCom ,NumBuveur ,NumVin , Qtte ,DateCom ) 
    VALUES (12 ,1100 ,120 ,6 ,STR_TO_DATE('13-12-1989', '%d-%m-%Y') );




INSERT INTO Livraison (NumCom ,Qtte ,DateLiv ) 
    VALUES (2 ,12 ,STR_TO_DATE('30-08-1987', '%d-%m-%Y') );

INSERT INTO Livraison (NumCom ,Qtte ,DateLiv ) 
    VALUES (1 ,6 ,STR_TO_DATE('15-07-1987', '%d-%m-%Y') );

INSERT INTO Livraison (NumCom ,Qtte ,DateLiv ) 
    VALUES (2 ,6 ,STR_TO_DATE('27-09-1987', '%d-%m-%Y') );

INSERT INTO Livraison (NumCom ,Qtte ,DateLiv ) 
    VALUES (3 ,12 ,STR_TO_DATE('20-11-1987', '%d-%m-%Y') );

INSERT INTO Livraison (NumCom ,Qtte ,DateLiv ) 
    VALUES (4 ,6 ,STR_TO_DATE('20-12-1987', '%d-%m-%Y') );

INSERT INTO Livraison (NumCom ,Qtte ,DateLiv ) 
    VALUES (6 ,8 ,STR_TO_DATE('28-12-1987', '%d-%m-%Y') );

INSERT INTO Livraison (NumCom ,Qtte ,DateLiv ) 
    VALUES (7 ,3 ,STR_TO_DATE('30-12-1987', '%d-%m-%Y') );