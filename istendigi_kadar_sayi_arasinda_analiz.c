#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count,son,sayi,sayac1,sayac2;

int input();
int rnd();

int main() {
    srand(time(0));
    int sayi = input();
    for (int i = 1; i <= sayi; i++) {
        int son = rnd();
        if (son == 1) {
            sayac1++;
        } else if (son == 2) {
            sayac2++;
        }
    }
    printf("1 sayisi %d, 2 sayisi %d",sayac1,sayac2);
}

int input() {
    printf("Kac sayi arasinda analiz yapilsin?\n");
    scanf("%d", &sayi);
    return sayi;
}

int rnd() {
    return rand() % 2 + 1;
}