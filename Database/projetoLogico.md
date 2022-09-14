# Projeto lógico

- Atributo multivalorado: Crie um elemento com seu nome e seus atributos são identificadores, atríbuto único do pai e próprio nome.
- Relacionamento unário: Torna-se atributo do elemento.
- Relacionamento: Tem como atributos identificadores os identificadores dos elementos ligados.
- Associativa: Não esquecer de determinar os relacionamentos!
- Relacionamento 1:N a relação identificada é do lado de N

## Projeto

1. PESSOA(**cpf**, sexo, cep, bairro, cidade, rua, número, complemento)

---

2. FONE(**cpf, fone**)

- cpf -> PESSOA(cpf)

3. EMAIL(**cpf, email**)

- cpf -> PESSOA(cpf)

---

4. CLINICA(**id_DA_CLINICA**, capacidade, cep, bairro, cidade, rua, numero, complemento)

5. FONE_CLINICA(**id, fone**)

- id -> CLINICA(id_DA_CLINICA)

---

6. FUNCIONARIO(**cpf**, matricula, [paga])

- paga -> CLINICA(id_DA_CLINICA)
- cpf -> PESSOA(cpf)

---

```
É necessário key composta para paciente?
CASO: Médico e recepcionista pode ser paciente.
```

7. PACIENTE(**cpf, id_paciente**)

- cpf -> PESSOA(cpf)

---

8. RECEPCIONISTA(**cpf, id_recepcionista**)

- cpf -> FUNCIONARIO(cpf)

---

```
É necessário key composta para médico?
CASO: CRM identifica o médico.
```

9. MEDICOS(**cpf, CRM**, chefia)

- cpf -> PESSOA(cpf)
- chefia -> MEDICOS(cpf)

---

10. EXAME(**cpf_paciente, id_de_paciente, cod**)

- (cpf_paciente, id_de_paciente) -> PACIENTE(cpf, id_de_paciente)

12. MEDICAMENTO(**cpf_paciente, id_de_paciente, cod**, medicamento)

- (cpf_paciente, id_de_paciente, cod) -> EXAME(cpf_paciente, id_de_paciente, cod)

---

13. AGENDAMENTO(**cpf_recepcionista, id_recepcionista, cpf_paciente, id_de_paciente, cpf_medico, CRM, Formulário**)

- (cpf_recepcionista, id_recepcionista) -> RECEPCIONISTA(cpf, id_recepcionista)
- (cpf_paciente, id_de_paciente) -> PACIENTE(cpf, id_de_paciente)
- (CRM, cpf_medico) -> MEDICO(CRM, cpf)

---

```
CASO: Agendamento têm uma key composta.
DÚVIDA: Deve-se pegar o resto além do formulário?
```

14. CONSULTA(**data**, marca)

- data -> CONSULTA(data)
- marca -> AGENDAMENTO(Formulário)
