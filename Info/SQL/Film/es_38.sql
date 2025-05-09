SELECT attori.nome
FROM attori
LEFT JOIN film on attori.nome = film.regista
WHERE film.regista is NULL