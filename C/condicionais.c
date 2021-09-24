#include <stdio.h>

// Juquinha deve a um agiota malando, ele só quer receber as maiores notas que você sacar e não devolve o troco, faça um programa que de acordo com o dinheiro que Juquinha tiver vai dizer se ele conseguiu ou não pagar o agiota e se perdeu mais dinheiro por não receber o troco.

int main() {
    int divida, dinheiro = 0, quantidade = 0;
    scanf("%d %d", &dinheiro, &divida);
    //Trabalhar apenas com 100
    //Ele não devolve o troco
    //Dizer quanto sobrou (dinheiro vem quebrado)
    //Dizer o quanto sobrou
    if (divida > 0) { //Verificar se tem divida
        if (dinheiro >= divida) { //Paga
            if (divida % 100 > 0) divida = (divida / 100) + 1;
            else divida = 1;
            dinheiro = dinheiro - (divida * 100);
            printf("Esta pago\nTroco %d", dinheiro);
        } else {
            printf("Juquinha se lascou");
        }
    } else {
        printf("Esta pago\n");
        printf("Troco %d", dinheiro);
    }

    return 0;
}