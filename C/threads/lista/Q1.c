#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pthread.h"

// Professor disse que poderia deixar tudo pré-definido.
#define NUM_ARQUIVOS 10
#define NUM_THREADS 10
#define NUM_ITEMS 10

typedef struct {
  pthread_t thread;
  int id;
} Thread;

Thread threads[NUM_THREADS];
// Mutex para abrir um arquivo por vez:
pthread_mutex_t open_mutex = PTHREAD_MUTEX_INITIALIZER;
// Mutex para cada produto:
pthread_mutex_t produto_mutex[NUM_ITEMS];
// O vetor para contagem de produtos:
int produtos[NUM_ITEMS] = {0};

void *preencher();

int main() {
  // Iniciar mutexes dos produtos:
  for(int i = 0; i < NUM_ITEMS; i++) {
    pthread_mutex_init(&produto_mutex[i], NULL);
  }
  // Setando ID e iniciando rotina das threads:
  for(int i = 0; i < NUM_THREADS; i++){
    threads[i].id = i;
    pthread_create(&threads[i].thread, NULL, preencher, &threads[i].id);
  }
  
  for(int i = 0; i < NUM_THREADS; i++){
    pthread_join(threads[i].thread, NULL);
  }
  pthread_mutex_destroy(&open_mutex);
  for(int i = NUM_ITEMS; i > 0; i--) {
    pthread_mutex_destroy(&produto_mutex[i - 1]);
  }

  // Imprimindo resultado:
  printf("Produto - Quant\n");
  for(int i = 0; i < NUM_ITEMS; i++){
    printf(" P[%d] ------ %d\n", i, produtos[i]);
  }
}

void *preencher(void *arg){
  int *ID_THREAD = (int*) arg;
  char local_produto[20], tipo_arquivo[10], qtd_arquivo[5];
  int num_produto = 0;

  printf("Rotina iniciada thread[%d]\n", (*ID_THREAD));
  // Variáveis para abertura de arquivos:
  strcpy(local_produto, "./produtos/");
  // strcpy(qtd_arquivo, (*ID_THREAD));
  strcpy(tipo_arquivo, ".txt");
  sprintf(qtd_arquivo, "%d", (*ID_THREAD)+1);
  // Região crítica para abertura de arquivo:
  pthread_mutex_lock(&open_mutex);
  printf("Thread[%d] abriu %s.txt\n", (*ID_THREAD), qtd_arquivo);
  // local_produto = './produtos/x';
  strcat(local_produto, qtd_arquivo);
  // local_produto = './produtos/x.in';
  strcat(local_produto, tipo_arquivo);

  pthread_mutex_unlock(&open_mutex);

  FILE *file = fopen(local_produto, "r");
  if (file == NULL) {
    printf("Nao foi possivel abrir o arquivo %s\n", local_produto);
  }
  while(fscanf(file, "%d", &num_produto) != EOF){
    // Região crítica para preenchimento do produto:
    pthread_mutex_lock(&produto_mutex[num_produto]);

    printf("Produto[%d] adicionado por thread[%d]\n", num_produto, (*ID_THREAD));
    produtos[num_produto]++;

    pthread_mutex_unlock(&produto_mutex[num_produto]);
  }   
  fclose(file);
}