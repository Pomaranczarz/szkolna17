#pragma once

#include <random>
#include <array>

template<size_t N>
[[nodiscard]] std::array<int, N> get_random_array(int range_begin, int range_end) {
    auto distribution = std::uniform_int_distribution<int>{};
    auto generator = std::default_random_engine{};
    std::array<int, N> tab;
    for (auto& i : tab)
        i = distribution(generator) % (range_end - range_begin + 1) + range_begin;
    return tab;
}
