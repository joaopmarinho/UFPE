# Laços

## For

### Forma Geral:
 - for(inicialização; condição; incremento) comando;

. Inicialização, geralmente uma variável para o controle do laço.
. Condição, Determina quando o laço acaba.
. Incremento, define a variação a cada vez que o laço repetido.

### Variações
 - Inicialização pode ser separado por virgula:
for(int x = 0, int y = 0; x == y; x++) printf("Oi");

 - Condição pode ser qualquer sentença lógica:
for (int x = 0; x < 3 && strcmp (str), "senha"; ++x) {
    printf("Digite a senha por favor:");
    gets(str);
}

 - Em geral, pode ser usado qualquer expressão válida em C nas seções.
for (printf("Digite um número" ); scanf("%d", &x); printf("Digite um número: )) {
    printf("%d\n", x*x);
}

 - Não é obrigatório ter definições nas seções:
for (; x < y;) condição;
Lembrando que se não colocar uma condicional no meio, será infinito.
A menos que tenha break.

 - For sem corpo é útil para atraso de tempo:
for ( ; *str == ' '; str++) ;

## While

### Forma Geral
 - while(condição) comando;

### Variações

 - Não é necessário haver nenhum comando no corpo do while
while((ch=getchar()) != 'A') {};

## Do-While

### Forma Geral
 - do { comando; } while (condição);

Basicamente faz, enquanto.

## Outros comandos:

- return
- goto
- exit()
- continue