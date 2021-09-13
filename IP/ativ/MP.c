#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// jdsc2

typedef struct {
    char nome[20], mat[10];
    float notas[5];
    float media;
    int faltas;
} Aluno;

typedef struct {
    int qtd;
    char professor[20], id[5];
    Aluno *alunos;
} Turma;

void selection_sort(Aluno arr[], int size) {
    int i;
    for (i = 0; i < (size-1); i++) 
    {
        int min = i; 
        //min pois no próximo for o i será +1 para que passe a verificar os próximos
        int j;

        for (j = (i+1); j < size; j++) { 
            //Aqui ele apenas está guardando o número da posição em diante.
            if (strcmp(arr[j].nome, arr[min].nome) < 0) {
                min = j;
            } 
        }
        if (i != min) { 
        //Aqui ele troca de lugar o número em questão pelo menor encontrado no for anterior.
            Aluno aux = arr[i];
            arr[i] = arr[min];
            arr[min] = aux;
        }
    }
}

void inserir(Turma **turmas, int i) {
    int quantidade, falta, j, k;
    char id[5], nome[20], matricula[10], teacher[20];
    float nota[5];

    (*turmas) = (Turma *) realloc(*turmas, i*sizeof(Turma));
    if (*turmas == NULL) {
        printf("Erro ao criar turma");
        exit(1);
    }
    
    printf("Quantidade de alunos:\n");
    scanf("%d", &quantidade);
    (*turmas)[i-1].qtd = quantidade;
    
    printf("Professor:\n");
    scanf(" %s", teacher);
    strcpy((*turmas)[i-1].professor, teacher);

    printf("ID\n");
    scanf(" %s", id);
    strcpy((*turmas)[i-1].id, id);
    
    (*turmas)[i-1].alunos = (Aluno *) calloc((*turmas)[i-1].qtd, sizeof(Aluno));

    for (j = 0; j < quantidade; j++) {

        printf("Nome do aluno:\n");
        scanf(" %s", nome);
        strcpy((*turmas)[i-1].alunos[j].nome, nome);

        printf("Matricula:\n");
        scanf(" %s", matricula);
        strcpy((*turmas)[i-1].alunos[j].mat, matricula);

        printf("Notas:\n");
        for (k = 0; k < 5; k++) {
            scanf("%f", &nota[k]);
            (*turmas)[i-1].alunos[j].notas[k] = nota[k];
            (*turmas)[i-1].alunos[j].media += nota[k];
        }

        printf("N de faltas\n");
        scanf("%d", &falta);
        (*turmas)[i-1].alunos[j].faltas = falta;
    }

    selection_sort((*turmas)[i-1].alunos, (*turmas)[i-1].qtd);
}

void excluir(Turma *turmas, int i) {
    char nome[20], matricula[20];
    int j, k;

    printf("Escolha o nome:\n");
    scanf(" %s", nome);

    printf("matricula para exclusao:\n");
    scanf(" %s", matricula);

    for (j = 0; j < i-1; j++) {
        for (k = 0; k < turmas[j].qtd; k++) {
            if (strcmp(nome, turmas[j].alunos[k].nome) == 0 && strcmp(matricula, turmas[j].alunos[k].mat) == 0) {
                turmas[j].alunos[k] = turmas[j].alunos[turmas[j].qtd-1];
                turmas[j].qtd -= 1;
                turmas[j].alunos = (Aluno *) realloc(turmas[j].alunos, turmas[j].qtd * sizeof(Aluno));
            }
        }
    }
}

void aprovado(Turma *turmas, int i) {
    char id[5];
    int j, k;

    printf("Diga o ID da turma\n");
    scanf(" %s", id);
    for (j = 0; j < i-1; j++) {
        if (strcmp(id, turmas[j].id) == 0) {
            for (k = 0; k < turmas[j].qtd; k++) {
                if (turmas[j].alunos[k].media/5 >= 7) {
                    printf("Aluno %d: %s\n", k+1, turmas[j].alunos[k].nome);
                }
            } 
        }
    }
}

void reprovado(Turma *turmas, int i) {
    int j, k;
    char id[5];

    printf("Diga o ID da turma\n");
    scanf(" %s", id);
    for (j = 0; j < i-1; j++) {
        if (strcmp(id, turmas[j].id) == 0) {
            for (k = 0; k < turmas[j].qtd; k++) {
                if (turmas[j].alunos[k].media/5 < 3) {
                    printf("Aluno %d°: %s\n", k+1, turmas[j].alunos[k].nome);
                }
            } 
        }
    }
}

void exibir(Turma *turmas, int i) {
    int j, k;
    
    for (j = 0; j < i-1; j++) {
        printf("* Turma %d: %s\n", j+1, turmas[j].professor);
        for (k = 0; k < turmas[j].qtd; k++) {
            printf("- %s\n", turmas[j].alunos[k].nome);
        }
        printf("--------------------------------------\n");
    }
}

int main (void) { 
    int verif = 1, menu, i = 1, j;

    Turma *turmas;
    turmas = NULL;

    while (verif != 0) {
        printf("Escolha entre 1-5\n");
        scanf("%d", &menu);
        //scr sei de mais nada
        switch (menu)
        {
        case 1:
            inserir(&turmas, i);
            i++;
            break;
        case 2:
            excluir(turmas, i);
            break;
        case 3:
            aprovado(turmas, i);
            break;
        case 4:
            reprovado(turmas, i);
            break;
        case 5:
            exibir(turmas, i);
            break;
        default:
            printf("Escolha incomum, fechando programa.\n");
            verif = 0;
            break;
        }
    }
    printf("Saiu do programa, free\n");
    for (j = 0; j < i; j++) {
        free(turmas[j].alunos);
    }
    free(turmas);
}

