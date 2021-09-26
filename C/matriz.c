#include <stdio.h>

//LK o inimigo do trabalho, estava estudando a cadeira 'Locais para se esconder de um agiota' em seu curso de finanças, com um mapa de locais que LK pode estar ele vai sair de local em local sabendo que o agiota está atrás dele, cada local que ele passa anota +1 para que evite passar por lá, crie um programa que diga qual local ele não deve passar mais.

int main() {
    int xy[4][4], verif = 0, coordX, coordY;
    char input;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            xy[i][j] = 0;
        }
    }
    int x = 0;
    int y = 0;
    for (int k = 0; k < 16; k++) {
        scanf(" %c", &input);
        if (input == 'e') y--;
        if (input == 'd') y++;
        if (input == 'b') x++;
        if (input == 'c') x--;
        xy[x][y]++;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d ", xy[i][j]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (xy[i][j] > verif) {
                verif = xy[i][j];
                coordX = j; 
                coordY = i;
            }
        }
    }
    printf("Coordenada X:%d, Y:%d", coordX, coordY);
}