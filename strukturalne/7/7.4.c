#include <stdio.h>
#include <stdlib.h>

void calculateNewSalaries(float* arr, unsigned len);
float getSumOfSalaries(float* arr, unsigned len);
void printSalaries(float* arr, unsigned len);

int main() {
    unsigned num_of_workers;
    printf("Podaj liczbe pracownikow: \n");
    scanf("%u", &num_of_workers);

    float* salaries = (float*)malloc(num_of_workers * sizeof(float));
    unsigned i;
    for (i = 0; i < num_of_workers; i++) {
        printf("Podaj place %u. pracownika: \n", i + 1);
        scanf("%f", salaries + i);
    }

    calculateNewSalaries(salaries, num_of_workers);
    printSalaries(salaries, num_of_workers);
    printf("\nSuma plac: %f", getSumOfSalaries(salaries, num_of_workers));
    
    free(salaries);

    return 0;
}

void calculateNewSalaries(float* arr, unsigned len) {
    unsigned i;
    for (i = 0; i < len; i++) {
        if (arr[i] > 5000)
            arr[i] += arr[i] * 0.05f;
        else
            arr[i] += arr[i] * 0.1f;
    }
}

float getSumOfSalaries(float* arr, unsigned len) {
    unsigned i;
    float sum = 0;
    for (i = 0; i < len; i++)
        sum += arr[i];

    return sum;
}

void printSalaries(float* arr, unsigned len) {
    unsigned i;
    for (i = 0; i < len; i++)
        printf("%u. %.2f\n", i + 1, arr[i]);
}
