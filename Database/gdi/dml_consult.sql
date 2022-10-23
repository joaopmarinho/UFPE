--id da clínica que tem mais de n funcionarios com inner join e group by
select c.razao_social, count(*) qtd_func from funcionario f
inner join clinica c on c.id = f.id_clinica
group by c.razao_social
having count(*) > 10
