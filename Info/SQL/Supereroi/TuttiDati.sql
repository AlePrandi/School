SELECT superhero_name, gender.gender, o.colour AS "colore_occhi", c.colour AS "colore_capelli", 
p.colour AS "colore_pelle", race AS "razza", publisher.publisher_name, alignment.alignment, height_cm, weight_kg
FROM superhero,gender, colour  AS o, colour AS c, colour AS p, race, publisher, alignment
WHERE superhero.gender_id = gender.id
AND superhero.eye_colour_id = o.id 
AND superhero.hair_colour_id = c.id
AND superhero.skin_colour_id = p.id
AND superhero.race_id = race.id
AND superhero.publisher_id = publisher.id
AND superhero.alignment_id = alignment.id
AND superhero.superhero_name LIKE "%Batman%"