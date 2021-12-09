#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/// Print array of integers.
void PrintArrayI(int* array, unsigned size, const char* sep) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);

        if (i == size - 1) printf(" ");
        else printf("%s", sep);
    }
    printf("]\n");
}

/// Print array of floats.
void PrintArrayF(float* array, unsigned size, const char* sep) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%f", array[i]);

        if (i == size - 1) printf(" ");
        else printf("%s", sep);
    }
    printf("]\n");
}

/// Print char array.
void PrintArrayC(char* array, unsigned size, const char* sep) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%c", array[i]);

        if (i == size - 1) printf(" ");
        else printf("%s", sep);
    }
    printf("]\n");
}

/// Reverse given array. Resulting array needs to be freed.
float* ReverseF(float* begin, float* end) {
    float* reversed = (float*)malloc((end - begin) * sizeof(float));

    for (int i = end - begin - 1, j = 0; i >= 0; i--, j++)
        reversed[j] = begin[i];

    return reversed;
}

/// Reverse given array. Resulting array needs to be freed.
int* ReverseI(int* begin, int* end) {
    int* reversed = (int*)malloc((end - begin) * sizeof(int));

    for (int i = end - begin - 1, j = 0; i >= 0; i--, j++)
        reversed[j] = begin[i];

    return reversed;
}

/// Get random integer in range. srand() needs to be called for correct performance.
int GetRandomI(int begin, int end) {
    return rand() % (end - begin) + begin;
}

/// Get sum of elements in [begin; end) range with starting init value.
float AccumulateF(float* begin, float* end, float init) {
    float result = init;
    while (begin != end) {
        result += *begin;
        begin++;
    }

    return result;
}

/// Get sum of elements in [begin; end) range with starting init value.
int AccumulateI(int* begin, int* end, int init) {
    int result = init;
    while (begin != end) {
        result += *begin;
        begin++;
    }

    return result;
}

/// Fill range [begin; end) with increasing sequence starting from init.
void Iota(int* begin, int* end, int init) {
    for (int i = init; begin != end; begin++, i++)
        *begin = i;
}

/// Check if all elements in range [begin; end) satisfy given predicate.
bool AreAllI(int* begin, int* end, bool(*predicate)(int)) {
    while (begin != end) {
        if (!predicate(*begin))
            return false;

        begin++;
    }

    return true;
}

/// Check if all elements in range [begin; end) satisfy given predicate.
bool AreAllF(float* begin, float* end, bool(*predicate)(float)) {
    while (begin != end) {
        if (!predicate(*begin))
            return false;

        begin++;
    }

    return true;
}

/// Apply transforming function f to every element in [begin; end) range.
void TransformI(int* begin, int* end, void(*f)(int*)) {
    while (begin != end) {
        f(begin++);
    }
}

/// Apply transforming function f to every element in [begin; end) range.
void TransformF(float* begin, float* end, void(*f)(float*)) {
    while (begin != end) {
        f(begin++);
    }
}

/// Count elements satisfying given predicate.
unsigned CountIfI(int* begin, int* end, bool(*predicate)(int)) {
    unsigned count = 0;
    for (; begin != end; begin++)
        if (predicate(*begin)) 
            count++;

    return count;
}

/// Count elements satisfying given predicate.
unsigned CountIfF(float* begin, float* end, bool(*predicate)(float)) {
    unsigned count = 0;
    for (; begin != end; begin++)
        if (predicate(*begin)) 
            count++;

    return count;
}

/// Get numbers of elements with given value.
unsigned CountI(int* begin, int* end, int value) {
    unsigned count = 0;
    for (; begin != end; begin++)
        if (*begin == value)
            count++;

    return count;
}

/// Read from stdin to array.
void ReadStdinToArrayI(int* array, unsigned size) {
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

/// Read from stdin to array.
void ReadStdinToArrayF(float* array, unsigned size) {
    for (int i = 0; i < size; i++)
        scanf("%f", &array[i]);
}

/// Get average of elements in range [begin; end).
float AverageI(int* begin, int* end) {
    int sum = 0;
    for (; begin != end; begin++)
        sum += *begin;

    return (float)sum / (end - begin);
}

/// Get average of elements in range [begin; end).
float AverageF(float* begin, float* end) {
    float sum = 0.0;
    for (; begin != end; begin++)
        sum += *begin;

    return sum / (end - begin);
}

/// Get max element in [begin; end) range.
int* MaxElementI(int* begin, int* end) {
    int* max = begin++;
    for (; begin != end; begin++)
        if (*begin > *max)
            max = begin;

    return max;
}

/// Get min element in [begin; end) range.
int* MinElementI(int* begin, int* end) {
    int* min = begin++;
    for (; begin != end; begin++)
        if (*begin < *min)
            min = begin;

    return min;
}

/// Get max element in [begin; end) range.
float* MaxElementF(float* begin, float* end) {
    float* max = begin++;
    for (; begin != end; begin++)
        if (*begin > *max)
            max = begin;

    return max;
}

/// Get min element in [begin; end) range.
float* MinElementF(float* begin, float* end) {
    float* min = begin++;
    for (; begin != end; begin++)
        if (*begin < *min)
            min = begin;

    return min;
}

/// Swap two values.
void swapI(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/// Swap two values.
void swapF(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

/// Check if number is prime.
bool IsPrime(int number) {
    int i;
    for (i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            return false;

    return true;
}

void BubblesortI(int* begin, int* end) {
    bool swap_occured;
    int size = end - begin;

    for (int i = 0; i < size; i++) {
        swap_occured = false;

        for (int j = 0; j < size - 1; j++) {
            if (begin[j] > begin[j + 1]) {
                swapI(&begin[j], &begin[j + 1]);
                swap_occured = true;
            }
        }

        if (swap_occured == false)
            return;
    }
}

void BubblesortF(float* begin, float* end) {
    bool swap_occured;
    int size = end - begin;

    for (int i = 0; i < size; i++) {
        swap_occured = false;

        for (int j = 0; j < size - 1; j++) {
            if (begin[j] > begin[j + 1]) {
                swapF(&begin[j], &begin[j + 1]);
                swap_occured = true;
            }
        }

        if (swap_occured == false)
            return;
    }
}

struct Point2Df {
    float x;
    float y;
};

struct Point2Di {
    int x;
    int y;
};

float GetDistanceBetweenPointsF(struct Point2Df p1, struct Point2Df p2) {
    return sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2));
}

float GetDistanceBetweenPointsI(struct Point2Di p1, struct Point2Di p2) {
    return sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2));
}

#endif /* UTILS_H */
