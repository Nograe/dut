CREATE TABLE Chocolatier(
       idChocolatier INTEGER PRIMARY KEY AUTO_INCREMENT,
       nom VARCHAR(25) NOT NULL,
       ville VARCHAR(25) NOT NULL
       );
CREATE TABLE Client(
       idClient INTEGER PRIMARY KEY AUTO_INCREMENT,
       nom VARCHAR(25) NOT NULL,
       ville VARCHAR(25) NOT NULL
       );
CREATE TABLE Chocolat(
       idChocolat INTEGER PRIMARY KEY AUTO_INCREMENT,
       nomChocolat VARCHAR(25) NOT NULL,
       pourcentageCacao INTEGER NOT NULL,
       origineFeve VARCHAR(25) NOT NULL,
       biologique BOOLEAN NOT NULL,
       idChocolatier INTEGER NOT NULL,
       FOREIGN KEY (idChocolatier) REFERENCES Chocolatier (idChocolatier)
       );
CREATE TABLE Commande(
       idCommande INTEGER PRIMARY KEY AUTO_INCREMENT,
       idChocolat INTEGER NOT NULL,
       idClient INTEGER NOT NULL,
       quantite INTEGER NOT NULL,
       dateCommande DATE NOT NULL,
       FOREIGN KEY (idChocolat) REFERENCES Chocolat (idChocolat),
       FOREIGN KEY (idClient) REFERENCES Client (idClient)
       );
