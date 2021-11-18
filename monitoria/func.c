#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    char telefone[20];
    int dia;
    int mes;
} Agenda;

//Sem argumento, mas retornando o ponteiro
Agenda* inserirSA(int qtd) {
    Agenda *contato = NULL;
    char nome[50], telefone[20];
    int dia, mes;
    contato = (Agenda *) calloc(qtd+1, sizeof(Agenda));
    if (contato == NULL) {
        printf("------------------\nDeu ruim em alocar\n------------------\n");
        return;
    }
    printf("Digite o Nome:\n");
    scanf("%s", nome);
    strcpy(contato[qtd].nome, nome);

    printf("Digite o telefone:\n");
    scanf("%s", telefone);
    strcpy(contato[qtd].telefone, telefone);

    printf("Digite o dia e mes\n");
    scanf("%d %d", &dia, &mes);
    contato[qtd].dia = dia;
    contato[qtd].mes = mes;
    return contato;
}
//Com ponteiro simples no argumento 
void inserir(Agenda *contato, int qtd) {
    char nome[50], telefone[20];
    int dia, mes;
    contato = (Agenda *) realloc(contato, (qtd+1) * sizeof(Agenda));
    if (contato == NULL) {
        printf("------------------\nDeu ruim em alocar\n------------------\n");
        return;
    }
    printf("Digite o Nome:\n");
    scanf("%s", nome);
    strcpy(contato[qtd].nome, nome);

    printf("Digite o telefone:\n");
    scanf("%s", telefone);
    strcpy(contato[qtd].telefone, telefone);

    printf("Digite o dia e mes\n");
    scanf("%d %d", &dia, &mes);
    contato[qtd].dia = dia;
    contato[qtd].mes = mes;
}
//Com ponteiro duplo ou ++ no argumento
void inserirPD(Agenda **contato, int qtd) {
    char nome[50], telefone[20];
    int dia, mes;
    (*contato) = (Agenda *) realloc(*contato, (qtd+1) * sizeof(Agenda));
    if ((*contato) == NULL) {
        printf("------------------\nDeu ruim em alocar\n------------------\n");
        return;
    }
    printf("Digite o Nome:\n");
    scanf("%s", nome);
    strcpy((*contato)[qtd].nome, nome);

    printf("Digite o telefone:\n");
    scanf("%s", telefone);
    strcpy((*contato)[qtd].telefone, telefone);

    printf("Digite o dia e mes\n");
    scanf("%d %d", &dia, &mes);
    (*contato)[qtd].dia = dia;
    (*contato)[qtd].mes = mes;
}

int pesquisar(Agenda *contato, int qtd, char nome[]) {
    int i;
    for (i = 0; i < qtd; i++) {
        if (strcmp(nome, contato[i].nome) == 0) {
            return i;
        }
    }
    return;
}

void remover(Agenda *contato, int qtd) {
    char nome[50];
    int num;

    printf("Digite o nome do contato que quer excluir: ");
    scanf(" %s", nome);
    num = pesquisar(contato, qtd, nome);
    if (!num) {
        printf("Nao ha esse contato na agenda\n");
        return;
    }

    contato[num] = contato[qtd];
    contato = (Agenda *) realloc(contato, qtd * sizeof(Agenda));
}

void listar(Agenda *contato, int qtd) {
    int i;
    printf("------------------------------------\n");
    for (i = 0; i < qtd; i++) {
        printf("Nome: %s\n", contato[i].nome);
        printf("Telefone: %s\n", contato[i].telefone);
        printf("Aniversario: %d/%d\n", contato[i].dia, contato[i].mes);
        printf("------------------------------------\n");
    }
}

void imprimir(Agenda *contato, int qtd, int mes) {
    int i;
    for (i = 0; i < qtd; i++) {
        if (contato[i].mes == mes) {
            printf("Nome do aniversariante: %s\n", contato[i].nome);
        }
    }
}

int main() {
    int escolha, qtd = 0, mes;
    Agenda *contatos = NULL;
    printf("Digite o mes atual (1-12): \n");
    scanf("%d", &mes);

    contatos = inserirSA(qtd);
    qtd++;

    printf("Agenda\n");
    printf("Digite 0 para sair\n1 Inserir contato\n2 Remover contato\n3 Listar contatos\n4 Imprimir aniversariante\n");
    scanf("%d", &escolha);

    while (escolha != 0) {
        switch (escolha)
        {
        case 1:
            inserir(contatos, qtd);
            qtd++;
            inserirPD(&contatos, qtd);
            qtd++;
            break;
        case 2:
            remover(contatos, qtd);
            qtd--;
            break;
        case 3:
            listar(contatos, qtd);
            break;
        case 4:
            imprimir(contatos, qtd, mes);
            break;
        default:
            printf("Numero invalido\n");
            break;
        }
        printf("Digite 0 para sair\n1 Inserir contato\n2 Remover contato\n3 Listar contatos\n4 Imprimir aniversariante\n");
        scanf("%d", &escolha);
    }
}