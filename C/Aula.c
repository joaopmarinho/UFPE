 
#include <stdio.h>
#include <string.h>

int main() {
  char frase[150] = {0};
  scanf(" %[^\n]", frase);
  int tamanho = strlen(frase);

  for (int i = 0; i < tamanho; i++) {
    int mult = frase[i] * tamanho-1;
    if (frase[i] == 32) {
      mult = 0;
    } 
    else {
        frase[i] = 65;
    }
    for (int j = 0; j < mult; j++) {
      // printf("%c ", frase[i]);
      frase[i]++;
      if (frase[i] > 122) {
        frase[i] = 65;
      } else if (frase[i] > 90 && frase[i] < 97) {
        frase[i] = 97;
      }
    }
    // printf("\n");
  }

  printf("%s", frase);

  return 0;
} 