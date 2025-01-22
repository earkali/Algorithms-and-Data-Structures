#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kisi;
int input();

int main() {
    srand(time(NULL));
    printf("Kisi sayisi girin:\n");
    kisi = input();

    for (int i = 0; i < kisi; i++) {
        int r = i + (rand() % (kisi - i));
        printf("%d. sayi=%d\n", i + 1, r + 1);
    }

    return 0;
}

int input() {
    int temp;
    scanf("%d", &temp);
    return temp;
}
