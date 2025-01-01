#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ustsinir;
int altsinir;
int temp;

int input();
int rnd();

int main() {
    srand(time(NULL));
    int son = rnd();
    printf("%d\n", son);
    return 0;
}

int rnd() {
    printf("Ust siniri giriniz: ");
    ustsinir = input();
    printf("Alt siniri giriniz: ");
    altsinir = input();

    int random_number;
    do {
        random_number = altsinir + rand() % (ustsinir - altsinir + 1);
    } while (random_number < altsinir || random_number > ustsinir);

    return random_number;
}

int input() {
    scanf("%d", &temp);
    return temp;
}
