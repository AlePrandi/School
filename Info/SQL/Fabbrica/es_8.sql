SELECT a.codOperaio, a.sesso
FROM sedeA AS a LEFT JOIN sedeB AS b
ON a.codOperaio = b.codOperaio
WHERE b.codOperaio IS NULL
UNION
SELECT b.codOperaio,b.sesso
FROM sedeB AS b LEFT JOIN sedeA AS a
ON b.codOperaio = a.codOperaio
WHERE a.codOperaio IS NULL