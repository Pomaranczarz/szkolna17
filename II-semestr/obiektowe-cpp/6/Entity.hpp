#pragma once

#include "../4/Settings.hpp"
#include "EntityIntent.hpp"
#include "../5/Neighborhood.hpp"

class Entity
{
public:
    Entity(char symbol = SimulationSettings::getInstance().unknownSign);
    Entity(const Entity& inhibitant);

    virtual char getSymbol() const final;
    virtual ~Entity();
    virtual EntityType getType() = 0;
    virtual EntityIntent chooseAction(Neighborhood neighborhood) = 0;
    virtual Entity* getChild() = 0;
    virtual void getTrophy(Entity* inhibitant) = 0;

protected:
    char symbol;
};