use veleprodaja;

LOAD DATA LOCAL INFILE 'veleprodaja/zaposleni.txt' INTO TABLE Zaposleni
  FIELDS TERMINATED BY ',';
  
LOAD DATA LOCAL INFILE 'veleprodaja/kupci.txt' INTO TABLE Kupac
  FIELDS TERMINATED BY ',';
  
LOAD DATA LOCAL INFILE 'veleprodaja/kontakti.txt' INTO TABLE Kontakt_osoba
  FIELDS TERMINATED BY ',';

LOAD DATA LOCAL INFILE 'veleprodaja/porudzbina.txt' INTO TABLE Porudzbina
  FIELDS TERMINATED BY ',';
  
LOAD DATA LOCAL INFILE 'veleprodaja/ponuda.txt' INTO TABLE Ponuda
  FIELDS TERMINATED BY ',';
  
LOAD DATA LOCAL INFILE 'veleprodaja/otpremnica.txt' INTO TABLE Otpremnica
  FIELDS TERMINATED BY ','; 
  
LOAD DATA LOCAL INFILE 'veleprodaja/faktura.txt' INTO TABLE Faktura
  FIELDS TERMINATED BY ','; 
  
LOAD DATA LOCAL INFILE 'veleprodaja/proizvod.txt' INTO TABLE Proizvod
  FIELDS TERMINATED BY ',';
  
LOAD DATA LOCAL INFILE 'veleprodaja/proizvod_has_proizvod.txt' INTO TABLE Proizvod_has_Proizvod
  FIELDS TERMINATED BY ',';
  
LOAD DATA LOCAL INFILE 'veleprodaja/stavka.txt' INTO TABLE Stavka
  FIELDS TERMINATED BY ',';
