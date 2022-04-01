#include "../utils.h"

void ReadTwoDimensional(int** arr, int rows, int cols);
void PrintAverages(int** arr, int rows, int cols);
void PrintAllAverage(int** arr, int rows, int cols);
void PrintMax(int** arr, int rows, int cols);
void PrintAll(int** arr, int rows, int cols);

int main(void) {
    unsigned N, M;
    printf("Podaj liczbe zespolow: \n");
    scanf("%d", &N);
    printf("Podaj liczbe studentow w zespole: \n");
    scanf("%d", &M);

    int** oceny = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        oceny[i] = (int*)malloc(M * sizeof(int));

    ReadTwoDimensional(oceny, N, M);

    PrintAll(oceny, N, M);

    PrintAverages(oceny, N, M);

    PrintAllAverage(oceny, N, M);

    PrintMax(oceny, N, M);

    return 0;
}

void ReadTwoDimensional(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            printf("Podaj %d. ocene studenta w %d. zespole: \n", j + 1, i + 1);
            scanf("%d", &arr[i][j]);
        }
}

void PrintAverages(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++)
            sum += arr[i][j];

        printf("Srednia ocen %d. zespolu: %.2f\n", i + 1, (float)sum / cols);
    }
}

void PrintAllAverage(int** arr, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            sum += arr[i][j];

    printf("Srednia wszystkich ocen: %.2f\n", (float)sum / (rows * cols));
}

void PrintMax(int** arr, int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] > max)
                max = arr[i][j];

    printf("Najwieksza ocena: %d\n", max);
}

void PrintAll(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", arr[i][j]);

        printf("\n");
    }
}