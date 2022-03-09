#pragma once

class Organism
{
public:
    Organism(
        unsigned short lifeLength,
        unsigned short mealLimit,
        unsigned short childCost
    );

    virtual ~Organism() = default;

    [[nodiscard]] bool isAlive() const {
        return healthCount > 0;
    }

    [[nodiscard]] bool isHungry() const {
        return isAlive() && mealCount < mealLimit;
    }

    [[nodiscard]] bool canReproduce() const {
        return isAlive() && mealCount > childCost;
    }

    [[nodiscard]] unsigned short getHealthCount() const {
        return healthCount;
    }

    [[nodiscard]] unsigned short getMealCount() const {
        return mealCount;
    }

    [[nodiscard]] bool eat();
    [[nodiscard]] bool reproduce();

    void simulationStep();
private:
    unsigned short healthCount;
    unsigned short mealCount;
    const unsigned short mealLimit;
    const unsigned short childCost;
};