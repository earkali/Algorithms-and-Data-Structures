#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sayi;
int sayac1 = 0, sayac2 = 0;

int input();
int rnd();

int main() {
    srand(time(0));
    sayi = input();
    int count = 0;
    int all_ones = 0;

    while (!all_ones) {
        all_ones = 1;
        sayac1 = 0;
        sayac2 = 0;
        for (int i = 1; i <= sayi; i++) {
            int son = rnd();
            if (son != 1) {
                all_ones = 0;
            }
            if (son == 1) {
                sayac1++;
            } else if (son == 2) {
                sayac2++;
            }
        }
        count++;
    }
    printf("Hep 1'lerin gelmesini saglamak icin %d kez deneme yapildi.\n", count);
    printf("1 sayisi %d kere, 2 sayisi %d kere bulundu.\n", sayac1, sayac2);
    return 0;
}

int input() {
    printf("Kac sayi arasinda analiz yapilsin?\n");
    scanf("%d", &sayi);
    return sayi;
}

int rnd() {
    return rand() % 2 + 1;
}
