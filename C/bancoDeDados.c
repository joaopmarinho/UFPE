#include <stdio.h>
#include <string.h>

typedef struct {
    char sexo;
    char data[10];
    char nome[50];
} cap;

typedef struct {
    cap morador[4];
} casas;

typedef struct {
    cap morador[4];
} apartamentos;

typedef struct {
    apartamentos ap[2];
} andares;

typedef struct {
    andares andar[20]; 
} edif;

typedef struct{
    char nome[50];
    casas casa[50];
    edif edificio[50];
} ruas;

typedef struct {
    ruas rua[5];
} cidade;

int main(void) {
    cidade jaime;
    int flag = 0;
    int n, i = 0, j, k, w, v, z, m = 0, t = 0;
    int numCasa, numE, numAndar, numAp;
    char local, verif[50], M[50], R[50];
    
    scanf("%d", &n);
    while (n != 3) {
        switch (n) {
        case 1:
            scanf(" %[^\n]", verif);

            for (i = 0; i < 5; i++) {
                if (strcmp(verif, jaime.rua[i].nome) != 0 && jaime.rua[i].nome != 0) {
                    strcpy(jaime.rua[i].nome, verif);
                    m = 0;
                    t = 0;
                    break;
                } else if (strcmp(verif, jaime.rua[i].nome) == 0){
                    break;
                }
            }

            scanf(" %c", &local);
            if (local == 'c') {
                scanf("%d", &numCasa);
                scanf(" [^\n]", jaime.rua[i].casa[numCasa-1].morador[m].nome);
                scanf(" %c", &jaime.rua[i].casa[numCasa-1].morador[m].sexo);
                scanf(" %s", jaime.rua[i].casa[numCasa-1].morador[m].data);
                m++;

            } else if (local == 'e') {
                scanf("%d %d %d", &numE, &numAndar, &numAp);
                scanf(" [^\n]", jaime.rua[i].edificio[numE-1].andar[numAndar-1].ap[numAp].morador[t].nome);
                scanf(" %c", &jaime.rua[i].edificio[numE-1].andar[numAndar-1].ap[numAp].morador[t].sexo);
                scanf(" %s", jaime.rua[i].edificio[numE-1].andar[numAndar-1].ap[numAp].morador[t].data);

            }

            scanf("%d", &n);
            break;
        case 2:
            scanf(" [^\n]", M);
            scanf(" [^\n]", R);
            for (k = 0; k < 5; k++) {
                if (strcmp(R, jaime.rua[k].nome) == 0) {
                    break;
                } 
            }
            for (j = 0; j < 50; j++) {
                for (v= 0; v < 5; v++) {
                    if (strcmp(M, jaime.rua[k].casa[j].morador[v].nome) == 0) {
                        printf("Casa: %d | Sexo: %c | Nascimento: %s\n", j+1, jaime.rua[k].casa[j].morador[v].sexo, jaime.rua[k].casa[j].morador[v].data);
                        flag = 1;
                    }
                } 
            }
            for (j = 0; j < 50; j++) {
                for (w = 0; w < 20; w++) {
                    for (z = 0; z < 2; z++) {
                        for (v= 0; v < 5; v++) {
                            if (strcmp(M, jaime.rua[k].edificio[j].andar[w].ap[z].morador[v].nome) == 0) {
                                printf("Edificio: %d | Andar: %d | Numero do apt.: %d | Sexo: %c | Nascimento: %s\n", j+1, w+1, z+1, jaime.rua[k].edificio[j].andar[w].ap[z].morador[v].sexo, jaime.rua[k].edificio[j].andar[w].ap[z].morador[v].data);
                                flag = 1;
                            }
                        } 
                    }
                }
            }
            if (!flag) printf("Sem dados de \"%s\" em \"%s\"!\n", M, R);
            flag = 0;
            scanf("%d", &n);
            break;
        case 3:
            printf("O programa sera fechado, obrigado por fazer uso dele. Lembre-se de evitar a fadiga!");

            break;
        default:
            printf("Opcao invalida. Por favor, digite uma opcao valida.");

            scanf("%d", &n);
            break;
        }

    }
}