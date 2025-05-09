SELECT titolo
FROM film
WHERE genere = "fantascienza" AND ((annoProd > 1990 AND nazionalita = "JPN") OR nazionalita ="FR")