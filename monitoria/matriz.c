#include <stdio.h>

int main () {
  int N;
  scanf("%d", &N);
  int M[N][N], X[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        scanf("%d", &M[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &X[i][j]);
    }
  }

  int matrizR[N][N];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrizR[i][j] = M[i][j] + X[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", matrizR[i][j]);
    }
    printf("\n");
  }
  
}