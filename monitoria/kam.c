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
    //i com vazamento de memória
    for(i; i< tam; i++) {
        scanf("%s", letra);
        //Usando mesma variável do loop anterior
        for(i; i< letra; i++) {
            if(letra[i]>=97 && 122>=letra[i]){
                //Boleano?
                letra==x;
            }
        }    
    }
    //Só tá considerando a última palavra
    for(i=0; i < tam; i++) {
        for(j=0; j < tam; j++){
            mat[i][j]=letra;
        }
    }
    
    for(i=0; i < tam; i++) {
        //Variável max não muda
        if(max<i){
            //Variável lugar não existe
            // lugar = vet[k];
        }
        for(j=0; j < tam; j++){
        //Buscando diagonal principal!
            if(i==j)
              mat[i][j]=x+1;
        }
    }
    
    //10%
    // Percebi que está com dificuldade nos conceitos de programação, ocorrendo pequenos deslizes durante o desenvolvimento, sendo necessário alguns ajustes.
    //Busque apoio para evitar o mesmo resultado na próxima MP, pegue questões passadas para blindar sua lógica e entre em contato conosco!
    return 0;
}