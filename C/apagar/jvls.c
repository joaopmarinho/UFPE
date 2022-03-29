#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_CODE 15
#define N_REG 32

typedef struct{
    int num_instrucao;
    char instr_nome[4];
    int destino, origem;
}Instrucao;

int main()
{
    int N_LINHA=0,i,j,flag = 0,valor = 0;

    scanf("%d",&N_LINHA);

    int registe[N_REG] = {0};
    Instrucao instrucao[N_LINHA];//ESTRUTURA
    char codigo[N_LINHA][TAM_CODE];//MATRIZ DE STRING

    for(i=0;i<N_LINHA;i++){//preenche a matriz de caracteres de codigo !
        // Desconsidera que o ldv tenha muitos números
        scanf(" %14[^\n]", codigo[i]);
    }

    for(i=0;i<N_LINHA;i++){
        // -5, Nome é a linha toda?
        strcpy(instrucao[i].instr_nome,codigo[i]);
        for(j=0;j<TAM_CODE;j++){
        // -10 Não considerou que o número possa ser dezena.
        if(codigo[i][j] == 'l' && flag!=1){
            // Instrução 1, incorreta.
            instrucao[i].num_instrucao = 1;
            instrucao[i].destino = codigo[i][4]; 
            instrucao[i].origem = codigo[i][6]; 
            // -10, número pode ser dezena, centena...
            flag = 1;
        }
        if(codigo[i][j] == 's' && codigo[i][j+1] == 'w' && flag!=1){
            instrucao[i].num_instrucao = 2;
            instrucao[i].destino = codigo[i][4];
            instrucao[i].origem = codigo[i][6];
            flag = 1;
        }
        if(codigo[i][j] == 'm' && codigo[i][j+1] == 'o' && flag!=1){
            instrucao[i].num_instrucao = 3;
            instrucao[i].destino = codigo[i][4];
            instrucao[i].origem = codigo[i][6];
            flag = 1;
        }
        if(codigo[i][j] == 'a' && flag!=1){
            instrucao[i].num_instrucao = 4;
            instrucao[i].destino = codigo[i][4];
            instrucao[i].origem = codigo[i][6];
            flag = 1;
        }
        if(codigo[i][j] == 's' && codigo[i][j+1] == 'u' && flag!=1){
            instrucao[i].num_instrucao = 5;
            instrucao[i].destino = codigo[i][4];
            instrucao[i].origem = codigo[i][6];
            flag = 1;
        }
        if(codigo[i][j] == 'm' && codigo[i][j+1] == 'u' && flag!=1){
            instrucao[i].num_instrucao = 6;
            instrucao[i].destino = codigo[i][4];
            instrucao[i].origem = codigo[i][6];
            flag = 1;
        }
            }
            flag = 0;
    }
    for(i=0;i<N_REG;i++){//faz as instrucoes
            if(instrucao[i].num_instrucao == 1){
                // -10 Isso não existe
                scanf("%d", &valor);
                registe[instrucao[i].destino] = valor;
            }
            if(instrucao[i].num_instrucao == 2){
                // -5 Swap? A = B e B = 0????? 
                registe[instrucao[i].destino] = registe[instrucao[i].origem];
                registe[instrucao[i].origem] = 0;
            }
            if(instrucao[i].num_instrucao == 3){
                registe[instrucao[i].destino] = registe[instrucao[i].origem];
            }
            if(instrucao[i].num_instrucao == 4){
                registe[instrucao[i].destino] = registe[instrucao[i].destino] + registe[instrucao[i].origem];
            }
            if(instrucao[i].num_instrucao == 5){
                registe[instrucao[i].destino] = registe[instrucao[i].destino] - registe[instrucao[i].origem];
            }
            if(instrucao[i].num_instrucao == 6){
                registe[instrucao[i].destino] = registe[instrucao[i].destino] * registe[instrucao[i].origem];
            }

    }
    //imprimi os valores na tela.
    printf("Valores nos registradores:\n");
    for(i=0;i<N_REG && flag!= 2;i++){
        if(registe[i] != 0){
            printf("register[%d] = %d\n",i,registe[i]);
        }
        if(i>N_REG){
            printf("ERRO!!!");
            flag = 2;
        }
    }

    return 0;
}

// 60% Retirando pontos +5 por usar o registrador