SELECT sale.nome, SUM(proiezioni.incasso) as incasso_Totale
FROM sale, proiezioni
WHERE sale.citta = "Pisa" 
AND sale.codSala = proiezioni.codSala
AND strftime('%m-%Y', proiezioni.dataProiezione) = "01-2005"
GROUP BY sale.nome
HAVING SUM(proiezioni.incasso) > 20000;
