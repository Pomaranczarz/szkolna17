#include <stdio.h>

void assignSumAndSub(int* l, int* r) {
    *l = *l + *r;
    *r = *l - 2 * (*r);
}

int main(void) {
    int a, b;

    printf("Podaj a i b oddzielone spacja: \n");
    scanf("%i %i", &a, &b);
    
    assignSumAndSub(&a, &b);
    printf("Suma: %i\nRoznica: %i", a, b);

    return 0;
}