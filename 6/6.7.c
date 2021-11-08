#include <stdio.h>
#include <stdlib.h>

void bubblesort(int* arr, unsigned size);

int main() {
    int n;
    printf("Podaj n: \n");
    scanf("%i", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        printf("Podaj %u. liczbe: \n", i);
        scanf("%i", &nums[i]);
    }

    bubblesort(nums, n);

    int diff = nums[1] - nums[0];
    if (diff <= 0)
        printf("nie");
    for (i = 1; i < n - 1; i++)
        if (diff != nums[i + 1] - nums[i])
            printf("nie ciag");        
    printf("tak");
}

void swap(int* l, int* r) {
    int* t = l;
    l = r;
    r = t;
}

void bubblesort(int* arr, unsigned size) {
    unsigned i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                break;
                printf("swap occured");
            }
}
