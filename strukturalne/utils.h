#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <memory.h>

/// Swap two values.
static void swapI(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/// Swap two values.
static void swapF(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

/// Print array of integers.
static void PrintArrayI(int* array, unsigned size, const char* sep) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);

        if (i == size - 1) printf(" ");
        else printf("%s", sep);
    }
    printf("]\n");
}

/// Print array of floats.
static void PrintArrayF(float* array, unsigned size, const char* sep) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%f", array[i]);

        if (i == size - 1) printf(" ");
        else printf("%s", sep);
    }
    printf("]\n");
}

/// Print char array.
static void PrintArrayC(char* array, unsigned size, const char* sep) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%c", array[i]);

        if (i == size - 1) printf(" ");
        else printf("%s", sep);
    }
    printf("]\n");
}

/// Append single character to string with updating length and capacity.
static void AppendToStringAndEnsureLength(char* str, unsigned* str_len, unsigned* current_capacity, char to_append) {
    if (*str_len + 1 >= *current_capacity) {
        *current_capacity = *current_capacity * 2;
        str = realloc(str, *current_capacity);
    }

    str[(*str_len)++] = to_append;
}

/// Concatenate num_of_args strings into result. result length is returned.
static unsigned Concatenate(char** result, unsigned num_of_args, ...) {
    if (*result != NULL)
        free(*result);

    *result = (char*)malloc(20 * sizeof(char));
    unsigned resultCapacity = 20;
    unsigned resultLen = 0;

    va_list args;
    va_start(args, num_of_args);

    for (int i = 0; i < num_of_args; i++) {
        const char* current_str = va_arg(args, const char*);
        for (int current_str_index = 0; current_str_index < strlen(current_str); current_str_index++)
            AppendToStringAndEnsureLength(*result, &resultLen, &resultCapacity, current_str[current_str_index]);

        AppendToStringAndEnsureLength(*result, &resultLen, &resultCapacity, ' ');
    }

    return resultLen;
}

/// Reverse given array. 
static void ReverseF(float* begin, float* end) {
    for (int i = 0, j = (end - begin) - 1; i < (end - begin) / 2; i++, j--)
        swapF(&begin[i], &begin[j]);
}

/// Reverse given array. 
static void ReverseI(int* begin, int* end) {
    for (int i = 0, j = (end - begin) - 1; i < (end - begin) / 2; i++, j--)
        swapI(&begin[i], &begin[j]);
}

/// Get random integer in range. srand() needs to be called for correct performance.
static int GetRandomI(int begin, int end) {
    return rand() % (end - begin) + begin;
}

/// Get sum of elements in [begin; end) range with starting init value.
static float AccumulateF(float* begin, float* end, float init) {
    for (float* it = begin; it != end; it++)
        init += *it;

    return init;
}

/// Get sum of elements in [begin; end) range with starting init value.
static int AccumulateI(int* begin, int* end, int init) {
    for (int* it = begin; it != end; it++)
        init += *it;

    return init;
}

/// Fill range [begin; end) with increasing sequence starting from init.
static void Iota(int* begin, int* end, int init) {
    for (int* it = begin; it != end; it++)
        *it = init++;
}

/// Check if all elements in range [begin; end) satisfy given predicate.
static bool AreAllI(int* begin, int* end, bool(*predicate)(int)) {
    for (int* it = begin; it != end; it++)
        if (!predicate(*it))
            return false;

    return true;
}

/// Check if all elements in range [begin; end) satisfy given predicate.
static bool AreAllF(float* begin, float* end, bool(*predicate)(float)) {
    for (float* it = begin; it != end; it++)
        if (!predicate(*it))
            return false;

    return true;
}

/// Apply transforming function f to every element in [begin; end) range.
void TransformI(int* begin, int* end, void(*f)(int*)) {
    for (int* it = begin; it != end; it++)
        f(it);
}

/// Apply transforming function f to every element in [begin; end) range.
static void TransformF(float* begin, float* end, void(*f)(float*)) {
    for (float* it = begin; it != end; it++)
        f(it);
}

/// Apply transforming funtion f to every element in range [begin; end) which satisfies predicate.
static void TransformIfI(int* begin, int* end, bool(*predicate)(int), void(*f)(int*)) {
     for (int* it = begin; it != end; it++)
        if (predicate(*it))
            f(it);
}

/// Apply transforming funtion f to every element in range [begin; end) which satisfies predicate.
static void TransformIfF(float* begin, float* end, bool(*predicate)(float), void(*f)(float*)) {
    for (float* it = begin; it != end; it++)
        if (predicate(*it))
            f(it);
}

/// Count elements satisfying given predicate.
static unsigned CountIfI(int* begin, int* end, bool(*predicate)(int)) {
    unsigned count = 0;
    for (int* it = begin; it != end; it++)
        if (predicate(*it)) 
            count++;

    return count;
}

/// Count elements satisfying given predicate.
static unsigned CountIfF(float* begin, float* end, bool(*predicate)(float)) {
    unsigned count = 0;
    for (float* it = begin; it != end; it++)
        if (predicate(*it)) 
            count++;

    return count;
}

/// Get numbers of elements with given value.
static unsigned CountI(int* begin, int* end, int value) {
    unsigned count = 0;
    for (int* it = begin; it != end; it++)
        if (*it == value)
            count++;

    return count;
}

/// Read from stdin to array.
static void ReadStdinToArrayI(int* array, unsigned size) {
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

/// Read from stdin to array.
void ReadStdinToArrayF(float* array, unsigned size) {
    for (int i = 0; i < size; i++)
        scanf("%f", &array[i]);
}

/// Get average of elements in range [begin; end).
static float AverageI(int* begin, int* end) {
    int sum = 0;
    for (int* it = begin; it != end; it++)
        sum += *it;

    return (float)sum / (end - begin);
}

/// Get average of elements in range [begin; end).
static float AverageF(float* begin, float* end) {
    float sum = 0.0;
    for (float* it = begin; it != end; it++)
        sum += *it;

    return sum / (end - begin);
}

/// Get max element in [begin; end) range.
static int* MaxElementI(int* begin, int* end) {
    int* max = begin++;
    for (; begin != end; begin++)
        if (*begin > *max)
            max = begin;

    return max;
}

/// Get min element in [begin; end) range.
static int* MinElementI(int* begin, int* end) {
    int* min = begin++;
    for (; begin != end; begin++)
        if (*begin < *min)
            min = begin;

    return min;
}

/// Get max element in [begin; end) range.
static float* MaxElementF(float* begin, float* end) {
    float* max = begin++;
    for (; begin != end; begin++)
        if (*begin > *max)
            max = begin;

    return max;
}

/// Get min element in [begin; end) range.
static float* MinElementF(float* begin, float* end) {
    float* min = begin++;
    for (; begin != end; begin++)
        if (*begin < *min)
            min = begin;

    return min;
}

/// Check if number is prime.
static bool IsPrime(int number) {
    int i;
    for (i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            return false;

    return true;
}

static void BubblesortI(int* begin, int* end) {
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

static void BubblesortF(float* begin, float* end) {
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

static float GetDistanceBetweenPointsF(struct Point2Df p1, struct Point2Df p2) {
    return sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2));
}

static float GetDistanceBetweenPointsI(struct Point2Di p1, struct Point2Di p2) {
    return sqrtf(powf(p2.x - p1.x, 2) + powf(p2.y - p1.y, 2));
}

#endif /* UTILS_H */
