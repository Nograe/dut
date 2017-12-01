ys1. update Livraison set Qtte=Qtte+1 where DateLiv>='1987-11-1'
+--------+------+------------+	    	  
| NumCom | Qtte | DateLiv    |	    
+--------+------+------------+	    
|      1 |    6 | 1987-07-15 |	    
|      2 |   12 | 1987-08-30 |	    
|      2 |    6 | 1987-09-27 |
|      3 |   12 | 1987-11-20 |	    
|      4 |    6 | 1987-12-20 |	    
|      6 |    8 | 1987-12-28 |	    
|      7 |    3 | 1987-12-30 |	    
+--------+------+------------+	    
+--------+------+------------+
| NumCom | Qtte | DateLiv    |
+--------+------+------------+
|      1 |    6 | 1987-07-15 |
|      2 |   12 | 1987-08-30 |
|      2 |    6 | 1987-09-27 |
|      3 |   13 | 1987-11-20 |
|      4 |    7 | 1987-12-20 |
|      6 |    9 | 1987-12-28 |
|      7 |    4 | 1987-12-30 |
+--------+------+------------+
2. START TRANSACTION; ROLLBACK; COMMIT;
3. update Commande set Qtte=12 where NumCom=12;
+--------+-----------+--------+------+------------+
| NumCom | NumBuveur | NumVin | Qtte | DateCom    |
+--------+-----------+--------+------+------------+
|      1 |      1600 |     90 |    6 | 1990-04-22 |
|      2 |      1500 |    100 |   18 | 1990-04-22 |
|      3 |      1500 |     88 |   24 | 1990-04-22 |
|      4 |      1600 |    175 |    6 | 1990-04-22 |
|      5 |      1300 |    140 |    3 | 1990-04-22 |
|      6 |      1100 |    140 |    8 | 1990-04-22 |
|      7 |      1200 |     88 |    3 | 1990-04-22 |
|      8 |      1400 |    140 |   12 | 1990-04-22 |
|     11 |      1200 |    140 |   12 | 1990-04-22 |
|     12 |      1100 |    120 |    6 | 1990-04-22 |
+--------+-----------+--------+------+------------+
+--------+-----------+--------+------+------------+
| NumCom | NumBuveur | NumVin | Qtte | DateCom    |
+--------+-----------+--------+------+------------+
|      1 |      1600 |     90 |    6 | 1990-04-22 |
|      2 |      1500 |    100 |   18 | 1990-04-22 |
|      3 |      1500 |     88 |   24 | 1990-04-22 |
|      4 |      1600 |    175 |    6 | 1990-04-22 |
|      5 |      1300 |    140 |    3 | 1990-04-22 |
|      6 |      1100 |    140 |    8 | 1990-04-22 |
|      7 |      1200 |     88 |   12 | 1990-04-22 |
|      8 |      1400 |    140 |   12 | 1990-04-22 |
|     11 |      1200 |    140 |   12 | 1990-04-22 |
|     12 |      1100 |    120 |    6 | 1990-04-22 |
+--------+-----------+--------+------+------------+
4. CREATE TABLE Cave_Cooperative(
   NumCave INTEGER PRIMARY KEY,
   VilleCave VARCHAR(25) NOT NULL);

5. ALTER table Viticulteur ADD (NumCave INTEGER NOT NULL  REFERENCES Cave_Cooperative(NumCave) );

6. INSERT INTO Cave_Cooperative(NumCave, VilleCave) VALUES (1, 'Paris');
   INSERT INTO Cave_Cooperative(NumCave, VilleCave) VALUES (2, 'Lille');
   INSERT INTO Cave_Cooperative(NumCave, VilleCave) VALUES (3, 'Bordeaux');
   INSERT INTO Cave_Cooperative(NumCave, VilleCave) VALUES (4, 'Marseille');
   INSERT INTO Cave_Cooperative(NumCave, VilleCave) VALUES (5, 'Macon');
   INSERT INTO Cave_Cooperative(NumCave, VilleCave) VALUES (6, 'Chateau-Chalon');