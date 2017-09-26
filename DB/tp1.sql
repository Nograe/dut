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
       FOREIGN KEY (NumVitic) REFERENCES Viticulteur (NumVitic),
       );
CREATE TABLE Commande(
       NumCom INTEGER PRIMARY KEY NOT NULL,
       NumBuveur INTEGER NOT NULL,
       NumVin INTEGER NOT NULL,
       Qtte INTEGER NOT NULL,
       DateCom DATE NOT NULL,
       FOREIGN KEY (NumVin) REFERENCES Vin (NumVin),
       FOREIGN KEY (NumBuveur) REFERENCES Buveur (NumBuveur),
       );
CREATE TABLE Livraison(
       NumCom INTEGER KEY NOT NULL,
       Qtte INTEGER NOT NULL,
       DateLiv DATE NOT NULL,
       PRIMARY KEY (NumCom, DateLiv),
       FOREIGN KEY (NumCom) REFERENCES Commande (NumCom),
       );
