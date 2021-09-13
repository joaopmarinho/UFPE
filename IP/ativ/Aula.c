#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ERRO
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

int main (void) { 
    int verif = 1, menu, i = 1, j, k;
    char id[5], nome[20], matricula[10];
    Turma *turmas;

    turmas = (Turma*) malloc(1*sizeof(Turma));
    turmas = NULL;

    while (verif != 0) {
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            turmas = (Turma *) realloc(turmas, i*sizeof(Turma));
            if (turmas == NULL) {
                printf("Erro ao criar turma");
                exit(1);
            }
            scanf("%d", &turmas[i-1].qtd);
            scanf(" %s %s", turmas[i-1].professor, turmas[i-1].id);

            turmas[i-1].alunos = (Aluno *) calloc(turmas[i-1].qtd, sizeof(Aluno));
            for (j = 0; j < turmas[i-1].qtd; j++) {
                scanf(" %s", turmas[i-1].alunos[j].nome);
                scanf(" %s", turmas[i-1].alunos[j].mat);
                printf("Notas:\n");
                for (k = 0; k < 5; k++) {
                    scanf("%f", &turmas[i-1].alunos[j].notas[k]);
                    turmas[i-1].alunos[j].media += turmas[i-1].alunos[j].notas[k];
                }
                scanf("%d", &turmas[i-1].alunos[j].faltas);
            }

            i++;
            break;
        case 2:
            scanf(" %s\n %s\n", nome, matricula);
            for (j = 0; j < i; j++) {
                for (k = 0; k < turmas[j].qtd; k++) {
                    if (strcmp(nome, turmas[j].alunos[k].nome) == 0 && strcmp(matricula, turmas[j].alunos[k].mat) == 0) {
                        strcpy(turmas[j].alunos[k].nome, "");
                        strcpy(turmas[j].alunos[k].mat, "");
                        turmas[j].alunos[k].media = 0;
                        turmas[j].alunos[k].faltas = 0;
                        int l;
                        for (l = 0; l < 5; l++) {
                            turmas[j].alunos[k].notas[l] = 0;
                        }
                    }
                }
            }
            break;
        case 3:
            scanf(" %s\n", id);
            for (j = 0; j < i; j++) {
                if (strcmp(id, turmas[j].id) == 0) {
                    for (k = 0; k < turmas[j].qtd; k++) {
                        if (turmas[j].alunos[k].media/5 >= 7) {
                            printf("Aluno %d°: %f\n", k+1, turmas[j].alunos[j].nome);
                        }
                    } 
                }
            }
            break;
        case 4:
            scanf(" %s", id);
            for (j = 0; j < i; j++) {
                if (strcmp(id, turmas[j].id) == 0) {
                    for (k = 0; k < turmas[j].qtd; k++) {
                        if (turmas[j].alunos[k].media/5 < 3) {
                            printf("Aluno %d°: %f\n", k+1, turmas[j].alunos[j].nome);
                        }
                    } 
                }
            }
            break;
        case 5:
            for (j = 0; j < i; j++) {
                printf("Turma %d: %s\n", j+1, turmas[j].professor);
                selection_sort(turmas[j].alunos, turmas[j].qtd);
                for (k = 0; k < turmas[j].qtd; k++) {
                    printf("Aluno %d: %s", k+1, turmas[j].alunos[k].nome);
                }
            }

            break;
        default:
            verif = 0;
            break;
        }
    }
    for (j = 0; j < i; j++) {
        free(turmas[j].alunos);
    }
    free(turmas);
}