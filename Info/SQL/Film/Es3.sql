SELECT titolo, durata
FROM film
WHERE genere = "fantascienza" AND annoProd > 1990 AND ( nazionalita = "FR" OR nazionalita ="JPN")