#include "Organism.hpp"

Organism::Organism(
    unsigned short lifeLength,
    unsigned short mealLimit,
    unsigned short childCost
)
    : healthCount { lifeLength }
    , mealCount { 0 }
    , mealLimit { mealLimit }
    , childCost { childCost }
{

}

bool Organism::eat() {
    if (isHungry()) {
        mealCount++;
        return true;
    }
    else
        return false;
}

bool Organism::reproduce() {
    if (canReproduce()) {
        mealCount -= childCost;
        return true;
    }
    else
        return false;
}

void Organism::simulationStep() {
    if (isAlive())
        healthCount--;
}