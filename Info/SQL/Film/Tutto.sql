SELECT *
FROM attori, recita, film, proiezioni, sale
WHERE attori.codAttore = recita.codAttore
AND recita.codFilm = film.codFilm
AND proiezioni.codFilm = recita.codFilm
AND sale.codSala = proiezioni.codSala