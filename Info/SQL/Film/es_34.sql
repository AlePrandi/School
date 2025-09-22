SELECT titolo
FROM film
WHERE codFilm NOT IN (
    SELECT codFilm
    FROM recita
)
