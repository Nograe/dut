Q1
CREATE TABLE AUTEUR(NumAuteur integer primary key, NomAuteur varchar(20));

CREATE TABLE EDITEUR(CodeEditeur integer primary key, RaisonSociale varchar(50));

CREATE TABLE LIVRE(NumLivre integer primary key, Titre varchar(60), CodeEditeur integer references EDITEUR on delete set null);

Q2
INSERT INTO Auteur VALUES(1, 'Madeleine');
INSERT INTO Editeur VALUES(1, 'Robert');
INSERT INTO Editeur VALUES(2, 'Gallimart');
INSERT INTO Livre VALUES(1, 'Madeleine', 1);

//La suppression d un éditeur déclenche le trigger

Q3
CREATE TABLE A_ECRIT(NumAuteur integer references AUTEUR on delete set null, NumLivre integer references Livre on delete cascade, Primary key (NumAuteur, NumLivre));
INSERT INTO A_ECRIT VALUES(1, 1);

DELETE FROM Livre; //Suppression déclence la suppression du tuple dans A_ECRIT
DELETE FROM Auteur; //Trigger non activé car not null sur NumAuteur dans A_ECRIT