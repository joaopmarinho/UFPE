#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    while(scanf("%d", &n) > 0){
        
        if( n <= 0){
            exit(1);
        }
        int *vet = malloc(n * sizeof(int));
        if(vet != NULL){
            printf("memoria alocada com sucesso!\n");
        }
        free(vet);
    }
    return 0;
}