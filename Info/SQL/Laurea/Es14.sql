SELECT C.CodCorso, C.NomeCorso, COUNT(*)
FROM CORSI C
JOIN FREQUENTA F ON C.CodCorso = F.CodCorso
GROUP BY C.CodCorso, C.NomeCorso
HAVING COUNT(*) = (
    	SELECT COUNT(*) AS NumeroStudenti
    	FROM FREQUENTA
    	GROUP BY frequenta.CodCorso
	ORDER BY NUmeroStudenti DESC
LIMIT 1
	)
