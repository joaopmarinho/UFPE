#include <stdio.h>

// Juquinha reprovou na cadeira 'Como fugir de um agiota NI' no curso de finanças, decidiu ver na prática e agora ele deve a um agiota malando, ele só quer receber apenas notas de 100 que você sacar e não devolve o troco, faça um programa que de acordo com o que Juquinha tiver vai mostra se ele conseguiu ou não pagar o agiota e se perdeu mais dinheiro por não receber o troco.

int main() {
    int divida, dinheiro = 0;
    scanf("%d %d", &dinheiro, &divida);
    
    if (divida > 0) { //Verificar se tem divida
        if (dinheiro >= divida) { //Paga
            if (divida % 100 > 0) {
                divida = (divida / 100) + 1;
                printf("Pegou mais\n");
            }
            else divida = 1;
            dinheiro = dinheiro - (divida * 100);
            printf("Esta pago\nSobrou %d", dinheiro);
        } else {
            printf("Juquinha se lascou");
        }
    } else {
        printf("Esta pago\n");
        printf("Sobrou %d", dinheiro);
    }

    return 0;
}