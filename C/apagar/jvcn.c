#include <stdio.h>
#include <string.h>

#deﬁne TAM_CODE 15
#deﬁne N_REG 32
// Struct confusa, -35
typedef struct{
    char codigo[7][6];      // ??????????
    char comandos;         // ???????????
    int num_instrucao[0]; // ????????????
    char instr_nome[4];
} Assembly;

int main(){
    int N_LINHA,i,j,valor;
    scanf("%d", &N_LINHA); // +5
    // ?????????????????????????????
    Assembly codigo[N_LINHA][TAM_CODE];
    Assembly comandos[N_LINHA];
    Assembly valor[1000][1000]; // Registrador é isso?

    for(i = 0 ; i < N_LINHA ; i++){ // +5
        for(j = 0 ; j < N_LINHA; j++){
        // Não funciona o fgets sem o fflush
            fgets(codigo[i], 6 , stdin);        // scanear as strings
        // fgets dentro de tipo Assembly????????
            if(codigo[i][0].Assembly == 'l'){         // se for ldv armazena o valor
            // Não podia usar sprintf
                sprintf(codigo[i][6].Assembly, valor[i][j]);  
                // botando o char valor em inteiro
        }
    }
} // ?????????????????????????????
    for(i = 0 ; i < N_LINHA ; i++){
        for(j = 0 ; j < N_LINHA ; j++){
            if(codigo[i][1] == 'w'){      // se for swap
            // ??????????????????????????
                valor[i][j] = valor[j][i];  // trocando os valores das posicoes
            }
            else if(codigo[i][1] == 'o'){     // se for mov
            // ??????????????????????????
                valor[i][j] = valor[N_LINHA][TAM_CODE]; // copia o valor entre os registradores
            }
            else if(codigo[i][0] == 'a'){   // se for add
                valor[i][j] = valor[i][j] + valor[j][i];  // adiciona os valores destino -- > origem
            }
            else if(codigo[i][2] == 'b'){     // se for sub
                valor[i][j] = valor[i][j] - valor[j][i];  // subtrai os valores
            }
            else if(codigo[i][2] == 'l'){   // se for mul
                valor[i][j] = valor[i][j] * valor[j][i]; // multiplica os valores
        }
    }
}                                                                                        //   =( desculp eu tentei
    printf("Valores nos registradores: "); // +5
    for(i = 0 ; i < N_LINHA - N_LINHA / 2 ; i++){
        for(j = 0 ; j < N_lINHA - N_LINHA / 2 ; j+=){
            printf("Register[%s] = %d", codigo[5].Assembly , valor[i][j]);      
            // posicao 5 sera o numero do registrador
            // ????????????????????????????????
        }
    }
    return 0;
}

// Competência 1 - Struct, falhou
// Competência 2 - Vetores, Tentou
// Competência 3 - Strings, falhou