#include "RandomGenerator.hpp"
#include <iostream>

int main() {
    std::cout << "Liczby losowe typu int:\n";
    std::cout << " od 0 do 5: ";
    for (int i = 0; i < 5; ++i)
        std::cout << RandomGenerator::randFromZeroTo(5) << " ";

    std::cout << "\n od 0 do 3: ";
    for (int i = 0; i < 3; ++i)
        std::cout << RandomGenerator::randFromZeroTo(3) << " ";

    std::cout << "\n od 0 do 20: ";
    for (int i = 0; i < 20; ++i)
        std::cout << RandomGenerator::randFromZeroTo(20) << " ";
    std::cout << "\n\n";

    std::cout << "Liczby losowe typu long:\n";
    std::cout << " od -2 do 2: ";
    for (int i = 0; i < 10; ++i)
        std::cout << GEN::randBetween(-2L, 2L) << " ";

    std::cout << "\n\nLiczby losowe typu unisgned short: \n";
    std::cout << " od 2 do 6: ";

    unsigned short min = 2, max = 6;
    for (int i = 0; i < 10; ++i)
        std::cout << GEN::randBetween(min, max) << " ";
}