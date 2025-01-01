#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kisi;
int input();

int main() {
    srand(time(NULL));
    printf("Kisi sayisi girin:\n");
    kisi = input();

    int *numbers = malloc(kisi * 4);

    for (int i = 0; i < kisi; i++) {
        *(numbers + i) = i + 1;
    }

    for (int i = kisi - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = *(numbers + i);
        *(numbers + i) = *(numbers + j);
        *(numbers + j) = temp;
    }

    for (int i = 0; i < kisi; i++) {
        printf("%d. sayi=%d\n", i + 1, *(numbers + i));
    }

    return 0;
}

int input() {
    int temp;
    scanf("%d", &temp);
    return temp;
}
