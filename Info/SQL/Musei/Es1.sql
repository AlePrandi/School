SELECT Codice, Titolo
FROM OPERE, ARTISTI, MUSEI
WHERE OPERE.CodA = ARTISTI.CodA 
  AND OPERE.CodM = MUSEI.CodM 
  AND ARTISTI.NomeA = 'Tiziano' 
  AND MUSEI.NomeM = 'National Gallery';
