/*Quanti superhero ci sono nel db*/
-- per testare che funzioni basta mettere il SELECT *
-- group by --> raggruppare
SELECT gender.gender as Generi, count(*)
FROM superhero, gender
WHERE superhero.gender_id = gender.id
/*
WHERE gender_id = 1 -- sul singolo dato di ricerca
UNION
SELECT COUNT(*)
FROM superhero 
WHERE gender_id = 2 
*/
GROUP BY gender_id