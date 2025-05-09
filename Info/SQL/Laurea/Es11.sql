SELECT DISTINCT c.CodCorso, c.NomeCorso
FROM CORSI c, FREQUENTA f, STUDENTI s
WHERE c.CodCorso = f.CodCorso
AND f.Matricola = s.Matricola
AND s.Matricola IN (
SELECT s.Matricola 
FROM STUDENTI s, CORSIDILAUREA cl
WHERE s.CorsoLaurea = cl.CorsoLaurea
AND cl.CorsoLaurea LIKE "%SBC%"
AND cl.TipoLaurea LIKE "%Triennale%"
)