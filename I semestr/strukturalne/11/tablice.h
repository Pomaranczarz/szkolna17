#ifndef TABLICE_H
#define TABLICE_H

#include <stdio.h>
#include <stdlib.h>

void ReadStdinToArray1D(int* array, unsigned size) {
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

void ReadStdinToArray2D(int** array, unsigned rows, unsigned cols) {
    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            scanf("%d", &array[i][j]);
}

void PrintArray1D(int* array, unsigned size, const char* sep) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);

        if (i == size - 1) printf(" ");
        else printf("%s", sep);
    }
    printf("]\n");
}

void PrintArray2D(int** array, unsigned rows, unsigned cols, const char* sep) {
    for (unsigned i = 0; i < rows; i++)
        PrintArray1D(array[i], cols, sep);
}

int Accumulate1D(int* arr, unsigned size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

int Accumulate2D(int** arr, unsigned rows, unsigned cols) {
    int sum = 0;
    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            sum += arr[i][j];

    return sum;
}

float Average1D(int* arr, unsigned size) {
    return (float)Accumulate1D(arr, size) / size;
}

float Average2D(int** arr, unsigned rows, unsigned cols) {
    return (float)Accumulate2D(arr, rows, cols) / (rows * cols);
}

int MaxElement1D(int* arr, unsigned size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    return max; 
}

int MinElement1D(int* arr, unsigned size) {
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];

    return min; 
}

int MaxElement2D(int** arr, unsigned rows, unsigned cols) {
    int max = arr[0][0];
    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            if (arr[i][j] > max)
                max = arr[i][j];

    return max;
}

int MinElement2D(int** arr, unsigned rows, unsigned cols) {
    int min = arr[0][0];
    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            if (arr[i][j] < min)
                min = arr[i][j];

    return min;
}

int Count1D(int* arr, unsigned size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            count++;

    return count;
}

int Count2D(int** arr, unsigned rows, unsigned cols, int value) {
    int count = 0;
    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            if (arr[i][j] == value)
                count++;

    return count;
}

void Transform1D(int* arr, unsigned size, void(*f)(int*)) {
    for (int i = 0; i < size; i++)
        f(&arr[i]);
}

void Transform2D(int** arr, unsigned rows, unsigned cols, void(*f)(int*)) {
    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            f(&arr[i][j]);
}

#endif /* TABLICE_H */
