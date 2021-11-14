#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "");
    int TAM, diferenca, resultado;
    int aux2 = 0;
    
    scanf("%i", &TAM);
    scanf("%i", &diferenca);
    
    int vetor[TAM];
    int j, aux = 0;
    
    for(j=0; j<TAM; ++j){
        scanf("%d", &vetor[j]);
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
        resultado = vetor[j]-vetor[TAM];
        if(resultado > 0){
            if(resultado == diferenca){
                aux2 = aux2 +1;
                printf("%i ", aux2);
            }
        }
        else{
            resultado = vetor[TAM]-vetor[j];
            if(resultado == diferenca){
                aux2 = aux2+1;
                printf("%i ", aux2);
            }
        }
    }

    printf("\n");
    
    for(j=0; j<TAM; ++j){
        resultado = vetor[j]-vetor[TAM];
        if(resultado == diferenca){
            printf("%i %i ", vetor[TAM-1], vetor[j]);
        }
         
        else {
            resultado = vetor[TAM]-vetor[j];
            if(resultado == diferenca){
                printf("%i %i ", vetor[TAM-1], vetor[j]);
            }
        }
    }
             
    return 0;
}