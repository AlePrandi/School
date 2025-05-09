SELECT film.titolo, count(*) as n_proiezioni, sum(proiezioni.incasso) as incasso_tot
FROM film, sale, proiezioni
WHERE film.regista like "%S.Spielberg%"
AND sale.citta like "%Pisa%" and sale.codSala = proiezioni.codSala
AND film.codFilm = proiezioni.codFilm
GROUP BY film.titolo