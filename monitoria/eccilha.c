#include <stdio.h>
int main(){
    int N;
    scanf ("%d", &N);
    char Matriz[N][N];
    int i, j;
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            scanf(" %c", &Matriz[i][j]);
            if (Matriz[i][j] >= 97 && Matriz[i][j] <= 120) {
                Matriz[i][j] = Matriz[i][j] + 2;
            }
            else if (Matriz[i][j] == 121) {
                Matriz[i][j] = 'a';
            } else if (Matriz[i][j] == 122) {
                Matriz[i][j] = 'b';
            }
        }
    } 
    for(i=0; i < N; i++ ){
        for(j=0; j < N; j++){
            printf("%c", Matriz[j][i]);
        }
        printf("\n");   
    }
    return 0;
}