#pragma once

#include "Settings.hpp"
#include "EntityIntent.hpp"
#include "Neighborhood.hpp"

class Entity
{
public:
    Entity(char symbol = SimulationSettings::getInstance().unknownSign);
    Entity(const Entity &inhibitant);
    Entity(Entity &&other);
    Entity &operator=(const Entity &other);
    Entity &operator=(Entity &&other);

    virtual char getSymbol() const final;
    virtual ~Entity();
    virtual EntityType getType() = 0;
    virtual EntityIntent chooseAction(Neighborhood neighborhood) = 0;
    virtual Entity *getChild() = 0;
    virtual void getTrophy(Entity *inhibitant) = 0;

protected:
    char symbol;
};