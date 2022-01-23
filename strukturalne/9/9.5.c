#include <stdio.h>

void decompose(float* number) {
    int integer_part = (int)(*number);
    float floating_part = *number - integer_part;

    printf("Liczba: %f\nCzesc calkowita: %i\nCzesc ulamkowa: %f\n", *number, integer_part, floating_part);
}

int main(void) {
    unsigned i;
    float input;
    for (i = 0; i < 3; i++) {
        printf("Podaj liczbe: \n");
        scanf("%f", &input);

        decompose(&input);
    }

    return 0;
}