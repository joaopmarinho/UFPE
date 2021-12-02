#include <stdio.h>
#include <string.h> 
// Estrutura
typedef struct{
  char nome[50];
  float price;
} Lista;

int main (){
  // Declarações
  int N, cont = 0;
  float moneyT, auxM, soma = 0;
  Lista lista[100] = {1}, aux;
  // Captação de variáveis
  scanf("%f",&moneyT);
  scanf("%d", &N);
  
  for (int i = 0; i < N; i++) {
    scanf(" %s %f", lista[i].nome, &lista[i].price);
    soma += lista[i].price;
  }
  // Se ele não conseguir comprar todos os itens:
  if (moneyT < soma){
// Ordena a lista por valor 
//(visto que ele quer pegar o máximo de itens, 
// vai comprar do menor para o maior).
    for (int i = 0; i < N-1; i++) {
      for (int j = i+1; j < N; j++) {
        if (lista[i].price > lista[j].price) {
          aux = lista[i];
          lista[i] = lista[j];
          lista[j] = aux;
        }
      }
    } 
// Um auxiliar para verificação e reutilizar a variável soma
    auxM = moneyT;
    soma = 0;
//Verificando quantos itens ele consegue comprar
    for (int i = 0; auxM - lista[i].price >= 0; i++) {
      cont++; //Quantidade de itens
      auxM = auxM - lista[i].price;
      soma += lista[i].price; // Dinheiro gasto
    }
//Ordenar a lista por nome
    for (int i = 0; i < cont-1; i++) {
      for (int j = i+1; j < cont; j++) {
        if (strcmp(lista[i].nome, lista[j].nome) > 0) {
          aux = lista[i];
          lista[i] = lista[j];
          lista[j] = aux;
        }
      }
    } 
// Imprimir os resultados
    for (int i = 0; i < cont; i++) {
      printf("%s %.2f\n", lista[i].nome, lista[i].price);
    }
    printf("%.2f", moneyT - soma);

  } else { // Caso consiga comprar todos os itens:
  // Ordena a lista por nome
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (strcmp(lista[i].nome, lista[j].nome) > 0) {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    } 
  // Imprime o resultado
    for (int i = 0; i < N; i++) {   
      printf("%s %.2f\n", lista[i].nome, lista[i].price);
    }
    printf("%.2f",moneyT - soma);
  }
}