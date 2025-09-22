SELECT regista, COUNT(*) AS numFilm
FROM film
GROUP BY regista
HAVING numfilm = (
SELECT max(numFilm) as max
FROM (
SELECT count(*) as numFilm
FROM film f
GROUP BY regista)
)
