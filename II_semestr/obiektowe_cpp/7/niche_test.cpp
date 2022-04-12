#include <iostream>
#include "Niche.hpp"
#include "Entities.hpp"

static Niche n1, n2, n3;

static char sep = SimulationSettings::getInstance().separatorSign;

void printNiche() {
    std::cout << n1.getSymbol() << sep << n2.getSymbol() << sep << n3.getSymbol() << '\n';
}

int main() {
    std::cout << "Puste nisze: ";
    printNiche();

    std::cout << "Lokowanie mieszkancow: ";
    n1.assignEntity(new Alga());
    n3.assignEntity(new Fungus());
    printNiche();

    std::cout << "Przesuwanie lokatorow: ";
    n2 = n1;
    printNiche();

    std::cout << "Przesuwanie lokatorow: ";
    n3 = n2;
    printNiche();
}