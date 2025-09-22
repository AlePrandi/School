SELECT titolo
FROM film 
WHERE titolo <> "%Casablanca%"
regista = 
	(SELECT regista
	FROM film 
	WHERE Titolo LIKE "%Casablanca%")