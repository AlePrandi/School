SELECT race.race, sum(superhero.weight_kg) as Peso_Totale, avg(superhero.height_cm) AS Altezza_Media
FROM superhero, race
WHERE superhero.race_id = race.id
AND race.race LIKE "%Saiyan%"
GROUP BY race_id