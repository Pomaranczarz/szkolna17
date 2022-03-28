#include "Neighborhood.hpp"

Neighborhood::Neighborhood(EntityType type)
{
    for (auto& row : neighborhood)
        for (auto& element : row)
            element = type;

    neighborhood[1][1] = UNKNOWN;
}

Position Neighborhood::getRandomPosition() {
    unsigned short min = 0, max = 8;
    return static_cast<Position>(RandomGenerator::randBetween(min, max));
}

void Neighborhood::setNeighbor(Position position, EntityType type)
{
    if (position != NOWHERE)
        *innerElement(position) = type;
}

EntityType Neighborhood::getNeighborType(Position position)
{
    if (position != NOWHERE)
        return *innerElement(position);
    else
        return UNKNOWN;
}

unsigned short Neighborhood::getNumberOfNeighborsOfType(EntityType type) const
{
    unsigned short numberOfNeighbors = 0;

    for (int i = 0; i < neighborhood.size(); ++i)
        for (int j = 0; j < neighborhood[i].size(); ++j)
            if (!(i == 1 && j == 1) && neighborhood[i][j] == type)
                ++numberOfNeighbors;

    return numberOfNeighbors;
}

Position Neighborhood::getPositionOfRandomNeighborOfType(EntityType type)
{
    unsigned short numberOfNeighbors = getNumberOfNeighborsOfType(type);
    if (numberOfNeighbors == 0)
        return NOWHERE;

    Position position = getRandomPosition();

    while (getNeighborType(position) != type)
        position = getRandomPosition();

    return position;
}

void Neighborhood::changeIndexesFromPosition(Position position, long& row, long& column)
{
    if (position == PG || position == P || position == PD)
        ++column;
    else if (position == LG || position == L || position == LD)
        --column;

    if (position == LG || position == G || position == PG)
        --row;
    else if (position == LD || position == D || position == PD)
        ++row;
}

void Neighborhood::changeIndexesFromPosition(Position position, unsigned& row, unsigned& column)
{
    long r = static_cast<long>(row), c = static_cast<long>(column);

    changeIndexesFromPosition(position, r, c);

    row = static_cast<unsigned>(r);
    column = static_cast<unsigned>(c);
}

EntityType* Neighborhood::innerElement(Position position) 
{
    switch (position) {
        case Position::P: return &neighborhood[1][2];
        case Position::PG: return &neighborhood[0][2];
        case Position::G: return &neighborhood[0][1];
        case Position::LG: return &neighborhood[0][0];
        case Position::L: return &neighborhood[1][0];
        case Position::LD: return &neighborhood[2][0];
        case Position::D: return &neighborhood[2][1];
        case Position::PD: return &neighborhood[2][2];
        case Position::Nowhere: return nullptr;
        default: nullptr
    }
}
