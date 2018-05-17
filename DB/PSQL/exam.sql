Exercice 2
1.
CREATE DATABASE "filmDB" WITH OWNER="Matthieu";

CREATE TABLE "Film" (
    "numFilm" integer NOT NULL,
    "titreFilm" character varying(25) NOT NULL,
    "dateSortie" date NOT NULL,
    "dateAchat" date NOT NULL,
    "numRealisateur" integer NOT NULL,
    "genreFilm" character varying(25) NOT NULL,
    CONSTRAINT genre CHECK (genreFilm = "Fantastique" OR genreFilm = "Thriller" OR genreFilm = "Comique"),
    CONSTRAINT constraintdate CHECK (dateSortie < dateAchat),
    PRIMARY KEY ("numFilm")
);
CREATE TABLE "Realisateur" (
    "numRealisateur" integer NOT NULL,
    "nom" character varying(25) NOT NULL,
    "prenom" integer NOT NULL,
    "numHeures" integer NOT NULL,
    PRIMARY KEY ("numRealisateur")
);
CREATE TABLE "DVD" (
    "numDVD" integer NOT NULL,
    "numFilm"  integer NOT NULL,
    "numEmb" integer NOT NULL,
    PRIMARY KEY ("numDVD")
);
CREATE TABLE "EmballageDVD" (
    "numEmb" integer NOT NULL,
    "numDVD" integer NOT NULL,
    PRIMARY KEY ("numEmb")
);
ALTER TABLE "Film"
    ADD CONSTRAINT "fk_numRealisateur" FOREIGN KEY ("numRealisateur")
    REFERENCES "Realisateur" ("numRealisateur");
ALTER TABLE "DVD"
    ADD CONSTRAINT "fk_numFilm" FOREIGN KEY ("numFilm")
    REFERENCES "Film" ("numFilm");
ALTER TABLE "DVD"
    ADD CONSTRAINT "fk_numEmb" FOREIGN KEY ("numEmb")
    REFERENCES "EmballageDVD" ("numEmb");
ALTER TABLE "EmballageDVD"
    ADD CONSTRAINT "fk_numDVD" FOREIGN KEY ("numDVD")
    REFERENCES "DVD" ("numDVD");

-- ALTER TABLE "Film" ADD CONSTRAINT "domain_Genre" CHECK (Film.genreFilm = "Fantastique" OR Film.genreFilm = "Thriller" OR Film.genreFilm = "Comique");
-- ALTER TABLE "Film" ADD CONSTRAINT "domain_Genre" CHECK (Film.genreFilm = "Fantastique" OR Film.genreFilm = "Thriller" OR Film.genreFilm = "Comique");

INSERT INTO "Realisateur" VALUES(1, 'Roger', 'js;kjs;lj;slk', 10);
INSERT INTO "Realisateur" VALUES(2, 'Alain', 'js;kjs;lj', 525);
INSERT INTO "Film" VALUES(1, 'Terminator', '2018-05-01', '2018-05-08', 1, 'Aventure');
INSERT INTO "Film" VALUES(2, 'Terminator2', '2029-05-01', '2030-05-08', 1, 'Aventure');

2.
On modifie la contrainte précédemment créee
ALTER TABLE "Film"
   ALTER COLUMN numRealisateur TYPE integer
ALTER TABLE "Film"
    ADD CONSTRAINT "fk_numRealisateur" FOREIGN KEY ("numRealisateur")
    REFERENCES "Realisateur" ("numRealisateur") ON DELETE SET NULL;

Cas normal: lorsqu on supprime un tuple dans la table Realisateur, le numéro associé dans Film set met à NULL automatiquement

3.
CREATE FUNCTION "countFilm"()
    RETURNS bigint
    LANGUAGE 'sql'

AS $BODY$
select COUNT(("Film")."numFilm") from "Film"
$BODY$;

4.a
postgres=# CREATE USER resp WITH PASSWORD 'resp';
CREATE ROLE
postgres=# CREATE DATABASE resp;
CREATE DATABASE
postgres=# CREATE USER ut1 WITH PASSWORD 'ut1';
CREATE ROLE
postgres=# CREATE USER ut2 WITH PASSWORD 'ut2';
CREATE ROLE
postgres=# CREATE DATABASE ut1;
CREATE DATABASE
postgres=# CREATE DATABASE ut2;
CREATE DATABASE

4.b
CREATE TABLE "Emprunt" (
    "dateEmprunt" date NOT NULL,
    "loginEmprunteur" character varying(25) NOT NULL,
    "numFilm" integer REFERENCES "Film"
);

CREATE VIEW "EmpruntsView" AS
(SELECT Emprunt.dateEmprunt, Emprunt.numFilm, COUNT(numDVD)
FROM Emprunt NATURAL JOIN Film NATURAL JOIN DVD
WHERE Emprunt.loginEmprunteur = CURRENT_USER
);

4.c
GRANT SELECT ON EmpruntsView TO ut1;
GRANT SELECT ON EmpruntsView TO ut2;

5.a
CREATE OR REPLACE FUNCTION process_TriggerFilm() RETURNS TRIGGER AS
$trigger_Film$
BEGIN
IF (NEW.titreFilm NOT IN ('A', 'B', 'C'))
THEN
RAISE EXCEPTION 'Echec de contrainte CHECK sur Film.titreFilm';
END IF;
IF (NEW.titreFilm = 'A')
THEN
IF (SELECT numHeures FROM Realisateur WHERE numRealisateur = NEW.numRealisateur) < 300
THEN
RAISE EXCEPTION 'Echec de contrainte CHECK sur Realisateur.numHeures';
END IF;
END IF;
IF (NEW.titreFilm = 'B')
THEN
IF (SELECT numHeures FROM Realisateur WHERE numRealisateur = NEW.numRealisateur) < 300 AND > 500
THEN
RAISE EXCEPTION 'Echec de contrainte CHECK sur Realisateur.numHeures';
END IF;
END IF;
IF (NEW.titreFilm = 'C')
THEN
IF (SELECT numHeures FROM Realisateur WHERE numRealisateur = NEW.numRealisateur) < 500
THEN
RAISE EXCEPTION 'Echec de contrainte CHECK sur Realisateur.numHeures';
END IF;
END IF;
END;
$trigger_Film$ LANGUAGE plpgsql;
