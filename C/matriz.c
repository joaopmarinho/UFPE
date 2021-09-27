#include <stdio.h>

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
    for (int k = 0; k < 20; k++) {
        scanf(" %c", &input);
        if (input == 'e') y = (--y) < 0 ? 3 : y--;
        if (input == 'd') y = (y + 1) % 4;
        if (input == 'b') x = (x + 1) % 4;
        if (input == 'c') x = (--x) < 0 ? 3 : x--;

        xy[x][y]++;

        // for (int i = 0; i < 4; i++) {
        //     for (int j = 0; j < 4; j++) {
        //         printf("%d ", xy[i][j]);
        //     }
        //     printf("\n");
        // }
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