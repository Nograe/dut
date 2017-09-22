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
       NumCom INTEGER
       NumBuveur INTEGER
       NumVin INTEGER
       Qtte INTEGER
       DateCom DATE
CREATE TABLE Livraison(