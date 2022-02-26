#include "tablice.h"

void square(int* n) { *n *= *n; }

int main(void) {
    int* oneDim = (int*)malloc(3 * sizeof(int));
    int** twoDim = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++)
        twoDim[i] = (int*)malloc(3 * sizeof(int));

    ReadStdinToArray1D(oneDim, 3);
    ReadStdinToArray2D(twoDim, 3, 3);

    PrintArray1D(oneDim, 3, ", ");
    PrintArray2D(twoDim, 3, 3, ", ");

    int oneDim_sum = Accumulate1D(oneDim, 3);
    int twoDim_sum = Accumulate2D(twoDim, 3, 3);

    float oneDim_avg = Average1D(oneDim, 3);
    float twoDim_avg = Average2D(twoDim, 3, 3);

    int oneDim_max = MaxElement1D(oneDim, 3);
    int twoDim_max = MaxElement2D(twoDim, 3, 3);

    int oneDim_min = MinElement1D(oneDim, 3);
    int twoDim_min = MaxElement2D(twoDim, 3, 3);
    
    int oneDim_equalTo5 = Count1D(oneDim, 3, 5);
    int twoDim_equalTo5 = Count2D(twoDim, 3, 3, 5);

    printf("\n\n\n");
    printf("Suma: %d\n", oneDim_sum);
    printf("Suma: %d\n", twoDim_sum);
    printf("Srednia: %f\n", oneDim_avg);
    printf("Srednia: %f\n", twoDim_avg);
    printf("Max: %d\n", oneDim_max);
    printf("Max: %d\n", twoDim_max);
    printf("Min: %d\n", oneDim_min);
    printf("Min: %d\n", twoDim_min);
    printf("Liczba elementow rowna 5: %d\n", oneDim_equalTo5);
    printf("Liczba elementow rowna 5: %d\n", twoDim_equalTo5);

    Transform1D(oneDim, 3, square);
    Transform2D(twoDim, 3, 3, square);

    printf("Tablica po transformacji:\n");
    PrintArray1D(oneDim, 3, ", ");
    PrintArray2D(twoDim, 3, 3, ", ");

    free(oneDim);
    for (int i = 0; i < 3; i++)
        free(twoDim[i]);
    free(twoDim);

    return 0;
}