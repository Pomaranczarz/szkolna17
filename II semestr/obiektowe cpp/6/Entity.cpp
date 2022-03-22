#include "Entity.hpp"

Entity::Entity(char symbol)
    : symbol{ symbol }
{

}

Entity::Entity(const Entity& inhibitant)
    : symbol{ inhibitant.symbol }
{

}

char Entity::getSymbol() const
{
    return symbol;
}

Entity::~Entity()
{

}