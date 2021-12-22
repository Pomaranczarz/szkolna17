#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* nowatabDyn(int* tabS, size_t n, int a, int b, int* match_count);
void PrintOneDimensional(int* arr, size_t size);

int main(void) {
    srand(time(NULL));
    int tabS[100];
    for (int i = 0; i < 100; i++)
        tabS[i] = rand() % 100 + 1;

    int a, b;
    printf("Podaj kolejno dolna i gorna granice przedzialu: \n");
    scanf("%d %d", &a, &b);

    int match_count = 0;
    for (int i = 0; i < 100; i++) 
        if (tabS[i] >= a && tabS[i] <= b)
            match_count++;

    int* nowaTab = nowatabDyn(tabS, 100, a, b, &match_count);

    printf("tabS: \n");

    PrintOneDimensional(tabS, 100);

    printf("\n\nnowaTab:\n");

    PrintOneDimensional(nowaTab, match_count);

    printf("\n");
    
    return 0;
}

int* nowatabDyn(int* tabS, size_t n, int a, int b, int* match_count) {
    int* result = (int*)malloc(*match_count * sizeof(int));
    for (int i = 0, resultIndex = 0; i < n; i++)
        if (tabS[i] >= a && tabS[i] <= b)
            result[resultIndex++] = tabS[i];

    return result;
}

void PrintOneDimensional(int* arr, size_t size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
