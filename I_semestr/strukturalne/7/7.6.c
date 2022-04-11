#include <stdio.h>
#include <math.h>

int factorial(int n) {
    int i;
    int result = 1;
    for (i = 1; i <= n; i++)
        result *= i;

    return result;
}

float Sin(float x, unsigned k) {
    unsigned i;
    float result = 0;

    for (i = 0; i < k; i++)
        result += (pow(-1, i) / factorial(2 * i + 1)) * pow(x, 2 * i + 1);

    return result;
}

int main() {
    unsigned k;
    float angle;

    printf("Podaj kat (w radianach): \n");
    scanf("%f", &angle);

    printf("Podaj k: \n");
    scanf("%u", &k);

    printf("sin(%.2f) = %f", angle, Sin(angle, k));

    return 0;
}