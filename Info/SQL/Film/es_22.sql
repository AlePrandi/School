SELECT film.codFilm, film.titolo, film.regista, SUM(proiezioni.incasso) as incasso_tot
FROM film, proiezioni
WHERE film.annoProd > 2000
AND film.codFilm = proiezioni.codFilm