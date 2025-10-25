#include <stdio.h>

int swap(int *a, int *b);

int main() {
    int x, y;
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);
    printf("Before swap:first number= %d, second number = %d\n", x, y);

    swap(&x, &y);
    printf("After swap:first number= %d, second number = %d\n", x, y);
    return 0;
}

swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

