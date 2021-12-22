#include <stdlib.h>
#include <stdio.h>

float* f1(float** arr, size_t rows, size_t cols, int* resSize);
float* f2(float** arr, size_t rows, size_t cols, int* resSize);
void PrintOneDimensional(int* arr, size_t size);

int main(void) {
    float tab2[][] = {
        {3, 4, 5, 6, 7},
        {1, 4, 7, 8, 10},
        {-3, 7, -12, 420, -27},
        {0, -1, -9, -21, 21}
    };

    int negSize, posSize;
    float* positive = f1(tab2, 4, 5, &posSize);
    float* negative = f2(tab2, 4, 5, &negSize);

    printf("Dodatnie: \n");
    PrintOneDimensional(positive, posSize);

    printf("\nUjemne: \n");
    PrintOneDimensional(negative, negSize);

    return 0;
}

float* f2(float** arr, size_t rows, size_t cols, int* resSize) {
    int negative_count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] < 0)
                negative_count++;

    float* result = (float*)malloc(negative_count * sizeof(float));

    int resultIndex = 0
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] < 0)
                result[resultIndex++] = arr[i][j];

    *resSize = negative_count;

    return result;
}

float* f1(float** arr, size_t rows, size_t cols, int* resSize) {
    int positive_count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] > 0)
                positive_count++;

    float* result = (float*)malloc(positive_count * sizeof(float));

    int resultIndex = 0
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] > 0)
                result[resultIndex++] = arr[i][j];

    *resSize = positive_count;

    return result;
}

void PrintOneDimensional(int* arr, size_t size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
