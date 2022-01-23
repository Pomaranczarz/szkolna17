#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20

void FillRandom(int* arr, unsigned len);
void ArrCpyIndexNotation(int src[], int dsc[], unsigned len);
void ArrCpyPtrNotation(int* src, int* dsc, unsigned len);
void PrintArray(const char* arr_name, int* arr, unsigned len);

int main(void) {
    srand(time(NULL));

    int arr1[ARRAY_SIZE];
    int arr2[ARRAY_SIZE];
    int arr3[ARRAY_SIZE];

    FillRandom(arr1, ARRAY_SIZE);
    PrintArray("Tablica 1", arr1, ARRAY_SIZE);

    ArrCpyIndexNotation(arr1, arr2, ARRAY_SIZE);
    PrintArray("Tablica skopiowana przy uzyciu notacji tablicowej", arr2, ARRAY_SIZE);

    ArrCpyPtrNotation(arr1, arr3, ARRAY_SIZE);
    PrintArray("Tablica skopiowana przy uzyciu notacji wskaznikowej", arr3, ARRAY_SIZE);

    return 0;
}

void FillRandom(int* arr, unsigned len) {
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 100 + 1;
}

void ArrCpyIndexNotation(int src[], int dsc[], unsigned len) {
    for (int i = 0; i < len; i++)
        dsc[i] = src[i];
}

void ArrCpyPtrNotation(int* src, int* dsc, unsigned len) {
    for (int i = 0; i < len; i++)
        *(dsc + i) = *(src + i);
}

void PrintArray(const char* arr_name, int* arr, unsigned len) {
    printf("%s: \n[ ", arr_name);
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i == len - 1)
            printf(" ");
        else
            printf(", ");
    }

    printf("]\n");
}