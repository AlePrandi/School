SELECT DISTINCT s.NomeS, s.Matricola
FROM STUDENTI s LEFT JOIN FREQUENTA f ON
s.Matricola = f.Matricola 
WHERE f.Matricola IS NULL