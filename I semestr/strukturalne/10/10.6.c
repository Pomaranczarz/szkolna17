#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ARRAY_SIZE 10

bool check_all(int* begin, int* end, bool(*predicate)(int));
void FillRandom(int* arr, unsigned len); 
void PrintArray(const char* arr_name, int* arr, unsigned len);
bool HasPassed(int mark);

int main(void) {
    srand(time(NULL));

    int oceny[ARRAY_SIZE];
    FillRandom(oceny, ARRAY_SIZE);

    PrintArray("Oceny", oceny, ARRAY_SIZE);

    if (check_all(oceny, oceny + ARRAY_SIZE, HasPassed)) 
        printf("Wszyscy zdali");
    else
        printf("Nie wszyscy zdali");
}

bool check_all(int* begin, int* end, bool(*predicate)(int)) {
    while (begin != end) {
        if (!predicate(*begin))
            return false;
        
        begin++;
    }

    return true;
}

bool HasPassed(int mark) {
    return mark >= 3;
}

void FillRandom(int* arr, unsigned len) {
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 4 + 2;
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