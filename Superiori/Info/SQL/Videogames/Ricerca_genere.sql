-- Elencare tutti i dati per ogni gioco della categoria scelta
--SELECT game.id, game.game_name, genre.genre_name
SELECT COUNT(*), genre.genre_name
FROM game, genre
WHERE genre.genre_name LIKE "%Sports%" AND game.genre_id = genre.id 
/*
= vuole la scritta usata
LIKE vuole i campi simili si usa il % per completare la ricerca 
es. Acti% da tutti i risultati che iniziano con Acti
es. %S% in qualsiasi posizione

*/