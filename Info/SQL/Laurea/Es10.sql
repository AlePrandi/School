SELECT s.Matricola, s.NomeS
FROM studenti s, frequenta f
WHERE s.Matricola = f.Matricola
AND f.CodCorso IN (
SELECT DISTINCT c.CodCorso 
FROM corsi c, DOCENTI d
WHERE c.CodDocente = d.CodDocente
AND d.Dipartimento LIKE "%Storia%"
)