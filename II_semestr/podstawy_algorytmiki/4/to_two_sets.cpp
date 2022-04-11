#include <iostream>
#include "SubsetPredicate.hpp"


template<typename T, typename LeftSetPredicate>
size_t to_two_subsets(T* arr, size_t size, LeftSetPredicate predicate);

bool isEven(int value) { return value % 2 == 0; }

int main() {
    int tab[]{ 6, 2, 3, 5, 4, 6, 7, 10, 12, 18, 22 };

    size_t div_index = to_two_subsets(tab, 11, isEven);

    std::cout << "Div index: " << div_index << std::endl;

    for (size_t i = 0; i < 11; ++i) {
        std::cout << tab[i] << " ";
    }
}

template<typename T, typename LeftSetPredicate>
size_t to_two_subsets(T* arr, size_t size, LeftSetPredicate predicate) {
    if (size < 2)
        return 0;

    size_t i = 0;
    size_t j = size - 1;
    while (i < j) {
        while (predicate(arr[i]) && i < j) ++i;
        while (!predicate(arr[j]) && i < j) --j;

        if (i < j) {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }

    return !predicate(arr[i]) ? i : i + 1;
}