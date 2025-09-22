SELECT film.titolo, sum(proiezioni.incasso) as incasso
FROM film, proiezioni
WHERE film.genere like "%Fanta%"
AND film.codFilm = proiezioni.codFilm
AND proiezioni.dataProiezione > "01-01-2001"
GROUP BY film.titolo