#pragma once

#include <array>
#include "../4/RandomGenerator.hpp"

class InhibitantType;
class Position;

class Neighborhood
{
public:
    Neighborhood(InhibitantType type = UNKNOWN);
    void setNeighbor(Position position, InhibitantType type);
    [[nodiscard]] InhibitantType getNeighborType(Positon position);
    [[nodiscard]] unsigned short getNumberOfNeighborsOfType(InhibitantType type) const;
    [[nodiscard]] Position getPositionOfRandomNeighborOfType(InhibitantType type);
    static void changeIndexesFromPosition(Position position, long& row, long& column);
    static void changeIndexesFromPosition(Position position, unsigned& row, unsigned& column);

private:
    std::array<std::array<InhibitantType, 3>, 3> neighborhood;
    InhibitantType* innerElement(Position position);
    [[nodiscard]] static Position getRandomPosition();

};