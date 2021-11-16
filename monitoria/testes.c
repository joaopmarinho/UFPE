#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int TAM, diferenca, resultado;
    int aux2=0;
    
    scanf("%i", &TAM);

    while(TAM!=-1) {
        scanf("%i", &diferenca);
        int vetor[TAM];
        int j, aux;
        int ord[TAM];
    
        for(j=0; j<TAM; ++j){
            scanf("%d", &vetor[j]);
        }

        for(j=0; j<TAM; ++j){
            ord[j] = vetor[j];
        }

        for(int j=0; j <TAM; ++j){
            for(int y=j+1; y<TAM; ++y){
                if(vetor[j]>vetor[y]){
                    aux = vetor[j];
                    vetor[j] = vetor[y];
                    vetor[y] = aux;
                }
            }
        }

        for(j=0; j<TAM; ++j){
            resultado = abs(ord[j]-vetor[j]);
            if(resultado == diferenca){
                aux2 = aux2 +1;
            }
        }
        printf("%i\n", aux2);

        for(j=0; j<TAM; ++j) {
            resultado = abs(ord[j]-vetor[j]);
            if(resultado == diferenca){
                printf("%i %i %i\n", ord[j], vetor[j], j+1);
            }
        }

        scanf("%i", &TAM);
    }
             
    return 0;
}