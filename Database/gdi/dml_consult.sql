/* CONSULTA 22 - PROJETAR O TÍTULO DE TODOS OS ARTIGOS PUBLICADOS E A SIGLA DOS SEUS RESPECTIVOS EVENTOS  - 
USANDO “INNER JOIN” */
SELECT A.TITULO, E.SIGLA
FROM ARTIGO A INNER JOIN EVENTO E ON (A.COD = E.COD);

/* CONSULTA 30  - PROJETAR OS ARTIGOS (TÍTULOS) NÃO PUBLICADOS E OS EVENTOS (SIGLAS) SEM ARTIGOS 
- USANDO “FULL OUTER JOIN” */
SELECT A.TITULO, E.SIGLA
FROM ARTIGO A FULL OUTER JOIN EVENTO E ON (A.COD = E.COD)
WHERE  A.COD IS NULL OR E.COD IS NULL;

CREATE OR REPLACE PROCEDURE MORE_THAN (QTD IN INT) IS 
BEGIN  
  SELECT P.NOME, COUNT(*) 
  FROM PESQUISADOR P INNER JOIN ESCREVE E ON (P.CPF = E.CPF) 
  GROUP BY P.NOME
  HAVING COUNT(*) > QTD;
END;

/* CONSULTA 43 - PROJETAR OS TÍTULOS DOS ARTIGOS COM NOTA MAIOR DO QUE TODOS OS ARTIGOS DO EVENTO ‘SBBD’ */
SELECT TITULO
FROM ARTIGO
WHERE NOTA > ALL
    (SELECT NOTA
    FROM ARTIGO A INNER JOIN EVENTO E ON (A.COD = E.COD)
    WHERE  E.SIGLA = 'SBBD21');


/* CONSULTA 44 - PROJETAR OS TÍTULOS DOS ARTIGOS COM NOTA MAIOR DO QUE TODOS OS ARTIGOS DO EVENTO ‘SBBD21’ */
SELECT TITULO
FROM ARTIGO
WHERE NOTA >
    (SELECT MAX(NOTA)
    FROM ARTIGO A INNER JOIN EVENTO E ON (A.COD = E.COD)
    WHERE E.SIGLA = 'SBBD21');

-- CONSULTA 54 - PROJETAR A QUALIDADE DO ARTIGO 
SELECT TITULO,
CASE 
    WHEN NOTA >= 8 THEN 'BOM'
    WHEN NOTA >= 6 THEN 'REGULAR'
    ELSE 'RUIM'
END AS QUALIDADE
FROM ARTIGO
