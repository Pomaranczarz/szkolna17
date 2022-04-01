#include <iostream>

#include "random_array.hpp"

template<size_t N>
void insertion_sort(std::array<int, N>& tab);

int main() {
    std::array<int, 17> array = get_random_array<17>(34, 89);

    std::cout << "Tablica przed sortowaniem: ";
    for (const auto& i : array)
        std::cout << i << " ";
    std::cout << '\n';

    insertion_sort(array);

    std::cout << "Tablica po sortowaniu: ";
    for (const auto& i : array)
        std::cout << i << " ";
    std::cout << '\n';
}

template<size_t N>
void insertion_sort(std::array<int, N>& tab) {
    for (size_t i = 1; i < tab.size(); ++i) {
        int tmp = tab[i];
        size_t j = i;
        while (j > 0 && tab[j - 1] > tmp) {
            tab[j] = tab[j - 1];
            --j;
        }
        tab[j] = tmp;
    }
}