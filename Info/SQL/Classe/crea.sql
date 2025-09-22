CREATE TABLE "alunni" (
	"ID"	INTEGER NOT NULL UNIQUE,
	"cognome"	VARCHAR(30) NOT NULL CHECK("cognome" REGEXP '^[A-Z][a-z]+$'),
	"nome"	VARCHAR(30) NOT NULL CHECK("nome" REGEXP '^[A-Z][a-z]+$'),
	"Id_rappresentante"	INTEGER,
	"classe"	VARCHAR(4) NOT NULL CHECK("classe" REGEXP '^[1-5][A-Z]$'),
	"media_voti"	REAL NOT NULL CHECK("media_voti" BETWEEN 0 AND 10),
	PRIMARY KEY("ID" AUTOINCREMENT)
);