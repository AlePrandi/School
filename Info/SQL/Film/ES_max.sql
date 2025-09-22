SELECT f.titolo, max(incasso) as max_incasso
FROM film AS f, proiezioni as p
WHERE f.codFilm = p.codFilm
HAVING max_incasso = (
SELECT max(incasso) as max_incasso 
FROM film AS f, proiezioni AS p
ORDER BY max_incasso DESC LIMIT 1
)
