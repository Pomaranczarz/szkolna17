#pragma once

#include "../5/Neighborhood.hpp"
#include "../6/Entity.hpp"

class Niche
{
public:
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