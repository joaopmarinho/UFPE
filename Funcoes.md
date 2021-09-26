# Funções

## Forma Geral
 - tipo nome(parâmetros) { corpo; }

### tipo
 - Qualquer tipo de valor que o comando return devolverá.
 - Caso nenhum especificado será retornado inteiro.

### Parâmetros
 - Nome de variáveis separados por vírgula e seus tipos.
 - Função pode não ter parâmetro (parênteses ainda são necessários).
 - Suas variáveis são destruídas na saída.

### Corpo
 - Funções tem escopo diferente do resto do código.
 - Variáveis locais é chamada a variável definida na função.
Use static para tornar global: static int x;

### Return
 - Provoca uma sáida da função
 - Provoca o retorno do valor de uma varíavel ao que chama.
 - Pode ser void caso especifíque no tipo ou não devolver valor.
 
## Chama por Referência
O padrão é a chamada por valor, no qual o método copia o valor de um argumento no parâmetro.

 - Recebe o endereço no parâmetro, possíbilitando alterações.


