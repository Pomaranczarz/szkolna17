#include "Entities.hpp"
#include "Environment.hpp"
#include "Neighborhood.hpp"
#include "Niche.hpp"
#include <fstream>
#include <iostream>

int main() {
	Environment ecosystem = Environment::readFromFile("start.txt");

	std::ofstream out{ "symulacja.txt" };
	if (!out.good())
		return 1;

	std::string simulationStatus;

	unsigned long i = 0;

	do {
		system("clear");
		std::cout << "Krok symulacji: " << i << "\n";
		out << "Krok symulacji: " << i << '\n';
		simulationStatus = ecosystem.toString();

		std::cout << '\n'
			    << simulationStatus << '\n';
		out << simulationStatus << '\n';

		std::cin.ignore(1);
		ecosystem++;
		++i;
	}
	while (i < 200 && !ecosystem);
}