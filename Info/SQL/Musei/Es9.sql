SELECT OPERE.Codice, OPERE.Titolo
FROM OPERE, ARTISTI, MUSEI, PERSONAGGI
WHERE OPERE.CodA = ARTISTI.CodA 
  AND OPERE.CodM = MUSEI.CodM 
  AND OPERE.codice = Personaggi.codice
  AND ARTISTI.Nazionalita = 'ITA' 
  AND MUSEI.Citta = 'Londra'
  AND PERSONAGGI.Personaggio LIKE '%Madonna%';
