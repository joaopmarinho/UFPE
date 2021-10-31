#include<stdio.h>
#include<string.h>
#define TAM 1000
int main(){
    //i,j e k (PARA NAVEGAR PELA MATRIZ), somador
    int N, i, j, k, somador;
    // DETERMINANDO FLAGS ==1 (HIPOTESE QUE A MATRIZ SATISFAZ TODAS AS PROPRIEDADES)
    char Strings_Diagonais=1, Letras_Maiusculas=1;
    scanf("%d", &N);
    //DETERMINADO MATRIZ DE STRINGS COM TAMANHO MAXIMO 30, MATRIZ SENHA E MATRIZ NUM
    char Matriz_Strings[N][N][31], SENHA[TAM], NUM[TAM];
    SENHA[0]= '\0';
    //LENDO MATRIZ DE STRINGS
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           scanf(" %s", Matriz_Strings[i][j]);
        }
    }
    //VERIFICANDO SE AS STRINGS DA DIAGONAL PRINCIPAL POSSUEM TAMANHO i+j+1, PARA TODO i==j
    for(i=0;i<N && Strings_Diagonais == 1;i++){
        j=i;
        //VERIFICANDO SE STRING TEM TAM DIFERENTE DE i+j+1
        if(strlen(Matriz_Strings[i][j])!= i+j+1){
                Strings_Diagonais = 0;
            //A STRING DA DIAGONAL PRINCIPAL POSSUI TAMNHO DIFERENTE DE i+j+1!!!
        }
    }
    if(Strings_Diagonais ==0) Letras_Maiusculas =0;
    //VERIFICANDO SE TODAS AS LETRAS FORA DA DIAGONAL PRINCIPAL SAO MAIUSCULAS
    for(i=0;i<N && Letras_Maiusculas==1;i++){
        for(j=0;j<N && Letras_Maiusculas==1;j++){
           if(i!=j){
              for(k=0;k<strlen(Matriz_Strings[i][j]) && Letras_Maiusculas==1;k++){
                //SE OS ELEMENTOS DA STRING i j EM CADA POSICAO DA STRING NAO SAO VOGAIS MAIUSCULAS
                if(Matriz_Strings[i][j][k]>=65 && Matriz_Strings[i][j][k]<=90){
                    //LETRA DA STRING PERTENCE AO ALFABETO MAIUSCULO
                   if(Matriz_Strings[i][j][k]!= 'A' && Matriz_Strings[i][j][k]!= 'E' && Matriz_Strings[i][j][k]!= 'I' && Matriz_Strings[i][j][k]!= 'O' && Matriz_Strings[i][j][k]!= 'U'){
                       //LETRA DA STRING NAO EH VOGAL==> EH CONSOANTE MAIUSCULA

                   }else Letras_Maiusculas=0;               //LETRA DA STRING EH VOGAL MAIUSCULA
                }else Letras_Maiusculas=0;                 //LETRA DA STRING NAO PERTENCE AO ALFABETO MAIUSCULO
              }
           }
        }
    }
    //SE AS DUAS PROPRIEDADES SAO SATISFEITAS  ==> letras_maiusculas ==1 e strings_diagonais==1
    if(Letras_Maiusculas==1 && Strings_Diagonais==1){
        //ITERANDO TODA MATRIZ DE STIRNGS
        for(i=0;i<N;i++){
          for(j=0;j<N;j++){
           //SE STRING PERTENCE A DIAGONAL PRINCIPAL
           if(i==j){
             strcat(SENHA, Matriz_Strings[i][j]);
           }else{ //CASO A STRING NAO PERTENCA A DIAGONAL PRINCIPAL

              // ZERANDO O SOMADOR PARA A STRING NA POSICAO i,j
              somador=0;
              //SOMANDO LETRA POR LETRA DA MATRIZ EM UM SOMADOR
              for(k=0;k<strlen(Matriz_Strings[i][j]);k++){
                  somador+=Matriz_Strings[i][j][k];
              }
              //COLOCANDO O VALOR SO SOMADOR NUMA STRING TEMPORARIA
              sprintf(NUM,"%d",somador);
              //PASSANDO DA STRING TEMPORARIA PARA A TRING SENHA
              strcat(SENHA, NUM);
              //'ZERANDO' A MATRIZ NUM
              NUM[0]= '\0';
           }
        }
    }
    //IMPRIMINDO A SENHA
    printf("\n%s", SENHA);


    }else printf("A MATRIZ DE STRINGS NAO SATISFAZ AS PROPIEDADES !!!"); // CASO EM QUE A MATRIZ NAO SATISFAZ AS PROPRIEDADES

    return 0;


}







