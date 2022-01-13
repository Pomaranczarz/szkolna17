#include "../utils.h"

void FillTwoDimensional(float** arr, unsigned rows, unsigned cols);
void f(float** arr, unsigned rows, unsigned cols);

int main(void) {
    srand(time(NULL));

    float** numbers = (float**)malloc(3 * sizeof(float*));
    for (int i = 0; i < 3; i++)
        numbers[i] = (float*)malloc(3 * sizeof(float));

    FillTwoDimensional(numbers, 3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%f ", numbers[i][j]);

        printf("\n");
    }

    f(numbers, 3, 3);
    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%f ", numbers[i][j]);

        printf("\n");
    }

    return 0;
}

void FillTwoDimensional(float** arr, unsigned rows, unsigned cols) {
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++)
            arr[i][j] = GetRandomI(-100, 100);
}

void f(float** arr, unsigned rows, unsigned cols) {
    unsigned zero_count = 0;
    for (int i = 0; i < rows; i++) {
        zero_count = 0;
        for (int j = 0; j < cols; j++) {
            if (arr[j][i] == 0)
                zero_count++;

            if (zero_count > (float)(i / 2))
                arr[i][j] = 0;
        }

    }
}
