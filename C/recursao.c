#include <stdio.h>

typedef struct {
    int x;
} Pos;

void imprimir(int n) {
    printf("%d\n", n);
}

int fatorial(int n) {
    if (n == 0) return 1;
    return n * fatorial(n - 1);
}

int fibonacci(int n) {
    if (n == 1 || n ==2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void recursao(int n) {
    imprimir(fibonacci(n));
    imprimir(fatorial(n));
}

int incrementar(Pos *p) {
    return (p->x)++;
}

void begin() {
    Pos num;
    num.x = 5;
    recursao(incrementar(&num));
}

int main(void) {
    printf("Teste de callback\n");
    begin();

    printf("No main: fib(5) = %d\n", fibonacci(3));
    printf("Main: fat(5) = %d\n", fatorial(4));
}