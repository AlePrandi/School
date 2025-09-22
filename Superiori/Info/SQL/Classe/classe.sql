SELECT alu.*, rappre.cognome AS cognome_rappre, rappre.nome AS nome_rappre
FROM alunni AS alu, alunni AS rappre
WHERE alu.Id_rappresentante = rappre.id