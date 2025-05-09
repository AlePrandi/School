SELECT codOperaio
FROM sedeB
WHERE strftime("%Y", assuntoIl) = "2011"
ORDER BY assuntoIl DESC
