SELECT codOperaio, assuntoIl
FROM sedeB, Responsabili
WHERE nome = "Maria" AND cognome = "Fassa" AND codR = codResp
ORDER BY assuntoIl