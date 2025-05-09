SELECT DISTINCT sale.nome
FROM attori, proiezioni, sale, recita
WHERE recita.codFilm = proiezioni.codFilm 
AND proiezioni.codSala = sale.codSala 
AND recita.codAttore = attori.codAttore 
AND proiezioni.dataProiezione = "2004-12-25"  
AND sale.citta = "Napoli" 
AND attori.nome = "Robin Williams"