#include <stdio.h>
#include <string.h>

int main()
{
    int tam, i, j, max=0,x;
    scanf("%i", &tam);
    int mat[i][j];
    char letra[30];
    char k;
    int vet[k];
    
    tam= tam*tam;
    for(i; i< tam; i++) {
        scanf("%s", letra);
        for(i; i< letra; i++) {
            if(letra[i]>=97 && 122>=letra[i]){
                letra==x;
            }
        }    
    }
    
    for(i=0; i < tam; i++) {
        for(j=0; j < tam; j++){
            mat[i][j]=letra;
        }
    }
    
    for(i=0; i < tam; i++) {
        if(max<i){
            // lugar = vet[k];
        }
        for(j=0; j < tam; j++){
            if(i==j)
              mat[i][j]=x+1;
        }
    }
    

    return 0;
}