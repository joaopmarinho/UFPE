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

6. FUNCIONARIO(**cpf**, matricula, paga!)

- paga -> CLINICA(id_DA_CLINICA)
- cpf -> PESSOA(cpf)

---

7. PACIENTE(**cpf**, id_paciente)

- cpf -> PESSOA(cpf)

---

8. RECEPCIONISTA(**cpf**, id_recepcionista)

- cpf -> FUNCIONARIO(cpf)

---

9. MEDICO(**cpf**, chefia, CRM)

- cpf -> FUNCTIONARIO(cpf)
- chefia -> MEDICO(cpf)

---

10. EXAME(**cpf_paciente, cod**)

- (cpf_paciente) -> PACIENTE(cpf)

11. MEDICAMENTO(**cpf_paciente, cod**, medicamento)

- (cpf_paciente, cod) -> EXAME(cpf_paciente, cod)

---

12. AGENDAMENTO(**cpf_recepcionista, cpf_paciente, cpf_medico, Formulário**)

- (cpf_recepcionista) -> RECEPCIONISTA(cpf)
- (cpf_paciente) -> PACIENTE(cpf)
- (cpf_medico) -> MEDICO(cpf)

---

13. CONSULTA(**data**, cpf_recepcionista, cpf_paciente, cpf_medico, Formulário)

- data -> CONSULTA(data)
- (cpf_recepcionista, cpf_paciente, cpf_medico, Formulário) -> AGENDAMENTO(cpf_recepcionista, cpf_paciente, cpf_medico, Formulário)

<!-- Falta Relacionamento 1:1 -->
