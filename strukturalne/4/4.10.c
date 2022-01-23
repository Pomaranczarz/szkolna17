#include <stdio.h>
#include <stdlib.h>

void swap(int* l, int* r);
void displayReversed(int number);

int main() {
    int a;
    int b;

    printf("Podaj dwie liczby oddzielone spacja:\n");
    scanf("%i %i", &a, &b);

    printf("a = %i\tb = %i\n", a, b);
    swap(&a, &b);
    printf("Po zamianie: a = %i\tb = %i", a, b);

    printf("\nOdwrocone a:\n");
    displayReversed(a);
    printf("\nOdwrocone b:\n");
    displayReversed(b);

    return 0;
}

void swap(int* l, int* r) {
    int temp = *l;
    *l = *r;
    *r = temp;
}

int getNumLen(int num) {
    int count = 0;
    while (num) {
        num /= 10;
        count++;
    }
}

void displayReversed(int number) {
    int* arr = (int*)malloc(getNumLen(number) * sizeof(int));
    int i = 0;
    while (number) {
        arr[i++] = number % 10;
        number /= 10;
    }

    int index;
    for (index = 0; index < i; index++)
        printf("%i", arr[index]);
}
