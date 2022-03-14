#include <iostream>

enum class SortMode { Ascending, Descending };

void quicksort(int* tab, int left, int right, SortMode sortMode = SortMode::Ascending);

int main() {
    int tab[] { 6, 3, 4, 8, 9, 7, 1, 2, 5 };
    quicksort(tab, 0, 8);

    for (int i = 0; i < 9; i++)
        std::cout << tab[i] << " ";

}

void quicksort(int* tab, int left, int right, SortMode sortMode) {
    if (left < right) {
        int pivot = tab[(left + right) / 2];
        int i = left;
        int j = right;

        while (i <= j) {
            if (sortMode == SortMode::Ascending) {
                while (tab[i] < pivot) ++i;
                while (tab[j] > pivot) --j;
            }
            else {
                while (tab[i] > pivot) ++i;
                while (tab[j] < pivot) --j;
            }

            if (i <= j) {
                std::swap(tab[i], tab[j]);
                ++i;
                --j;
            }
        }

        quicksort(tab, left, j, sortMode);
        quicksort(tab, i, right, sortMode);
    }
}