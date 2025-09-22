SELECT s.NomeS, s.Matricola
FROM studenti s
WHERE s.Matricola NOT IN (
SELECT DISTINCT f.Matricola 
FROM FREQUENTA f)