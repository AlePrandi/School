SELECT film.regista, sum(proiezioni.incasso) as incasso
FROM film, proiezioni
WHERE film.codFilm = proiezioni.codFilm
GROUP BY film.regista
ORDER BY sum(proiezioni.incasso) ASC 