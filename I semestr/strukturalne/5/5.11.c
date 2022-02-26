#include <stdio.h>
#include <stdbool.h>

unsigned product(unsigned* arr, unsigned size) {
    unsigned i;
    unsigned result = 1;
    
    for (i = 0; i < size; i++)
        result *= arr[i];

    return result;
}

unsigned sum(unsigned* arr, unsigned size) {
    unsigned i = 0;
    unsigned result = 0;

    for (i = 0; i < size; i++)
        result += arr[i];

    return result;
}

bool areAllEven(unsigned* arr, unsigned size) {
    unsigned i;
    for (i = 0; i < size; i++)
        if (arr[i] % 2 != 0)
            return false;

    return true;
}

int main() {
    unsigned numbers[3] = { 0 };
    int i;
    for (i = 0; i < 3; i++) {
        printf("Podaj %i. liczbe: \n", i + 1);
        scanf("%u", &numbers[i]);
    }

    if (areAllEven(numbers, 3))
        printf("Suma liczb: %u", sum(numbers, 3));
    else {
        for (i = 0; i < 3; i++)
            if (numbers[i] == 1) {
                printf("Iloczyn: %u", product(numbers, 3));
                break;
            }

        return -1;
    }

    return 0;
}