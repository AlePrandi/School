/*SELECT titolo 
FROM film
WHERE film.codFilm NOT IN (
SELECT DISTINCT proiezioni.codFilm
FROM proiezioni, sale
WHERE proiezioni.codSala = sale.codSala
AND sale.citta LIKE "%Pisa%"
)*/

SELECT titolo 
FROM film
WHERE film.codFilm NOT IN (
SELECT DISTINCT proiezioni.codFilm
FROM proiezioni, sale
WHERE proiezioni.codSala = sale.codSala
AND sale.citta <> "Pisa"
)