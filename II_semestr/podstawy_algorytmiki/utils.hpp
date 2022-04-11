#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>
#include <string>
#include <iterator>
#include <type_traits>
#include <iostream>

class RandomGenerator
{
public:
    [[nodiscard]] static int get_int(int min, int max) noexcept {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }

    [[nodiscard]] static double get_double(double min, double max) noexcept {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);
        return dis(gen);
    }

    [[nodiscard]] static char get_char(char min, char max) noexcept {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(min, max);
        return static_cast<char>(dis(gen));
    }

    [[nodiscard]] static std::string get_string(int length) noexcept {
        std::string str;
        for (int i = 0; i < length; i++) {
            str += get_char('a', 'z');
        }
        return str;
    }
};

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

template<typename ForwardIterator>
void printRange(ForwardIterator begin, ForwardIterator end) {
    std::cout << "[ ";
    for (auto it = begin; it != end; it++) {
        std::cout << *it << " ";
    }
    std::cout << "]\n";
}

#endif // UTILS_HPP
