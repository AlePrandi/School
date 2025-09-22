SELECT film.titolo, sum(proiezioni.incasso) as incasso
FROM film, proiezioni
WHERE film.genere like "%Fanta%"
AND film.codFilm = proiezioni.codFilm
GROUP BY film.titolo