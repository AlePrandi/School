SELECT ARTISTI.NomeA, OPERE.Titolo
FROM OPERE, ARTISTI, MUSEI
WHERE OPERE.CodA = ARTISTI.CodA 
  AND OPERE.CodM = MUSEI.CodM 
  AND Musei.nomeM IN ("Galleria degli Uffizi","National Gallery")
