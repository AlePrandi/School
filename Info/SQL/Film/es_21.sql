SELECT film.titolo,film.regista, count(*) as n_attori
FROM film, recita, attori
WHERE attori.codAttore = recita.codAttore
AND film.codFilm = recita.codFilm
GROUP BY titolo
HAVING n_attori<6

