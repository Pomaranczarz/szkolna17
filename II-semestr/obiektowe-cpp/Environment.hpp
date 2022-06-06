#pragma once

#include "RandomGenerator.hpp"
#include "Settings.hpp"
#include "Niche.hpp"
#include "Entities.hpp"
#include <string>
#include <fstream>
#include <sstream>

class Environment
{
public:
    const unsigned int rows, columns;
    const unsigned long nicheCount;

private:
    Niche **niche;

public:
    Environment(unsigned rows, unsigned cols);
    ~Environment();

    void allocate(Entity *entity, unsigned row, unsigned col);
    unsigned long count(EntityType type) const;
    bool dead();

    Neighborhood getNeighborhood(unsigned row, unsigned col) const;

    // Change location to neighboring random, free niche
    void performJump(unsigned row, unsigned col);
    void performAction(unsigned row, unsigned col);
    void simulationStep();
    void operator++(int) { simulationStep(); }
    bool operator!() { return !dead(); }

    std::string toString() const;

    static Environment readFromFile(const std::string &filename);
};

std::ostream &operator<<(std::ostream &out, const Environment &env);