SELECT DISTINCT a.nome
FROM attori a, recita r, film f
WHERE r.codFilm = f.codFilm
AND a.codAttore = r.codAttore
AND f.annoProd < 1960
AND f.regista LIKE "%Fellini%"
AND a.codAttore NOT IN (
	SELECT DISTINCT r.codAttore
	FROM recita r, film f
	WHERE f.codFilm = r.codFilm
	AND annoProd < 1960
	AND f.regista NOT LIKE "%Fellini%"
)