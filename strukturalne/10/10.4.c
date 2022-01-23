#include <stdio.h>
#include <stdlib.h>

void print(int** arr, unsigned size);
int diagonalProduct(int** arr, unsigned size);
int aboveDiagonalSum(int** arr, unsigned size);

int main(void) {
    unsigned N;
    printf("Podaj N:");
    scanf("%u", &N);

    int** tab = (int**)malloc(N * sizeof(int));    
    for (int i = 0; i < N; i++)
        tab[i] = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            printf("Podaj %d. liczbe: \n", N * i + j + 1);
            scanf("%d", &tab[i][j]);
        }

    print(tab, N);

    printf("Iloczyn przekatnej: %d\n", diagonalProduct(tab, N));
    printf("Suma ponad przekatna: %d\n", aboveDiagonalSum(tab, N));

    return 0;
}

void print(int** arr, unsigned size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%3d ", arr[i][j]);

        printf("\n");
    }
}

int diagonalProduct(int** arr, unsigned size) {
    int result = 1;
    for (int i = 0, j = 0; i < size; i++, j++)
        result *= arr[i][j];

    return result;
}

int aboveDiagonalSum(int** arr, unsigned size) {
    int result = 0;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size && j > 0; j++)
            result += arr[i][j];

    return result;
}