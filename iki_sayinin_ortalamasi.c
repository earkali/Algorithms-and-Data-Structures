#include <stdio.h>

int input();

float ortalama(int sayi1 ,int sayi2);

int main() {
    printf("Sayi giriniz:");
    int sayi1 = input();
    printf("Sayi giriniz:");
    int sayi2 = input();
    printf("Sayilarin ortalamasi: %.1f",ortalama(sayi1,sayi2));
    return 0;
}

int input() {
    int sayi;
    scanf("%d",&sayi);
    return sayi;
}

float ortalama(int sayi1, int sayi2) {
    float ortalama = (float)(sayi1 + sayi2) / 2;
    return ortalama;
}