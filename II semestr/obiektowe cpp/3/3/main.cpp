#include <iostream>

#include "Organism.hpp"

void printOrganism(const Organism& organism) {
    std::cout << "Organism: " << '\n';
    std::cout << "  isAlive: " << organism.isAlive() << '\n';
    std::cout << "  isHungry: " << organism.isHungry() << '\n';
    std::cout << "  canReproduce: " << organism.canReproduce() << '\n';
    std::cout << "  healthCount: " << organism.getHealthCount() << '\n';
    std::cout << "  mealCount: " << organism.getMealCount() << '\n';
}

int main() {
    Organism organism1 { 8, 3, 2 };
    Organism organism2 = organism1;
    Organism organism3 { organism1 };

    std::cout << "Organism1: \n";
    printOrganism(organism1);
    std::cout << "Organism2: \n";
    printOrganism(organism2);
    std::cout << "Organism3: \n";
    printOrganism(organism3);

    organism1.eat();
    organism2.eat();
    organism3.eat();

    organism3.simulationStep();

    std::cout << "Organism1: \n";
    printOrganism(organism1);
    std::cout << "Organism2: \n";
    printOrganism(organism2);
    std::cout << "Organism3: \n";
    printOrganism(organism3);

    Organism organism4 { 8, 3, 2 };

    std::cout << "Initial state:\n";
    printOrganism(organism4);

    for (int i = 1; i < 11; ++i) {
        organism4.simulationStep();

        if (organism4.canReproduce()) {
            organism4.reproduce();
            std::cout << "---> Reproduced!\n";
        }
        else
            organism4.eat();

        std::cout << "After " << i << " simulations step:\n";
        printOrganism(organism4);
    }
}