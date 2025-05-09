SELECT b.*, cognome AS "Cognome Responsabili", nome AS "Nome Responsabile"	
FROM sedeA AS b, Responsabili AS r 
where b.codR = r.codResp 