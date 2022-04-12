#include "Neighborhood.hpp"

std::string entityTypeToString(EntityType type) {
    switch (type) {
    case EntityType::Alga:      return "GLON";
    case EntityType::Bacteria:  return "BAKTERIA";
    case EntityType::Fungus:    return "GRZYB";
    case EntityType::Void:      return "PUSTKA";
    case EntityType::Wall:      return "SCIANA";
    case EntityType::Corpse:    return "TRUP";
    case EntityType::Unknown:   return "NIEZNANE";
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
        std::cout << "polozenie=" << position << " rodzaje=" << entityTypeToString(type) << "\n";
    }

    std::cout << "\nPoliczenie sasiadow okreslonego rodzaju: \n";
    std::cout << "glony=" << neighborhood.getNumberOfNeighborsOfType(EntityType::Alga) << "\n";
    std::cout << "grzyby=" << neighborhood.getNumberOfNeighborsOfType(EntityType::Fungus) << "\n";
    std::cout << "trupy=" << neighborhood.getNumberOfNeighborsOfType(EntityType::Corpse) << "\n";

    std::cout << "\nWylosowanie sasiada: \n";
    std::cout << " glon -> " << neighborhood.getPositionOfRandomNeighborOfType(EntityType::Alga) << "\n";
    std::cout << " pustka -> " << neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void) << "\n";
    std::cout << " trup -> " << neighborhood.getPositionOfRandomNeighborOfType(EntityType::Corpse) << "\n";

    long row, column;
    std::cout << "\nZmiana indeksow [5][7] wg polozenia: \n";

    for (int i = 0; i < 8; ++i) {
        Position position = static_cast<Position>(i);
        Neighborhood::changeIndexesFromPosition(position, row, column);
        std::cout << " polozenia: " << p << " ->[" << row << "][" << column << "]\n";
    }
}