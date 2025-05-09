SELECT DISTINCT d.NomeD, d.CodDocente
FROM DOCENTI d, Corsi c, Frequenta f
WHERE d.CodDocente = c.CodDocente
AND c.CodCorso = f.CodCorso
and d.CodDocente NOT IN (
		SELECT DISTINCT CORSI.CodDocente
		FROM CORSI, FREQUENTA
		WHERE CORSI.CodCorso = FREQUENTA.CodCorso
		GROUP BY CORSI.CodCorso
		HAVING COUNT(*) <=5
)
