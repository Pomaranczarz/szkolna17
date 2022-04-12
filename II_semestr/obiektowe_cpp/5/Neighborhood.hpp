#pragma once

#include <array>
#include "../4/RandomGenerator.hpp"
#include "../4/Settings.hpp"

class Neighborhood
{
public:
    Neighborhood(EntityType type = EntityType::Unknown);
    /// Set neighbor of 
    void setNeighbor(Position position, EntityType type);
    [[nodiscard]] EntityType getNeighborType(Position position);
    [[nodiscard]] unsigned short getNumberOfNeighborsOfType(EntityType type) const;
    [[nodiscard]] Position getPositionOfRandomNeighborOfType(EntityType type);
    static void changeIndexesFromPosition(Position position, long& row, long& column);
    static void changeIndexesFromPosition(Position position, unsigned& row, unsigned& column);

private:
    std::array<std::array<EntityType, 3>, 3> neighborhood;
    EntityType* innerElement(Position position);
    [[nodiscard]] static Position getRandomPosition();

};