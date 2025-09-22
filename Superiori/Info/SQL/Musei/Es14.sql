SELECT NomeM 
FROM MUSEI 
WHERE Citta = 'Londra' 
  AND CodM NOT IN (
    SELECT CodM 
    FROM OPERE 
    WHERE CodA != (SELECT CodA FROM ARTISTI WHERE NomeA = 'Tiziano')
  )
  AND CodM IN (
    SELECT CodM 
    FROM OPERE 
    WHERE CodA = (SELECT CodA FROM ARTISTI WHERE NomeA = 'Tiziano')
  )