#pragma once

#include "Neighborhood.hpp"
#include "Entity.hpp"

class Environment;

class Niche
{
public:
    friend class Environment;
    Niche();
    Niche(Niche &another);
    Niche &operator=(Niche &another);
    ~Niche();

    void assignEntity(Entity *entity);
    Entity *getEntity();
    bool occupied() const { return entity != nullptr; }
    EntityType getEntityType()
    {
        return occupied() ? entity->getType() : EntityType::Void;
    }

    bool isEntityAlive() const;
    char getSymbol() const;

private:
    EntityIntent activateEntity(Neighborhood neighborhood)
    {
        return entity->chooseAction(neighborhood);
    }

    Entity *releaseChild()
    {
        return entity->getChild();
    }

    void getTrophy(Entity *victim)
    {
        entity->getTrophy(victim);
    }

    Entity *entity;
};