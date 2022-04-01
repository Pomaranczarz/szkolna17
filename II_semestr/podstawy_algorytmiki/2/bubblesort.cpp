#include <iostream>
#include <ctime>
#include <cstdlib>
#include "random_array.hpp"

template<size_t N>
void bubblesort(std::array<int, N>& tab);

int main() {
    std::array<int, 10> array = get_random_array<10>(25, 125);

    std::cout << "Tablica przed sortowaniem: ";
    for (const auto& i : array)
        std::cout << i << " ";
    std::cout << '\n';

    bubblesort(array);

    std::cout << "Tablica po sortowaniu: ";
    for (const auto& i : array)
        std::cout << i << " ";
    std::cout << '\n';
}

template<size_t N>
void bubblesort(std::array<int, N>& tab) {
    for (size_t i = 0; i < tab.size(); ++i) {
        bool swap_occured = false;
        for (size_t j = 0; j < tab.size() - 1; ++j) {
            if (tab[j] > tab[j + 1]) {
                // int tmp = tab[j];
                // tab[j] = tab[j + 1];
                // tab[j + 1] = tmp;
                std::swap(tab[j], tab[j + 1]);
                swap_occured = true;
            }
        }

        if (!swap_occured)
            return;
    }
}
