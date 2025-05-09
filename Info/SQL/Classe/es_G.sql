SELECT a.cognome, a.nome, a.classe, a.media_voti, (Gardini.media_voti - a.media_voti) as differenza
FROM alunni a, alunni Gardini
WHERE (Gardini.cognome = "Gardini" AND Gardini.nome = "Ennio")
AND a.media_voti < Gardini.media_voti
ORDER BY a.media_voti DESC
