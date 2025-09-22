SELECT film.titolo, count(*) as n_attori
FROM attori, film, recita
WHERE film.codFilm = recita.codFilm
AND attori.codAttore = recita.codAttore
AND attori.annoNascita < 1970
GROUP BY film.titolo