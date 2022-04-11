#include <iostream>
#include "SubsetPredicate.hpp"

struct ThreeSubsetsSortResult
{
    size_t first_set_end_index;
    size_t third_set_start_index;
};

template<typename T, typename FirstSetPredicate, typename SecondSetPredicate>
ThreeSubsetsSortResult to_three_subsets(
    int* arr,
    size_t size,
    FirstSetPredicate firstSetPredicate,
    SecondSetPredicate secondSetPredicate
);

bool lessThan1(int value) { return value < 1; }
bool moreThan1(int value) { return value > 1; }

int main() {
    int tab[]{ 0, 1, 2, 2, 1, 2, 0, 0, 1, 2, 1, 1 };

    auto sets_indexes = to_three_subsets<int>(tab, 12, lessThan1, moreThan1);

    for (int i = 0; i < 12; ++i)
        std::cout << tab[i] << " ";

    std::cout << "\n" << sets_indexes.first_set_end_index << " " << sets_indexes.third_set_start_index << '\n';
}

template<typename T, typename FirstSetPredicate, typename SecondSetPredicate>
ThreeSubsetsSortResult to_three_subsets(
    int* arr,
    size_t size,
    FirstSetPredicate firstSetPredicate,
    SecondSetPredicate secondSetPredicate
)
{
    int i = -1;
    int j = 0;
    int k = size;

    while (j < k) {
        if (firstSetPredicate(arr[j])) {
            ++i;
            std::swap(arr[i], arr[j]);
            ++j;
        }
        else if (secondSetPredicate(arr[j])) {
            --k;
            std::swap(arr[j], arr[k]);
        }
        else
            ++j;

    }

    return ThreeSubsetsSortResult{
        .first_set_end_index = static_cast<size_t>(i),
        .third_set_start_index = static_cast<size_t>(k)
    };
}