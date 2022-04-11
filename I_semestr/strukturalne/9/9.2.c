#include <stdio.h>

void swap(int* l, int* r) {
    int temp = *l;
    *l = *r;
    *r = temp;
}

int main(void) {
    int a, b;

    printf("Podaj a i b oddzielone spacja: \n");
    scanf("%i %i", &a, &b);
    
    printf("Przed zmiana:\na = %i\nb = %i\n", a, b);
    swap(&a, &b);
    printf("Po zmianie:\na = %i\nb = %i\n", a, b);
}