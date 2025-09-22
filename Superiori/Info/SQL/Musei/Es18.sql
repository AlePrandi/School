SELECT Titolo, (SELECT NomeA FROM ARTISTI WHERE ARTISTI.CodA = OPERE.CodA) AS NomeA 
FROM OPERE 
WHERE CodA IN (
    SELECT CodA 
    FROM ARTISTI 
    WHERE Nazionalita = 'italiana'
  )
  AND Codice NOT IN (
    SELECT Codice 
    FROM PERSONAGGI
  )
