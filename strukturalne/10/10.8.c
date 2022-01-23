#include "../utils.h"

void FillTwoDimensional(float** arr, unsigned rows, unsigned cols);
float* f1(float** arr, unsigned rows, unsigned cols, unsigned* count);
float* f2(float** arr, unsigned rows, unsigned cols, unsigned* count);
unsigned CountZeros(float** arr, unsigned rows, unsigned cols);

int main(void) {
    srand(time(NULL));
    float** numbers = (float**)malloc(3 * sizeof(float*));
    for (int i = 0; i < 3; i++)
        numbers[i] = (float*)malloc(3 * sizeof(float));

    FillTwoDimensional(numbers, 3, 3);
    unsigned positive_size, negative_size;
    float* positive = f1(numbers, 3, 3, &positive_size);
    float* negative = f2(numbers, 3, 3, &negative_size);
    unsigned zeros = CountZeros(numbers, 3, 3);

    printf("Dodatnie: \n");
    PrintArrayF(positive, positive_size, ", ");

    printf("Ujemne: \n");
    PrintArrayF(negative, negative_size, ", ");

    printf("Zer: %u", zeros);

    return 0;
}

void FillTwoDimensional(float** arr, unsigned rows, unsigned cols) {
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++)
            arr[i][j] = GetRandomI(-100, 100);
}

float* f1(float** arr, unsigned rows, unsigned cols, unsigned* count) {
    float temp_arr[rows * cols];
    unsigned positive_count = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] > 0) 
                temp_arr[positive_count++] = arr[i][j];

    float* result = (float*)malloc(positive_count * sizeof(float));
    for (int i = 0; i < positive_count; i++)
        result[i] = temp_arr[i];

    *count = positive_count;
    return result;
}

float* f2(float** arr, unsigned rows, unsigned cols, unsigned* count) {
    float temp_arr[rows * cols];
    unsigned negative_count = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] < 0) 
                temp_arr[negative_count++] = arr[i][j];

    float* result = (float*)malloc(negative_count * sizeof(float));
    for (int i = 0; i < negative_count; i++)
        result[i] = temp_arr[i];

    *count = negative_count;
    return result;
}

unsigned CountZeros(float** arr, unsigned rows, unsigned cols) {
    unsigned count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] == 0)
                count++;

    return count;
}
