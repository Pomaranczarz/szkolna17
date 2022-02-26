#include "../utils.h"

float* rowSum(float** arr, int rows, int cols, float* colSum);

int main(void) {
    float** t = (float**)malloc(3 * sizeof(float*));
    for (int i = 0; i < 3; i++)
        t[i] = (float*)malloc(3 * sizeof(float));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            t[i][j] = 3 * i + j;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
            printf("%f ", t[i][j]);

        printf("\n");
    }

    float* col_sum = (float*)malloc(3 * sizeof(float));
    float* row_sum = rowSum(t, 3, 3, col_sum);

    printf("Sumy kolum:\n");
    PrintArrayF(col_sum, 3, ", ");

    printf("\nSumy wierszy:\n");
    PrintArrayF(row_sum, 3, ", ");

    for (int i = 0; i < 3; i++)
        free(t[i]);

    free(t);
    free(col_sum);
    free(row_sum);
}

float* rowSum(float** arr, int rows, int cols, float* colSum) {
    float* result = (float*)malloc(rows * sizeof(float));
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) {
            result[i] += arr[i][j];
            colSum[i] += arr[j][i];
        }

    return result;
}
