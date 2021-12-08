#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void bubblesort(int* arr, unsigned size);

int main(void) {
    int* numbers;
    unsigned n, i;

    printf("Podaj n: \n");
    scanf("%u", &n);

    numbers = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("Podaj %u. liczbe: \n", i + 1);
        scanf("%d", &numbers[i]);
    }

    bubblesort(numbers, n);

    printf("\nNajwieksza: %d\n Druga najwieksza: %d\n", numbers[n - 1], numbers[n - 2]);

    free(numbers);

    return 0;
}

void swap(int* l, int* r) {
    int t = *l;
    *l = *r;
    *r = t;
}

void bubblesort(int* arr, unsigned size) {
    unsigned i, j;
    bool swap_occured;

    for (i = 0; i < size; i++) {
        swap_occured = false;

        for (j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swap_occured = true;
            }
        }

        if (swap_occured == false)
            return;
    }
}