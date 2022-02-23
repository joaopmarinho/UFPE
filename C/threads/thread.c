#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *PrintHello(void *threadid) {
  printf("Olá, mundo!\n");
  pthread_exit(NULL);
}

int main () {
  pthread_t thread;
  int rc;
  rc = pthread_create(&thread, NULL, PrintHello, NULL);

  if (rc) {
    printf("ERRO, código de retorno é %d\n", rc);
    exit(-1);
  }
  pthread_exit(NULL);
}