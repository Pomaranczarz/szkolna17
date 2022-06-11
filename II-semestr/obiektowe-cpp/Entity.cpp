#include "Entity.hpp"

Entity::Entity(char symbol)
    : symbol{ symbol } {
}

Entity::Entity(const Entity& inhibitant)
    : symbol{ inhibitant.symbol } {
}

Entity::Entity(Entity&& other)
    : symbol{ other.symbol } {
}

Entity& Entity::operator=(const Entity& other) {
	if (this == &other)
		return *this;

	symbol = other.symbol;
	return *this;
}

Entity& Entity::operator=(Entity&& other) {
	if (this == &other)
		return *this;

	symbol = other.symbol;
	return *this;
}

char Entity::getSymbol() const {
	return symbol;
}

Entity::~Entity() {
}