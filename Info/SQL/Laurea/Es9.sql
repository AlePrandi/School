SELECT d.CodDocente, d.NomeD
FROM DOCENTI d, CORSI c
WHERE d.CodDocente = c.CodDocente
AND c.CodCorso NOT IN (
SELECT f.CodCorso
FROM FREQUENTA f
)