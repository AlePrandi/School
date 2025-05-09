SELECT cl.CorsoLaurea, avg(YEAR(CUR_DATE) - YEAR(AnnoN)) as eta_media
FROM CORSIDILAUREA as cl, studenti as s
WHERE s.CorsoLaurea = cl.CorsoLaurea
GROUP BY cl.CorsoLaurea