#include <stdio.h>

int main() {
    int divida, dinheiro = 0, flag = 0;
    scanf("%d %d", &dinheiro, &divida);
    
    if (divida > 0) { //Verificar se tem divida
        if (dinheiro >= divida) { //Paga
            if (divida % 100 > 0) {
                divida = (divida / 100) + 1;
                flag = 1;
            }
            else divida = 1;
            dinheiro = dinheiro - (divida * 100);

            if (dinheiro >= 0) {
                if (flag) printf("Pegou mais\n");
                printf("Esta pago\nSobrou %d\n", dinheiro);
            } else {
                printf("Pedro vai ter que fugir\n");
            }
        } else {
            printf("Pedro vai ter que fugir\n");
        }
    } else {
        printf("Esta pago\n");
        if (dinheiro >= 0) printf("Sobrou %d\n", dinheiro);
        else printf("Sobrou 0\n");
    }
    return 0;
}