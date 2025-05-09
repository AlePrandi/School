SELECT NomeM 
FROM MUSEI 
WHERE Citta = 'Londra' 
  AND CodM NOT IN (
    SELECT CodM 
    FROM OPERE 
    WHERE CodA IN (
        SELECT CodA 
        FROM ARTISTI 
        WHERE Nazionalita = 'italiana' 
          AND NomeA != 'Tiziano'
      )
  )
