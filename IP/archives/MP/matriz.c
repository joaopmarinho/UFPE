#include <stdio.h>
#include <stdlib.h>
int **alocarScanfMatriz(int lin, int col){
    int **m;
    m = (int **)calloc(lin, sizeof(int *));
    if(m==NULL){
        printf("ERRO DE ALOCACAO!\n");
        exit(1);
    }
    for(int i=0; i<lin; i++){
        m[i] = (int *)calloc(col, sizeof(int));
        if(m[i]==NULL){
            printf("ERRO DE ALOCACAO!\n");
            exit(2);
        }
    }
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            scanf("%d", &m[i][j]);
        }
    } 
    return m;
}
void imprimirMatriz(int **m, int lin, int col){
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
void freeMatriz(int **m, int lin){
    for (int i = 0; i < lin; i++){
        free(m[i]);
    }
    free(m);
}
int main(void){
    int **matriz;
    int lin, col;
    printf("Num de linhas: \n");
    scanf("%d", &lin);
    printf("Num de colunas: \n");
    scanf("%d", &col);
    matriz = alocarScanfMatriz(lin, col);
    imprimirMatriz(matriz, lin, col);
    freeMatriz(matriz, lin);
    /*excluirLinha();
    ordenarLinha();
    excluirColuna();
    ordenarColuna();*/
}