#include <iostream>

void quicksort(int* tab, int size);

int main() {

}

void quickSort(int* tab, int size) {
    if (size <= 1)
        return;

    int pivot = tab[size / 2];
    int i = 0;
    int j = size - 1;

    while (i <= j) {
        while (tab[i] < pivot) i++;
        while (tab[j] > pivot) j--;
        if (i <= j) {
            std::swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    quickSort(tab, i);
    quickSort(tab + i, size - i);
}