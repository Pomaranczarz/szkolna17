#ifndef UTILS_HPP
#define UTILS_HPP

#include <algorithm>
#include <string>
#include <type_traits>
#include <concepts>
#include <iterator>
#include <random>

class RandomGenerator
{
public:
    /// Get random integer in range [min, max].
    [[nodiscard]] static int get_int(int min, int max) noexcept {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    /// Get random double in range [min, max].
    [[nodiscard]] static double get_double(double min, double max) noexcept {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);
        return dis(gen);
    }

    /// Get random char in range [min, max].
    [[nodiscard]] static char get_char(char min, char max) noexcept {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return static_cast<char>(dis(gen));
    }

    /// Get random string of length len.
    [[nodiscard]] static std::string get_string(int length) noexcept {
        std::string str;
        str.reserve(length);
        std::fill(str.begin(), str.end(), get_char('a', 'z'));

        return str;
    }
};

/// Check if number is prime
template<std::integral T>
[[nodiscard]] constexpr bool isPrime(const T& number) noexcept {
    if (number < 2)
        return false;

    for (T i = 2; i * i <= number; ++i) {
        if (number % i == 0)
            return false;
    }

    return true;
}

#endif // UTILS_HPP
