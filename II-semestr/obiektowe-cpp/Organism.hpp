#pragma once

class Organism
{
public:
	Organism(
	    unsigned short lifeLength,
	    unsigned short mealLimit,
	    unsigned short childCost);

	virtual ~Organism() = default;

	bool isAlive() const {
		return healthCount > 0;
	}

	bool isHungry() const {
		return isAlive() && mealCount < mealLimit;
	}

	bool canReproduce() const {
		return isAlive() && mealCount > childCost;
	}

	unsigned short getHealthCount() const {
		return healthCount;
	}

	unsigned short getMealCount() const {
		return mealCount;
	}

	bool eat();

	bool reproduce();

	void simulationStep();

private:
	unsigned short healthCount;
	unsigned short mealCount;
	const unsigned short mealLimit;
	const unsigned short childCost;
};