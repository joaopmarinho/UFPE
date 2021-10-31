#include <stdio.h>
#include <string.h>

int main(){
    int dimensoes, i, j, k, analise=1, parar=0, soma_int=0;
    scanf("%d", &dimensoes);
    char matriz[dimensoes][dimensoes][31], senha[100]="\0", soma_char[100];
    for(i=0; i<dimensoes; i++){ //entrada da matriz
        for(j=0; j<dimensoes; j++){
            scanf(" %s", matriz[i][j]);
        }
    }
    for(i=0; i<dimensoes; i++){ //laço para analisar se a matriz serve
        for(j=0; j<dimensoes; j++){
            for(k=0; matriz[i][j][k]!='\0' && parar!=1; k++){
                if(i==j){ //analise da diagonal principal
                    if(strlen(matriz[i][j])!=(i+j+1)){
                        analise=0;
                        parar=1;
                    }if(matriz[i][j][k]!=97 && matriz[i][j][k]!=101 && matriz[i][j][k]!=105 && matriz[i][j][k]!=111 && matriz[i][j][k]!=117){
                        analise=0;
                        parar=1;
                    }
                }else{ //analise demais diagonais
                    if(matriz[i][j][k]>=97 || matriz[i][j][k]==65 || matriz[i][j][k]==69 || matriz[i][j][k]==73  || matriz[i][j][k]==79 || matriz[i][j][k]==85){
                        analise=0;
                        parar=1;
                    }
                }
            }
        }
    }

    if(analise==1){ //concatenação da senha, se a matriz serve
        for(i=0; i<dimensoes; i++){
            for(j=0; j<dimensoes; j++){
                if(i==j){
                    strcat(senha, matriz[i][j]);
                }else{
                    for(k=0; matriz[i][j][k]!='\0'; k++){
                        soma_int+=matriz[i][j][k];
                    }
                    sprintf(soma_char, "%d", soma_int);
                    strcat(senha, soma_char);
                    soma_int=0;
                }
            }
        }
    }
    if(analise==1){ //saida
        printf("sua senha eh %s\n", senha);
    }else{
        printf("sua matriz nao satisfaz a propriedade\n");
    }

    return 0;
}
