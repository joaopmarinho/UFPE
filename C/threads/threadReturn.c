#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *printHello(void *threadId) {
  int *tID = (int *)threadId;
  char *ret = (char*) malloc(100);
  sprintf(ret, "Olá, mundo Sou eu, a thread %d", *tID);
  pthread_exit((void *)tID);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int *taskIDS[NUM_THREADS];
  int rc;
  for (int i = 0; i < NUM_THREADS; i++) {
    printf("No main: criando thread %d\n", i);
    taskIDS[i] = (int*) malloc(sizeof(int));
    *taskIDS[i] = i;
    pthread_create(&threads[i], NULL, printHello, (void*)taskIDS[i]);
  }

  for (int j = 0; j < NUM_THREADS; j++) {
    int *res;
    pthread_join(threads[j], (void **) &res);
    printf("%d\n", *res);
  }
  pthread_exit(NULL);
}