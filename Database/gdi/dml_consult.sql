-- MOSTRANDO NOME DA CLINICA QUE POSSUEM MAIS DE 10 FUNCIONARIOS (COM INNER JOIN)
select c.razao_social, count(*) qtd_func from funcionario f
inner join clinica c on c.id = f.id_clinica
group by c.razao_social
having count(*) > 10

-- MOSTRANDO ID DAS CLINICAS QUE TEM MAIS FUNCIONARIOS QUE A MÉDIA 
SELECT ID_CLINICA, COUNT(*) 
FROM FUNCIONARIO 
GROUP BY ID_CLINICA
HAVING COUNT(*) > (SELECT AVG(QTD)
                    FROM (SELECT ID_CLINICA, COUNT(*) AS QTD
                            FROM FUNCIONARIO GROUP BY ID_CLINICA));
                            
--MOSTRANDO NOME DAS CLINICAS QUE TEM MAIS FUNCIONARIO QUE A MÉDIA
SELECT C.RAZAO_SOCIAL, COUNT(*) 
FROM FUNCIONARIO F
INNER JOIN CLINICA C 
ON (F.ID_CLINICA = C.ID)
GROUP BY C.RAZAO_SOCIAL
HAVING COUNT(*) > (SELECT AVG(QTD)
                    FROM (SELECT ID_CLINICA, COUNT(*) AS QTD
                            FROM FUNCIONARIO GROUP BY ID_CLINICA));
                            
--MOSTRANDO FUNCIONARIOS (NOME, CPF) QUE NAO RECEBEM SALARIO
SELECT NOME, CPF FROM FUNCIONARIO 
WHERE CPF NOT IN (SELECT CPF 
                        FROM PAGA_FUNCIONARIO);

--NOME DOS MÉDICOS QUE RECEBE MAIS DE 5 MIL (COM INNER JOIN)
SELECT F.NOME, M.CRM 
FROM FUNCIONARIO F 
INNER JOIN MEDICOS M 
ON (M.CPF = F.CPF)
INNER JOIN PAGA_FUNCIONARIO P
ON (P.CPF = F.CPF)
WHERE P.VALOR > 5000;
                        
--NOME DOS MÉDICOS QUE RECEBE MAIS DE 5 MIL (COM SUB-CONSULTA)
SELECT F.NOME, M.CRM 
FROM FUNCIONARIO F 
INNER JOIN MEDICOS M 
ON (M.CPF = F.CPF)
WHERE M.CPF IN (SELECT CPF 
                FROM PAGA_FUNCIONARIO
                WHERE VALOR > 5000);    

--id da clínica que tem mais de n funcionarios com //inner join e group by
-- select c.razao_social, count(*) qtd_func from funcionario f
-- inner join clinica c on c.id = f.id_clinica
-- group by c.razao_social
-- having count(*) > 10

-- funcao de uma empresa que tem industries no nome
-- select funcao from EMPRESA_TERCEIRIZADA
-- where razao_social like ('%Industries')

--quantidade de medicos que não tem supervisor
-- select count(*) from medicos
-- where cpf in (select supervisor from medicos)

--funcionarios que trabalham de graça para a clinica com left join e null
--select nome from funcionario f
--left join paga_funcionario p on p.cpf = f.cpf
--where f.id_clinica is not null and p.cpf is null

--funcionarios que trabalham de graça para a clinica com right join e null
-- select nome from paga_funcionario p
-- right join funcionario f on p.cpf = f.cpf
-- where f.id_clinica is not null and p.cpf is null

--exibindo funcionarios que não são medicos com //antijoin
-- select nome from funcionario
-- where cpf not in (select cpf from medicos)

--medicos que não recebem salario com anti join e in
-- select nome from funcionario
-- where cpf in (select cpf from medicos) and cpf not in (select cpf from paga_funcionario)

-- nomes e salarios das pessoas que ganham salario trabalhando na clinica de id 8 e a capacidade maior que 100
-- select nome, valor from paga_funcionario p, funcionario f
-- where p.id_clinica in (select id from clinica
--                     where id = 8 and capacidade > 100) and
--                     p.cpf in (select cpf from funcionario)
--                     and valor is not null

-- quantos medicos recebem salário
-- select count(*)as medicosAssalariados from medicos
-- where cpf in (select cpf from paga_funcionario)

--RAZÃO SOCIAL DAS CLINICAS DOS ESTADOS QUE TEM MAIS DE 2 CLINICAS, retorna uma tabela

-- select RAZAO_SOCIAL,ESTADO from CLINICA
-- where ESTADO in(select ESTADO from CLINICA
-- GROUP BY ESTADO
-- having COUNT(ESTADO) > 2)
-- order by ESTADO

-- o nome de todos os supervisores e qtd de medicos q supervisionam mais de 3 medicos

-- select NOME, count(SUPERVISOR) as qtd from FUNCIONARIO 
-- inner join MEDICOS on FUNCIONARIO.CPF = MEDICOS.SUPERVISOR
-- group by nome, Supervisor
-- HAVING COUNT(SUPERVISOR) > 3
-- order by QTD DESC

-- nomes dos pacientes que não são funcionários//antijoin
-- select nome from paciente p
-- where not exists (select f.cpf from funcionario f
--                 where p.cpf = f.cpf)

--nomes dos pacientes que também são funcionários//está faltando popular pacientes que também são funcionários

-- select nome from funcionario
-- intersect
-- select nome from paciente

--uniao de beneficio com paga


                    
