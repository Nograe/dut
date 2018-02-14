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
       FOREIGN KEY (aeroportArrivee) REFERENCES AEROPORT (codeAeroport)
       CHECK (numEscale > 0) AND (numEscale <= 25),
       CHECK (aeroportArrive != aeroportDepart),
       CHECK (heureDepartPrevue >= 0 AND heureDepartPrevue <= 24)
       CHECK (heureArrivee >= 0 AND heureDepartPrevue <= 24) 
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
       FOREIGN KEY (idAvion) REFERENCES  (),
       FOREIGN KEY () REFERENCES  ()
);

CREATE TABLE EQUIPAGE (

);

CREATE TABLE HOTESSE_EQUIPAGE (

);


FOREIGN KEY (idEquipe) REFERENCES EQU (),