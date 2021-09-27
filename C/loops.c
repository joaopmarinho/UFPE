// Laços!
#include <stdio.h>

int main () {
    int curva, aceleracao, i = 0;
    scanf("%d %d", &aceleracao, &curva);

    while (curva > 0) {
        for (i = 0; i < 30; i += aceleracao) {
        }
        //Manipular os argumentos do for
        for (i = 30; i > 0; i -= aceleracao + 1) {
        }
        //Aprende a não apenas criar variável no escopo
        if (i >= 0) {
            printf("Curvou\n");
        }
        else {
            curva = 0;
            printf("Pedro se cagou todo e foi pego.\n");
        }
        aceleracao++;
        curva--;
    }
    return 0;
}