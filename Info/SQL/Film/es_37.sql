SELECT attori.nome
FROM attori, film
WHERE attori.nome = film.regista
GROUP BY attori.nome