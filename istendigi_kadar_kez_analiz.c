#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count, son,sayi;

int input();
int rnd();

int main() {
    srand(time(0));
    int sayi = input();
    for (int i = 1; i <= sayi; i++) {
        int son = rnd();
        printf("Sayi %d = %d\n", i, son);
    }
}

int input() {
    printf("Kac sayi istiyorsunuz?\n");
    scanf("%d", &sayi);
    return sayi;
}

int rnd() {
    return rand() % 100;
}