#include <stdio.h>
#include <stdlib.h>

float* countIncomeAfterYear(float salary, float interest, unsigned capitalizationsPerYear);

int main(void) {
    float p1, p2;
    float x;

    printf("Podaj p1: \n");
    scanf("%f", &p1);

    printf("Podaj p2: \n");
    scanf("%f", &p2);

    printf("Podaj wplate: \n");
    scanf("%f", &x);

    float* p1_result = countIncomeAfterYear(x, p1, 2);
    float* p2_result = countIncomeAfterYear(x, p2, 1);

    printf("\nWyplata po roku na lokacie p1: %.2f\n", *p1_result);
    printf("Wyplata po roku na lokacie p2: %.2f\n", *p2_result);

    free(p1_result);
    free(p2_result);

    return 0;
}

float* countIncomeAfterYear(float salary, float interest, unsigned capitalizationsPerYear) {
    float* result = (float*)malloc(sizeof(float));
    *result = salary;
    unsigned i;

    for (i = 0; i < capitalizationsPerYear; i++)
        *result += *result * (interest / 100);

    return result;
}