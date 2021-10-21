#include <stdio.h>

int main() {
    int N, fatorial;
    double Euler = 0;
    scanf("%d", &N);
    for (int k = 1; k <= N; k++){
        fatorial = 1;
        for (int i = 2; i < k; i++) {
            fatorial = fatorial * i;
        }
              //Cast de inteiro para double
        Euler = Euler + (double) 1/fatorial; 
    }
    printf("%.15lf", Euler);
}