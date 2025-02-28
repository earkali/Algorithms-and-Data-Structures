#include <stdio.h>
#define SIZE 5
int maximum;
int input();
int arr[SIZE];

int main() {
    input();
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nMaximum: %d\n", maximum);
}

int input() {
    for (int i = 0; i < SIZE; i++) {
        printf("Bir eleman girilsin:");
        scanf("%d", &arr[i]);
        if (i == 0 || arr[i] > maximum) {
            maximum = arr[i];
        }
    }
}
