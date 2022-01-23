#include <stdio.h>
#include <stdlib.h>

int* productOfEnteredNumbers() {
    int number = 1;
    int* result = (int*)malloc(sizeof(int));
    *result = 1;

    do {
        *result *= number;

        printf("Podaj liczbe: \n");
        scanf("%i", &number);
    } while (number >= 0 && number <= 100);

    return result;
}

int main(void) {
    int* func_result = productOfEnteredNumbers();
    printf("Iloczyn wprowadzonych liczb: %i", *func_result);

    free(func_result);
    return 0;
}