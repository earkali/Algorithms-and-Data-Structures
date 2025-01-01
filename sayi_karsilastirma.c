#include <stdio.h>

int temp;

int input();

int maksimum(int a, int b);

int minimum(int a, int b);

int main() {

    int x = input();
    int y = input();
    printf("Sayilarin en buyugu = %d\n", maksimum(x, y));
    printf("Sayilerin en kucugu = %d\n", minimum(x, y));
    return 0;
}
int input() {

    printf("Sayi girin: ");
    scanf("%d", &temp);
    return temp;
}
int maksimum(int a, int b) {
    return (a > b) ? a : b;
}
int minimum(int a, int b) {
    return (a < b) ? a : b;
}
