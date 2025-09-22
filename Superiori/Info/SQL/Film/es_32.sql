SELECT A.Nome
FROM ATTORI A
WHERE A.Nazionalita = 'ITA'
AND A.CodAttore NOT IN (
    SELECT DISTINCT R.CodAttore
    FROM RECITA R
    JOIN FILM F ON R.CodFilm = F.CodFilm
    WHERE F.Regista = 'Fellini'
)
