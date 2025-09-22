-- Union mette due tabelle con le stesse colonne una sotto l'altra
-- fa vedere in automatico righe distinte
SELECT * , "sede A" as sede
FROM sedeA 
UNION ALL   -- mettendo ALL include anche quelle che si ripetono
SELECT * , "sede B" as sede
FROM sedeB
ORDER BY codOperaio