SELECT film.titolo, sale.nome
FROM sale, film, proiezioni
WHERE sale.codSala = proiezioni.codSala
AND proiezioni.codFilm = film.codFilm
AND sale.citta = "Pisa"
AND strftime('%m-%Y', proiezioni.dataProiezione) = "01-2005"