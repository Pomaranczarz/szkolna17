#include <iostream>
#include <iomanip>
#include "functions.hpp"

void read_data(std::istream& in, std::string& str, const std::string& message) {
    std::cout << message;
    std::getline(in, str);
}

int main() {
    std::string text{};
    std::string pattern;

    read_data(std::cin, text, "Podaj tekst: \n");
    read_data(std::cin, pattern, "Podaj wyszukiwana fraze: \n");

    std::cout << "Napis: \n";

    std::cout << "Wynik algorytmu naiwnego: \n";
    find_naive(text, pattern);
    std::cout << "Wynik algorytmu K-M-P: \n";
    find_kmp(text, pattern);
}
