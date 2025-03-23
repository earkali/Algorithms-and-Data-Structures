#include <stdio.h>

void yazdir_dizi(int satir, int sutun, int array[satir][sutun]);
void ogrenci_not_giris(int satir, int sutun, int array[satir][sutun]);
int maks(int satir, int sutun, int array[satir][sutun]);
int min(int satir, int sutun, int array[satir][sutun]);
void ortalama_hesap(int satir, int sutun, int array[satir][sutun]);

int main() {
    int satir, sutun;
    printf("Kac ogrenci girilecek? ");
    scanf("%d", &satir);
    printf("Ogrenciler kac sinava girdi?: ");
    scanf("%d", &sutun);

    int array[satir][sutun];

    ogrenci_not_giris(satir, sutun, array);
    yazdir_dizi(satir, sutun, array);
    int max = maks(satir, sutun, array);
    int minimum = min(satir, sutun, array);
    printf("En dusuk %d, en yuksek %d\n", minimum, max);
    ortalama_hesap(satir, sutun, array);
    return 0;
}

void ogrenci_not_giris(int satir, int sutun, int array[satir][sutun]) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            printf("Ogrenci %d'nin %d'inci notunu giriniz: ", i + 1, j + 1);
            scanf("%d", &array[i][j]);
        }
    }
}

void yazdir_dizi(int satir, int sutun, int array[satir][sutun]) {
    printf("Dizi elemanlari:\n");
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void ortalama_hesap(int satir, int sutun, int array[satir][sutun]) {
    printf("Ortalama degerler:\n");
    for (int i = 0; i < satir; i++) {
        int toplam = 0;
        for (int j = 0; j < sutun; j++) {
            toplam += array[i][j];
        }
        float ortalama = toplam / (float)sutun;
        printf("%d'inci ogrencinin ortalamasi %.2f\n",i+1, ortalama);
    }
    printf("\n");
}

int maks(int satir, int sutun, int array[satir][sutun]) {
    int temp = 0;
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            if (array[i][j] > temp) {
                temp = array[i][j];
            }
        }
    }
    return temp;
}

int min(int satir, int sutun, int array[satir][sutun]) {
    int temp = 100;
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            if (array[i][j] < temp) {
                temp = array[i][j];
            }
        }
    }
    return temp;
}