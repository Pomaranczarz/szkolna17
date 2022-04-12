#include "Neighborhood.hpp"
#include <iostream>

std::string entityTypeToString(EntityType type) {
    switch (type) {
    case EntityType::Alga:      return "GLON";
    case EntityType::Bacteria:  return "BAKTERIA";
    case EntityType::Fungus:    return "GRZYB";
    case EntityType::Void:      return "PUSTKA";
    case EntityType::Wall:      return "SCIANA";
    case EntityType::Corpse:    return "TRUP";
    case EntityType::Unknown:   return "NIEZNANE";
    default:                    throw std::invalid_argument("Unknown entity type");
    }
}

int main() {
    Neighborhood neighborhood;

    neighborhood.setNeighbor(Position::P, EntityType::Alga);
    neighborhood.setNeighbor(Position::PG, EntityType::Fungus);
    neighborhood.setNeighbor(Position::G, EntityType::Fungus);
    neighborhood.setNeighbor(Position::LG, EntityType::Alga);
    neighborhood.setNeighbor(Position::L, EntityType::Bacteria);
    neighborhood.setNeighbor(Position::LD, EntityType::Bacteria);
    neighborhood.setNeighbor(Position::D, EntityType::Alga);
    neighborhood.setNeighbor(Position::PD, EntityType::Void);

    std::cout << "Przeglad sasiedztwa: \n";
    for (int i = 0; i < 8; ++i) {
        Position position = static_cast<Position>(i);
        EntityType type = neighborhood.getNeighborType(position);
        std::cout << "polozenie=" << static_cast<int>(position) << " rodzaje=" << entityTypeToString(type) << "\n";
    }

    std::cout << "\nPoliczenie sasiadow okreslonego rodzaju: \n";
    std::cout << "glony=" << neighborhood.getNumberOfNeighborsOfType(EntityType::Alga) << "\n";
    std::cout << "grzyby=" << neighborhood.getNumberOfNeighborsOfType(EntityType::Fungus) << "\n";
    std::cout << "trupy=" << neighborhood.getNumberOfNeighborsOfType(EntityType::Corpse) << "\n";

    std::cout << "\nWylosowanie sasiada: \n";
    std::cout << " glon -> " << static_cast<int>(neighborhood.getPositionOfRandomNeighborOfType(EntityType::Alga)) << "\n";
    std::cout << " pustka -> " << static_cast<int>(neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void)) << "\n";
    std::cout << " trup -> " << static_cast<int>(neighborhood.getPositionOfRandomNeighborOfType(EntityType::Corpse)) << "\n";

    long row, column;
    std::cout << "\nZmiana indeksow [5][7] wg polozenia: \n";

    for (int i = 0; i < 8; ++i) {
        Position position = static_cast<Position>(i);
        row = 5, column = 7;

        Neighborhood::changeIndexesFromPosition(position, row, column);
        std::cout << " polozenie: " << static_cast<int>(position) << " ->[" << row << "][" << column << "]\n";
    }
}