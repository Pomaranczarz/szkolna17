#include "utils.hpp"
#include <iostream>

int main() {
    std::cout << std::boolalpha;
    for (int i = 0; i < 10; ++i)
        std::cout << isPrime(i) << '\n';
}