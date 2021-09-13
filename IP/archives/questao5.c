/*
5.Faça um programa gerenciar uma agenda de contatos. Para cada contato armazene o nome, o telefone e o aniversário (dia e mês). O programa deve permitir:
(a)Inserir contatos
(b)Remover contato
(c)Pesquisar um contato pelo nome
(d)Listar todos os contatos
(e)Listar os contatos cujo nome inicia com uma determinada letra
(f)Imprimir os aniversariantes do mês
Sempre que o programa for encerrado, os contatos devem ser armazenados em um arquivo binário. Quando o programa iniciar, os contatos devem ser inicializados com dados contidos neste arquivo binário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[35];
    char telefone[15];
    unsigned short int aniverDia, aniverMes;
} Agenda;

void inserir(Agenda **contato, int qtd)
{
    char nome[35], telefone[15];
    unsigned short int dia, mes;
    (*contato) = (Agenda *)realloc(*contato, (qtd + 1) * sizeof(Agenda));

    if ((*contato) == NULL)
        exit(1);

    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);
    strcpy((*contato)[qtd].nome, nome);

    printf("Digite o telefone: ");
    scanf(" %s", telefone);
    strcpy((*contato)[qtd].telefone, telefone);

    printf("Digite o dia e mes do aniversario: ");
    scanf("%hu %hu", &dia, &mes);
    (*contato)[qtd].aniverDia = dia;
    (*contato)[qtd].aniverMes = mes;
}

int pesquisar(Agenda *contato, int qtd, char nome[])
{
    for (int i = 0; i < qtd; i++)
        if (strcmp(nome, contato[i].nome) == 0)
            return i;
    return qtd;
}

void remover(Agenda *contato, int *qtd)
{
    char nome[35];
    int num, existe = 0;
    printf("Digite o nome do contato que quer excluir: ");
    scanf(" %[^\n]", nome);
    num = pesquisar(contato, *qtd, nome);
    if (num != (*qtd))
    {
        existe = 1;
        contato[num] = contato[(*qtd) - 1];
        contato = (Agenda *)realloc(contato, (*qtd) * sizeof(Agenda));
        (*qtd)--;
    }

    if (!existe)
        printf("Contato inexistente.\n");
}

void pesquisarNome(Agenda *contato, int qtd)
{
    char nome[35];
    int existe = 0, contador = 0;
    printf("Digite o nome que voce quer pesquisar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < qtd; i++)
    {
        if (strcmp(nome, contato[i].nome) == 0)
        {
            contador++;
            existe = 1;
        }
    }

    if (!existe)
        printf("Contato inexistente.\n");
    else
        printf("Existe(m) %d contato(s) com esse nome.\n", contador);
}

void listarTodos(Agenda *contato, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        printf("Nome: %s\n", contato[i].nome);
        printf("Telefone: %s\n", contato[i].telefone);
        printf("Aniversario: %02d/%02d\n", contato[i].aniverDia, contato[i].aniverMes);

        if (i != qtd - 1)
            printf("-----------------------------\n");
    }
}

void listarInicial(Agenda *contato, int qtd)
{
    int existe = 0, contador = 0;
    char inicial;
    printf("Digite a inicial do nome do contato: ");
    scanf(" %c", &inicial);

    for (int i = 0; i < qtd; i++)
        if (contato[i].nome[0] == inicial)
        {
            printf("%s\n", contato[i].nome);
            existe = 1;
            contador++;
        }

    if (!existe)
        printf("Voce nao tem nenhum contato que comeca com essa letra.\n");
    else
        printf("(%d contatos comecam com a letra %c)\n", contador, inicial);
}

void aniverDoMes(Agenda *contato, int qtd)
{
    unsigned short int mes;
    printf("Digite o mes: ");
    scanf("%hu", &mes);

    for (int i = 0; i < qtd; i++)
        if (contato[i].aniverMes == mes)
            printf("Nome do aniversariante: %s\n", contato[i].nome);
}

int main(void)
{
    int qtd = 0;
    char operacao;
    Agenda *contatos = NULL;
    FILE *file = NULL;

    file = fopen("contatos.bin", "a+b");
    if (file == NULL)
        exit(1);

    //contabilizar quantos contatos há na agenda
    fseek(file, 0, SEEK_END);
    qtd = ftell(file) / sizeof(Agenda);
    rewind(file);

    contatos = (Agenda *)malloc(qtd * sizeof(Agenda));
    if (contatos == NULL)
        exit(1);

    fread(contatos, sizeof(Agenda), qtd, file);
    fclose(file);

    printf("-----------------\tAgenda\t-----------------\n");
    printf("a: Inserir contato\nb: Remover contato\nc: Pesquisar um contato pelo nome\nd: Listar contatos\ne: Listar contatos cujo nome inicia com uma determinada letra\nf: Imprimir aniversariantes do mes");
    printf("\n-----------------\n");

    do
    {
        scanf(" %c", &operacao);
        printf("-----------------\n");
        switch (operacao)
        {
        case 'a': //Inserir contato
            inserir(&contatos, qtd);
            qtd++;
            file = fopen("contatos.bin", "wb");
            fwrite(contatos, sizeof(Agenda), qtd, file);
            fclose(file);
            break;

        case 'b': //Remover contato
            remover(contatos, &qtd);
            file = fopen("contatos.bin", "wb");
            fwrite(contatos, sizeof(Agenda), qtd, file);
            fclose(file);
            break;

        case 'c': //Pesquisar um contato pelo nome
            pesquisarNome(contatos, qtd);
            break;

        case 'd': //Listar todos os contatos
            listarTodos(contatos, qtd);
            break;

        case 'e': //Listar os contatos cujo nome inicia com uma determinada letra
            listarInicial(contatos, qtd);
            break;

        case 'f': //Imprimir os aniversariantes do mês
            aniverDoMes(contatos, qtd);
            break;
        }
        printf("-----------------\n");
    } while (operacao >= 'a' && operacao <= 'f');

    free(contatos);

    return 0;
}