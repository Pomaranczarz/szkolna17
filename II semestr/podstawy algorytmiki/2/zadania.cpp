#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

enum class SortMode { Ascending, Descending };

void bubblesort2d(int** tab, int w, int k, SortMode mode, size_t nrKol);
void selectionsort(int* tab, int size, SortMode mode);
void bubblesort(int* tab, int size, SortMode mode);
void insertsort(int* tab, int size, SortMode mode);

void selectionsort_test();
void bubblesort2d_test();
void bubblesort_test();
void insertsort_test();

int main() {
    srand(time(0));
    int choice{ 0 };
    do {
        std::cout << "\n1. Zadanie 2.2\n2. Zadanie 2.3\n3. Zadanie 2.4\n4. Zadanie 2.5\n5. Wyjscie\n";
        std::cin >> choice;

        switch (choice) {
        case 1: bubblesort_test();      break;
        case 2: selectionsort_test();   break;
        case 3: insertsort_test();      break;
        case 4: bubblesort2d_test();    break;
        }
    } while (choice != 5);
}

void fill_range_random(int* tab, int size, int min, int max) {
    for (int i = 0; i < size; ++i)
        tab[i] = rand() % (max - min + 1) + min;
}

void print_array(int* tab, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << std::setw(4) << tab[i] << " ";
}

void print_array_2d(int** tab, int w, int k) {
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < k; ++j)
            std::cout << std::setw(4) << tab[i][j] << " ";

        std::cout << '\n';
    }
}

void bubblesort_test() {
    int range_min, range_max;
    size_t size;
    int sortChoice{ 0 };
    SortMode sortMode;

    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> size;

    std::cout << "Podaj kolejno dolna i gorna granice przedzialu: ";
    std::cin >> range_min >> range_max;

    std::cout << "Wybierz tryb sortowania (1 - rosnaca, inne - malejaca): ";
    std::cin >> sortChoice;

    sortMode = (sortChoice == 1 ? SortMode::Ascending : SortMode::Descending);

    int* tab = new int[size];
    fill_range_random(tab, size, range_min, range_max);

    std::cout << "\nTablica przed sortowaniem: \n";
    print_array(tab, size);

    bubblesort(tab, size, sortMode);

    std::cout << "\nTablica po sortowaniu: \n";
    print_array(tab, size);

    delete[] tab;
}

void selectionsort_test() {
    int range_min, range_max;
    size_t size;
    int sortChoice{ 0 };
    SortMode sortMode;

    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> size;

    std::cout << "Podaj kolejno dolna i gorna granice przedzialu: ";
    std::cin >> range_min >> range_max;

    std::cout << "Wybierz tryb sortowania (1 - rosnaca, inne - malejaca): ";
    std::cin >> sortChoice;

    sortMode = (sortChoice == 1 ? SortMode::Ascending : SortMode::Descending);

    int* tab = new int[size];
    fill_range_random(tab, size, range_min, range_max);

    std::cout << "\nTablica przed sortowaniem: \n";
    print_array(tab, size);

    selectionsort(tab, size, sortMode);

    std::cout << "\nTablica po sortowaniu: \n";
    print_array(tab, size);

    delete[] tab;
}

void insertsort_test() {
    int range_min, range_max;
    size_t size;
    int sortChoice{ 0 };
    SortMode sortMode;

    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> size;

    std::cout << "Podaj kolejno dolna i gorna granice przedzialu: ";
    std::cin >> range_min >> range_max;

    std::cout << "Wybierz tryb sortowania (1 - rosnaca, inne - malejaca): ";
    std::cin >> sortChoice;

    sortMode = (sortChoice == 1 ? SortMode::Ascending : SortMode::Descending);

    int* tab = new int[size];
    fill_range_random(tab, size, range_min, range_max);

    std::cout << "\nTablica przed sortowaniem: \n";
    print_array(tab, size);

    insertsort(tab, size, sortMode);

    std::cout << "\nTablica po sortowaniu: \n";
    print_array(tab, size);

    delete[] tab;
}

void bubblesort2d_test() {
    int range_min, range_max;
    size_t w, k;
    size_t nrKol;
    int sortChoice{ 0 };
    SortMode sortMode;

    std::cout << "Podaj kolejno liczbe wierszy i kolumn: ";
    std::cin >> w >> k;

    std::cout << "Podaj numer kolumny: ";
    std::cin >> nrKol;

    std::cout << "Podaj kolejno dolna i gorna granice przedzialu: ";
    std::cin >> range_min >> range_max;

    std::cout << "Wybierz tryb sortowania (1 - rosnaca, inne - malejaca): ";
    std::cin >> sortChoice;

    sortMode = (sortChoice == 1 ? SortMode::Ascending : SortMode::Descending);

    int** tab = new int*[w];
    for (int i = 0; i < w; ++i)
        tab[i] = new int[k];
    
    for (int i = 0; i < w; ++i)
        fill_range_random(tab[i], k, range_min, range_max);

    std::cout << "\nTablica przed sortowaniem: \n";
    print_array_2d(tab, w, k);

    bubblesort2d(tab, w, k, sortMode, nrKol);

    std::cout << "\nTablica po sortowaniu: \n";
    print_array_2d(tab, w, k);

    for (int i = 0; i < w; ++i)
        delete[] tab[i];
    delete[] tab;
}

void bubblesort(int* tab, int size, SortMode mode) {
    bool swap_occurred{ false };
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1- i; ++j) {
            if (mode == SortMode::Ascending) {
                if (tab[j] > tab[j + 1]) {
                    std::swap(tab[j], tab[j + 1]);
                    swap_occurred = true;
                }
            } else {
                if (tab[j] < tab[j + 1]) {
                    std::swap(tab[j], tab[j + 1]);
                    swap_occurred = true;
                }
            }
        }

        if (!swap_occurred)
           return;
    }
}

int get_min_index(int* tab, int size, int begin) {
    int min_index = begin;
    for (int i = begin; i < size; ++i)
        if (tab[i] < tab[min_index])
            min_index = i;
    
    return min_index;
}

int get_max_index(int* tab, int size, int begin) {
    int max_index = begin;
    for (int i = begin; i < size; ++i)
        if (tab[i] > tab[max_index])
            max_index = i;
    
    return max_index;
}

void selectionsort(int* tab, int size, SortMode mode) {
    for (int i = 0; i < size; ++i) {
        if (mode == SortMode::Ascending) {
            int min_index = get_min_index(tab, size, i);
            std::swap(tab[i], tab[min_index]);
        } else {
            int max_index = get_max_index(tab, size, i);
            std::swap(tab[i], tab[max_index]);
        }
    }
}

void insertsort(int* tab, int size, SortMode mode) {
    for (size_t i = 1; i < size; ++i) {
        int tmp = tab[i];
        size_t j = i;
        if (mode == SortMode::Ascending) {
            while (j > 0 && tab[j - 1] > tmp) {
                tab[j] = tab[j - 1];
                --j;
            }
        } else {
            while (j > 0 && tab[j - 1] < tmp) {
                tab[j] = tab[j - 1];
                --j;
            }
        }
        tab[j] = tmp;
    }
}

void bubblesort2d(int** tab, int w, int k, SortMode mode, size_t nrKol) {
    bool swap_occurred{ false };
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < w - 1 - i; ++j) {
            if (mode == SortMode::Ascending) {
                if (tab[j][nrKol] > tab[j + 1][nrKol]) {
                    std::swap(tab[j][nrKol], tab[j + 1][nrKol]);
                    swap_occurred = true;
                }
            }
            else {
                if (tab[j][nrKol] < tab[j + 1][nrKol]) {
                    std::swap(tab[j][nrKol], tab[j + 1][nrKol]);
                    swap_occurred = true;
                }
            }
        }

        if (!swap_occurred)
            return;
    }
}
