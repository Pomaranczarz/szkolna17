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

    /// Check if organism is alive.
    [[nodiscard]] bool isAlive() const {
        return healthCount > 0;
    }

    /// Check is organism is hungry, i.e. lives and mealCount is less than mealLimit.
    [[nodiscard]] bool isHungry() const {
        return isAlive() && mealCount < mealLimit;
    }

    /// Check if organism can reproduce, i.e. lives and mealCount is greater than childCost.
    [[nodiscard]] bool canReproduce() const {
        return isAlive() && mealCount > childCost;
    }

    /// Get organism's health.
    [[nodiscard]] unsigned short getHealthCount() const {
        return healthCount;
    }

    /// Get organism's mealCount;
    [[nodiscard]] unsigned short getMealCount() const {
        return mealCount;
    }

    /// Increase mealCount by one.
    [[nodiscard]] bool eat();

    /// Produce child. Returns false if organims cannot reproduce.
    [[nodiscard]] bool reproduce();

    /// Proceed to next simulation step.
    void simulationStep();

private:
    unsigned short healthCount;
    unsigned short mealCount;
    const unsigned short mealLimit;
    const unsigned short childCost;
};