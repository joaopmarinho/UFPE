#include <stdio.h>
#include <string.h>

int main() {
  int TAM, i, j, k, cont=0;
  int teste1=1, teste2=1, teste3=1, numero;
  char numeroS[10];
  scanf("%d", &TAM); 
  char matriz[TAM][TAM][31], senha[50] = "\0";
  
  //LEITURA DA MATRIZ
  for (i=0; i<TAM; i++) {
    for (j=0; j<TAM; j++) {
      scanf(" %49[^\n]", matriz[i][j]);
    }
  }
  
  //TESTE 1 TAMANHO DIAGONAL
  for (i=0; i<TAM; i++) {
    if (strlen(matriz[i][i])<i+i+1) teste1=0;
  }

  //TESTE 2 VOGAL MINUSCULA NA DIAGONAL
  for (i=0; i<TAM; i++){
    cont = 0;
    for (j=0; matriz[i][i][j] != '\0'; j++){
      if (matriz[i][i][j] == 97 || matriz[i][i][j] == 101 || 
          matriz[i][i][j] == 105 || matriz[i][i][j] == 111 ||
          matriz[i][i][j] == 117) cont++;
    }
    if (cont != strlen(matriz[i][i])) teste2=0;
  }

  //TESTE 3 CONSOANTE MAIUSCULA FORA DA DIAGONAL
  for (i=0; i<TAM; i++) {
    for (j=0; j<TAM; j++) {
      for (k=0; matriz[i][j][k] != '\0'; k++) {
        if (i==j) ; //NAO VAI FAZER NADA SE ESTIVER NA DIAGONAL PRINCIPAL
        else {
          //SE NAO ESTIVER DENTRO DO INTERVALO DO ALFABETO MAIUSCULO
          if (matriz[i][j][k] < 65 || matriz[i][j][k] > 90) teste3=0;

          //VERIFICAR SE POSSUI ALGUMA VOGAL
          else if (matriz[i][j][k]==65 || matriz[i][j][k]==69 || matriz[i][j][k]==73 || matriz[i][j][k]==79 || matriz[i][j][k]== 85) teste3=0;
        }
      }
    }
  }

  //SENHA
  printf("%s\n", senha);
  if (teste1==1 && teste2==1 && teste3==1) {
    for (i=0; i<TAM; i++) {
      for (j=0; j<TAM; j++) {
        if (i==j) 
          strcat(senha, matriz[i][j]);
        else {
          numero = 0;
          for (k=0; matriz[i][j][k] != '\0'; k++) {
            numero = numero + matriz[i][j][k];
          }
          sprintf(numeroS, "%d", numero);
          strcat(senha, numeroS);
       }
      }
    }
  }

  if (teste1==1 && teste2==1 && teste3==1)
    printf("Sua senha %s", senha);
  else printf("Nao foi poss�vel gerar sua senha");

	return 0;
  //100%
  //Faltou considerar que a variável senha vem com lixo de memória.
}