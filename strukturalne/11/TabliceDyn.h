#ifndef TABLICE_DYN_H
#define TABLICE_DYN_H

#include <stdlib.h>
#include <stdio.h>

float* CreateOneDimensional(size_t size);
void DeleteOneDimensional(float* arr);
void PrintOneDimensional(float* arr, size_t size);
float** CreateTwoDimensional(size_t rows, size_t cols);
void DeleteTwoDimensional(float** arr, size_t cols);
void PrintTwoDimensional(float** arr, size_t rows, size_t cols);

#endif