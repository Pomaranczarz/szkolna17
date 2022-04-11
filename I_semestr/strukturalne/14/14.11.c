#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_POS 1
#define N_POS 2

void GenerateFileWithNumbersFromOneToN(const char* filename, int n);
void PrintFile(const char* filename);
float GetAvgFromFile(const char* filename);

int main(int argc, char** argv) {
    char filename[20];
    int n;
    if (argc == 1) {
        memcpy(filename, "dane.txt", strlen("dane.txt"));
        n = 10;
    } else {
        memcpy(filename, argv[FILENAME_POS], strlen(argv[FILENAME_POS]));
        filename[strlen(filename) - 1] = '\0';
        n = atoi(argv[N_POS]);
    }

    GenerateFileWithNumbersFromOneToN(filename, n);
    PrintFile(filename);
    printf("\nSrednia = %f", GetAvgFromFile(filename));
}

void GenerateFileWithNumbersFromOneToN(const char* filename, int n) {
    FILE* out = fopen(filename, "w");
    if (out == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    for (int i = 1; i < n; i++)
        fprintf(out, "%d\n", i);

    fclose(out);
}

void PrintFile(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    int num;
    while (fscanf(in, "%d\n", &num) == 1) 
        printf("%d\n", num);

    fclose(in);
}

float GetAvgFromFile(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return -1;
    }

    int num;
    int sum = 0;
    int count = 0;

    while (fscanf(in, "%d\n", &num) == 1) {
        count++;
        sum += num;
    }

    fclose(in);

    return (float)sum / count;
}