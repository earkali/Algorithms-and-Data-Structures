#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int input();
int rnd();
int kontrol(int x, int y);
int zar1 = 0;
int zar2 = 1;
int main() {
    srand(time(NULL));
    while (zar1 != zar2) {
        zar1 = rnd();
        zar2 = rnd();
        printf("\n");
    }
    kontrol(zar1,zar2);
}
int rnd() {
    int zar = rand() % 6 +1;
    printf("%d", zar);
    return zar;
}
int kontrol(int x, int y) {
    if (x==y) {
        switch (x) {
                case 1:
           printf("1-1 / Hep yek\n");
            break;
            case 2:
                printf("2-2 / Du bara\n");
            break;
            case 3:
                printf("3-3 / Du se\n");
            break;
            case 4:
                printf("4-4 / Dort Cehar\n");
            break;
            case 5:
                printf("5-5 / Du bes\n");
            break;
            case 6:
                printf("6-6 / Du ses\n");
            break;
            default:
                break;
        }
    }
}