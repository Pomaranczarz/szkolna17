#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

float* Reverse(float* arr, unsigned size);
void SwapMinMax(float* arr, unsigned size);
float* Squares(float* arr, unsigned size);
float* Cubes(float* arr, unsigned size);
void FillRandom(float* arr, unsigned len);
void PrintArray(const char* arr_name, float* arr, unsigned len);
int GetChoice();

int main(void) {
    srand(time(NULL));
    
    float* rev;
    float* squares;
    float* cubes;
    float nums[N];

    FillRandom(nums, N);
    PrintArray("Liczby", nums, N);
    
    switch (GetChoice()) {
    case 1: 
        SwapMinMax(nums, N);
        PrintArray("Po zamianie miejscami najwiekszego i najmniejszego elementu", nums, N);
        break;
    case 2:
        rev = Reverse(nums, N);
        PrintArray("Tablica w odwrotnej kolejnosci", rev, N);
        free(rev);
        break;
    case 3:
        squares = Squares(nums, N);
        cubes = Cubes(nums, N);

        PrintArray("Kwadraty liczb", squares, N);
        PrintArray("Szesciany liczb", cubes, N);

        free(squares);
        free(cubes);
        break;
    default:
        return -1;
    }
}

int GetChoice() {
    int choice;
    const char* menu = "\nMenu:\n1. Zamiana miejscami max i min\n2. Odwrocenie elementow\n3. Wyswietlenie kwadratowi szescianow wartosci\n";
    printf("%s", menu);
    scanf("%d", &choice);
    return choice;
}

float* max_element(float* arr, unsigned size) {
    float* max = &arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] > *max)
            max = &arr[i];

    return max;
}

float* min_element(float* arr, unsigned size) {
    float* min = &arr[0];
    for (int i = 0; i < size; i++)
        if (arr[i] < *min)
            min = &arr[i];

    return min;
}

void swap(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void SwapMinMax(float* arr, unsigned size) {
    swap(max_element(arr, size), min_element(arr, size));
}

float* Reverse(float* arr, unsigned size) {
    float* reversed = (float*)malloc(size * sizeof(size));

    for (int i = size - 1, j = 0; i >= 0; i--, j++)
        reversed[j] = arr[i];

    return reversed;
}

float* Squares(float* arr, unsigned size) {
    float* squares = (float*)malloc(size * sizeof(size));
    for (int i = 0; i < size; i++)
        squares[i] = arr[i] * arr[i];

    return squares;
}

float* Cubes(float* arr, unsigned size) {
    float* cubes = (float*)malloc(size * sizeof(size));
    for (int i = 0; i < size; i++)
        cubes[i] = arr[i] * arr[i] * arr[i];

    return cubes;
}

void FillRandom(float* arr, unsigned len) {
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 100 + ((float)(rand() % 100) / 100);
}

void PrintArray(const char* arr_name, float* arr, unsigned len) {
    printf("%s: \n[ ", arr_name);
    for (int i = 0; i < len; i++) {
        printf("%f", arr[i]);
        if (i == len - 1)
            printf(" ");
        else
            printf(", ");
    }

    printf("]\n");
}