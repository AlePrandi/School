SELECT film.titolo, attori.nome
FROM attori, recita, film
WHERE attori.codAttore = recita.codAttore
AND recita.codFilm = film.codFilm
AND attori.nazionalita = "FR"