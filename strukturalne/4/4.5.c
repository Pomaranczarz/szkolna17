#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2;
    printf("Podaj dwie liczby oddzielone spacja:\n");
    scanf("%i %i", &num1, &num2);

    int sum = num1 + num2;
    printf("Srednia arytmetyczna: %.2f\n", sum * 1.0 / 2.f);
    printf("Srednia geometryczna: %.2f\n", sqrt(sum * 1.0));

    return 0;
}
