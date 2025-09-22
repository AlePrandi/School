SELECT titolo
FROM film
WHERE regista LIKE "%Fellini%"
AND codFilm NOT IN (
    SELECT r.codFilm
    FROM recita r, attori a
    WHERE r.codAttore = a.codAttore
    AND a.nazionalita = "ITA"
)
