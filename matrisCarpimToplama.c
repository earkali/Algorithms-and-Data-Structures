#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SATIR1 2
#define SUTUN1 3
#define SATIR2 3
#define SUTUN2 2

int dizi1[SATIR1][SUTUN1];
int dizi2[SATIR2][SUTUN2];
int toplamSonuc[SATIR1][SUTUN1];
int carpimSonuc[SATIR1][SUTUN2];

void dizi1Rasgele(int dizi1[SATIR1][SUTUN1]);
void dizi2Rasgele(int dizi2[SATIR2][SUTUN2]);
void matriksTopla(int dizi1[SATIR1][SUTUN1], int dizi2[SATIR1][SUTUN1], int toplamSonuc[SATIR1][SUTUN1]);
void matriksCarp(int dizi1[SATIR1][SUTUN1], int dizi2[SATIR2][SUTUN2], int carpimSonuc[SATIR1][SUTUN2]);
void matriksYazdir1(int matris[SATIR1][SUTUN1]);
void matriksYazdir2(int matris[SATIR2][SUTUN2]);
void toplamSonucYazdir(int toplamSonuc[SATIR1][SUTUN1]);
void carpimSonucYazdir(int carpimSonuc[SATIR1][SUTUN2]);

int main(void) {
    srand(time(NULL));

    dizi1Rasgele(dizi1);
    dizi2Rasgele(dizi2);

    printf("Dizi1 (2x3):\n");
    matriksYazdir1(dizi1);

    printf("Dizi2 (3x2):\n");
    matriksYazdir2(dizi2);

    if (SATIR1 == SATIR2 && SUTUN1 == SUTUN2) {
        matriksTopla(dizi1, dizi1, toplamSonuc);
        printf("Toplam Sonucu (Dizi1 + Dizi1, 2x3):\n");
        toplamSonucYazdir(toplamSonuc);
    } else {
        printf("Matrisler toplanamaz: Boyutlar eslesmiyor.\n");
    }

    matriksCarp(dizi1, dizi2, carpimSonuc);
    printf("Carpim Sonucu (2x2):\n");
    carpimSonucYazdir(carpimSonuc);

    return 0;
}

void dizi1Rasgele(int dizi1[SATIR1][SUTUN1]) {
    for (int i = 0; i < SATIR1; i++) {
        for (int j = 0; j < SUTUN1; j++) {
            dizi1[i][j] = rand() % 100 + 1;
        }
    }
}

void dizi2Rasgele(int dizi2[SATIR2][SUTUN2]) {
    for (int i = 0; i < SATIR2; i++) {
        for (int j = 0; j < SUTUN2; j++) {
            dizi2[i][j] = rand() % 100 + 1;
        }
    }
}

void matriksTopla(int dizi1[SATIR1][SUTUN1], int dizi2[SATIR1][SUTUN1], int toplamSonuc[SATIR1][SUTUN1]) {
    for (int i = 0; i < SATIR1; i++) {
        for (int j = 0; j < SUTUN1; j++) {
            toplamSonuc[i][j] = dizi1[i][j] + dizi2[i][j];
        }
    }
}

void matriksCarp(int dizi1[SATIR1][SUTUN1], int dizi2[SATIR2][SUTUN2], int carpimSonuc[SATIR1][SUTUN2]) {
    for (int i = 0; i < SATIR1; i++) {
        for (int j = 0; j < SUTUN2; j++) {
            carpimSonuc[i][j] = 0;
            for (int k = 0; k < SUTUN1; k++) {
                carpimSonuc[i][j] += dizi1[i][k] * dizi2[k][j];
            }
        }
    }
}

void matriksYazdir1(int matris[SATIR1][SUTUN1]) {
    for (int i = 0; i < SATIR1; i++) {
        for (int j = 0; j < SUTUN1; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

void matriksYazdir2(int matris[SATIR2][SUTUN2]) {
    for (int i = 0; i < SATIR2; i++) {
        for (int j = 0; j < SUTUN2; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

void toplamSonucYazdir(int toplamSonuc[SATIR1][SUTUN1]) {
    for (int i = 0; i < SATIR1; i++) {
        for (int j = 0; j < SUTUN1; j++) {
            printf("%d ", toplamSonuc[i][j]);
        }
        printf("\n");
    }
}

void carpimSonucYazdir(int carpimSonuc[SATIR1][SUTUN2]) {
    for (int i = 0; i < SATIR1; i++) {
        for (int j = 0; j < SUTUN2; j++) {
            printf("%d ", carpimSonuc[i][j]);
        }
        printf("\n");
    }
}