#include <iostream>
#include "random_array.hpp"

template<size_t N>
void selection_sort(std::array<int, N>& tab);

int main() {
    std::array<int, 15> array = get_random_array<15>(0, 100);

    std::cout << "Tablica przed sortowaniem: ";
    for (const auto& i : array)
        std::cout << i << " ";
    std::cout << '\n';

    selection_sort(array);

    std::cout << "Tablica po sortowaniu: ";
    for (const auto& i : array)
        std::cout << i << " ";
    std::cout << '\n';
}

template<size_t N>
void selection_sort(std::array<int, N>& tab) {
    for (size_t i = 0; i < tab.size(); ++i) {
        size_t min = i;
        for (size_t j = i + 1; j < tab.size(); ++j) {
            if (tab[j] < tab[min])
                min = j;
        }
        std::swap(tab[i], tab[min]);
    }
}