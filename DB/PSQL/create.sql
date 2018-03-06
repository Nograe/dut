CREATE TABLE AEROPORT (
    codeAeroport varchar(15) primary key,
    nom varchar(40) not null,
    ville varchar(40) not null,
    pays varchar(40) not null,
    unique (nom,ville,pays)
);

CREATE TABLE VOL (
    numVol integer primary key,
    compagnie varchar(40) not null,
    periodeVol varchar(30) not null
);

CREATE TABLE TYPE_AVION (
    nomType varchar(40) primary key,
    maxSieges integer not null,
    nomConstructeur varchar(40) not null
);

CREATE TABLE AVION (
    idAvion integer primary key,
    totalSieges integer not null,
    nomTypeAvion varchar(40) not null REFERENCES TYPE_AVION (nomType)
);

CREATE TABLE PEUT_ATTERIR (
    nomTypeAvion varchar(40) not null,
    codeAeroport varchar(15) not null,
    PRIMARY KEY (nomTypeAvion, codeAeroport),
    FOREIGN KEY (nomTypeAvion) REFERENCES TYPE_AVION (nomType),
    FOREIGN KEY (codeAeroport) REFERENCES AEROPORT (codeAeroport)
);

CREATE TABLE PERSONNEL (
    idPersonne integer primary key,
    Nom varchar(40) not null,
    Prenom varchar(40) not null,
    Fonction varchar(40) not null
);



CREATE TABLE ESCALE (
    numVol integer not null,
    numEscale integer not null,
    aeroportDepart varchar(15) not null,
    aeroportArrivee varchar(15) not null,
    heureDepartPrevue integer not null,
    minuteDepartPrevue integer not null,
    heureArriveePrevue integer not null,
    minuteArriveePrevue integer not null,
    PRIMARY KEY (numVol, numEscale),
    FOREIGN KEY (aeroportDepart) REFERENCES AEROPORT (codeAeroport),
    FOREIGN KEY (aeroportArrivee) REFERENCES AEROPORT (codeAeroport),
    CHECK (numEscale > 0 AND numEscale <= 20),
    CHECK (aeroportArrivee != aeroportDepart),
    CHECK (heureDepartPrevue >= 0 AND heureDepartPrevue <= 24),
    CHECK (heureArriveePrevue >= 0 AND heureDepartPrevue <= 24),
    CHECK (minuteDepartPrevue >= 0 AND minuteDepartPrevue <= 24),
    CHECK (minuteArriveePrevue >= 0 AND minuteDepartPrevue <= 24)
);

CREATE TABLE EQUIPAGE (
   numVol integer not null,
   numEscale integer not null,
   dateEscale date not null,
   idEquipe integer PRIMARY KEY,
   idPilote integer not null,
   idCoPilote integer not null,
   idChefCabine integer not null,
   FOREIGN KEY (idPilote) REFERENCES PERSONNEL (idPersonne),
   FOREIGN KEY (idCoPilote) REFERENCES PERSONNEL (idPersonne),
   FOREIGN KEY (idChefCabine) REFERENCES PERSONNEL (idPersonne)
);

CREATE TABLE INSTANCE_ESCALE (
    numVol integer not null,
    numEscale integer not null,
    dateEscale date not null,
    nbrSieges integer not null,
    idAvion integer not null,
    dateDepartEffectuee date not null,
    dateArriveeEffectuee date not null,
    idEquipe integer not null,
    PRIMARY KEY (numVol, numEscale, dateEscale),
    FOREIGN KEY (numVol, numEscale) REFERENCES Escale (numVol, numEscale),
    FOREIGN KEY (idAvion) REFERENCES Avion (idAvion),
    FOREIGN KEY (idEquipe) REFERENCES Equipage (idEquipe),
    CHECK (dateDepartEffectuee < dateArriveeEffectuee)
);

CREATE TABLE HOTESSE_EQUIPAGE (
   idEquipe integer not null,
   idPersonne integer not null,
   PRIMARY KEY (idEquipe, idPersonne),
   FOREIGN KEY (idEquipe) REFERENCES Equipage (idEquipe),
   FOREIGN KEY (idPersonne) REFERENCES PERSONNEL (idPersonne)
);

ALTER TABLE EQUIPAGE ADD FOREIGN KEY (numVol, numEscale, dateEscale) REFERENCES INSTANCE_ESCALE;

CREATE DOMAIN statut_compagnie VARCHAR(10) CHECK (VALUE = 'Prive' OR VALUE = 'Public');

CREATE TABLE COMPAGNIE_AERIENNE (
   codeCompagnie integer PRIMARY KEY,
   nomCompagnie varchar(40) not null,
   villeSiege varchar(40) not null,
   paysSiege varchar(40) not null,
   statut statut_compagnie
);