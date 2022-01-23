#include <stdio.h>
#include "../utils.h"

bool is_even(int n) {
    return n % 2 == 0;
}

int main(void) {
    int* t = (int*)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
        t[i] = i;

    int* new_end = FilterI(t, t + 10, is_even);

    for (int* it = t; it != new_end; it++)
        printf("%d", *it);

    return 0;
}