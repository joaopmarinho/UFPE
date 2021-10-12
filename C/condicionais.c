#include <stdio.h>

int main() {
    int i, num, count, count1, divlove, maior;

    scanf("%d", &num);
    count = 0;

    while(num%2 == 0){
        num/=2;
        count++;
    }
    for(i == 3; i <= num; i += 2){
        divlove=num /i;
    while(num % i == 0)
        count1++;
    }
    maior = 0;
    if (count > maior && count > count1){
        maior = count;
        printf("frequency: %d\n", maior);
        printf("mostfrequency: \n");

        if (count1 > maior && count1 < count) {
            printf("\nfrequency: %d\n", count1);
            printf("\nmostfrequency:%d", i);
        }
    }

    return 0;
}