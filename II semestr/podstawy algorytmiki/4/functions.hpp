#pragma once

#include <utility>

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

    return (!predicate(arr[i]) ? i : i + 1);
}

struct ThreeSubsetsSortResult
{
    size_t first_set_end_index;
    size_t third_set_start_index;
};

template<typename T, typename FirstSetPredicate, typename ThirdSetPredicate>
ThreeSubsetsSortResult to_three_subsets(T* arr, size_t size, FirstSetPredicate firstSetPredicate, ThirdSetPredicate thirdSetPredicate)
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
        else if (thirdSetPredicate(arr[j])) {
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