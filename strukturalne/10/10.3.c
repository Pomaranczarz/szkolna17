#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

void read(float tab[N][M]);
void print(float tab[N][M]);
float sum(float tab[N][M]);
float average(float tab[N][M]);

int main(void) {
    float tab[N][M];

    read(tab);
    print(tab);
    printf("Suma: %.2f\n", sum(tab));
    printf("Srednia: %.2f\n", average(tab));

    return 0;
}

void read(float tab[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Podaj liczbe: ");
            scanf("%f", &tab[i][j]);
        }
    }
}

void print_delimiter(int count) {
    for (int i = 0; i < count; i++)
        printf("-");
    printf("\n");
}

void print(float tab[N][M]) {
    print_delimiter(N * 9 + 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("| %6.2f ", tab[i][j]);
        printf("|\n");
        print_delimiter(N * 9 + 1);
    }
}

float sum(float tab[N][M]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += tab[i][j];
        }
    }
    return sum;
}

float average(float tab[N][M]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += tab[i][j];
        }
    }
    return sum / (N * M);
}