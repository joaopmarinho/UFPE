#include <stdio.h>

void soma (int a, int b) {
    printf("a + b = %d\n", a+b);
}

void argumento (int a, int b, int (*ponteiro) (int, int)) {
    printf("Rodando dentro da funcao: ");
    (*ponteiro)(a, b);
}

void seLigaNoArgumento(int (*p)(const char *));

int main (void) {
    int a = 5, b = 7;
    //Criando um ponteiro para função.
    int (*ponteiroFunc) ();
    //Recebendo uma função:
    ponteiroFunc = soma;
    //Inicializando a função:
    (*ponteiroFunc)(a, b);
    //Colocando o ponteiro no arguemento da função.
    argumento(a, b, ponteiroFunc);

    //Utilizando funções da biblioteca!
    ponteiroFunc = printf;
    (*ponteiroFunc)("Pode ser com qualquer funcao!");
    seLigaNoArgumento(ponteiroFunc);
}

void seLigaNoArgumento(int (*p)(const char *)) {
    (*p)("\nFunciona!");
}