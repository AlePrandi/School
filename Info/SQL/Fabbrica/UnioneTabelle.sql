SELECT b.*, cognome AS "Cognome Responsabili", nome AS "Nome Responsabile"	--dot notation
FROM sedeB AS b, Responsabili AS r    --congiunzione   --as cambia solo la visualizzazione 
where b.codR = r.codResp AND sesso = "F"

-- prodotto cartesiano tra le tabelle, mette tutte le righe in combinazione con le altre righe
-- una riga si chiama tupla
-- numero di colonne = Grado delle colonne
-- numero di righe = Cardinalità
-- insieme di righe e colonne = Istanza
-- la tabella risultato del prodotto cartesiano avrà un grado uguale alla somma dei gradi 
-- la tabella risultato del prodotto cartesiano avrà una cardinalità uguale al prodotto delle cardinalità