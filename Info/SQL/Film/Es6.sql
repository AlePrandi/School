SELECT DISTINCT film.titolo, film.genere
FROM proiezioni, film, sale
WHERE film.codFilm = proiezioni.codFilm AND proiezioni.codSala = sale.codSala AND dataProiezione = "2004-12-25"  AND sale.citta = "Napoli" 