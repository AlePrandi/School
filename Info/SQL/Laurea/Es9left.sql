SELECT d.CodDocente, d.NomeD
FROM DOCENTI d, CORSI c LEFT JOIN FREQUENTA f ON 
c.CodCorso = f.CodCorso
WHERE d.CodDocente = c.CodDocente
AND f.CodCorso IS NULL