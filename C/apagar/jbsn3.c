#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_CODE 15
#define N_REG 32
#define INSTR_SIZE 4

typedef struct {
    int num_instrucao;
    char instr_nome[INSTR_SIZE];
    int destino, origem;
} Instrucao;

int main () {
    int i, N_LINHA;
    int current_destiny, current_origin, current_instr_number;
    int regs[N_REG];
    int aux_commands;
    char current_instr[INSTR_SIZE];

    // valores para verificar se cada comando está válido
    char *ldv, *swp, *mov, *add, *sub, *mul;

    Instrucao commands[N_REG]; 

    scanf("%d", &N_LINHA);

    char codigo[N_LINHA][TAM_CODE];

    // preenche o vetor de código com os comandos
    for (i = 0; i < N_LINHA; i++) {
        scanf(" %15[^\n]s", codigo[i]);
    }

    // zera todos os registradores
    for (i = 0; i < N_REG; i++) {
        regs[i] = 0;
    }

    // preenche o vetor de structs
    for (i = 0; i < N_LINHA; i++) {
        // pega o valor de posição em inteiro
        // por teste local char '4' == 52 && char '5' == 53, logo 48 é a base para essa transformação de char para inteiro
        current_destiny = codigo[i][4] - 48; // Não considerou +9
        current_origin = codigo[i][6] - 48; // Não considerou dezenas

        // usa strstr pra verificar se a string está dentro daquele valor
        ldv = strstr(codigo[i], "ldv");
        swp = strstr(codigo[i], "swp");
        mov = strstr(codigo[i], "mov");
        add = strstr(codigo[i], "add");
        sub = strstr(codigo[i], "sub");
        mul = strstr(codigo[i], "mul");

        // se o valor pra cada variável for verdadeira, então aquela string está incluída no comando
        // define cada valor de instrução e copia a string para ser inserida no struct
        if (ldv) {
            current_instr_number = 1;
            strcpy(current_instr, "ldv");
        } else if (swp) {
            current_instr_number = 2;
            strcpy(current_instr, "swp");
        } else if (mov) {
            current_instr_number = 3;
            strcpy(current_instr, "mov");
        } else if (add) {
            current_instr_number = 4;
            strcpy(current_instr, "add");
        } else if (sub) {
            current_instr_number = 5;
            strcpy(current_instr, "sub");
        } else if (mul) {
            current_instr_number = 6;
            strcpy(current_instr, "mul");
        }

        commands[i].num_instrucao = current_instr_number;
        commands[i].destino = current_destiny;
        commands[i].origem = current_origin;
        strcpy(commands[i].instr_nome, current_instr);
    }

    // executa cada comando
    for (i = 0; i < N_LINHA; i++) {
        switch (commands[i].num_instrucao) {
            case 1:
                // neste caso, origem seria o valor de inicialização
                regs[commands[i].destino] = commands[i].origem;
                break;
            case 2:
                aux_commands = regs[commands[i].origem];
                regs[commands[i].origem] = regs[commands[i].destino];
                regs[commands[i].destino] = aux_commands;
                break;
            case 3:
                regs[commands[i].destino] = regs[commands[i].origem];
                break;
            case 4:
                regs[commands[i].destino] = regs[commands[i].destino] + regs[commands[i].origem];
                break;
            case 5:
                regs[commands[i].destino] = regs[commands[i].destino] - regs[commands[i].origem];
                break;
            case 6:
                regs[commands[i].destino] = regs[commands[i].destino] * regs[commands[i].origem];
                break;
            default:
                break;
        }
    }

    printf("Valores nos registradores:\n");
    for (i = 0; i < N_REG; i++) {
        if (regs[i] != 0) {
            printf("register[%d] = %d\n", i, regs[i]);
        } 
    }
    return 0;
}

// 90% parabéns, tinha que considerar qualquer numero dentro um range de inteiros