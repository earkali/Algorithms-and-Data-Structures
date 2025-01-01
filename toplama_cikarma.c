#include <stdio.h>

int temp;
int islem;
int sonuc = 0;

int islem1();
int input();
int toplama();
int cikarma();
int kiyas();
int devam();
int yazdir();
int yazi();

int main() {
    temp = devam();
    return 0;
}

int input() {
    scanf("%d", &temp);
    return temp;
}

int toplama() {
    sonuc = input() + input();
    return sonuc;
}

int cikarma() {
    sonuc = input() - input();
    return sonuc;
}

int islem1() {
    printf("Toplama icin 1'i, Cikarma icin 2'yi tuslayin:\n");
    islem = input();
    return islem;
}

int kiyas() {
    int result;
    if (islem == 1) {
        yazi();
        result = toplama();
    } else if (islem == 2) {
        yazi();
        result = cikarma();
    } else {
        printf("Yanlis tuslama yaptiniz, basa donuluyor...\n");
        islem1();
        result = kiyas();
    }
    return result;
}

int devam() {
    islem1();
    sonuc = kiyas();
    yazdir();
    return 0;
}

int yazdir() {
    printf("Sonuc: %d\n", sonuc);
    return 0;
}

int yazi() {
    printf("Iki Sayi giriniz:\n ");
    return 0;
}
