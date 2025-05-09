SELECT DISTINCT film.titolo
FROM attori, recita, film
WHERE attori.codAttore = recita.codAttore
AND recita.codFilm = film.codFilm
AND (attori.nome LIKE "%Mastroianni%" OR attori.nome LIKE "%Loren%")