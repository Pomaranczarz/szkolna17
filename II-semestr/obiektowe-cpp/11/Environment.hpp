#pragma once

#include "../4/RandomGenerator.hpp"
#include "../4/Settings.hpp"
#include "../7/Niche.hpp"
#include <string>

class Environment
{
public:
    const unsigned int rows, columns;
    const unsigned long nicheCount;

private:
    Niche** niche;

public:
    Environment(unsigned rows, unsigned cols);
    ~Environment();

    void allocate(Entity* entity, unsigned row, unsigned col);
    unsigned long count(EntityType type) const;
    bool dead();

    Neighborhood getNeighborhood(unsigned row, unsigned col) const;

    // Change location to neighboring random, free niche
    void performJump(unsigned row, unsigned col);
    void performAction(unsigned row, unsigned col);
    void simulationStep();

    std::string toString() const;
};