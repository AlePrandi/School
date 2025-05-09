SELECT c.CodCorso
FROM Corsi c, Frequenta f, Studenti s
WHERE c.CodCorso = f.CodCorso
AND s.Matricola = f.Matricola
AND S.corsoLaurea LIKE "SBC"
GROUP BY F.codcorso
HAVING COUNT(*) = (SELECT count(*)
	FROM Studenti
	WHERE corsoLaurea LIKE "SBC"
)
