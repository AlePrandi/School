CREATE VIEW "VIEW_Migliori" AS 
SELECT a.cognome, a.nome, a.classe, rappre.cognome as cognome_rappre, rappre.nome as nome_rappre, 
rappre.media_voti as media_rappre
FROM alunni a, alunni rappre
WHERE rappre.id = a.id_rappresentante AND a.media_voti > rappre.media_voti;

-- LA CREATE VIEW SI AGGIORNA COSTANTEMENTE SI USA IN CASI PIU' COMPLICATI 
-- LA CREATE TABLE RIMANE FISSA