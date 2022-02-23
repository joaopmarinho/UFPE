#include <stdio.h>

int buscar(int x, int A[], int B[]) {
    for (int i = 0; i < 6; i++) {
        if (A[x] == B[i] || A[x+1] == B[i]) {
            if (i <= 1) {
                printf("%d-%d ", B[0], B[1]);
                B[0] = -1; B[1] = -1;
                printf("1\n");
                return 0;
            }
            else if (i <= 3) {
                printf("%d-%d ", B[2], B[3]);
                B[2] = -1; B[3] = -1;
                printf("2\n");
                return 2;
            }
            else {
                printf("%d-%d ", B[4], B[5]);
                B[4] = -1; B[5] = -1;
                printf("3\n");
                return 4;
            }
        }
    }
    return 0;
}

int main () {
    int A[8], B[6], choiceA, pecaA, pecaB;
    
    for (int i = 0; i < 8; i++) 
        scanf("%d", &A[i]);
    
    for (int i = 0; i < 6; i++) 
        scanf("%d", &B[i]);
    
    for (int i = 0; i < 3; i++) {
        scanf("%d", &choiceA);
        switch (choiceA) {
            case 1:
                buscar(0, A, B);
                break;
            case 2: 
                buscar(2, A, B);
                break;
            case 3:
                buscar(4, A, B);
                break;
            case 4: 
                buscar(6, A, B);
                break;
        }
    }
}