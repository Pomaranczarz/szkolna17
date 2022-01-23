#include "TabliceDyn.h"

float* CreateOneDimensional(size_t size) {
    return malloc(size * sizeof(float));
}

void DeleteOneDimensional(float* arr) {
    free(arr);
}

void PrintOneDimensional(float* arr, size_t size) {
    for (int i = 0; i < size; i++)
        printf("%f ", arr[i]);
}

float** CreateTwoDimensional(size_t rows, size_t cols) {
    float** result = (float**)malloc(rows * sizeof(float*));

    for (int i = 0; i < rows; i++) 
        result[i] = (float*)malloc(cols * sizeof(float));

    return result;
}

void DeleteTwoDimensional(float** arr, size_t cols) {
    for (int i = 0; i < cols; i++)
        free(arr[i]);

    free(arr);
}

void PrintTwoDimensional(float** arr, size_t rows, size_t cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%f ", arr[i][j]);

        printf("\n");
    }
}
