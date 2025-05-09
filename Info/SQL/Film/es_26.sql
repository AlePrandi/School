SELECT film.titolo, proiezioni.incasso
FROM film, proiezioni
WHERE film.genere = "fantascienza" AND (film.codFilm = proiezioni.codFilm) and proiezioni.dataProiezione >= "2001-01-01"
GROUP BY film.titolo