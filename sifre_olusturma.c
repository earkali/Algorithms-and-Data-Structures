#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input();
int sifreuret();
int secici();

int basamak, random;
int secim = 0;

int main() {
    srand(time(NULL));
    printf("Kac basamakli olsun: ");
    basamak = input();
    secici();
    return 0;
}

int input() {
    int temp;
    scanf("%d", &temp);
    return temp;
}

int secici() {
    for (int i = basamak; i > 0; i--) {
        secim = rand() % 3;
        switch (secim) {
            case 0:
                random = rand() % 14 + 33;
            break;
            case 1:
                random = rand() % 10 + 48;
            break;
            case 2:
                random = rand() % 7 + 58;
            break;
            case 3:
                random = rand() % 26 + 65;
            break;
            case 4:
                random = rand() % 26 + 97;
            break;
        }
        printf("%c", random);
    }
    printf("\n");
    return 0;
}