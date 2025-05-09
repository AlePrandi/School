SELECT film.titolo, film.genere
FROM proiezioni,film
WHERE film.codFilm = proiezioni.codFilm AND proiezioni.dataProiezione = "2004-12-25" 