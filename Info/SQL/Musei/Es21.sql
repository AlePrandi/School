SELECT NomeM 
FROM MUSEI 
WHERE CodM IN (
    SELECT CodM 
    FROM OPERE 
    WHERE CodA IN (
        SELECT CodA 
        FROM ARTISTI 
        WHERE Nazionalita = 'italiana'
      )
  )
  AND CodM = (
    SELECT CodM 
    FROM OPERE 
    WHERE CodA IN (
        SELECT CodA 
        FROM ARTISTI 
        WHERE Nazionalita = 'italiana'
      )
    GROUP BY CodM 
    ORDER BY COUNT(Codice) DESC 
    LIMIT 1
  );
