SELECT attori.nome, film.regista, count(*) as n_film
FROM film, attori, recita
WHERE film.codFilm = recita.codFilm
AND recita.codAttore = attori.codAttore
GROUP BY attori.nome, film.regista